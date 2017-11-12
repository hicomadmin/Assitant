#include "mainwindow.h"
#include <QFontDatabase>
#include <qapplication.h>
#include <QtGui/QGuiApplication>
#include <QDeclarativeView>
#include "QtDeclarative/QDeclarativeView"
#include <QQuickView>
#include <QQuickItem>


MainWindow::MainWindow()
{
    DEBUGLOG;
    m_pstCallListInfo = NULL;
    m_isExecute = 0;
    m_isGetrecordList = 0;
    m_isLoaderLocalMusic = 0;
    m_title_dateTime.year = 0;
    m_title_dateTime.month = 0;
    m_showFlag = 0;
    //对接收到的消息信号处理
    connect(this, SIGNAL(receiveMsg(ST_SMS_INFO*)), this, SLOT(onReceiveMsg(ST_SMS_INFO*)));
    //对发送状态的信号处理
    connect(this, SIGNAL(sendStatus(ST_SMS_STATUS_FRM*)), this, SLOT(onSendStatus(ST_SMS_STATUS_FRM*)));
    //对发送消息信号处理
    connect(this, SIGNAL(initiativeSend(ST_SMS_STATUS_FRM*)), this, SLOT(onInitiativeSend(ST_SMS_STATUS_FRM*)));
    connect(this, SIGNAL(receiveContact(bool)), this, SLOT(onReceiveContact(bool)));
    //读取最近通话记录
    connect(this, SIGNAL(callLogs(int)), this, SLOT(onCallLogs(int)));
    //local music
    connect(this, SIGNAL(getLocalSongList(int, int, int)), this, SLOT(onGetLocalSongList(int, int, int)));
    connect(this, SIGNAL(getSongInfo(ST_SONG_INFO*)), this, SLOT(onGetSongInfo(ST_SONG_INFO*)));

    //canlendar
    connect(this, SIGNAL(canlendarReciveEvent()), this, SLOT(onCanlendarReciveEvent()));
}

MainWindow::~MainWindow()
{
    if(st_LocalSong_Info)
    {
        delete[] st_LocalSong_Info;
        st_LocalSong_Info = NULL;
    }
    if(m_pstCallListInfo)
    {
        delete[] m_pstCallListInfo;
        m_pstCallListInfo = NULL;
    }
    exitLink();
}

void MainWindow::init()
{
    DEBUGLOG;
    m_messageListModel = new Msg_ListModel(this);            //短信列表
    this->rootContext()->setContextProperty("c_messageListModel", m_messageListModel);
    m_detailListModel = new Msg_DetailListModel(this);      //详细短信列表
    this->rootContext()->setContextProperty("c_detailListModel", m_detailListModel);
    m_phraseListModel = new Msg_PhaseModel(this);           //快捷短语列表
    this->rootContext()->setContextProperty("c_phraseListModel", m_phraseListModel);

    m_contactListModel = new PhonebookListModel(this);      //电话簿联系人
    this->rootContext()->setContextProperty("c_bookListModel", m_contactListModel);
    m_recordListModel = new PhoneRecordListModel(this);     //最近联系人
    this->rootContext()->setContextProperty("c_recordListModel", m_recordListModel);
    m_thinkResultListModel = new phoneThinkResultListModel(this);  //拨号联想结果
    this->rootContext()->setContextProperty("c_thinkResultListModel", m_thinkResultListModel);
    //local music
    m_localMusicList = new LocalMusicListModel(this);
    this->rootContext()->setContextProperty("localmusic", m_localMusicList);
    //AppList
    m_appList = new AppListItemModel(this);
    m_appListPage = new AppListItemModel(this);
    this->rootContext()->setContextProperty("AppList", m_appList);
    this->rootContext()->setContextProperty("AppListPge", m_appListPage);
}

void MainWindow::freePhoneContactsMem()
{
    if(st_LocalSong_Info)
    {
        delete[] st_LocalSong_Info;
        st_LocalSong_Info = NULL;
    }
    if(m_pstCallListInfo)
    {
        delete[] m_pstCallListInfo;
        m_pstCallListInfo = NULL;
    }
    m_isExecute = 0;
    m_isGetrecordList = 0;
    m_isLoaderLocalMusic = 0;
    assistant.eventlistmodel->clear();     //清空日历事件列表
    m_recordListModel->clear();            //清空通话记录
    m_contactListModel->clear();           //清空电话簿联系人
    emit g_pAppWnd->setTextNull();         //拔线后清空电话编辑区内容，和清空联想结果,回到拨号界面
    emit g_pAppWnd->sendMessageBtnUnused(); //发送短信标识复位
}

void MainWindow::exitLink()
{
    DEBUG_CHAR("exitLink=======");
    assistant.assistant_api.SSP_iAssistant_UnInit();
    exit(0);
}

void MainWindow::assistantDeviceStateReport(int state)
{
    g_pAppWnd->assistant.assistant_api.SSP_iAssistant_DeviceStateReport(state);
}

void MainWindow::getLocalAppList()
{
    m_appList->clear();
    m_appListPage->clear();
    pst_LocalAppList = g_pAppWnd->assistant.assistant_api.SSP_ptAssistant_GetLocalAppList();

    DEBUG_PARAM("ret:", pst_LocalAppList->ret);
    DEBUG_PARAM("count:", pst_LocalAppList->count);
    DEBUG_PARAM("preInstallCount:", pst_LocalAppList->preInstallCount);

    if(pst_LocalAppList->ret == 0)
    {
        if(pst_LocalAppList->count < 8)
        {
            AppListItem pageItem = AppListItem("","",0, 0);
            m_appListPage->addAppListItem(pageItem);
        }
        else
        {
            for(int i = 0; i < pst_LocalAppList->count/8; i++)
            {
                AppListItem pageItem = AppListItem("","",0, i);
                m_appListPage->addAppListItem(pageItem);
            }
        }

        for(int i = 0;i < pst_LocalAppList->count;i++)
        {
            AppListItem item = AppListItem(QString(pst_LocalAppList->pstLocalApp[i].name),
                                           QString("file://")+QString(pst_LocalAppList->pstLocalApp[i].iconPath),
                                           i,
                                           0);
            DEBUG_PARAM("i:", i);
            DEBUG_PARAM("iconPath:", pst_LocalAppList->pstLocalApp[i].iconPath);
            DEBUG_PARAM("name:", pst_LocalAppList->pstLocalApp[i].name);
            m_appList->addAppListItem(item);
        }

        emit sigAppListCount(pst_LocalAppList->count);
    }
}

void MainWindow::doLaunchApp(int index)
{
    DEBUG_PARAM("index:", index);
    assistant.assistant_api.SSP_iAssistant_RunProcess(pst_LocalAppList->pstLocalApp[index].id, pst_LocalAppList->pstLocalApp[index].type);
}

void MainWindow::runMusicAppProcess(QString appID)
{
    DEBUG_PARAM("appID:", appID.toLocal8Bit().data());
    assistant.assistant_api.SSP_iAssistant_RunProcess(appID.toLocal8Bit().data(), 0);
}

void MainWindow::setAssistantLanguage(int languageFlag)
{
    DEBUGLOG;
    I108n* I18n = I108n::instance();
    if(0 == languageFlag)
    {
        DEBUG_CHAR("setLang zh");
        I18n->setLang("zh");
    }
    else
    {
        DEBUG_CHAR("setLang en");
        I18n->setLang("en");
    }
}

void MainWindow::assistant_do_runMirror()
{
    DEBUG_CHAR("assistant_do_runMirror =======");
    g_pAppWnd->assistant.assistant_api.SSP_iAssistant_MirrorStateReport(1);
    g_pAppWnd->assistant.assistant_api.SSP_iAssistant_StartMirrorMode();
}

void MainWindow::requestVRStatus(QString status)
{
    if(status == "start") {
        assistant.assistant_api.SSP_iVR_Request_StartVr();
    }
    else if(status == "stop") {
        assistant.assistant_api.SSP_iVR_Request_StopVr();
    }
    else if(status == "end") {
        assistant.assistant_api.SSP_iVR_Request_VoiceEnd();
    }
}

void MainWindow::localMusicRun()
{
    DEBUGLOG;
    assistant.assistant_api.SSP_iAssistant_LocalMusicRun();
}

void MainWindow::hideAssistantWindow()
{
    DEBUG_CHAR("hide AssistantWindow huanght 6666======");
    g_pAppWnd->hide();
    m_showFlag = 0;
}

void MainWindow::showAssistantWindow()
{
    DEBUG_CHAR("show AssistantWindow huanght 6666======");
    g_pAppWnd->show();
    m_showFlag = 1;
}

void MainWindow::specialShow()
{
    DEBUGLOG;
    g_pAppWnd->show();
}

int MainWindow::getShowFlag() const
{
    return m_showFlag;
}
void MainWindow::mySleep(unsigned long um)
{
    DEBUG_PARAM("mySleep = ", um);
    QThread::usleep(um);
}

void MainWindow::assistant_do_stopMirrorMode()
{
    g_pAppWnd->assistant.assistant_api.SSP_vAssistant_StopMirrorMode();
}

void MainWindow::assistantDisplayStateReport(int state)
{
    //state 0: hide, 1: show, 2: exit 车机助手给主机返回显隐消息接口
    g_pAppWnd->assistant.assistant_api.SSP_iAssistant_DisplayStateReport(state);
}

void MainWindow::assistantStateReport(int state)
{
    g_pAppWnd->assistant.assistant_api.SSP_iAssistant_AssisStateReport(state);
}

void MainWindow::activate_start()
{
    DEBUGLOG; //激活
    assistant.assistant_api.SSP_iActivate_Start();
}

void MainWindow::activate_return()
{
    DEBUGLOG; //激活
    assistant.assistant_api.SSP_iActivate_Return();
}

/******************************* localMusic start *******************************/
void MainWindow::localMusic_do_Wakeup()
{
    DEBUG_CHAR("localMusic_do_Wakeup");
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_WakeUp();
}

void MainWindow::localMusic_do_GetSongInfo()
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_GetSongInfo();
}

void MainWindow::localMusic_do_ExitPhoneAPP()
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_ExitPhoneAPP();
}

void MainWindow::localMusic_do_LoadList(int musicPageNumber)
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_LocalSongList(musicPageNumber);
}

void MainWindow::localMusic_do_PlayPrevMusic()
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_vMusic_Prev();
}

void MainWindow::localMusic_do_PlayNextMusic()
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_vMusic_Next();
}

void MainWindow::localMusic_do_PlayOrPause(unsigned char playOrPause)
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_vMusic_PlayOrPause(playOrPause);
}

void MainWindow::localMusic_do_SetPlayMode(int playMode)
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_ChangePlayMode(playMode);
}

void MainWindow::localMusic_do_PlayLocalSong(QString str)
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_PlayLocalSong(str.toLatin1().data());
}

void MainWindow::localMusic_do_GetLocalPic(QString str)
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_LocalPic(str.toLatin1().data());
}


/******************************* localMusic End *******************************/
//Calendar
//根据当前日期计算日历上的第一天是哪一天，由QDate的addDays计算
void MainWindow::UpdateDateInfo(QDate dCurrDate)
{
    QDate qFirstDateAtMonth = dCurrDate;
    qFirstDateAtMonth.setDate(qFirstDateAtMonth.year(), qFirstDateAtMonth.month(), 1);
    int nWeekForFirstDay 	= qFirstDateAtMonth.dayOfWeek();
    int nPreviousMonthDays 	= 0;

    if(nWeekForFirstDay == 7){
        nPreviousMonthDays = 0;
    }
    else if(nWeekForFirstDay <7 && nWeekForFirstDay >= 1){
        nPreviousMonthDays = nWeekForFirstDay;
    }

    QDate qFirstDateAtCalendar	= qFirstDateAtMonth.addDays(nPreviousMonthDays*(-1));
    tMonthDateInfo.nCurrYear    = dCurrDate.year();
    tMonthDateInfo.nCurrMonth 	= dCurrDate.month();
    tMonthDateInfo.nCurrDay		= dCurrDate.day();
    for(int i=0; i<42; ++i){
        tMonthDateInfo.arrMonthDateInfo[i].SetDate(qFirstDateAtCalendar.addDays(i));
    }
}

void MainWindow::UpdateDateInfo(DateTimeInfo_t dCurrDate)
{
    QDate qFirstDateAtMonth;
    qFirstDateAtMonth.setDate(dCurrDate.year, dCurrDate.month, 1);
    int nWeekForFirstDay 	= qFirstDateAtMonth.dayOfWeek();
    int nPreviousMonthDays 	= 0;

    if(nWeekForFirstDay == 7){
        nPreviousMonthDays = 0;
    }
    else if(nWeekForFirstDay <7 && nWeekForFirstDay >= 1){
        nPreviousMonthDays = nWeekForFirstDay;
    }

    QDate qFirstDateAtCalendar	= qFirstDateAtMonth.addDays(nPreviousMonthDays*(-1));
    tMonthDateInfo.nCurrYear    = dCurrDate.year;
    tMonthDateInfo.nCurrMonth 	= dCurrDate.month;
    tMonthDateInfo.nCurrDay		= dCurrDate.day;
    for(int i=0; i<42; ++i){
        tMonthDateInfo.arrMonthDateInfo[i].SetDate(qFirstDateAtCalendar.addDays(i));
    }
}

void MainWindow::UpdateDateEventCount(int nCount[31])
{
    tMonthDateInfo.setEventCount(nCount);
}

void MainWindow::AddEventMsgByDate(int nYear, int nMonth, int nDay, Message_t *pMsg)
{
    tMonthDateInfo.setEventMsg(nYear, nMonth, nDay, pMsg);
}

void MainWindow::onCalendarInit()
{
    m_nListClickItem = -1;
    if(tMonthDateInfo.nCurrYear == -1){
        QDate qDate = QDate::currentDate();
        UpdateDateInfo(qDate);
    }
}

void MainWindow::onWeatherInit()
{
    DEBUGLOG;
    m_bLoadedOK = false;
    m_bLoadedFail = false;
    m_bLoading = true;
    assistant.assistant_api.fun_SSP_iWeather_GetCurrentCityWeather();
}

bool MainWindow::isWeatherLoadedOK()
{
    return m_bLoadedOK;
}

bool MainWindow::isWeatherLoadedFail()
{
    return m_bLoadedFail;
}

bool MainWindow::isWeatherLoading()
{
    return m_bLoading;
}

void MainWindow::setCalendarToToday()
{
    tMonthDateInfo.nCheckMonth = tMonthDateInfo.nCurrMonth;
    tMonthDateInfo.nCheckDay = tMonthDateInfo.nCurrDay;
    emit assistant.signal_updateDateInfo();
}

MonthDateInfo MainWindow::getMonthDateInfo()
{
    return tMonthDateInfo;
}

int MainWindow::getCalendarDay(int nIndex)
{
    if(nIndex < 42 && nIndex>=0){
        return  tMonthDateInfo.arrMonthDateInfo[nIndex].nDay;
    }
    else{
        return -1;
    }
}

int MainWindow::getCalendarDayMonth(int nIndex)
{
    if(nIndex < 42 && nIndex>=0){
        return  tMonthDateInfo.arrMonthDateInfo[nIndex].nMonth;
    }
    else{
        return -1;
    }
}

int MainWindow::getCalendarCheckMonth()
{
    return tMonthDateInfo.nCheckMonth;
}

int MainWindow::getCalendarYear()
{
    //return tMonthDateInfo.nCurrYear;
    return m_title_dateTime.year;
}

int MainWindow::getCalendarMonth()
{
    //return tMonthDateInfo.nCurrMonth;
    return m_title_dateTime.month;
}

int MainWindow::getCalendarCurrDay()
{
    return tMonthDateInfo.nCurrDay;
}

int MainWindow::getCalendarCheckDay()
{
    return tMonthDateInfo.nCheckDay;
}

void MainWindow::onCalendarDayClicked(int nIndex)
{
    DEBUG_PARAM("nIndex = ", nIndex);
    tMonthDateInfo.nCheckMonth = tMonthDateInfo.arrMonthDateInfo[nIndex-1].nMonth;
    tMonthDateInfo.nCheckDay = tMonthDateInfo.arrMonthDateInfo[nIndex-1].nDay;

    emit assistant.signal_updateDateInfo();
}

QVariantList MainWindow::getMessageByCheckDay()
{
    DEBUGLOG;
    QVector<Message_t*> vtMsg = tMonthDateInfo.getEventMsg(tMonthDateInfo.nCurrYear, tMonthDateInfo.nCheckMonth, tMonthDateInfo.nCheckDay);
    DEBUG_PARAM("getMessageByCheckDay enter event size = ", vtMsg.size());
    assistant.eventlistmodel->clear();
    event_list_item* pitem = new event_list_item();
    char cTemp[20] = {0};
    QString sStartTime = "00:00";
    QString sEndTime = "24:00";
    char dateInfo[20] = {0};

    for(int i=0; i<vtMsg.size(); ++i)
    {
        sprintf(dateInfo, "%d年%d月%d日",  (*vtMsg[i]).stStartDateInfo.year, (*vtMsg[i]).stStartDateInfo.month, (*vtMsg[i]).stStartDateInfo.day);

        if(!(*vtMsg[i]).iAllDay)
        {
            sStartTime = "";
            sEndTime = "";
            sprintf(cTemp, "%02d",  (*vtMsg[i]).stStartDateInfo.hour);
            sStartTime +=QString(cTemp) + ":";
            memset(cTemp, 0, 20);
            sprintf(cTemp, "%02d",  (*vtMsg[i]).stStartDateInfo.minute);
            sStartTime += cTemp;
            memset(cTemp, 0, 20);

            sprintf(cTemp, "%02d",  (*vtMsg[i]).stEndDateInfo.hour);
            sEndTime += QString(cTemp) + ":";
            memset(cTemp, 0, 20);
            sprintf(cTemp, "%02d",  (*vtMsg[i]).stEndDateInfo.minute);
            sEndTime += cTemp;
            memset(cTemp, 0, 20);
        }
        pitem->setiteminfo(0, sStartTime, sEndTime,  QString::fromUtf8(dateInfo), QString::fromUtf8((*vtMsg[i]).cTitle));
        assistant.eventlistmodel->addEventListItem(*pitem);
    }
    if(0 == assistant.eventlistmodel->rowCount())
    {
        QQuickItem *calendarHinit = g_pAppWnd->rootObject()->findChild<QQuickItem*>("calendarHinit");
        if(calendarHinit)
        {
            calendarHinit->setProperty("visible", true);
        }
    }
    else
    {
        QQuickItem *calendarHinit = g_pAppWnd->rootObject()->findChild<QQuickItem*>("calendarHinit");
        if(calendarHinit)
        {
            calendarHinit->setProperty("visible", false);
        }
    }

    QVariantList listMsg;
    return listMsg;
}

void MainWindow::onCalendarListClicked(int nIndex)
{
    m_nListClickItem = nIndex;
}

QString g_sWeek[7] = {"周一", "周二", "周三", "周四", "周五", "周六", "周日"};

QVariantList MainWindow::getMessageByListClickedItem()
{
    QVariantList listMsg;

    DEBUGLOG;
    QVector<Message_t*> vtMsg = tMonthDateInfo.getEventMsg(tMonthDateInfo.nCurrYear, tMonthDateInfo.nCheckMonth, tMonthDateInfo.nCheckDay);
    DEBUG_PARAM("getMessageByCheckDay enter event size = ", vtMsg.size());

    char cTemp[20] = {0};
    QString sStartTime = "00:00";
    QString sEndTime = "24:00";
    int i = m_nListClickItem;

    if(m_nListClickItem >= 0 && m_nListClickItem < vtMsg.size()){

        if(!(*vtMsg[i]).iAllDay)
        {
            sStartTime = "";
            sEndTime = "";
            sprintf(cTemp, "%02d",  (*vtMsg[i]).stStartDateInfo.hour);
            sStartTime +=QString(cTemp) + ":";
            memset(cTemp, 0, 20);
            sprintf(cTemp, "%02d",  (*vtMsg[i]).stStartDateInfo.minute);
            sStartTime += cTemp;
            memset(cTemp, 0, 20);

            sprintf(cTemp, "%02d",  (*vtMsg[i]).stEndDateInfo.hour);
            sEndTime += QString(cTemp) + ":";
            memset(cTemp, 0, 20);
            sprintf(cTemp, "%02d",  (*vtMsg[i]).stEndDateInfo.minute);
            sEndTime += cTemp;
            memset(cTemp, 0, 20);
        }

        QString sDate = "";
        QDate dTemp = QDate::currentDate();
        dTemp.setDate(tMonthDateInfo.nCurrYear, tMonthDateInfo.nCheckMonth, tMonthDateInfo.nCheckDay);
        int nWeek = dTemp.dayOfWeek()-1;

        if(nWeek >=0 && nWeek<7){
            sDate = QString::number(tMonthDateInfo.nCurrYear) + "/" +  QString::number(tMonthDateInfo.nCheckMonth) + "/" +  QString::number(tMonthDateInfo.nCheckDay) + "   " + g_sWeek[nWeek];
        }
        else{
            sDate = QString::number(tMonthDateInfo.nCurrYear) + "/" +  QString::number(tMonthDateInfo.nCheckMonth) + "/" +  QString::number(tMonthDateInfo.nCheckDay);
        }

        listMsg.append(sStartTime);
        listMsg.append(sEndTime);
        listMsg.append(QString::fromUtf8((*vtMsg[i]).cTitle));
        listMsg.append(sDate);
        listMsg.append(QString::fromUtf8(strlen((*vtMsg[i]).cDetail) == 0 ? "无" :(*vtMsg[i]).cDetail));
        listMsg.append(QString::fromUtf8(strlen((*vtMsg[i]).cLocation) == 0 ? "无" :(*vtMsg[i]).cLocation));
    }

    return listMsg;
}

bool MainWindow::haveAffairsCalendarDay(int nIndex)
{
    if(nIndex < 42 && nIndex>=0){
        return  tMonthDateInfo.arrMonthDateInfo[nIndex].nHaveAffairs;
    }else{
        return -1;
    }
}


/******************************* Weather Start *******************************/
QString MainWindow::getCurrentWeekWeaeher()
{
    if(strlen(g_pAppWnd->m_stWeatherEveryDay[1].date) != 0)
    {
        return QString::fromUtf8(g_pAppWnd->m_stWeatherEveryDay[1].week);
    }
    return "";
}

QVariantList MainWindow::getCurrentDayWeatherInfo()
{
    QVariantList weatherList;
    if(g_pAppWnd->m_stWeatherData.result == _SSP_OK){
        weatherList.append(g_pAppWnd->m_stWeatherData.result);
        weatherList.append(g_pAppWnd->m_stWeatherData.cityCode);
        weatherList.append(g_pAppWnd->m_stWeatherData.repTime);
        weatherList.append(g_pAppWnd->m_stWeatherData.weaWarring);
        weatherList.append(g_pAppWnd->m_stWeatherData.todayWeather);
        weatherList.append(g_pAppWnd->m_stWeatherData.nowTemp);

        int nWeatherID = g_pAppWnd->m_stWeatherData.weatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        weatherList.append(g_pAppWnd->m_stWeatherData.cityName);
        weatherList.append(g_pAppWnd->m_stWeatherData.chineseDate);
        weatherList.append(g_pAppWnd->m_stWeatherData.highTemp);
        weatherList.append(g_pAppWnd->m_stWeatherData.lowTemp);
        weatherList.append(g_pAppWnd->m_stWeatherData.wet);
        weatherList.append(g_pAppWnd->m_stWeatherData.wind);
        weatherList.append(g_pAppWnd->m_stWeatherData.aqi);
        weatherList.append(g_pAppWnd->m_stWeatherData.aqiLevel);

        QString sWeatherIconPath = "../weatherImages/weather_icon_big/" + sWeatherTypeIconName[nWeatherID];
        weatherList.append(sWeatherIconPath);

        DEBUG_PARAM("wind = ", g_pAppWnd->m_stWeatherData.wind);
    }
    return weatherList;
}

QVariantList MainWindow::getFirstDayWeatherInfo()
{
    QVariantList weatherList;
    if(strlen(g_pAppWnd->m_stWeatherEveryDay[2].date) != 0){
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[2].date);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[2].week);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[2].highTemp);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[2].lowTemp);

        int nWeatherID = g_pAppWnd->m_stWeatherEveryDay[2].dayWeatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        nWeatherID = g_pAppWnd->m_stWeatherEveryDay[2].nightWeatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[2].windPower);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[2].windDir);

        QString sWeatherIconPath = "../weatherImages/weather_icon_small/" + sWeatherTypeIconName[g_pAppWnd->m_stWeatherEveryDay[2].dayWeatherID];
        weatherList.append(sWeatherIconPath);
    }
    return weatherList;
}

QVariantList MainWindow::getSecondDayWeatherInfo()
{
    QVariantList weatherList;
    if(strlen(g_pAppWnd->m_stWeatherEveryDay[2].date) != 0){
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[3].date);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[3].week);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[3].highTemp);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[3].lowTemp);

        int nWeatherID = g_pAppWnd->m_stWeatherEveryDay[3].dayWeatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        nWeatherID = g_pAppWnd->m_stWeatherEveryDay[3].nightWeatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[3].windPower);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[3].windDir);

        QString sWeatherIconPath = "../weatherImages/weather_icon_small/" + sWeatherTypeIconName[g_pAppWnd->m_stWeatherEveryDay[3].dayWeatherID];
        weatherList.append(sWeatherIconPath);

        DEBUG_PARAM("getSecondDayWeatherInfo date: ", g_pAppWnd->m_stWeatherEveryDay[3].date);
    }

    return weatherList;
}

QVariantList MainWindow::getThirdDayWeatherInfo()
{
    QVariantList weatherList;
    if(strlen(g_pAppWnd->m_stWeatherEveryDay[2].date) != 0){
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[4].date);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[4].week);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[4].highTemp);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[4].lowTemp);

        int nWeatherID = g_pAppWnd->m_stWeatherEveryDay[4].dayWeatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        nWeatherID = g_pAppWnd->m_stWeatherEveryDay[4].nightWeatherID;
        if(nWeatherID >= ICON_ID_Sunny && nWeatherID <= ICON_ID_Sandstorm){
            weatherList.append(sWeatherType[nWeatherID]);
        }
        else if(nWeatherID == ICON_ID_Haze){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+1]);
        }
        else if(nWeatherID == ICON_ID_Unknown){
            weatherList.append(sWeatherType[ICON_ID_Sandstorm+2]);
        }

        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[4].windPower);
        weatherList.append(g_pAppWnd->m_stWeatherEveryDay[4].windDir);

        QString sWeatherIconPath = "../weatherImages/weather_icon_small/" + sWeatherTypeIconName[g_pAppWnd->m_stWeatherEveryDay[4].dayWeatherID];
        weatherList.append(sWeatherIconPath);

        DEBUG_PARAM("getThirdDayWeatherInfo date: ", g_pAppWnd->m_stWeatherEveryDay[4].date);
    }
    return weatherList;
}


/******************************* MESSAGE START *******************************/

void MainWindow::flushMsgDB()
{
    DEBUG_CHAR("flushMsgDB");
    char  unRead[3] = {0};
    g_pAppWnd->assistant.assistant_api.fun_iSms_iUnReadMsg(unRead);
    if(unRead[0] == '0' || strlen(unRead) == 0)
    {
        QQuickItem *recvMessage = g_pAppWnd->rootObject()->findChild<QQuickItem*>("recvMessage");
        if(recvMessage)
        {
            recvMessage->setProperty("visible", false);
        }
    }
    else
    {
        QQuickItem *recvMessage = g_pAppWnd->rootObject()->findChild<QQuickItem*>("recvMessage");
        if(recvMessage)
        {
            recvMessage->setProperty("visible", true);
        }
    }
}

void MainWindow::deleteOnePersonMessage(int index)
{
    DEBUG_PARAM("index", index);
    if(g_pAppWnd->assistant.assistant_api.fun_iBtSms_iDeleteOnePersonMsgRecord)
    {
        g_pAppWnd->assistant.assistant_api.fun_iBtSms_iDeleteOnePersonMsgRecord(m_messageListModel->get(index, "number").toString().toUtf8().data());
    }
    updateListContent();
}

void MainWindow::getOnePersonMessages(QString number)
{
    updateDetailContent(number);
}

void MainWindow::sendMessage(QString number, QString message)
{
    DEBUG_PARAM("message: ",message);
    if(g_pAppWnd->assistant.assistant_api.fun_iBtSms_iSendMsg)
    {
        DEBUGLOG;
        g_pAppWnd->assistant.assistant_api.fun_iBtSms_iSendMsg(number.toUtf8().data(), message.toUtf8().data());
    }
    updateDetailContent(m_detailListModel->get(0, "number").toString());
}
void MainWindow::reSendMessage(QString number, QString message, QString rank)
{
    if(g_pAppWnd->assistant.assistant_api.fun_iBtSms_iSendMsg)
    {
        g_pAppWnd->assistant.assistant_api.fun_iBtSms_iReSendMsg(number.toUtf8().data(), message.toUtf8().data(), rank.toUtf8().data());
    }
}

void MainWindow::updateDetailContent(QString number)
{
    ST_SMS_REPLY_INFOR_FRM smsReplyInfoFrm;
    PST_SMS_REPLY_INFOR pDetail;

    DEBUG_PARAM("number: ", number);
    smsReplyInfoFrm.count = 0;

    if(g_pAppWnd->assistant.assistant_api.fun_iBtSms_iOrderBynumberMsgRecord)
    {
        if(g_pAppWnd->assistant.assistant_api.fun_iBtSms_iOrderBynumberMsgRecord(number.toLocal8Bit().data(), &smsReplyInfoFrm))
            return ;
    }
    DEBUG_PARAM("count: ", smsReplyInfoFrm.count);
    m_detailListModel->clear();
    pDetail = smsReplyInfoFrm.pstSmsReplyInfor;

    Msg_DetailListItem item;
    QStringList sl;
    QString qStr = "";
    for(unsigned int i = 0; i < smsReplyInfoFrm.count; i++)
    {
        //Msg_DetailListItem item;  //循环内定义变量，放到循环外
        /*QStringList*/ sl = QString::fromUtf8(pDetail->cMsgDate).split("-");
        if(sl.at(0).toInt() == m_dateTimeInfo.year &&
                sl.at(1).toInt() == m_dateTimeInfo.month &&
                sl.at(2).toInt() == m_dateTimeInfo.day)
        {
            item.setTime(sl.at(1) + " " + sl.at(2) );    // 5月 12日
            qStr = item.time();
            strcpy(pDetail->cMsgDate, qStr.toLatin1());
        }
        else
        {
            item.setTime(sl.at(1) + "月"+ " " + sl.at(2) + "日");    // 5月 12日
            qStr = item.time();
            strcpy(pDetail->cMsgDate, qStr.toUtf8());
        }
        item = Msg_DetailListItem(QString::fromUtf8(pDetail->cStrTest),
                                  QString::fromUtf8(pDetail->cMsgDate)+ " " + pDetail->cMsgTime,
                                  pDetail->iName,
                                  pDetail->iNumber,
                                  QString::fromUtf8(pDetail->cMsgID),
                                  (bool)(pDetail->iMsgType),
                                  pDetail->iExecStatus,
                                  pDetail->Rank);

        m_detailListModel->addItem(item);
        pDetail++;
        if(i == smsReplyInfoFrm.count-1)
            emit m_detailListModel->dataChanged(m_detailListModel->index(i), m_detailListModel->index(i));
    }
    flushMsgDB();
    emit detailContentUpdated();

    if(smsReplyInfoFrm.pstSmsReplyInfor)
    {
        free(smsReplyInfoFrm.pstSmsReplyInfor); //free memory
        smsReplyInfoFrm.pstSmsReplyInfor = NULL;
    }
}

void MainWindow::updateListContent()
{
    ST_SMS_LIST_INFO_FRM smsListInfo;
    ST_SMS_LIST_INFOR *pMessage;

    smsListInfo.count = smsListInfo.result = 0;
    if(g_pAppWnd->assistant.assistant_api.fun_iSms_iOrderByTimeMsgRecord)
        g_pAppWnd->assistant.assistant_api.fun_iSms_iOrderByTimeMsgRecord(&smsListInfo);
    DEBUG_PARAM("MsgMinWindow::updateLIstContent: DB",g_pAppWnd->assistant.assistant_api.fun_iSms_iOrderByTimeMsgRecord);
    DEBUG_PARAM("sms list result:", smsListInfo.result);
    DEBUG_PARAM("sms list count:",smsListInfo.count);
    pMessage = smsListInfo.pstSmsListInfor;
    m_messageListModel->clear();

    Msg_ListItem item;
    QStringList sl;
    for(unsigned int i = 0; i < smsListInfo.count; i++) {
        //循环内定义变量，放到循环外
        /*Msg_ListItem*/ item = Msg_ListItem(QString::fromUtf8(pMessage->cMsgListName),
                                         QString::fromUtf8(pMessage->cMsgListNum),
                                         QString::fromUtf8(pMessage->pcMsgInfo),
                                         (bool)!pMessage->iReadStatus,
                                         pMessage->iSendResult);
        //循环内定义变量，放到循环外
        /*QStringList*/ sl = QString::fromUtf8(pMessage->cMsgListDate).split("-");
        if(sl.at(0).toInt() == m_dateTimeInfo.year &&
                sl.at(1).toInt() == m_dateTimeInfo.month &&
                sl.at(2).toInt() == m_dateTimeInfo.day)
        {
            item.setTime(sl.at(1) + "月" + " " + sl.at(2) + "日");    // 5月 12日
        }else{
            item.setTime(sl.at(1) + "月" + " " + sl.at(2) + "日");
        }
        m_messageListModel->addItem(item);
        pMessage++;


        QQuickItem *hintUncontacts = g_pAppWnd->rootObject()->findChild<QQuickItem*>("hintUncontacts");
        if(hintUncontacts)
        {
            hintUncontacts->setProperty("visible", false);
        }
        QQuickItem *hintUnchose = g_pAppWnd->rootObject()->findChild<QQuickItem*>("hintUnchose");
        if(hintUnchose)
        {
            hintUnchose->setProperty("text", "未选择项目");
        }
    }
    if(smsListInfo.count == 0)
    {
        QQuickItem *hintUncontacts = g_pAppWnd->rootObject()->findChild<QQuickItem*>("hintUncontacts");
        if(hintUncontacts)
        {
            hintUncontacts->setProperty("visible", true);
        }
    }

    if(smsListInfo.pstSmsListInfor)
    {
        free(smsListInfo.pstSmsListInfor); //free memory
        smsListInfo.pstSmsListInfor = NULL;
    }
}

void MainWindow::updateReadedStatus(QString number)
{
    if(g_pAppWnd->assistant.assistant_api.fun_iBtSms_iUpdateReadStatusByNumber)
    {
        g_pAppWnd->assistant.assistant_api.fun_iBtSms_iUpdateReadStatusByNumber(number.toUtf8().data());
    }
}

void MainWindow::getLatestMessages(void)
{
    DEBUGLOG;
    updateListContent();
}

void MainWindow::onSendStatus(ST_SMS_STATUS_FRM *pstSmsStatusFrm)
{
    Q_UNUSED(pstSmsStatusFrm);
    DEBUGLOG;
    updateDetailContent(m_detailListModel->get(0, "number").toString());
}
void MainWindow::onReceiveContact(bool ret)
{
    DEBUG_PARAM("ret = ", ret);
    if(ret) {
        updateListContent();
    }
}

void MainWindow::onInitiativeSend(ST_SMS_STATUS_FRM *pstSmsStatusFrm)
{
    Q_UNUSED(pstSmsStatusFrm);
    updateDetailContent(m_detailListModel->get(0, "number").toString());
}

void MainWindow::onReceiveMsg(ST_SMS_INFO *pstSmsInfo)
{
    DEBUGLOG;
    updateListContent();
    if(QString().fromUtf8(pstSmsInfo->number) == m_detailListModel->get(0, "number").toString()) {
        updateDetailContent(pstSmsInfo->number);
    }
}
/******************************* MESSAGE END *******************************/

/******************************* PHONE START *******************************/

void MainWindow::phoneAnswerCall()
{
    DEBUGLOG;
    g_pAppWnd->assistant.assistant_api.SSP_iPhone_Answer_Call();
}

unsigned int MainWindow::getFirstIndex(QString ch)
{
    DEBUG_PARAM("ch:", ch);
    return (m_contactListModel->getSearchResultIndex(ch)-1);

}
void MainWindow::flushDB()
{
    DEBUGLOG;
    if(g_pAppWnd->assistant.assistant_api.fun_iSms_iRequestAddresslist)
    {
        g_pAppWnd->assistant.assistant_api.fun_iSms_iRequestAddresslist();
    }
    if(g_pAppWnd->assistant.assistant_api.fun_iSms_iRequestMsgDB)
    {
        g_pAppWnd->assistant.assistant_api.fun_iSms_iRequestMsgDB();
    }
}

void MainWindow::readContactList()
{
    if(0 == m_isExecute)
    {
        ST_CONTACT_DATA_FRM st_contact_data_frm;
        st_contact_data_frm.count = st_contact_data_frm.result = 0;
        memset(&st_contact_data_frm, 0, sizeof(ST_CONTACT_DATA_FRM));

        //list all contacts
        if(g_pAppWnd->assistant.assistant_api.SSP_iContacts_ReadContactList)
        {
            g_pAppWnd->assistant.assistant_api.SSP_iContacts_ReadContactList(&st_contact_data_frm);
        }

        if(st_contact_data_frm.count == 0)
        {
            m_isExecute = 0;
        }
        else
        {
            if(0 == m_isExecute)
            {
                DEBUG_PARAM("count: ", st_contact_data_frm.count);
                ST_CONTACT_DATA *pst_contact_data = NULL;
                QString lastGroup = "";
                pst_contact_data = st_contact_data_frm.pstContactData;
                m_contactListModel->clear();

                for(unsigned int i = 0; i < st_contact_data_frm.count; i++)
                {
                    //filt the repeated item
                    if(i > 0 && !strcmp(pst_contact_data[i].Name, pst_contact_data[i - 1].Name)
                            && !strcmp(pst_contact_data[i].Number, pst_contact_data[i - 1].Number))
                        continue;

                    if(lastGroup != QString(pst_contact_data[i].GroupName))
                    {
                        lastGroup = QString(pst_contact_data[i].GroupName);
                        m_contactListModel->addContactItem(PhonebookListItem(lastGroup, "", "icon", "", ""));
                    }

                    m_contactListModel->addContactItem(PhonebookListItem(QString::fromUtf8(pst_contact_data[i].Name),
                                                                         pst_contact_data[i].Number,
                                                                         "text",
                                                                         QString::fromUtf8(pst_contact_data[i].NameSZM),
                                                                         pst_contact_data[i].GroupName));
                }

                m_isExecute = 1;
                if(st_contact_data_frm.pstContactData)
                {
                    free(st_contact_data_frm.pstContactData); // free memory
                    st_contact_data_frm.pstContactData = NULL;
                }
            }
        }
    }

    QQuickItem *phoneBookloadingIcon = g_pAppWnd->rootObject()->findChild<QQuickItem*>("phoneBookloadingIcon");
    if(phoneBookloadingIcon)
    {
        phoneBookloadingIcon->setProperty("visible", false);
    }
}

void MainWindow::dialNumber(QString number)
{
    DEBUG_PARAM("dialing number: ", number);
    if(number == "")
    {
        //号码为空，拨打最近一个电话 contectName
//        if(g_pAppWnd-> m_pstCallListInfo->number)
//        {
//            number = g_pAppWnd-> m_pstCallListInfo->number;
//            QQuickItem *dialName = g_pAppWnd->rootObject()->findChild<QQuickItem*>("contectName");
//            if(dialName)
//            {
//                dialName->setProperty("text", g_pAppWnd-> m_pstCallListInfo->name);
//            }
//        }

    }
    else
    {
        m_isGetrecordList = 0;
        if (g_pAppWnd->assistant.assistant_api.SSP_iPhone_Call_Phone)
            g_pAppWnd->assistant.assistant_api.SSP_iPhone_Call_Phone(number.toLatin1().data());
    }

}

void MainWindow::hangOffPhone()
{
    if(g_pAppWnd->assistant.assistant_api.SSP_iPhone_Hang_Off)
        g_pAppWnd->assistant.assistant_api.SSP_iPhone_Hang_Off();
}

void MainWindow::fillContactList(int searchMethod, QString text)
{

    ST_CONTACT_DATA_FRM st_contact_data_frm;
    ST_CONTACT_DATA *pst_contact_data = NULL;
    st_contact_data_frm.count = st_contact_data_frm.result = 0;
    DEBUG_PARAM("text: ", text);

    memset(&st_contact_data_frm, 0, sizeof(ST_CONTACT_DATA_FRM));

    if(searchMethod == 0)
    {   //list all contacts
        if(g_pAppWnd->assistant.assistant_api.SSP_iContacts_ReadContactList)
        {
            g_pAppWnd->assistant.assistant_api.SSP_iContacts_ReadContactList(&st_contact_data_frm);
        }
    }else if (searchMethod == 1)
    {
        if(g_pAppWnd->assistant.assistant_api.SSP_iContacts_SearchByNumber)
        {
            g_pAppWnd->assistant.assistant_api.SSP_iContacts_SearchByNumber(text.toLatin1().data(), &st_contact_data_frm);
            DEBUG_PARAM("search contact: ", text);
        }
    }

    pst_contact_data = st_contact_data_frm.pstContactData;
    m_thinkResultListModel->clear();

    if (pst_contact_data)
    {
        qDebug() << "count ============== " << st_contact_data_frm.count;
        qDebug() << "ID    ============== " << pst_contact_data->ID;
        qDebug() << "Number ============= " << QString::fromUtf8(pst_contact_data->Number);
        qDebug() << "Name  ============== " << QString::fromUtf8(pst_contact_data->Name);
    }

    phoneThinkResultListItem item;
    for(unsigned int i = 0; i < st_contact_data_frm.count && i < 3; i++)
    {
        //循环内定义变量，放到循环外
        /*phoneThinkResultListItem*/ item = phoneThinkResultListItem(
                    QString::fromUtf8(pst_contact_data->Name),
                    QString::fromUtf8(pst_contact_data->Number));

        m_thinkResultListModel->addItem(item);
        pst_contact_data++;
    }

    DEBUG_PARAM("fillContactList",st_contact_data_frm.pstContactData);
    if(st_contact_data_frm.pstContactData)
    {
        free(st_contact_data_frm.pstContactData); //free memory
        st_contact_data_frm.pstContactData = NULL;
    }
}

void MainWindow::getCallLogs()
{
    DEBUGLOG;
    if(0 == m_isGetrecordList)
    {
        if(g_pAppWnd->assistant.assistant_api.SSP_iPhone_Call_Logs)
        {
            g_pAppWnd->assistant.assistant_api.SSP_iPhone_Call_Logs();
        }
    }
    else
    {
        QQuickItem *phoneBookloadingIcon = g_pAppWnd->rootObject()->findChild<QQuickItem*>("phoneBookloadingIcon");
        if(phoneBookloadingIcon)
        {
            phoneBookloadingIcon->setProperty("visible", false);
        }
    }

    m_isGetrecordList = 1;
}

void MainWindow::onCallLogs(int count)
{
    DEBUGLOG;
    m_recordListModel->clear();
    PhoneRecordListItem item;
    for(int i = 0; i < count; i++)
    {
        //循环内定义变量，放到循环外
        /*PhoneRecordListItem*/ item = PhoneRecordListItem(
                    QString::fromUtf8(g_pAppWnd-> m_pstCallListInfo[i].date),
                    g_pAppWnd-> m_pstCallListInfo[i].type,
                    QString::fromUtf8(g_pAppWnd-> m_pstCallListInfo[i].name),
                    QString::fromUtf8(g_pAppWnd-> m_pstCallListInfo[i].number));
        DEBUG_PARAM("name:   ", QString::fromUtf8(g_pAppWnd-> m_pstCallListInfo[i].name));
        DEBUG_PARAM("number: ", QString::fromUtf8(g_pAppWnd-> m_pstCallListInfo[i].number));
        DEBUG_PARAM("date:   ", QString::fromUtf8(g_pAppWnd-> m_pstCallListInfo[i].date));
        g_pAppWnd->m_recordListModel->addItem(item);
    }

    QQuickItem *phoneBookloadingIcon = g_pAppWnd->rootObject()->findChild<QQuickItem*>("phoneBookloadingIcon");
    if(phoneBookloadingIcon)
    {
        phoneBookloadingIcon->setProperty("visible", false);
    }

}

/****************************** SLOT *******************************/

void MainWindow::onGetLocalSongList(int count, int pageNumber, int allPageNumber)
{

    int musicPageNumber = pageNumber;
    if(musicPageNumber == 1)
    {
        g_pAppWnd-> m_localMusicList->clear();
    }

    LocalMusicListItem item;
    for(int i = 0; i < count; i++)
    {
        DEBUG_PARAM("LocalSongList songName:", g_pAppWnd->st_LocalSong_Info[i].songName);
        DEBUG_PARAM("singer:", g_pAppWnd->st_LocalSong_Info[i].singer);
        DEBUG_PARAM("songId:", g_pAppWnd->st_LocalSong_Info[i].songID);

        QString temp = g_pAppWnd->st_LocalSong_Info[i].singer;
        QString singer;
        if(temp.length() > 29)
        {
            singer = temp.left(29);
            singer.append("···");
        }else
            singer = temp;

        item = LocalMusicListItem(g_pAppWnd-> st_LocalSong_Info[i].songName,
                                  singer,
                                  g_pAppWnd-> st_LocalSong_Info[i].songID);
        if(count < 3)
            emit g_pAppWnd-> m_localMusicList->dataChanged(m_localMusicList->index(i), m_localMusicList->index(i));
        else{
            if(i/3 == 0)
                emit g_pAppWnd-> m_localMusicList->dataChanged(m_localMusicList->index(i), m_localMusicList->index(i));
        }

        g_pAppWnd-> m_localMusicList->addLocalMusicListItem(item);
    }

    if (musicPageNumber < allPageNumber)
    {
        musicPageNumber++;
        g_pAppWnd->assistant.assistant_api.SSP_iMusic_LocalSongList(musicPageNumber);
    }else{
        g_pAppWnd->m_isLoaderLocalMusic = 1;
    }
}

void MainWindow::onGetSongInfo(ST_SONG_INFO *stSongInfo)
{
    DEBUG_PARAM("stSongInfo.songName = ",stSongInfo->songName);
    DEBUG_PARAM("stSongInfo.singer = ",stSongInfo->singer);
    DEBUG_PARAM("stSongInfo.picUrl = ",stSongInfo->picUrl);
    DEBUG_PARAM("stSongInfo.playStatus = ",stSongInfo->playStatus);
    DEBUG_PARAM("stSongInfo.songID = ",stSongInfo->songID);

    //call interface to get singer picture
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_LocalPic(stSongInfo->picUrl);
    //call interface to get music play mode.
    g_pAppWnd->assistant.assistant_api.SSP_iMusic_PlayMode();

    emit g_pAppWnd->sigGetMusicInfo(stSongInfo->songName,stSongInfo->singer,
                                    stSongInfo->songID,stSongInfo->playStatus);
}


//CanlendarReciveEvent
void MainWindow::onCanlendarReciveEvent()
{
    onCalendarInit();
    int iEventCount[31] = {0};
    DEBUG_PARAM("g_pAppWnd->tMonthDateInfo.nCurrYear", g_pAppWnd->tMonthDateInfo.nCurrYear);
    DEBUG_PARAM("g_pAppWnd->tMonthDateInfo.nCurrMonth", g_pAppWnd->tMonthDateInfo.nCurrMonth);
    g_pAppWnd->assistant.assistant_api.fun_iGetAllEventInfoOfMonth(g_pAppWnd->tMonthDateInfo.nCurrYear, g_pAppWnd->tMonthDateInfo.nCurrMonth, iEventCount);
    g_pAppWnd->UpdateDateEventCount(iEventCount);

    DateInfo_t stDate;
    Message_t *sMessage;
    for(int i=0; i<31; ++i){
        if(iEventCount[i] > 0){
            sMessage = new Message_t[iEventCount[i]];
            //底层已做初始化,若天宝底层无初始化，请打开一下注释，并确认程序OK
            //memset(sMessage[i].cTitle, 0, DEFAULT_TITLE_SIZE);
            //memset(sMessage[i].cDetail, 0, DEFAULT_REMARKS_SIZE);
            //memset(sMessage[i].cLocation, 0, DEFAULT_LOCATION_SIZE);

            uint nReviceCount = 0;
            stDate.year = g_pAppWnd->tMonthDateInfo.nCurrYear;
            stDate.month = g_pAppWnd->tMonthDateInfo.nCurrMonth;
            stDate.day = i+1;

            QDate tempDate;
            tempDate.setDate(stDate.year, stDate.month, stDate.day);
            if(!tempDate.isValid()){
                break;
            }
            g_pAppWnd->assistant.assistant_api.fun_iGetEventInfo(stDate, sMessage, &nReviceCount);

            for(uint i=0; i<nReviceCount; ++i){
                g_pAppWnd->AddEventMsgByDate(stDate.year, stDate.month, stDate.day,  &sMessage[i]);
            }
        }
    }
    printf("\n");

    emit g_pAppWnd->assistant.signal_updateEvent();
}



