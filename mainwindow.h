#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDate>
#include <QKeyEvent>
#include <QPainter>
#include <QDateTime>
#include <QTimer>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "./SSPLInk/ssp_assisant_fun.h"
#include "./SSPLInk/common.h"
//message
#include "./msgHeaders/msg_detaillistitem.h"
#include "./msgHeaders/msg_listitem.h"
#include "./msgHeaders/msg_phaseitem.h"
//phone
#include "./phoneHeaders/phonebooklistitem.h"
#include "./phoneHeaders/phonerecordlistitem.h"
#include "./phoneHeaders/phonethinkresultlistitem.h"
#include "./phoneHeaders/phone_quicksearch.h"
#include "LocalMusicListItem.h"
#include "AppListItem.h"
#include "i108n.h"



class MainWindow : public QQuickView
{
    Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();
    void init();                                                    //assistant
    Q_INVOKABLE void exitLink();                                    //assistant
    QObject* getMainWindow(){return  this;}                         //assistant
    Q_INVOKABLE void assistantDeviceStateReport(int state);         //send phone connect state to drive
    Q_INVOKABLE void getLocalAppList();
    void setAssistantLanguage(int languageFlag);                    //assistant language
    Q_INVOKABLE void assistant_do_runMirror();                      //mirror run
    Q_INVOKABLE void assistant_do_stopMirrorMode();                 //mirror stop
    Q_INVOKABLE void hideAssistantWindow();                         //assistant hide
    Q_INVOKABLE void showAssistantWindow();                         //assistant show
    Q_INVOKABLE void specialShow();                                 //用于特殊处理，不改变m_showFlag标志位
    Q_INVOKABLE int getShowFlag() const;
    Q_INVOKABLE void mySleep(unsigned long um);                     //assistant
    Q_INVOKABLE void assistantStateReport(int state);               //send assistant state to drive
    Q_INVOKABLE void assistantDisplayStateReport(int state);        //send display state to drive state 0: hide, 1: show, 2: exit 车机助手给主机返回显隐消息接口
    Q_INVOKABLE void activate_start();                              //激活
    Q_INVOKABLE void activate_return();                             //激活
    Q_INVOKABLE void doLaunchApp(int index);
    Q_INVOKABLE void requestVRStatus(QString status);
    Q_INVOKABLE void runMusicAppProcess(QString appID);
    Q_INVOKABLE void localMusicRun();

    //message
    void updateDetailContent(QString number);                        //message update content
    void updateListContent();                                        //message update list
    Q_INVOKABLE void getOnePersonMessages(QString number);           //message get msg content when click contact
    Q_INVOKABLE void sendMessage(QString number, QString message);   //message send message
    Q_INVOKABLE void reSendMessage(QString number, QString message, QString rank); //message
    Q_INVOKABLE void updateReadedStatus(QString number);             //message
    Q_INVOKABLE void getLatestMessages(void);                        //message
    Q_INVOKABLE void deleteOnePersonMessage(int index);              //message
    Q_INVOKABLE void flushMsgDB();                                   //message flush DB
    //phone
    Q_INVOKABLE void readContactList();                              //phone read telephone book
    Q_INVOKABLE void dialNumber(QString number);                     //phone give sb a call 
    Q_INVOKABLE void hangOffPhone();                                 //phone
    Q_INVOKABLE void fillContactList(int searchMethod, QString text);//phone dial
    Q_INVOKABLE void getCallLogs();                                  //phone recent dial number
    Q_INVOKABLE unsigned int  getFirstIndex(QString ch);             //phone
    Q_INVOKABLE void flushDB();                                      //phone and message DB
    Q_INVOKABLE void freePhoneContactsMem();                         //phone and localMusic
    Q_INVOKABLE void phoneAnswerCall();                              //phone

    //calendar
    Q_INVOKABLE void onCalendarInit();                              //calendar
    Q_INVOKABLE void setCalendarToToday();                          //calendar show today's calendar information
    Q_INVOKABLE int getCalendarDay(int nIndex);                     //calendar
    Q_INVOKABLE int getCalendarDayMonth(int nIndex);                //calendar
    Q_INVOKABLE int getCalendarCheckMonth();                        //calendar
    Q_INVOKABLE int getCalendarYear();                              //calendar
    Q_INVOKABLE int getCalendarMonth();                             //calendar
    Q_INVOKABLE int getCalendarCurrDay();                           //calendar
    Q_INVOKABLE int getCalendarCheckDay();                          //calendar
    Q_INVOKABLE bool haveAffairsCalendarDay(int nIndex);            //calendar
    Q_INVOKABLE void onCalendarDayClicked(int nIndex);              //calendar
    Q_INVOKABLE QVariantList getMessageByCheckDay();                //calendar
    Q_INVOKABLE void onCalendarListClicked(int nIndex);             //calendar
    Q_INVOKABLE QVariantList getMessageByListClickedItem();         //calendar
    void UpdateDateInfo(QDate dCurrDate);                           //calendar
    void UpdateDateInfo(DateTimeInfo_t dCurrDate);                  //calendar
    void UpdateDateEventCount(int nCount[31]);                      //calendar
    //void setMonthDateInfo(MonthDateInfo);                           //calendar
    void AddEventMsgByDate(int nYear, int nMonth, int nDay, Message_t *pMsg);//calendar
    //weather
    Q_INVOKABLE void onWeatherInit();                               //weather
    Q_INVOKABLE bool isWeatherLoadedOK();                           //weather
    Q_INVOKABLE bool isWeatherLoadedFail();                         //weather
    Q_INVOKABLE bool isWeatherLoading();                            //weather
    Q_INVOKABLE QString getCurrentWeekWeaeher();                    //weather
    Q_INVOKABLE QVariantList getCurrentDayWeatherInfo();            //weather
    Q_INVOKABLE QVariantList getFirstDayWeatherInfo();              //weather
    Q_INVOKABLE QVariantList getSecondDayWeatherInfo();             //weather
    Q_INVOKABLE QVariantList getThirdDayWeatherInfo();              //weather

    //local music
    Q_INVOKABLE void localMusic_do_Wakeup();                        //local music
    Q_INVOKABLE void localMusic_do_ExitPhoneAPP();                  //local music
    Q_INVOKABLE void localMusic_do_LoadList(int musicPageNumber);   //local music
    Q_INVOKABLE void localMusic_do_PlayPrevMusic();                 //local music
    Q_INVOKABLE void localMusic_do_PlayNextMusic();                 //local music
    Q_INVOKABLE void localMusic_do_PlayOrPause(unsigned char playOrPause);
    Q_INVOKABLE void localMusic_do_SetPlayMode(int playMode);       //local music
    Q_INVOKABLE void localMusic_do_PlayLocalSong(QString index);    //local music
    Q_INVOKABLE void localMusic_do_GetSongInfo();                   //local music
    Q_INVOKABLE void localMusic_do_GetLocalPic(QString str);        //local music

signals:
    //assistant
    Q_INVOKABLE void sigSetAssistantProgressBarAndPhrase(int value);
    Q_INVOKABLE void sigAssistantActivationReminder(int status);
    Q_INVOKABLE void sigSetAssistantAOAOrADB(int flags);
    Q_INVOKABLE void sigAppListCount(int value);
    Q_INVOKABLE void sigAudioStatus(int status);
	Q_INVOKABLE void sigSubAppStatus(int status);
    Q_INVOKABLE void sigVRStatus(int status, int failStatus);
    Q_INVOKABLE void sigrunSubAppFromVR(QString appName);
	//local music
    Q_INVOKABLE void sigGetMusicInfo(QString songName,QString singer,QString songID,int playStatus);
    Q_INVOKABLE void sigNoMusic();
    Q_INVOKABLE void sigGetPlayModeFromPhone(int playmode);         //localMusic signal
    Q_INVOKABLE void sigGetPhonePlayOrPause(int playStatus);        //localMusic signal
    Q_INVOKABLE void sigGetPlayorPause(int playStatus);             //localMusic signal
    Q_INVOKABLE void sigGetLocalPicture(QString picPath);           //localMusic signal
    Q_INVOKABLE void sigMusicRunAppInfo(QString appID, QString appName, QString iconPath);
    void getLocalSongList(int count, int pageNumber, int allPage);  //localMusic signal
    void getSongInfo(ST_SONG_INFO *stSongInfo);                     //localMusic signal
    void receiveMsg(ST_SMS_INFO *pstSmsInfo);                       //message signal
    void sendStatus(ST_SMS_STATUS_FRM *pstSmsStatusFrm);            //message signal
    void sendMessageCallback(void);                                 //message signal
    void sendMessageBtnUnused(void);                                //message signal
    void initiativeSend(ST_SMS_STATUS_FRM *pstSmsStatusFrm);        //message signal
    void receiveContact(bool ret);                                  //message signal
    Q_INVOKABLE void detailContentUpdated();                        //message signal
    Q_INVOKABLE void phoneCall(QString name, int flag);             //phone signal
    Q_INVOKABLE void phoneNoAnwer();                                //phone signal
    Q_INVOKABLE void phoneCalling();                                //phone signal
    void missedCall (void);                                         //phone signal
    void startRecognize();                                          //phone signal
    void callLogs(int);                                             //phone signal
    void setTextNull();                                             //phone signal
    void signalDataUpdate();                                        //canlendar signal
    void canlendarReciveEvent();                                    //canlendar
    void getSSPmainWeatherIconPath(QString path);                   //weather
    void setLoadingWeatherStop();                                   //weather
    Q_INVOKABLE void getVolumeValue(int volumeValue, int type);     //volume value for volumeProgressBar
    Q_INVOKABLE void setMute(int flag);                             //assistant mute Icon
    Q_INVOKABLE void setBluetooth(int flag);                        //assistant bluetooth Icon
    Q_INVOKABLE void sdIconDisplayFlag(int flag);                   //assistant SDIcon
    Q_INVOKABLE void auxIconDisplayFlag(int flag);                  //assistant AUXIcon
    Q_INVOKABLE void sigSetDisplayStatus(int value);

public slots:
    void onReceiveMsg(ST_SMS_INFO *pstSmsInfo);                     //message slot
    void onSendStatus(ST_SMS_STATUS_FRM *pstSmsStatusFrm);          //message slot
    void onInitiativeSend(ST_SMS_STATUS_FRM *pstSmsStatusFrm);      //message slot
    void onReceiveContact(bool ret);                                //message slot
    void onCallLogs(int);                                           //phone slot
    void onCanlendarReciveEvent();                                  //canlendar
	//localMusic
    void onGetLocalSongList(int count, int pageNumber, int allPageNumber);//localMusic slot
    void onGetSongInfo(ST_SONG_INFO *stSongInfo);                   //localMusic slot


public:
    assistant_control assistant;                                    //assistant data
    AppListItemModel *m_appList;
    AppListItemModel *m_appListPage;
    LocalMusicListModel* m_localMusicList;                          //localMusic data
    MonthDateInfo tMonthDateInfo;                                   //calendar data
    QVariantMap mapMessage;                                         //calendar data
    MonthDateInfo getMonthDateInfo();                               //calendar data
    DateTimeInfo_t m_title_dateTime;
    ST_WEATHER_24H_FRM  m_stWeather24Hour;                          //weather data only use sunriseTime and sunsetTime
    ST_WEATHER_DATA m_stWeatherData;                                //weather data
    ST_WEATHER_EVERYDAY m_stWeatherEveryDay[5];                     //weather data
    ST_AIR_QUALITY  m_stAirQuality;                                 //weather data
    ST_INDEX_DATA m_stIndexData;                                    //weather data
    ST_WARNING_DATA m_stWaringData;                                 //weather data
    PhoneRecordListModel *m_recordListModel;                        //phone data

    bool m_bLoadedOK;                                               //weather status
    bool m_bLoadedFail;                                             //weather status
    bool m_bLoading;                                                //weather status
    int m_nListClickItem;                                           //weather status

    ST_CALL_LIST_INFO *m_pstCallListInfo;                           //phone call logs
    ST_LOCALSONG_INFO *st_LocalSong_Info = NULL;                    //local music list
    int m_isExecute;                                                //phone contact list flag
    int m_isGetrecordList;                                          //phone record  list flag
    int m_isLoaderLocalMusic;                                       //localMusic flag
    ST_LOCALAPP_LIST *pst_LocalAppList = NULL;

private:
    PhonebookListModel *m_contactListModel;                         //phone data
    phoneThinkResultListModel *m_thinkResultListModel;              //phone data
    Msg_ListModel * m_messageListModel;                             //message data message list
    Msg_DetailListModel * m_detailListModel;                        //message data details of message list
    Msg_PhaseModel * m_phraseListModel;                             //message data shortcut phrase list
    DateTimeInfo_t m_dateTimeInfo;                                  //message time
    int m_currCategory;
    int m_preInstallAppCount;
    int m_isInSubApp;
    int m_showFlag;

    QTimer m_trLoadingTimeout;
};

extern MainWindow* g_pAppWnd;
extern ST_SONG_INFO *stSongInfo;
extern QString sWeatherTypeIconName[33];
extern QString sWeatherType[34];

#endif
