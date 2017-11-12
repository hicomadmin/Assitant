#include "./SSPLInk/ssp_assisant_fun.h"
#include "mainwindow.h"
#include <QThread>
#include <QtQuick>


void on_lpAssistant_Activate_Status(int status, void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("888888 status:", status);

    switch (status) {
    case ACTIVATE_STATUS_DISABLE:
        emit g_pAppWnd->sigAssistantActivationReminder(1);
        break;
    case ACTIVATE_STATUS_READY:
        emit g_pAppWnd->sigAssistantActivationReminder(2);
        break;
    case ACTIVATE_STATUS_DOING:
        emit g_pAppWnd->sigAssistantActivationReminder(3);
        break;
    case ACTIVATE_STATUS_STEP_1:
        emit g_pAppWnd->sigAssistantActivationReminder(4);
        break;
    case ACTIVATE_STATUS_STEP_2:
        emit g_pAppWnd->sigAssistantActivationReminder(5);
        break;
    case ACTIVATE_STATUS_STEP_3:
        emit g_pAppWnd->sigAssistantActivationReminder(6);
        break;
    case ACTIVATE_STATUS_SUCCESSFUL:
        emit g_pAppWnd->sigAssistantActivationReminder(7);
        break;
    case ACTIVATE_STATUS_FAILED:
        emit g_pAppWnd->sigAssistantActivationReminder(8);
        break;
    default:
        break;
    }
}

void on_lpAssistant_Subappprocessexit(char *process,void* pUserData)
{
    DEBUGLOG;
    Q_UNUSED(process);
    Q_UNUSED(pUserData);
    g_pAppWnd->exitLink();
}
void on_lpAssistant_Upgrade_Status(int status, void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("status:", status);
    switch (status) {
    case UPGRADE_STATUS_DISABLE:  //不升级
        emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(100);
        break;
    case UPGRADE_STATUS_DOING:  //升级中
        g_pAppWnd-> mySleep(500);
        emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(101);
        break;
    case UPGRADE_STATUS_FAILED://升级失败
        emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(102);
        break;
    default:
        break;
    }
}

void on_lpAssistant_PhoneAppIconPath(char* iconId,const char* iconPath,void* pUserData)
{
    Q_UNUSED(iconId);
    Q_UNUSED(iconPath);
    Q_UNUSED(pUserData);
}

void on_lpMirror_SetBtLinkState(int flag,char* addr)
{
    //flag instruction   0 disconnect  1:connect
    Q_UNUSED(addr);
    DEBUG_PARAM("BT-FLAG    FLAG = ",flag);
    emit g_pAppWnd->setBluetooth(flag);
}

void on_lpAssistant_SetMuteState(int flag)
{
    //flag instruction   0 unmute     1 mute
    DEBUG_PARAM("flag = ",flag);
    emit g_pAppWnd->setMute(flag);
}
void on_lpAssistant_SetSDState(int iFlag,void* pUserData)
{
    //iFlag 0:hide 1:show
    Q_UNUSED(pUserData);
    DEBUG_PARAM("sdIcon display iFlag: ", iFlag);
    if(0 == iFlag)
    {
        emit g_pAppWnd->sdIconDisplayFlag(iFlag);
    }
    else
    {
        emit g_pAppWnd->sdIconDisplayFlag(iFlag);
    }
}

void on_lpAssistant_SetAUXState(int iFlag,void* pUserData)
{
    //iFlag 0:hide 1:show
    Q_UNUSED(pUserData);
    DEBUG_PARAM("auxIcon display iFlag: ", iFlag);
    if(0 == iFlag)
    {
         emit g_pAppWnd->auxIconDisplayFlag(iFlag);
    }
    else
    {
        emit g_pAppWnd->auxIconDisplayFlag(iFlag);
    }
}

void on_lpAssistant_VolChange(int type, int volue)
{
    DEBUG_PARAM("volue = ",volue);
    DEBUG_PARAM("type = ",type);

	unsigned int systemVolumeValue = 15;
	unsigned int naviVolumeValue = 15;

	if(type == 0)
	{
		systemVolumeValue = volue;
        emit g_pAppWnd->getVolumeValue(systemVolumeValue, type);
	}
	else
	{
		naviVolumeValue = volue;
        emit g_pAppWnd->getVolumeValue(naviVolumeValue, type);
	}
}

void on_lpAssistant_InitListProcess(enum INIT_ASSIST_STATUS ret, enum INIT_ASSIST_PROCESS iProc, enum INIT_ASSIST_STRING iString, void* pUserData)
{
    Q_UNUSED(pUserData);
    qDebug("%s ret:%d, iProc:%d\n", __FUNCTION__, ret, iProc);

    switch (iProc) {
    case INIT_ASS_PROCESS_DISCONNECT:
        DEBUGLOG;
        emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(0);
        break;
    case INIT_ASS_PROCESS_CONNECT:
        DEBUGLOG;
        emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(1);
        break;
    default:
        break;
    }

    if(ret == INIT_ASSIST_STATUS_FAILTH)
    {
        switch(iProc) {
        case INIT_ASS_PROCESS_LIST:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(12);
            break;
        case INIT_ASS_PROCESS_APP_ICON:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(13);
            break;
        case INIT_ASS_PROCESS_APP:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(14);
            break;
        case INIT_ASS_PROCESS_TIME:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(15);
            break;
        case INIT_ASS_PROCESS_SMS_DB:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(16);
            break;
        case INIT_ASS_PROCESS_CALENDAR_DB:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(17);
            break;
        case INIT_ASS_PROCESS_MUSIC_INFO:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(18);
            break;
        case INIT_ASS_PROCESS_WEATHER_INFO:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(19);
            break;
        case INIT_ASS_PROCESS_TOTAL:
            DEBUGLOG;
            if(iString == INIT_ASSIST_STRING_ERROR_PHONE_APP_FAILED)
                emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(20);
            else if(iString == INIT_ASSIST_STRING_ERROR_NONE_SUPPORT)
                emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(21);
            else if(iString == INIT_ASSIST_STRING_ERROR_CONNECT_FAILED)
                emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(22);
            else
                emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(23);
            break;
        default:
            break;
        }
    }else{
        switch(iProc) {
        case INIT_ASS_PROCESS_LIST:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(2);
            break;
        case INIT_ASS_PROCESS_APP_ICON:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(3);
            break;
        case INIT_ASS_PROCESS_APP:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(4);
            break;
        case INIT_ASS_PROCESS_TIME:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(5);
            break;
        case INIT_ASS_PROCESS_SMS_DB:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(6);
            break;
        case INIT_ASS_PROCESS_CALENDAR_DB:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(7);
            break;
        case INIT_ASS_PROCESS_MUSIC_INFO:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(8);
            break;
        case INIT_ASS_PROCESS_WEATHER_INFO:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(9);
            break;
        case INIT_ASS_PROCESS_TOTAL:
            DEBUGLOG;
            emit g_pAppWnd->sigSetAssistantProgressBarAndPhrase(10);
            break;
        default:
            break;
        }
    }
}

void on_lpAssistant_RunProcess(ssp_uint8 ret,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM(" mirror runing callback  ret = ", ret);
    if(_SSP_OK == ret)
    {
        g_pAppWnd->assistant.assistant_api.SSP_iAssistant_MirrorStateReport(2);
        emit g_pAppWnd->sigSubAppStatus(1);
    }

}

void on_lpAssistant_PhoneAppChanged(void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUGLOG;
}

void on_lpAssistant_VR_Status(VR_STATUS status, int errorCode, void* pUserData)
{
    switch (status) {
    case VR_STATUS_NO_NET:
        emit g_pAppWnd->sigVRStatus(0, -1);
        break;
    case VR_STATUS_STARTING:
        emit g_pAppWnd->sigVRStatus(1, -1);
        break;
    case VR_STATUS_START_ERROR:
        emit g_pAppWnd->sigVRStatus(2, -1);
        break;
    case VR_STATUS_LISTENING:
        emit g_pAppWnd->sigVRStatus(3, -1);
        break;
    case VR_STATUS_UPLOADING:
        emit g_pAppWnd->sigVRStatus(4, -1);
        break;
    case VR_STATUS_RECOGNIZING:
        emit g_pAppWnd->sigVRStatus(5, -1);
        break;
    case VR_STATUS_FAILED:
        emit g_pAppWnd->sigVRStatus(6, errorCode);
        break;
    case VR_STATUS_OVER:
        emit g_pAppWnd->sigVRStatus(7, -1);
        break;
    default:
        break;
    }
}
void on_lpAssistant_VR_StartAPP(int type, char * appid, void* pUserData)
{
    QString appID = appid;
    if(type == -1)
    {
        if(appID == "ssp_phone")
            emit g_pAppWnd->sigrunSubAppFromVR("phone");
        else if(appID == "ssp_sms")
            emit g_pAppWnd->sigrunSubAppFromVR("message");
        else if(appID == "ssp_calendar")
            emit g_pAppWnd->sigrunSubAppFromVR("calendar");
        else if(appID == "ssp_music")
            emit g_pAppWnd->sigrunSubAppFromVR("music");
        else if(appID == "ssp_weather")
            emit g_pAppWnd->sigrunSubAppFromVR("weather");
    }
    else
    {
        emit g_pAppWnd->sigrunSubAppFromVR("otherApp");
        g_pAppWnd->assistant.assistant_api.SSP_iAssistant_RunProcess(appid, type);
    }
}
void on_lpAssistant_Music_App_Run(char * appId, char * appName, char * iconPath, void * pUserData)
{
    DEBUGLOG;
    Q_UNUSED(pUserData);
    if(appId != NULL)
    {
        DEBUG_PARAM("appId:", *appId);
        if(strcmp(appId, "ssp_music"))
        {
            if(appName != NULL)
            {
                DEBUG_PARAM("appName:", *appName);
                if(iconPath != NULL)
                {
                    DEBUG_PARAM("iconPath:", *iconPath);
                    emit g_pAppWnd->sigMusicRunAppInfo(appId, appName, iconPath);
                }
                else
                {
                    emit g_pAppWnd->sigMusicRunAppInfo(appId, appName, "");
                }
            }
        }
        else
        {
            emit g_pAppWnd->sigMusicRunAppInfo(appId, "", "");
        }
    }

}
void on_lpAssistant_MirrorState(enum MIRROR_STATUS ret,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("ret =",ret);
    if(ret == MIRROR_OFF_OK)
    {
        g_pAppWnd->assistant.assistant_api.SSP_iAssistant_MirrorStateReport(0);
        g_pAppWnd->assistant_do_stopMirrorMode();
    }
    else if(ret == MIRROR_ON_OK)
    {

    }
}

void on_lpAssistant_MirrorEnableStatus(ssp_uint8 ret,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("ret:", ret);
    if(ret == MIRROR_STATUS_ENABLE)
    {
        emit g_pAppWnd->sigSetAssistantAOAOrADB(0);
    }
    else if(ret == MIRROR_STATUS_DISABLE)
    {
        emit g_pAppWnd->sigSetAssistantAOAOrADB(1);
    }
}

void on_lpAssistant_SetDisplayState(int state,void* pUserData)  //state 1:show/0:hide 2:hide asisstant and show mirror
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("\n========== SetDisplayState ========== : state = ",state);
    if(state == 0)
    {
        DEBUGLOG;
        emit g_pAppWnd->sigSetDisplayStatus(1);
    }
    else if(state == 1)
    {
        DEBUGLOG;
        emit g_pAppWnd->sigSetDisplayStatus(2);
    }
    else
    {
        DEBUGLOG;
        emit g_pAppWnd->sigSetDisplayStatus(3);
    }
}

//获取语言回调
void on_lpAssistant_SetLanguage(int iLang,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("on_lpAssistant_SetLanguage iLang =", iLang);
    //ilang = 0 中文;  ilang = 1 英语
    g_pAppWnd->setAssistantLanguage(iLang);
}

void on_lpAssistant_Audio_Status(enum AUDIO_STATUS audioState, void * pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("AUDIO_STATUS audioState", audioState);
    if(audioState == AUDIO_NOT_WORK) //跳车机助手接听界面
    {
            emit g_pAppWnd->sigAudioStatus(0);
    }
    else if(audioState == AUDIO_BT_OK) //不跳车机助手接听界面
    {
            emit g_pAppWnd->sigAudioStatus(1);
    }
    else if(audioState == AUDIO_BT_NOT_SAME) //跳车机助手接听界面但是挂断按钮做100毫秒延迟操作
    {
            emit g_pAppWnd->sigAudioStatus(2);
    }
    else // AUDIO_BT_NOT_SAME 跳车机助手接听界面但是挂断按钮做100毫秒延迟操作
    {
            emit g_pAppWnd->sigAudioStatus(2);
    }
}
void on_lpAssistant_SetAudioState(int state,void* pUserData)  //state 1:ssplink source/0:other source
{
    Q_UNUSED(state);
    Q_UNUSED(pUserData);
}
//汽车方向盘上的按键，上一曲下一曲歌
void on_lpAssistant_SetHardKeyType(int keyType, int flag,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("keyType = ", keyType);
    DEBUG_PARAM("flag = ", flag);
    // keyType==1 && flag==1:nex song; keyType==0 && flag==1:prev song
    if(keyType==1 && flag==1)
    {
        g_pAppWnd->localMusic_do_PlayNextMusic();
    }
    if(keyType==0 && flag==1)
    {
        g_pAppWnd->localMusic_do_PlayPrevMusic();
    }
}

/******************************* LocalMusic start *******************************/
void on_lpMusic_Get_Wakeup_PhoneApp(void* pUserData)
{
    Q_UNUSED(pUserData);
}

void on_lpMusic_Get_Song_Info(PST_SONG_INFO pstSongInfo,void* pUserData)
{
    Q_UNUSED(pUserData);

    if(strlen(pstSongInfo->songName) != 0)
    {
        DEBUG_PARAM("pstSongInfo->songName = ",pstSongInfo->songName);
        DEBUG_PARAM("pstSongInfo->singer = ",pstSongInfo->singer);
        DEBUG_PARAM("pstSongInfo->picUrl = ",pstSongInfo->picUrl);
        DEBUG_PARAM("pstSongInfo->playStatus = ",pstSongInfo->playStatus);
        DEBUG_PARAM("pstSongInfo->songID = ",pstSongInfo->songID);

        if(stSongInfo != NULL)
            stSongInfo = NULL;
        stSongInfo = new ST_SONG_INFO;
        memset(stSongInfo,0,sizeof(ST_SONG_INFO));
        memcpy(stSongInfo,pstSongInfo,sizeof(ST_SONG_INFO));
        emit g_pAppWnd->getSongInfo(stSongInfo);
    }
    else
    {
        emit g_pAppWnd->sigNoMusic();
    }

}

void on_lpMusic_Get_LocalSongList(PST_LOCALSONG_LIST pstLocalSongList,void* pUserData)
{
    Q_UNUSED(pUserData);	
    DEBUG_PARAM("pstLocalSongList->ret=",pstLocalSongList->ret);
    //No music
    if(pstLocalSongList->count == 0)
        emit g_pAppWnd->sigNoMusic();

    if(_SSP_OK == pstLocalSongList->ret)
    {
        if(0 == g_pAppWnd->m_isLoaderLocalMusic)
        {
            if(g_pAppWnd->st_LocalSong_Info != NULL)
            {
                delete[] g_pAppWnd->st_LocalSong_Info;
                g_pAppWnd-> st_LocalSong_Info = NULL;
            }

            g_pAppWnd->st_LocalSong_Info = new ST_LOCALSONG_INFO[pstLocalSongList->count];
            for(int i = 0; i < pstLocalSongList->count; i++ )
            {
                memcpy(&g_pAppWnd->st_LocalSong_Info[i], &pstLocalSongList->pstLocalSongInfo[i], sizeof(ST_LOCALSONG_INFO));
                DEBUG_PARAM("songID = ", pstLocalSongList->pstLocalSongInfo[i].songID);
                DEBUG_PARAM("songName = ", pstLocalSongList->pstLocalSongInfo[i].songName);
                DEBUG_PARAM("singer = ", pstLocalSongList->pstLocalSongInfo[i].singer);
            }

            emit g_pAppWnd->getLocalSongList(pstLocalSongList->count, pstLocalSongList->pageNumber, pstLocalSongList->allPageNumber);
        }
        if(0 == pstLocalSongList->count)
        {
            g_pAppWnd->m_isLoaderLocalMusic = 0;
        }
    }
    else
    {
        g_pAppWnd->m_isLoaderLocalMusic = 0;
    }
}

void on_lpMusic_Get_SelectList(PST_SELECT_LIST pstSelectList,void* pUserData)
{
    Q_UNUSED(pstSelectList);
    Q_UNUSED(pUserData);
}

void on_lpMusic_Get_SelectSongList(PST_SELECTSONG_LIST pstSelSongList,void* pUserData)
{
    Q_UNUSED(pstSelSongList);
    Q_UNUSED(pUserData);
}

void on_lpMusic_Get_PlayorPause(ssp_int32 playStatus,ssp_int32 curTime,void* pUserData)
{
    Q_UNUSED(curTime);
    Q_UNUSED(pUserData);
    DEBUG_PARAM("playStatus = ",playStatus);
    emit g_pAppWnd->sigGetPlayorPause(playStatus);
}

void on_lpMusic_Get_Phone_PlayorPause(ssp_int32 playStatus,ssp_int32 curTime,void* pUserData)
{
    Q_UNUSED(curTime);
    Q_UNUSED(pUserData);
    DEBUG_PARAM("playStatus = ",playStatus);
    emit g_pAppWnd->sigGetPhonePlayOrPause(playStatus);
}

void on_lpMusic_Get_LocalPicture(ssp_int32 ret,const char* picPath,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("picPath = ",picPath);
    if(ret == _SSP_OK)
    {
        DEBUGLOG;
        QString picturePath= QString(QLatin1String(picPath));
        emit g_pAppWnd->sigGetLocalPicture(picturePath);
    }
    if(ret == _SSP_ERROR)
    {
        DEBUGLOG;
        QString picturePath= QString(QLatin1String("1"));
        emit g_pAppWnd->sigGetLocalPicture(picturePath);
    }
}

void on_lpMusic_Get_PlayMode(ssp_int32 ret,ssp_int32 playmode,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("playmode : ", playmode);
    if(ret == _SSP_OK)
    {
        emit g_pAppWnd->sigGetPlayModeFromPhone(playmode);
    }
}

void on_lpMusicInfo(ST_MUSIC_INFO musicInfo,void* pUserData)
{
    Q_UNUSED(musicInfo);
    Q_UNUSED(pUserData);
}

/******************************* calendar start *******************************/

void callback_SSPLinkCanlendarReciveEventCallBack(void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUGLOG;
    emit g_pAppWnd-> canlendarReciveEvent();
}

void callback_SSPLinkCanlendarReciveDateTimeCallBack(DateTimeInfo_t* pstDateTimeInfo,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("year:", pstDateTimeInfo->year);
    DEBUG_PARAM("month:", pstDateTimeInfo->month);
    g_pAppWnd->m_title_dateTime.year = pstDateTimeInfo->year;
    g_pAppWnd->m_title_dateTime.month = pstDateTimeInfo->month;

    DateTimeInfo_t stDataInfo = *pstDateTimeInfo;
    QDate qDate = QDate::currentDate();
    qDate.setDate(stDataInfo.year, stDataInfo.month, stDataInfo.day);
    g_pAppWnd->UpdateDateInfo(qDate);
    g_pAppWnd->assistant.assistant_api.fun_SSP_vCalendar_RequestEventInfoByYear((int)stDataInfo.year);
}

/******************************* weather start ******************************/
void callback_Weather_CityWeather(PST_WEATHER_DATA pstWeatherData,void * pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_PARAM("pstWeatherData->result", pstWeatherData->result);
    if(1 == pstWeatherData->result)
    {
        QString beijingCityID = "101010100";
        if(g_pAppWnd->assistant.assistant_api.fun_SSP_iWeather_GetCityWeather)
            g_pAppWnd->assistant.assistant_api.fun_SSP_iWeather_GetCityWeather(beijingCityID.toLatin1().data());
        if(g_pAppWnd->assistant.assistant_api.fun_SSP_iWeather_GetEverydayWeather)
            g_pAppWnd->assistant.assistant_api.fun_SSP_iWeather_GetEverydayWeather(beijingCityID.toLatin1().data());

        g_pAppWnd->m_bLoadedFail = true;
    }
    else if(0 == pstWeatherData->result)
    {
        g_pAppWnd->m_bLoading = false;

        g_pAppWnd->m_stWeatherData = *pstWeatherData;
        g_pAppWnd->assistant.assistant_api.fun_SSP_iWeather_GetEverydayWeather(g_pAppWnd->m_stWeatherData.cityCode);
        g_pAppWnd->assistant.assistant_api.fun_SSP_iWeather_GetIndexData(g_pAppWnd->m_stWeatherData.cityCode);

        g_pAppWnd->m_bLoadedOK = true;

        QQuickItem *weatherTemperature = g_pAppWnd->rootObject()->findChild<QQuickItem*>("weatherTemperature");
        if(weatherTemperature)
        {
            weatherTemperature->setProperty("text", g_pAppWnd->m_stWeatherData.nowTemp);
        }

        DEBUG_PARAM("cityCode", g_pAppWnd->m_stWeatherData.cityCode);
        QStringList date = QString::fromUtf8(g_pAppWnd->m_stWeatherData.repTime).split(" ");
        QStringList sl = QString::fromUtf8(date.at(0).toLatin1().data()).split("-");
        DEBUG_PARAM("g_pAppWnd->m_stWeatherData.repTime 909090", g_pAppWnd->m_stWeatherData.repTime);
        int moth = sl.at(0).toInt();
        int day  = sl.at(1).toInt();
        DEBUG_PARAM("moth 909090", moth);
        DEBUG_PARAM("day 909090", day);
        QString today = QString::number(moth) + "月"+QString::number(day) + "日";
        DEBUG_PARAM("today 909090", today);
        QQuickItem *weatherDate = g_pAppWnd->rootObject()->findChild<QQuickItem*>("weatherDate");
        if(weatherDate)
        {
            weatherDate->setProperty("text", today);
        }

        QQuickItem *currentLocation = g_pAppWnd->rootObject()->findChild<QQuickItem*>("currentLocation");
        if(currentLocation)
        {
            currentLocation->setProperty("text", g_pAppWnd->m_stWeatherData.cityName);
        }

        QQuickItem *weatherCondition = g_pAppWnd->rootObject()->findChild<QQuickItem*>("weatherCondition");
        if(weatherCondition)
        {
            weatherCondition->setProperty("text", g_pAppWnd->m_stWeatherData.todayWeather);
        }

        QString path = "../weatherImages/weather_icon_big/" + sWeatherTypeIconName[g_pAppWnd->m_stWeatherData.weatherID];

        emit g_pAppWnd->getSSPmainWeatherIconPath(path);
        emit g_pAppWnd->assistant.signal_updateCurrentDayWeather();
        emit g_pAppWnd->assistant.signal_load_ok();
    }
    else
    {
        DEBUG_CHAR("无网络连接");
        emit g_pAppWnd->assistant.signal_load_fail();
    }
}

void callback_Weather_GetEverydayWeather(PST_WEATHER_EVERYDAY_FRM pstWeatherEverydayFrm,void *pUserData)
{
    Q_UNUSED(pUserData);
    if(pstWeatherEverydayFrm->result == _SSP_OK){
        for(int i = 0; i<pstWeatherEverydayFrm->count && i < 5; ++i){
            memset(g_pAppWnd->m_stWeatherEveryDay[i].date, 0, 15);
            g_pAppWnd->m_stWeatherEveryDay[i] = (pstWeatherEverydayFrm->pstWeather_Everyday[i]);
        }

        emit g_pAppWnd->assistant.signal_updateEveryDayWeather(); 
        DEBUG_PARAM("callback_Weather_CityWeather enter1 count = ", pstWeatherEverydayFrm->count);
    }else{
        emit g_pAppWnd->assistant.signal_load_fail();
    }
}

void callback_Weather_GetIndexData(PST_INDEX_DATA pstIndexData,void* pUserData)
{
    Q_UNUSED(pUserData);
    DEBUG_CHAR("callback_Weather_CityWeather enter5");
    g_pAppWnd->m_stIndexData = *pstIndexData;

    if(_SSP_OK == pstIndexData->result)
    {
        QQuickItem *washIndexObj = g_pAppWnd->rootObject()->findChild<QQuickItem*>("washIndexObj");
        if(washIndexObj)
        {
            washIndexObj->setProperty("text", pstIndexData->xc_index);
        }
    }else{
        emit g_pAppWnd->assistant.signal_load_fail();
    }
}

/******************************* MESSAGE START *******************************/
//message callback
void SmsReciveMsgCallBack(PST_SMS_INFO pstSmsInfo,void* pUserData)
{
    DEBUGLOG;
    Q_UNUSED(pUserData);
    QQuickItem *recvMessage = g_pAppWnd->rootObject()->findChild<QQuickItem*>("recvMessage");
    if(recvMessage)
    {
        recvMessage->setProperty("visible", true);
    }
    static ST_SMS_INFO smsInfo;
    smsInfo = *pstSmsInfo;
    emit g_pAppWnd->receiveMsg(&smsInfo);
}

void SmsSendStatusCallBack(ST_SMS_STATUS_FRM *pstSmsStatusFrm,void* pUserData)
{
    DEBUGLOG;
    Q_UNUSED(pUserData);
    if(_SSP_OK == pstSmsStatusFrm->result)
    {
        static ST_SMS_STATUS_FRM smsStatusFrm;
        smsStatusFrm = *pstSmsStatusFrm;
        emit g_pAppWnd->sendStatus(&smsStatusFrm);
    }
}

//Send message callback
void SmsInitiativeSendCallBack(ST_SMS_STATUS_FRM *pstSmsStatusFrm,void* pUserData)
{
    DEBUGLOG;
    Q_UNUSED(pUserData);

    static ST_SMS_STATUS_FRM smsStatusFrm;
    smsStatusFrm = *pstSmsStatusFrm;
    emit g_pAppWnd->initiativeSend(&smsStatusFrm);
    emit g_pAppWnd->sendMessageCallback();

}

void SmsReciveMsgDBRsp(void* pUserData)
{
    Q_UNUSED(pUserData);
    char  unRead[3] = {0};
    g_pAppWnd->assistant.assistant_api.fun_iSms_iUnReadMsg(unRead);
    if(unRead[0] == '0')
    {
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

void SmsReciveContactCallBack(void* pUserData)
{
    DEBUGLOG;
    Q_UNUSED(pUserData);
    emit g_pAppWnd->receiveContact(true);
}

/******************************* PHONE START *******************************/
void Assistant_ConTact_IconPath_cb(ST_CONTACT_ICON_FRM *pstContactIconData)
{
    DEBUGLOG;
    Q_UNUSED(pstContactIconData);
}

void Assistant_Phone_Call_Logs_cb(PST_CALL_LIST_INFO_FRM pStCalListInfoFrm, void* pUserData)
{
    DEBUGLOG;
    Q_UNUSED(pUserData);
    DEBUG_PARAM("pStCalListInfoFrm->date", pStCalListInfoFrm->pstCallListInfo->date);

    if(_SSP_OK == pStCalListInfoFrm->result)
    {
        if(g_pAppWnd->m_pstCallListInfo != NULL)
        {
            delete[] g_pAppWnd->m_pstCallListInfo;
            g_pAppWnd-> m_pstCallListInfo = NULL;

        }

        g_pAppWnd->m_pstCallListInfo = new ST_CALL_LIST_INFO[pStCalListInfoFrm->count];
        for(int i = 0; i < pStCalListInfoFrm->count; i++ )
        {
            memcpy(&g_pAppWnd->m_pstCallListInfo[i], &pStCalListInfoFrm->pstCallListInfo[i], sizeof(ST_CALL_LIST_INFO));
            DEBUG_PARAM("SDK date", QString::fromUtf8(g_pAppWnd->m_pstCallListInfo[i].date));
        }

        emit g_pAppWnd->callLogs(pStCalListInfoFrm->count);
    }

}

void Assistant_Phone_CallFeedBack_cb(ssp_int32 callStatus, ssp_int32 type, void* pUserData)
{
    Q_UNUSED(pUserData);
    Q_UNUSED(callStatus);
    DEBUG_PARAM("callStatus:", callStatus);
    if(0 == callStatus)
    {
        emit g_pAppWnd->phoneNoAnwer();
    }
    if(1 == type)
    {
        DEBUG_PARAM("打电话状态回调 拨号    type = " , type);
        DEBUG_PARAM("打电话状态回调 拨号    callStatus = " , callStatus);
    }
    else if(2 == type)
    {
        DEBUG_PARAM("打电话状态回调 来电   type = " , type);
        DEBUG_PARAM("打电话状态回调 来电   callStatus = " , callStatus);
    }
    else if(3 == type)
    {
         DEBUG_PARAM("打电话状态回调 手机挂断 type = " , type);
         DEBUG_PARAM("打电话状态回调 手机挂断 callStatus = " , callStatus);
    }
    else if(4 == type)
    {
         DEBUG_PARAM("打电话状态回调 手机静音 type = " , type);
         DEBUG_PARAM("打电话状态回调 手机静音 callStatus = " , callStatus);
    }
}

void Assistant_Phone_Missed_Call_cb(void)
{
    DEBUGLOG;
    emit g_pAppWnd->missedCall();
}

void Assistant_Phone_Send_CallStatus_cb(PST_CALL_INFO pstCallInfo, void* pUserData)
{
    DEBUG_PARAM("type:", pstCallInfo->type);
    Q_UNUSED(pUserData);
#if 0
    enum PHONE_SEND_CALL_STATUS
    {
        PHONE_SEND_CALL_PHONE = 1,
        PHONE_SEND_ANSWER_CALL, //
        PHONE_SEND_HANG_OFF,
        PHONE_SEND_SILENCE,
        PHONE_SEND_REMIND, //laidiantixing
        PHONE_SEND_RESPONSE
    };
#endif
    if(1 == pstCallInfo->type)
    {
        DEBUG_PARAM("SSPLINK 打电话状态回调 拨号    pstCallInfo->type = " , pstCallInfo->type);
        g_pAppWnd->m_isGetrecordList = 0; //来电或打电话点击通讯录需要重新加载
        emit g_pAppWnd->phoneCall(pstCallInfo->name, 0);
    }
    else if(2 == pstCallInfo->type)
    {
        DEBUG_PARAM("SSPLINK 打电话状态回调 通话中   pstCallInfo->type = " , pstCallInfo->type);
        emit g_pAppWnd->phoneCalling();
    }
    else if(3 == pstCallInfo->type)
    {
         DEBUG_PARAM("SSPLINK 打电话状态回调 手机挂断 pstCallInfo->type = " , pstCallInfo->type);
         emit g_pAppWnd->phoneNoAnwer();
    }
    else if(4 == pstCallInfo->type)
    {
         DEBUG_PARAM("SSPLINK 打电话状态回调 手机静音 pstCallInfo->type = " , pstCallInfo->type);
    }
    else if(5 == pstCallInfo->type)
    {
         DEBUG_PARAM("SSPLINK 打电话状态回调 来电提醒 pstCallInfo->type = " , pstCallInfo->type);
         g_pAppWnd->m_isGetrecordList = 0;  //来电或打电话点击通讯录需要重新加
         emit g_pAppWnd->phoneCall(pstCallInfo->name, 1);
    }
}

void Assistant_Phone_Start_Recognize_cb(PST_CALL_STATE_INFO pstCallInfo)
{
    DEBUGLOG;
    static ST_CALL_STATE_INFO stateInfo;
    stateInfo = *pstCallInfo;

    emit g_pAppWnd->startRecognize();
}

/******************************* PHONE END *******************************/

