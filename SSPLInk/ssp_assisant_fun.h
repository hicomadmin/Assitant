#ifndef SSP_ASSISANT_FUN_H
#define SSP_ASSISANT_FUN_H
#include <QDate>
#include <QAbstractListModel>
#include <QDebug>
#include <QLibrary>
#include "ssp_assist_if.h"
#include "ssp_assist_struct.h"
#include "common.h"


typedef void (*lpSSP_iAssistant_AssisStateReport)(int state);
typedef void (*lpSSP_iAssistant_DisplayStateReport)(int state);
typedef void (*lpSSP_iAssistant_DeviceStateReport)(int state);
//assistant
typedef ssp_uint8 (*lpSSP_iAssistant_Init)(void);
typedef ssp_uint8 (*lpSSP_iAssistant_InitList)(void);
typedef ssp_uint8 (*lpSSP_iAssistant_UnInit)(void);
typedef void (*lpSSP_vAssistant_RegiestCallBack)(ST_CALLBACK stCallBack);
typedef ssp_uint8 (*lpSSP_iAssistant_RunProcess)(char* appId, ssp_uint8 appType);
typedef void (*lpSSP_vAssistant_KillProcess)(char *cExeName);
typedef void (*lpSSP_vAssistant_SetAppInstallPath)(char* installPath);
typedef void (*lpSSP_vAssistant_SetResourcePath)(char* resourcePath);
typedef void (*lpSSP_vAssistant_SetConfigPath)(char* configPath);
typedef PST_LOCALAPP_LIST (*lpSSP_ptAssistant_GetLocalAppList)(void);
typedef void (*lpSSP_vAssistant_StopMirrorMode)(void);
typedef void (*lpSSP_iAssistant_StartMirrorMode)(void);
typedef void (*lpSSP_iAssistant_MirrorStateReport)(int state);
typedef void (*lpAssistant_SetMuteState)(int flag);              //mute
typedef void (*lpMirror_SetBtLinkState)(int flag,char* addr);    //bluetooth
typedef ssp_uint8 (*lpSSP_iActivate_Start)();
typedef ssp_uint8 (*lpSSP_iActivate_Return)();
typedef ssp_int32 (*lpSSP_iVR_Request_StartVr)();
typedef ssp_int32 (*lpSSP_iVR_Request_VoiceEnd)();
typedef ssp_int32 (*lpSSP_iVR_Request_StopVr)();
typedef void (*lpSSP_iAssistant_LocalMusicRun)();
//localmusic
typedef ssp_int32 (*lpSSP_iMusic_LocalSongList)(ssp_int32 pageNum);
typedef ssp_int32 (*lpSSP_iMusic_SelectList)(ssp_int32 pageNum);
typedef ssp_int32 (*lpSSP_iMusic_SelectSongList)(char* selectID);
typedef ssp_int32 (*lpSSP_iMusic_ChangePlayMode)(ssp_int32 playMode);
typedef ssp_int32 (*lpSSP_iMusic_AlbumList)(ssp_int32 pageNum);
typedef ssp_int32 (*lpSSP_iMusic_AlbumSongList)(char* albumID);
typedef ssp_int32 (*lpSSP_iMusic_LocalPic)(char* picAddr);
typedef ssp_int32 (*lpSSP_iMusic_PlayLocalSong)(char* songID);
typedef ssp_int32 (*lpSSP_iMusic_ExitPhoneAPP)();
typedef ssp_int32 (*lpSSP_iMusic_PlayMode)();
typedef ssp_int32 (*lpSSP_iMusic_GetSongInfo)();
typedef ssp_int32 (*lpSSP_iMusic_WakeUp)();
typedef void (*lpSSP_vMusic_Next)();
typedef void (*lpSSP_vMusic_Prev)();
typedef void (*lpSSP_vMusic_PlayOrPause)(ssp_uint8 playFlag);
//calendar
typedef void (*lpSSP_vCalendar_SetDBPath)(char* databasePath);
typedef void (*lpSSP_vCalendar_RequestEventInfoByYear)(uint year);
typedef void (*lpSSP_vCalendar_RequestPhoneTime)();
typedef int (*lpiGetTodayDate)(DateInfo_t *pstTodayDate);
typedef int (*lpiGetTodayLunarDate)(DateInfo_t stTodayDate,Lunar_DateInfo_t * pstlunTodayDate);
typedef int (*lpiGetLunarCurrentMonthDays)(uint uiYear,uchar ucCurMonth,Month_Calendar_Item_t *pstLunarMonthArr);
typedef int (*lpiGetHoliday)(uint uiYear,uchar ucMonth,uchar ucDay, char* pcHoliday);
typedef int (*lpiGetLunarHoliday)(uint uiYear,uchar ucMonth,uchar ucDay, Boolean isLeapMonthDay,char* pcHoliday);
typedef int (*lpiGetEventInfo)(DateInfo_t stTodayDate,Message_t *pstMessages,uint *uiMesNum);
typedef int (*lpiGetFirstDayWeekNo)(uint uiYear,uchar ucMonth,uchar * pcWeek);
typedef int (*lpiGetDaysNumofMonth)(uint uiYear,uchar ucMonth,uchar * pcDayNum);
typedef int (*lpiGetDateFromLunarDate)(Lunar_DateInfo_t stlunTodayDate,DateInfo_t *pstTodayDate);
typedef int (*lpiGetDateFromHoliday)(int iHolidayID,uchar *ucMonth,uchar *ucDay);
typedef int (*lpiGetDateFromLunarHoliday)(int iHolidayID,uchar *ucMonth,uchar *ucDay);
typedef int (*lpiGetAllLunarMonthNumOfoneYear)(uint uiYear,uchar * pcMonthNum,uchar *pucLeapMonth);
typedef int (*lpiGetAllLunarDaysNumOfoneMonth)(uint uiYear,uchar cMonth,Boolean isLeapMonthDay, uchar *pucDayNum);
typedef int (*lpiGetAllEventInfoOfMonth)(uint uiYear,uchar ucCurMonth, int *iEventCount);
typedef int (*lpiGetQMHolidayDate)(uint uiYear,uchar *pucDay);
typedef void (*lpSSPLinkCanlendarReciveEventCallBack)(void);
typedef void (*lpSSPLinkCanlendarReciveTimeCallBack)(DateInfo_t *pstPhoneDateInfo);
//weather
typedef ssp_uint8 (*lpSSP_iWeather_GetCurrentCityWeather)();
typedef ssp_uint8 (*lpSSP_iWeather_GetCityWeather)(char* cityCode);
typedef ssp_uint8 (*lpSSP_iWeather_GetEverydayWeather)(char* cityCode);
typedef ssp_uint8 (*lpSSP_iWeather_Get24hourWeather)(char* cityCode);
typedef ssp_uint8 (*lpSSP_iWeather_GetWeatherDetail)(char* cityCode,ssp_uint8 dateIndex);
typedef ssp_uint8 (*lpSSP_iWeather_GetAirQuality)(char* cityCode);
typedef ssp_uint8 (*lpSSP_iWeather_GetIndexData)(char* cityCode);
typedef ssp_uint8 (*lpSSP_iWeather_GetAQIRank)(ssp_uint8 flag);
typedef ssp_uint8 (*lpSSP_iWeather_GetWarningInfo)(char* cityCode);
typedef void (*lpSSP_vWeather_SetCityDbPath)(char* dbPath);
typedef PST_CITY_INFO_FRM (*lpSSP_vWeather_GetCityList)(char* keyWord);
typedef ssp_uint8 (*lpSSP_iWeather_GetWeatherSummary)();

typedef void (*lpWeather_CityWeather)(PST_WEATHER_DATA pstWeatherData,void * pUserData);
typedef void (*lpWeather_GetEverydayWeather)(PST_WEATHER_EVERYDAY_FRM pstWeatherEverydayFrm,void *pUserData);
typedef void (*lpWeather_Get24hourWeather)(PST_WEATHER_24H_FRM pstWeather24hFrm,void* pUserData);
typedef void (*lpWeather_GetWeatherDetail)(PST_WEATHER_DETAIL pstWeatherDetail,void* pUserData);
typedef void (*lpWeather_GetAirQuality)(PST_AIR_QUALITY pstAirQuality,void* pUserData);
typedef void (*lpWeather_GetIndexData)(PST_INDEX_DATA pstIndexData,void* pUserData);
typedef void (*lpWeather_GetAQIRank)(PST_AQI_RANK pstAQIRank,void* pUserData);
typedef void(*lpWeather_GetWarningInfo)(PST_WARNING_DATA pstWarningData,void* pUserData);
typedef void (*lpWeatherSummaryInfo)(PST_WEATHER_SUMMARY weatherSummary, void* pUserData);
//message
typedef ssp_uint8 (*lpiSms_iRequestAddresslist)(void);
typedef ssp_uint8 (*lpiSms_iRequestMsgDB)(void);
typedef ssp_uint8 (*lpiSms_iUnReadMsg)(char *unReadNum);
typedef AL_UINT8 (*lpiBtSms_iSendMsg)(char* pNumberString, char* msg);
typedef AL_UINT8 (*lpiBtSms_iReSendMsg)(char* pNumberString, char* msg, char* pRankNumberString);
typedef void (*lpSSP_vSms_RegiestCallBack)(ST_CALLBACK stCallBack);
typedef AL_UINT8 (*lpiBtSmsContacts_ReadContactList)(PST_CONTACT_DATA_FRM  pstContactDataFrm);
typedef AL_UINT8 (*lpiBtSms_iClearMsg)();
typedef AL_UINT8 (*lpiBtSms_iCreateMsgTable)();
typedef AL_UINT8 (*lpiBtSms_iDeleteMsgRecord)(int iRank);
typedef AL_UINT8 (*lpiBtSms_iDeleteOnePersonMsgRecord)(char* pNum);
typedef AL_UINT8 (*lpiBtSms_iOrderBynumberMsgRecord)(char* pNum,PST_SMS_REPLY_INFOR_FRM pstSmsReplyInforFrm);
typedef AL_UINT8 (*lpiBtSms_iSelectInforByIDMsgRecord)(int iRank,char** cMsgInfor);
typedef AL_UINT8 (*lpiSms_iOrderByTimeMsgRecord)(PST_SMS_LIST_INFO_FRM pstSmsListInforFrm);
typedef int (*lpiBtSms_iSelectCountInMailBox)();
typedef int (*lpiBtSms_iSelectCountByNumberInReply)(char *pNum);
typedef AL_UINT8 (*lpiBtSms_iSelectResultByRankMsgRecord)(int iRank,int  iExecStatus);
typedef AL_UINT8 (*lpiBtSms_iUpdateReadStatusByNumber)(char *pNumber);
//phone contacts
typedef void (*lpSSP_vContacts_SetDBPath)(char* databasePath);
typedef ssp_uint8 (*lpSSP_iContacts_ReadContactList)(PST_CONTACT_DATA_FRM  pstContactDataFrm);
typedef void (*lpSSP_iContacts_SearchByName)(char * cPhoneName,PST_CONTACT_DATA_FRM  pstContactDataFrm);
typedef void (*lpSSP_iContacts_SearchByNumber)(char * cPhoneName,PST_CONTACT_DATA_FRM  pstContactDataFrm);
typedef void (*lpSSP_iContacts_SearchByFirstChar)(char * cPhoneNameSzm,PST_CONTACT_DATA_FRM  pstContactDataFrm);
typedef void (*lpSSP_iAssistant_GetcontactsIcons)(ssp_uint8 count, char *iconId[]);    //get head icon of address book
typedef void (*lpSSP_vContacts_CallStateReq)();
//phone
typedef ssp_int32 (*lSSP_iPhone_Call_Phone)(char *phoneNumber);
typedef ssp_int32 (*lSSP_iPhone_Answer_Call)();
typedef ssp_int32 (*lSSP_iPhone_Hang_Off)();
typedef ssp_int32 (*lSSP_iPhone_Silence)();
typedef ssp_int32 (*lSSP_iPhone_Address_List)();
typedef ssp_int32 (*lSSP_iPhone_Call_Logs)();
typedef ssp_int32 (*lSSP_iPhone_Received_Calls)();
typedef ssp_int32 (*lSSP_iPhone_Dialed_Calls)();
typedef ssp_int32 (*lSSP_iPhone_Missed_Calls)();
typedef ssp_int32 (*lSSP_iPhone_Call_Reply_Sms)(char *phoneNumber, char *msg);
typedef ssp_int32 (*lSSP_iPhone_Start_Recognize)();
typedef ssp_int32 (*lSSP_iPhone_Stop_Speech)();

typedef struct {
    lpSSP_iAssistant_AssisStateReport SSP_iAssistant_AssisStateReport;
    lpSSP_iAssistant_DisplayStateReport SSP_iAssistant_DisplayStateReport;
    lpSSP_iAssistant_DeviceStateReport SSP_iAssistant_DeviceStateReport;
    //assistant
    lpSSP_iAssistant_Init   SSP_iAssistant_Init;
    lpSSP_iAssistant_UnInit SSP_iAssistant_UnInit;
    lpSSP_vAssistant_RegiestCallBack SSP_vAssistant_RegiestCallBack;
    lpSSP_iAssistant_RunProcess SSP_iAssistant_RunProcess;
    lpSSP_vAssistant_KillProcess SSP_vAssistant_KillProcess;
    lpSSP_vAssistant_SetAppInstallPath SSP_vAssistant_SetAppInstallPath;
    lpSSP_vAssistant_SetResourcePath SSP_vAssistant_SetResourcePath;
    lpSSP_vAssistant_SetConfigPath SSP_vAssistant_SetConfigPath;
    lpSSP_ptAssistant_GetLocalAppList SSP_ptAssistant_GetLocalAppList;
    lpSSP_vAssistant_StopMirrorMode SSP_vAssistant_StopMirrorMode;
    lpSSP_iAssistant_StartMirrorMode SSP_iAssistant_StartMirrorMode;
    lpSSP_iAssistant_MirrorStateReport SSP_iAssistant_MirrorStateReport;
    lpAssistant_SetMuteState Assistant_SetMuteState;
    lpMirror_SetBtLinkState Mirror_SetBtLinkState;
    lpSSP_iActivate_Start SSP_iActivate_Start;
    lpSSP_iActivate_Return SSP_iActivate_Return;
    lpSSP_iVR_Request_StartVr SSP_iVR_Request_StartVr;
    lpSSP_iVR_Request_VoiceEnd SSP_iVR_Request_VoiceEnd;
    lpSSP_iVR_Request_StopVr SSP_iVR_Request_StopVr;
    lpSSP_iAssistant_LocalMusicRun SSP_iAssistant_LocalMusicRun;
    //localmusic
    lpSSP_iMusic_LocalSongList SSP_iMusic_LocalSongList;
    lpSSP_iMusic_SelectList SSP_iMusic_SelectList;
    lpSSP_iMusic_SelectSongList SSP_iMusic_SelectSongList;
    lpSSP_iMusic_ChangePlayMode SSP_iMusic_ChangePlayMode ;
    lpSSP_iMusic_LocalPic SSP_iMusic_LocalPic;
    lpSSP_iMusic_PlayLocalSong SSP_iMusic_PlayLocalSong;
    lpSSP_iMusic_ExitPhoneAPP SSP_iMusic_ExitPhoneAPP;
    lpSSP_iMusic_PlayMode SSP_iMusic_PlayMode ;
    lpSSP_iMusic_WakeUp SSP_iMusic_WakeUp;
    lpSSP_iMusic_GetSongInfo SSP_iMusic_GetSongInfo;
    lpSSP_vMusic_Next SSP_vMusic_Next;
    lpSSP_vMusic_Prev SSP_vMusic_Prev;
    lpSSP_vMusic_PlayOrPause SSP_vMusic_PlayOrPause;
    //calendar
    lpSSP_vCalendar_SetDBPath fun_SSP_vCalendar_SetDBPath;
    lpSSP_vCalendar_RequestEventInfoByYear fun_SSP_vCalendar_RequestEventInfoByYear;
    lpSSP_vCalendar_RequestPhoneTime fun_SSP_vCalendar_RequestPhoneTime;
    lpiGetTodayDate fun_iGetTodayDate;
    lpiGetTodayLunarDate fun_iGetTodayLunarDate;
    lpiGetLunarCurrentMonthDays fun_iGetLunarCurrentMonthDays;
    lpiGetHoliday fun_iGetHoliday;
    lpiGetLunarHoliday fun_iGetLunarHoliday;
    lpiGetEventInfo fun_iGetEventInfo;
    lpiGetFirstDayWeekNo fun_iGetFirstDayWeekNo;
    lpiGetDaysNumofMonth fun_iGetDaysNumofMonth;
    lpiGetDateFromLunarDate fun_iGetDateFromLunarDate;
    lpiGetDateFromHoliday fun_iGetDateFromHoliday;
    lpiGetDateFromLunarHoliday fun_iGetDateFromLunarHoliday;
    lpiGetAllLunarMonthNumOfoneYear fun_iGetAllLunarMonthNumOfoneYear;
    lpiGetAllLunarDaysNumOfoneMonth fun_iGetAllLunarDaysNumOfoneMonth;
    lpiGetAllEventInfoOfMonth fun_iGetAllEventInfoOfMonth;
    lpiGetQMHolidayDate fun_iGetQMHolidayDate;
    //weather
    lpSSP_iWeather_GetCurrentCityWeather fun_SSP_iWeather_GetCurrentCityWeather;
    lpSSP_iWeather_GetCityWeather fun_SSP_iWeather_GetCityWeather;
    lpSSP_iWeather_GetEverydayWeather fun_SSP_iWeather_GetEverydayWeather;
    lpSSP_iWeather_Get24hourWeather fun_SSP_iWeather_Get24hourWeather;
    lpSSP_iWeather_GetWeatherDetail fun_SSP_iWeather_GetWeatherDetail;
    lpSSP_iWeather_GetAirQuality fun_SSP_iWeather_GetAirQuality;
    lpSSP_iWeather_GetIndexData fun_SSP_iWeather_GetIndexData;
    lpSSP_iWeather_GetAQIRank fun_SSP_iWeather_GetAQIRank;
    lpSSP_iWeather_GetWarningInfo fun_SSP_iWeather_GetWarningInfo;
    lpSSP_vWeather_SetCityDbPath fun_SSP_vWeather_SetCityDbPath;
    lpSSP_vWeather_GetCityList fun_SSP_vWeather_GetCityList;
    lpSSP_iWeather_GetWeatherSummary fun_SSP_iWeather_GetWeatherSummary;
   //message
    lpiSms_iRequestAddresslist fun_iSms_iRequestAddresslist;
    lpiSms_iRequestMsgDB fun_iSms_iRequestMsgDB;
    lpiSms_iUnReadMsg fun_iSms_iUnReadMsg;
    lpiBtSms_iSendMsg fun_iBtSms_iSendMsg;
    lpiBtSms_iReSendMsg fun_iBtSms_iReSendMsg;
    lpSSP_vSms_RegiestCallBack SSP_vSms_RegiestCallBack;
    lpiBtSmsContacts_ReadContactList iBtSmsContacts_ReadContactList;
    lpiBtSms_iClearMsg fun_iBtSms_iClearMsg;
    lpiBtSms_iCreateMsgTable fun_iBtSms_iCreateMsgTable;
    lpiBtSms_iDeleteMsgRecord fun_iBtSms_iDeleteMsgRecord;
    lpiBtSms_iDeleteOnePersonMsgRecord fun_iBtSms_iDeleteOnePersonMsgRecord;
    lpiBtSms_iOrderBynumberMsgRecord fun_iBtSms_iOrderBynumberMsgRecord;
    lpiBtSms_iSelectInforByIDMsgRecord fun_iBtSms_iSelectInforByIDMsgRecord;
    lpiSms_iOrderByTimeMsgRecord fun_iSms_iOrderByTimeMsgRecord;
    lpiBtSms_iSelectCountInMailBox fun_iBtSms_iSelectCountInMailBox;
    lpiBtSms_iSelectCountByNumberInReply fun_iBtSms_iSelectCountByNumberInReply;
    lpiBtSms_iSelectResultByRankMsgRecord fun_iBtSms_iSelectResultByRankMsgRecord;
    lpiBtSms_iUpdateReadStatusByNumber fun_iBtSms_iUpdateReadStatusByNumber;
    //phone contacts
    lpSSP_vContacts_SetDBPath SSP_vContacts_SetDBPath;
    lpSSP_iContacts_ReadContactList  SSP_iContacts_ReadContactList;     //read list of address book
    lpSSP_iContacts_SearchByName SSP_iContacts_SearchByName;
    lpSSP_iContacts_SearchByNumber SSP_iContacts_SearchByNumber;
    lpSSP_iContacts_SearchByFirstChar SSP_iContacts_SearchByFirstChar;
    lpSSP_iAssistant_GetcontactsIcons  SSP_iAssistant_GetcontactsIcons;
    lpSSP_vContacts_CallStateReq SSP_vContacts_CallStateReq;
    //phone
    lSSP_iPhone_Call_Phone SSP_iPhone_Call_Phone;
    lSSP_iPhone_Answer_Call SSP_iPhone_Answer_Call;
    lSSP_iPhone_Hang_Off SSP_iPhone_Hang_Off;
    lSSP_iPhone_Silence SSP_iPhone_Silence;
    lSSP_iPhone_Address_List SSP_iPhone_Address_List;
    lSSP_iPhone_Call_Logs SSP_iPhone_Call_Logs;
    lSSP_iPhone_Received_Calls SSP_iPhone_Received_Calls;
    lSSP_iPhone_Dialed_Calls SSP_iPhone_Dialed_Calls;
    lSSP_iPhone_Missed_Calls SSP_iPhone_Missed_Calls;
    lSSP_iPhone_Call_Reply_Sms SSP_iPhone_Call_Reply_Sms;
    lSSP_iPhone_Start_Recognize SSP_iPhone_Start_Recognize;
    lSSP_iPhone_Stop_Speech SSP_iPhone_Stop_Speech;


    void initlink(QLibrary& library)
    {
        //assistant
        SSP_iAssistant_Init = (lpSSP_iAssistant_Init)library.resolve("SSP_iAssistant_Init");
        SSP_iAssistant_UnInit = (lpSSP_iAssistant_UnInit)library.resolve("SSP_iAssistant_UnInit");
        SSP_vAssistant_RegiestCallBack = (lpSSP_vAssistant_RegiestCallBack)library.resolve("SSP_vAssistant_RegiestCallBack");
        SSP_iAssistant_RunProcess = (lpSSP_iAssistant_RunProcess)library.resolve("SSP_iAssistant_RunProcess");
        SSP_vAssistant_KillProcess = (lpSSP_vAssistant_KillProcess)library.resolve("SSP_vAssistant_KillProcess");
        SSP_vAssistant_SetAppInstallPath = (lpSSP_vAssistant_SetAppInstallPath)library.resolve("SSP_vAssistant_SetAppInstallPath");
        SSP_vAssistant_SetResourcePath = (lpSSP_vAssistant_SetResourcePath)library.resolve("SSP_vAssistant_SetResourcePath");
        SSP_vAssistant_SetConfigPath = (lpSSP_vAssistant_SetConfigPath)library.resolve("SSP_vAssistant_SetConfigPath");
        SSP_ptAssistant_GetLocalAppList = (lpSSP_ptAssistant_GetLocalAppList)library.resolve("SSP_ptAssistant_GetLocalAppList");
        SSP_vAssistant_StopMirrorMode = (lpSSP_vAssistant_StopMirrorMode)library.resolve("SSP_vAssistant_StopMirrorMode");
        SSP_iAssistant_StartMirrorMode = (lpSSP_iAssistant_StartMirrorMode)library.resolve("SSP_iAssistant_StartMirrorMode");
        SSP_iAssistant_MirrorStateReport = (lpSSP_iAssistant_MirrorStateReport)library.resolve("SSP_iAssistant_MirrorStateReport"); //
        SSP_iAssistant_AssisStateReport = (lpSSP_iAssistant_AssisStateReport)library.resolve("SSP_iAssistant_AssisStateReport");
        SSP_iAssistant_DisplayStateReport = (lpSSP_iAssistant_DisplayStateReport)library.resolve("SSP_iAssistant_DisplayStateReport");
        SSP_iAssistant_DeviceStateReport = (lpSSP_iAssistant_DeviceStateReport)library.resolve("SSP_iAssistant_DeviceStateReport");
        Assistant_SetMuteState = (lpAssistant_SetMuteState)library.resolve("Assistant_SetMuteState");
        Mirror_SetBtLinkState = (lpMirror_SetBtLinkState)library.resolve("Mirror_SetBtLinkState");
        SSP_iActivate_Start = (lpSSP_iActivate_Start)library.resolve("SSP_iActivate_Start");
        SSP_iActivate_Return = (lpSSP_iActivate_Return)library.resolve("SSP_iActivate_Return");
        SSP_iVR_Request_StartVr = (lpSSP_iVR_Request_StartVr)library.resolve("SSP_iVR_Request_StartVr");
        SSP_iVR_Request_VoiceEnd = (lpSSP_iVR_Request_VoiceEnd)library.resolve("SSP_iVR_Request_VoiceEnd");
        SSP_iVR_Request_StopVr = (lpSSP_iVR_Request_StopVr)library.resolve("SSP_iVR_Request_StopVr");
        SSP_iAssistant_LocalMusicRun = (lpSSP_iAssistant_LocalMusicRun)library.resolve("SSP_iAssistant_LocalMusicRun");
        //localmusic
        SSP_iMusic_LocalSongList = (lpSSP_iMusic_LocalSongList)library.resolve("SSP_iMusic_LocalSongList");
        SSP_iMusic_SelectList=(lpSSP_iMusic_SelectList)library.resolve("SSP_iMusic_SelectList");
        SSP_iMusic_SelectSongList=(lpSSP_iMusic_SelectSongList)library.resolve("SSP_iMusic_SelectSongList");
        SSP_iMusic_ChangePlayMode=(lpSSP_iMusic_ChangePlayMode)library.resolve("SSP_iMusic_ChangePlayMode");
        SSP_iMusic_LocalPic=(lpSSP_iMusic_LocalPic)library.resolve("SSP_iMusic_LocalPic");
        SSP_iMusic_PlayLocalSong=(lpSSP_iMusic_PlayLocalSong)library.resolve("SSP_iMusic_PlayLocalSong");
        SSP_iMusic_ExitPhoneAPP=(lpSSP_iMusic_ExitPhoneAPP)library.resolve("SSP_iMusic_ExitPhoneAPP");
        SSP_iMusic_PlayMode=(lpSSP_iMusic_PlayMode)library.resolve("SSP_iMusic_PlayMode");
        SSP_iMusic_WakeUp=(lpSSP_iMusic_WakeUp)library.resolve("SSP_iMusic_WakeUp");
        SSP_iMusic_GetSongInfo=(lpSSP_iMusic_GetSongInfo)library.resolve("SSP_iMusic_GetSongInfo");
        SSP_vMusic_Next = (lpSSP_vMusic_Next)library.resolve("SSP_vMusic_Next");
        SSP_vMusic_Prev = (lpSSP_vMusic_Prev)library.resolve("SSP_vMusic_Prev");
        SSP_vMusic_PlayOrPause = (lpSSP_vMusic_PlayOrPause)library.resolve("SSP_vMusic_PlayOrPause");
        //calendar
        fun_SSP_vCalendar_SetDBPath = (lpSSP_vCalendar_SetDBPath)library.resolve("SSP_vCalendar_SetDBPath");
        fun_SSP_vCalendar_RequestEventInfoByYear = (lpSSP_vCalendar_RequestEventInfoByYear)library.resolve("SSP_vCalendar_RequestEventInfoByYear");
        fun_SSP_vCalendar_RequestPhoneTime = (lpSSP_vCalendar_RequestPhoneTime)library.resolve("SSP_vCalendar_RequestPhoneTime");
        fun_iGetTodayDate = (lpiGetTodayDate)library.resolve("iGetTodayDate");
        fun_iGetTodayLunarDate = (lpiGetTodayLunarDate)library.resolve("iGetTodayLunarDate");
        fun_iGetLunarCurrentMonthDays = (lpiGetLunarCurrentMonthDays)library.resolve("iGetLunarCurrentMonthDays");
        fun_iGetHoliday = (lpiGetHoliday)library.resolve("iGetHoliday");
        fun_iGetLunarHoliday = (lpiGetLunarHoliday)library.resolve("iGetLunarHoliday");
        fun_iGetEventInfo = (lpiGetEventInfo)library.resolve("iGetEventInfo");
        fun_iGetFirstDayWeekNo = (lpiGetFirstDayWeekNo)library.resolve("iGetFirstDayWeekNo");
        fun_iGetDaysNumofMonth = (lpiGetDaysNumofMonth)library.resolve("iGetDaysNumofMonth");
        fun_iGetDateFromLunarDate = (lpiGetDateFromLunarDate)library.resolve("iGetDateFromLunarDate");
        fun_iGetDateFromHoliday = (lpiGetDateFromHoliday)library.resolve("iGetDateFromHoliday");
        fun_iGetDateFromLunarHoliday = (lpiGetDateFromLunarHoliday)library.resolve("iGetDateFromLunarHoliday");
        fun_iGetAllLunarMonthNumOfoneYear = (lpiGetAllLunarMonthNumOfoneYear)library.resolve("iGetAllLunarMonthNumOfoneYear");
        fun_iGetAllLunarDaysNumOfoneMonth = (lpiGetAllLunarDaysNumOfoneMonth)library.resolve("iGetAllLunarDaysNumOfoneMonth");
        fun_iGetAllEventInfoOfMonth = (lpiGetAllEventInfoOfMonth)library.resolve("iGetAllEventInfoOfMonth");
        fun_iGetQMHolidayDate = (lpiGetQMHolidayDate)library.resolve("iGetQMHolidayDate");
        //weather
        fun_SSP_iWeather_GetCurrentCityWeather = (lpSSP_iWeather_GetCurrentCityWeather)library.resolve("SSP_iWeather_GetCurrentCityWeather");
        fun_SSP_iWeather_GetCityWeather = (lpSSP_iWeather_GetCityWeather)library.resolve("SSP_iWeather_GetCityWeather");
        fun_SSP_iWeather_GetEverydayWeather = (lpSSP_iWeather_GetEverydayWeather)library.resolve("SSP_iWeather_GetEverydayWeather");
        fun_SSP_iWeather_Get24hourWeather = (lpSSP_iWeather_Get24hourWeather)library.resolve("SSP_iWeather_Get24hourWeather");
        fun_SSP_iWeather_GetWeatherDetail = (lpSSP_iWeather_GetWeatherDetail)library.resolve("SSP_iWeather_GetWeatherDetail");
        fun_SSP_iWeather_GetAirQuality = (lpSSP_iWeather_GetAirQuality)library.resolve("SSP_iWeather_GetAirQuality");
        fun_SSP_iWeather_GetIndexData = (lpSSP_iWeather_GetIndexData)library.resolve("SSP_iWeather_GetIndexData");
        fun_SSP_iWeather_GetAQIRank = (lpSSP_iWeather_GetAQIRank)library.resolve("SSP_iWeather_GetAQIRank");
        fun_SSP_iWeather_GetWarningInfo = (lpSSP_iWeather_GetWarningInfo)library.resolve("SSP_iWeather_GetWarningInfo");
        fun_SSP_vWeather_SetCityDbPath = (lpSSP_vWeather_SetCityDbPath)library.resolve("SSP_vWeather_SetCityDbPath");
        fun_SSP_vWeather_GetCityList = (lpSSP_vWeather_GetCityList)library.resolve("SSP_vWeather_GetCityList");
        fun_SSP_iWeather_GetWeatherSummary = (lpSSP_iWeather_GetWeatherSummary)library.resolve("SSP_iWeather_GetWeatherSummary");
        //message
        fun_iSms_iRequestAddresslist = (lpiSms_iRequestAddresslist)library.resolve("iSms_iRequestAddresslist");
        fun_iSms_iRequestMsgDB = (lpiSms_iRequestMsgDB)library.resolve("iSms_iRequestMsgDB");
        fun_iSms_iUnReadMsg = (lpiSms_iUnReadMsg)library.resolve("iSms_iUnReadMsg");
        fun_iBtSms_iSendMsg = (lpiBtSms_iSendMsg)library.resolve("iSms_iSendMsg");
        fun_iBtSms_iReSendMsg = (lpiBtSms_iReSendMsg)library.resolve("iSms_iReSendMsg");
        fun_iBtSms_iClearMsg = (lpiBtSms_iClearMsg)library.resolve("iSms_iClearMsg");
        fun_iBtSms_iCreateMsgTable = (lpiBtSms_iCreateMsgTable)library.resolve("iSms_iCreateMsgTable");
        fun_iBtSms_iDeleteOnePersonMsgRecord = (lpiBtSms_iDeleteOnePersonMsgRecord)library.resolve("iSms_iDeleteOnePersonMsgRecord");
        fun_iBtSms_iOrderBynumberMsgRecord = (lpiBtSms_iOrderBynumberMsgRecord)library.resolve("iSms_iOrderBynumberMsgRecord");
        fun_iBtSms_iSelectInforByIDMsgRecord = (lpiBtSms_iSelectInforByIDMsgRecord)library.resolve("iSms_iSelectInforByIDMsgRecord");
        fun_iSms_iOrderByTimeMsgRecord = (lpiSms_iOrderByTimeMsgRecord)library.resolve("iSms_iOrderByTimeMsgRecord");
        fun_iBtSms_iSelectCountInMailBox = (lpiBtSms_iSelectCountInMailBox)library.resolve("iSms_iSelectCountInMailBox");
        fun_iBtSms_iSelectCountByNumberInReply = (lpiBtSms_iSelectCountByNumberInReply)library.resolve("iSms_iSelectCountByNumberInReply");
        fun_iBtSms_iSelectResultByRankMsgRecord = (lpiBtSms_iSelectResultByRankMsgRecord)library.resolve("iSms_iSelectResultByRankMsgRecord");
        fun_iBtSms_iUpdateReadStatusByNumber = (lpiBtSms_iUpdateReadStatusByNumber)library.resolve("iSms_iUpdateReadStatusByNumber");
        //phone
        SSP_iContacts_SearchByNumber = (lpSSP_iContacts_SearchByNumber)library.resolve("SSP_iContacts_SearchByNumber");
        //set database path of address book
        SSP_vContacts_SetDBPath = (lpSSP_vContacts_SetDBPath)library.resolve("SSP_vContacts_SetDBPath");
        //read contact list
        SSP_iContacts_ReadContactList = (lpSSP_iContacts_ReadContactList)library.resolve("SSP_iContacts_ReadContactList");
        //search by name
        SSP_iContacts_SearchByName = (lpSSP_iContacts_SearchByName)library.resolve("SSP_iContacts_SearchByName");
        //search by initials
        SSP_iContacts_SearchByFirstChar = (lpSSP_iContacts_SearchByFirstChar)library.resolve("SSP_iContacts_SearchByFirstChar");
        //get head icon of address book
        SSP_iAssistant_GetcontactsIcons = (lpSSP_iAssistant_GetcontactsIcons)library.resolve("SSP_iAssistant_GetcontactsIcons");
        SSP_vContacts_CallStateReq = (lpSSP_vContacts_CallStateReq)library.resolve("SSP_vContacts_CallStateReq");
        //give sb a call
        SSP_iPhone_Call_Phone = (lSSP_iPhone_Call_Phone)library.resolve("SSP_iPhone_Call_Phone");
        //answer call
        SSP_iPhone_Answer_Call = (lSSP_iPhone_Answer_Call)library.resolve("SSP_iPhone_Answer_Call");
        //hang up
        SSP_iPhone_Hang_Off = (lSSP_iPhone_Hang_Off)library.resolve("SSP_iPhone_Hang_Off");
        //silence of phone
        SSP_iPhone_Silence = (lSSP_iPhone_Silence)library.resolve("SSP_iPhone_Silence");
        //phone address list
        SSP_iPhone_Address_List = (lSSP_iPhone_Address_List)library.resolve("SSP_iPhone_Address_List");
        //call SSP_iPhone_Call_Logs interface can get all call records
        SSP_iPhone_Call_Logs = (lSSP_iPhone_Call_Logs)library.resolve("SSP_iPhone_Call_Logs");
        SSP_iPhone_Received_Calls = (lSSP_iPhone_Received_Calls)library.resolve("SSP_iPhone_Received_Calls");
        SSP_iPhone_Dialed_Calls = (lSSP_iPhone_Dialed_Calls)library.resolve("SSP_iPhone_Dialed_Calls");
        SSP_iPhone_Missed_Calls = (lSSP_iPhone_Missed_Calls)library.resolve("SSP_iPhone_Missed_Calls");
        SSP_iPhone_Call_Reply_Sms = (lSSP_iPhone_Call_Reply_Sms)library.resolve("SSP_iPhone_Call_Reply_Sms");
        SSP_iPhone_Start_Recognize = (lSSP_iPhone_Start_Recognize)library.resolve("SSP_iPhone_Start_Recognize");
        SSP_iPhone_Stop_Speech = (lSSP_iPhone_Stop_Speech)library.resolve("SSP_iPhone_Stop_Speech");

    }
}SSP_ASSISGANG_FUNC;

typedef struct DayInfo{
    int nYear;
    int nMonth;
    int nDay;
    int nWeekNumber;
    int nHolidayIndex;
    int nLunarYear;
    int nLunarMonth;
    int nLunarDay;
    int nSolarTermIndex;
    int nLunarHolidayIndex;
    int nHaveAffairs;
    QVector<Message_t*> mapMsg;

    DayInfo(){
        nYear				= -1;
        nMonth				= -1;
        nDay				= -1;
        nWeekNumber			= -1;
        nHolidayIndex		= -1;
        nLunarYear			= -1;
        nLunarMonth			= -1;
        nLunarDay			= -1;
        nSolarTermIndex		= -1;
        nLunarHolidayIndex	= -1;
        nHaveAffairs		= 0;
        mapMsg.clear();
    }

    void Reset(){
        nYear				= -1;
        nMonth				= -1;
        nDay				= -1;
        nWeekNumber			= -1;
        nHolidayIndex		= -1;
        nLunarYear			= -1;
        nLunarMonth			= -1;
        nLunarDay			= -1;
        nSolarTermIndex		= -1;
        nLunarHolidayIndex	= -1;
        nHaveAffairs 		= 0;

        for(int i=0; i<mapMsg.size(); ++i){
            delete mapMsg[i];
            mapMsg[i] = NULL;
        }
        mapMsg.clear();
    }

    void AddMsg(Message_t *pMsg){
        for(int i= 0; i<mapMsg.size(); ++i){
            memcmp(mapMsg[i], pMsg, sizeof(Message_t));
            DEBUG_PARAM("sizeof(Message_t) = ", sizeof(Message_t));
            if(0 == memcmp(mapMsg[i], pMsg, sizeof(Message_t))){
                return;
            }
        }
        mapMsg.push_back(pMsg);
    }

    QVector<Message_t*> getMsg(){
        return mapMsg;
    }

    void SetDate(QDate dDate, int nAffairs = 0){
        nYear				= dDate.year();
        nMonth				= dDate.month();
        nDay				= dDate.day();
        nWeekNumber			= -1;
        nHolidayIndex		= -1;
        nLunarYear			= -1;
        nLunarMonth			= -1;
        nLunarDay			= -1;
        nSolarTermIndex		= -1;
        nLunarHolidayIndex	= -1;
        nHaveAffairs		= nAffairs;
    }
}DayInfo, *pDayInfo;

typedef struct MonthDateInfo
{
    int nCurrYear;
    int nCurrMonth;
    int nCurrDay;
    int nCheckMonth;
    int nCheckDay;
    DayInfo arrMonthDateInfo[42];

    MonthDateInfo(){
        nCurrYear   = -1;
        nCurrMonth  = -1;
        nCurrDay	= -1;
        nCheckMonth	= -1;
        nCheckDay   = -1;
    }

    void Reset(){
        nCurrYear   = -1;
        nCurrMonth  = -1;
        nCurrDay	= -1;
        nCheckMonth	= -1;
        nCheckDay   = -1;
        for(int i=0; i<42; ++i){
            arrMonthDateInfo[i].Reset();
        }
    }

    void setEventCount(int nCount[31]){
        for(int i=0; i<42; ++i){
            if(arrMonthDateInfo[i].nMonth == nCurrMonth){
                for(int h=0; h<31; ++h){
                    if((i+h)<42){
                        arrMonthDateInfo[i+h].nHaveAffairs = nCount[h];
                    }
                }
                break;
            }
        }
    }

    void setEventMsg(int nYear, int nMonth, int nDay, Message_t *pMsg){
        for(int i=0; i<42; ++i){
            if(arrMonthDateInfo[i].nYear == nYear){
                if(arrMonthDateInfo[i].nMonth == nMonth){
                    if(arrMonthDateInfo[i].nDay == nDay){
                        arrMonthDateInfo[i].AddMsg(pMsg);
                    }
                }
            }
        }
    }

    QVector<Message_t*> getEventMsg(int nYear, int nMonth, int nDay){
        for(int i=0; i<42; ++i){
            if(arrMonthDateInfo[i].nYear == nYear){
                if(arrMonthDateInfo[i].nMonth == nMonth){
                    if(arrMonthDateInfo[i].nDay == nDay){
                        DEBUG_CHAR("getMessageByCheckDay enter event size =1 \n");
                        return arrMonthDateInfo[i].getMsg();
                    }
                }
            }
        }
        QVector<Message_t*> tempMapMsg;
        return tempMapMsg;
    }
}MonthDateInfo, *pMonthDateInfo;

//assistant
void on_lpAssistant_Activate_Status(int status, void* pUserData);
void on_lpAssistant_Subappprocessexit(char *process,void* pUserData);
void on_lpAssistant_Upgrade_Status(int status, void* pUserData);
void on_lpAssistant_SetLanguage(int iLang,void* pUserData);
void on_lpAssistant_Audio_Status(enum AUDIO_STATUS audioState, void * pUserData);
void on_lpAssistant_PhoneAppIconPath(char* iconId,const char* iconPath,void* pUserData);
void on_lpAssistant_VolChange(int type, int volue);
void on_lpAssistant_RunProcess(ssp_uint8 ret,void* pUserData);
void on_lpAssistant_PhoneAppChanged(void* pUserData);
void on_lpAssistant_InitListProcess(enum INIT_ASSIST_STATUS ret, enum INIT_ASSIST_PROCESS iProc, enum INIT_ASSIST_STRING iString, void* pUserData);
void on_lpAssistant_MirrorState(enum MIRROR_STATUS ret,void* pUserData);
void on_lpAssistant_MirrorEnableStatus(ssp_uint8 ret,void* pUserData);
void on_lpAssistant_SetDisplayState(int state,void* pUserData);
void on_lpAssistant_SetAudioState(int state,void* pUserData);
void on_lpAssistant_SetHardKeyType(int keyType, int flag,void* pUserData);
void on_lpAssistant_SetMuteState(int flag);
void on_lpMirror_SetBtLinkState(int flag,char* addr);
void on_lpAssistant_SetSDState(int iFlag,void* pUserData); //SD Icon
void on_lpAssistant_SetAUXState(int iFlag,void* pUserData);//AUX Icon
void on_lpAssistant_VR_Status(VR_STATUS status, int errorCode, void* pUserData);
void on_lpAssistant_VR_StartAPP(int type, char * appid, void* pUserData);
void on_lpAssistant_Music_App_Run(char * appId, char * appName, char * iconPath, void * pUserData);
//localmusic
void on_lpMusic_Get_Wakeup_PhoneApp(void* pUserData);
void on_lpMusic_Get_Song_Info(PST_SONG_INFO pstSongInfo,void* pUserData);
void on_lpMusic_Get_LocalSongList(PST_LOCALSONG_LIST pstLocalSongList,void* pUserData);
void on_lpMusic_Get_SelectList(PST_SELECT_LIST pstSelectList,void* pUserData);
void on_lpMusic_Get_SelectSongList(PST_SELECTSONG_LIST pstSelSongList,void* pUserData);
void on_lpMusic_Get_PlayorPause(ssp_int32 playStatus,ssp_int32 curTime,void* pUserData);
void on_lpMusic_Get_Phone_PlayorPause(ssp_int32 playStatus,ssp_int32 curTime,void* pUserData);
void on_lpMusic_Get_LocalPicture(ssp_int32 ret,const char* picPath,void* pUserData);
void on_lpMusic_Get_PlayMode(ssp_int32 ret,ssp_int32 playmode,void* pUserData);
void on_lpMusicInfo(ST_MUSIC_INFO musicInfo,void* pUserData);
//calendar
void callback_SSPLinkCanlendarReciveEventCallBack(void* pUserData);
void callback_SSPLinkCanlendarReciveDateTimeCallBack(DateTimeInfo_t* pstDateTimeInfo, void* pUserData);
//weather
void callback_Weather_CityWeather(PST_WEATHER_DATA pstWeatherData,void * pUserData);
void callback_Weather_GetEverydayWeather(PST_WEATHER_EVERYDAY_FRM pstWeatherEverydayFrm,void *pUserData);
void callback_Weather_GetIndexData(PST_INDEX_DATA pstIndexData,void* pUserData);
//message
void SmsReciveMsgCallBack(PST_SMS_INFO pstSmsInfo,void* pUserData);
void SmsSendStatusCallBack(PST_SMS_STATUS_FRM pstSmsStatusFrm,void* pUserData);
void SmsInitiativeSendCallBack(PST_SMS_STATUS_FRM pstSmsStatusFrm,void* pUserData);
void SmsReciveMsgDBRsp(void* pUserData);
void SmsReciveContactCallBack(void* pUserData);
//phone
void Assistant_ConTact_IconPath_cb(ST_CONTACT_ICON_FRM *pstContactIconData);//ConTact IconPath
void Assistant_Phone_Call_Logs_cb(PST_CALL_LIST_INFO_FRM pStCalListInfoFrm, void* pUserData);
void Assistant_Phone_CallFeedBack_cb(ssp_int32 callStatus, ssp_int32 type, void* pUserData);
void Assistant_Phone_Missed_Call_cb(void);
void Assistant_Phone_Send_CallStatus_cb(PST_CALL_INFO pstCallInfo, void* pUserData);
void Assistant_Phone_Start_Recognize_cb(PST_CALL_STATE_INFO pstCallInfo);


/******************************* Calendar START *******************************/
class event_list_item
{
public:
    event_list_item(){}
    event_list_item(int eventid, QString eventstarttime,QString eventendtime, QString eventlocal, QString eventtitle):
        m_event_id(eventid),m_eventstarttime(eventstarttime),m_eventendtime(eventendtime),m_eventlocal(eventlocal),m_eventtitle(eventtitle){
    }

    QString geteventstarttime() const{
        return m_eventstarttime;
    }
    QString geteventendtime() const{
        return m_eventendtime;
    }
    QString geteventlocal() const{
        return m_eventlocal;
    }
    QString geteventtitle() const{
        return m_eventtitle;
    }

    int geteventid() const{
        return m_event_id;
    }

    void setiteminfo(int event_id, QString eventstarttime,QString eventendtime, QString eventlocal, QString eventtitle){
        m_eventstarttime   = eventstarttime;
        m_eventendtime    = eventendtime;
        m_eventlocal          = eventlocal;
        m_eventtitle           = eventtitle;
        m_event_id  = event_id;
    }

private:
    int m_event_id;
    QString m_eventstarttime, m_eventendtime, m_eventlocal, m_eventtitle;
};

class calendar_event_list: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit calendar_event_list(QObject *parent = 0):QAbstractListModel(parent){
    }

    enum EventListItemRoles {
        EventListStartTimeRole = Qt::UserRole + 1,
        EventListEndTimeRole,
        EventLocalRole,
        EventTitleRole,
        EventIdRole
    };

    void addEventListItem(const event_list_item &item){
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_event_listItems << item;
        endInsertRows();
    }

    void clear(){
        beginResetModel();
        m_event_listItems.clear();
        endResetModel();
    }

    Q_INVOKABLE QVariant get(int index, QString role){
        if (index < 0 || index >= m_event_listItems.count())
            return QVariant();

        const event_list_item &item = m_event_listItems[index];
        if (role == "event_id")
            return item.geteventid();
        else if (role == "start_time")
            return item.geteventstarttime();
        else if (role == "end_time")
            return item.geteventendtime();
        else if (role == "event_local")
            return item.geteventlocal();
        else if (role == "event_title")
            return item.geteventtitle();
        else
            return QVariant();
    }

    int rowCount(const QModelIndex & parent = QModelIndex()) const{
        Q_UNUSED(parent);
        return m_event_listItems.count();
    }

    QVariant data(const QModelIndex & index, int role = Qt::UserRole) const{
        if (index.row() < 0 || index.row() >= m_event_listItems.count())
            return QVariant();

        const event_list_item &item = m_event_listItems[index.row()];
        if (role == EventIdRole)
            return item.geteventid();
        else if (role == EventListStartTimeRole)
            return item.geteventstarttime();
        else if (role == EventListEndTimeRole)
            return item.geteventendtime();
        else if (role == EventLocalRole)
            return item.geteventlocal();
        else if (role == EventTitleRole)
            return item.geteventtitle();
        else
            return QVariant();
    }

protected:
    QHash<int, QByteArray> roleNames() const{
        QHash<int, QByteArray> roles;
        roles[EventListStartTimeRole] = "start_time";
        roles[EventListEndTimeRole] = "end_time";
        roles[EventLocalRole] = "event_local";
        roles[EventTitleRole] = "event_title";
        roles[EventIdRole] = "event_id";

        return roles;
    }
private:
    QList<event_list_item> m_event_listItems;
};
/******************************* Calendar End *******************************/

class assistant_control:public QObject{
    Q_OBJECT
public:
    void init_assistant_data()
    {
        int ret;
        QString path = "/var/";
        QLibrary libSSP_SDK_Core(SSP_SDK_CORE_LIBRARY_PATH);
        ret = libSSP_SDK_Core.load();
        qDebug("load library %s %s", SSP_SDK_CORE_LIBRARY_PATH, ret?"succeed":"failed");

        QLibrary libSSP_Assistant(SSP_ASSISTANT_LIBRARY_PATH);
        ret = libSSP_Assistant.load();
        qDebug("load library %s %s", SSP_ASSISTANT_LIBRARY_PATH, ret?"succeed":"failed");

		assistant_api.initlink(libSSP_Assistant);

        DEBUG_CHAR("ST_CALLBACK=======");
        ST_CALLBACK callback;
        //language callback
        callback.funcType = CB_ASSISTANT_SET_LANGUAGE;
        callback.pFunc = (void *)on_lpAssistant_SetLanguage;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_ACTIVATE_STATUS;
        callback.pFunc = (void *)on_lpAssistant_Activate_Status;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_AUDIO_STATUS;
        callback.pFunc = (void *)on_lpAssistant_Audio_Status;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);
		
        callback.funcType = CB_ASSISTANT_SUBAPPPROCESSEXIT; //升级完成通知退出助手回调
        callback.pFunc = (void *)on_lpAssistant_Subappprocessexit;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);
		
        callback.funcType = CB_ASSISTANT_UPGRADE_STATUS;   //升级
        callback.pFunc = (void *)on_lpAssistant_Upgrade_Status;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);
		
        callback.funcType = CB_ASSISTANT_PHONE_APP_ICON_PATH;
        callback.pFunc = (void *)on_lpAssistant_PhoneAppIconPath;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_VOL_CHANGE;
        callback.pFunc = (void *)on_lpAssistant_VolChange;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_MUTE_STATE;
        callback.pFunc = (void *)on_lpAssistant_SetMuteState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_BT_STATE;
        callback.pFunc = (void *)on_lpMirror_SetBtLinkState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_SET_SD_STATE;
        callback.pFunc = (void *)on_lpAssistant_SetSDState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_SET_AUX_STATE;
        callback.pFunc = (void *)on_lpAssistant_SetAUXState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_INIT_LIST_PROCESS;
        callback.pFunc = (void *)on_lpAssistant_InitListProcess;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_RUNPROCESS;
        callback.pFunc = (void *)on_lpAssistant_RunProcess;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_PHONE_APP_CHANGED;
        callback.pFunc = (void *)on_lpAssistant_PhoneAppChanged;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);
        callback.funcType = CB_VR_STATUS;
        callback.pFunc = (void *)on_lpAssistant_VR_Status;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);
        callback.funcType = CB_VR_START_APP;
        callback.pFunc = (void *)on_lpAssistant_VR_StartAPP;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        //localmusic
        callback.funcType = CB_MUSIC_SONG_INFO;
        callback.pFunc = (void *)on_lpMusic_Get_Song_Info;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_MUSIC_WAKEUP;
        callback.pFunc = (void *)on_lpMusic_Get_Wakeup_PhoneApp;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_MUSIC_LOCALSONGLIST;
        callback.pFunc = (void *)on_lpMusic_Get_LocalSongList;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_MUSIC_PLAYORPAUSE;
        callback.pFunc = (void *)on_lpMusic_Get_PlayorPause;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_MUSIC_PHONE_PLAYORPAUSE;
        callback.pFunc = (void *)on_lpMusic_Get_Phone_PlayorPause;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_MUSIC_LOCALPICTURE;
        callback.pFunc = (void *)on_lpMusic_Get_LocalPicture;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_MUSIC_PLAYMODE;
        callback.pFunc = (void *)on_lpMusic_Get_PlayMode;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_CALENDAR_EVENT_CALLFEEDBACK;
        callback.pFunc = (void*)callback_SSPLinkCanlendarReciveEventCallBack;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_SMS_RECIVE_DATETIME;
        callback.pFunc = (void*)callback_SSPLinkCanlendarReciveDateTimeCallBack;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_MIRROR_STATE;
        callback.pFunc = (void *)on_lpAssistant_MirrorState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_MIRROR_ENABLE_STATUS;
        callback.pFunc = (void *)on_lpAssistant_MirrorEnableStatus;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        if(_SSP_ERROR == assistant_api.SSP_iAssistant_Init())
        {
            DEBUG_CHAR("_SSP_ERROR == assistant_api.SSP_iAssistant_Init()");
            exit(0);
        }

        assistant_api.fun_SSP_vCalendar_SetDBPath(path.toLatin1().data());

        callback.funcType = CB_ASSISTANT_DISPLAY_STATE;
        callback.pFunc = (void *)on_lpAssistant_SetDisplayState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_MUSIC_APP_RUN;
        callback.pFunc = (void *)on_lpAssistant_Music_App_Run;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_AUDIO_STATE;
        callback.pFunc = (void *)on_lpAssistant_SetAudioState;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_ASSISTANT_HARDKEY_TYPE;
        callback.pFunc = (void *)on_lpAssistant_SetHardKeyType;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        //weather register callback
        callback.funcType = CB_WEATHER_GET_CITY_WEATHER;
        callback.pFunc = (void*)callback_Weather_CityWeather;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_WEATHER_GET_EVERYDAY_WEATHER;
        callback.pFunc = (void*)callback_Weather_GetEverydayWeather;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_WEATHER_GET_INDEXDATA;
        callback.pFunc = (void*)callback_Weather_GetIndexData;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        assistant_api.fun_SSP_vWeather_SetCityDbPath(path.toLatin1().data());
		//message
        callback.funcType = CB_SMS_INITIATIVE_STATUS;
        callback.pFunc = (void *)SmsInitiativeSendCallBack;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_SMS_RECIVE_MSGDB;
        callback.pFunc = (void *)SmsReciveMsgDBRsp;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_SMS_RECIVE_CONTACT;
        callback.pFunc = (void *)SmsReciveContactCallBack;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_SMS_RECIVE_MSG;
        callback.pFunc = (void *)SmsReciveMsgCallBack;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_SMS_SEND_STATUS;
        callback.pFunc = (void *)SmsSendStatusCallBack;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        //contact phone
        callback.funcType = CB_CONTACT_ICONPATH;                    //contact head icon path
        callback.pFunc = (void *)Assistant_ConTact_IconPath_cb;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        //phone
        callback.funcType = CB_PHONE_CALL_LOGS;                     //call records
        callback.pFunc = (void*)Assistant_Phone_Call_Logs_cb;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_PHONE_CALLFEEDBACK;                  //call status
        callback.pFunc = (void *)Assistant_Phone_CallFeedBack_cb;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_PHONE_MISSED_CALLS;
        callback.pFunc = (void *)Assistant_Phone_Missed_Call_cb;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_PHONE_PHONE_SEND_CALLSTATUS;
        callback.pFunc = (void *)Assistant_Phone_Send_CallStatus_cb;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        callback.funcType = CB_PHONE_START_RECOGNIZE;
        callback.pFunc = (void *)Assistant_Phone_Start_Recognize_cb;
        assistant_api.SSP_vAssistant_RegiestCallBack(callback);

        DEBUG_CHAR("ST_CALLBACK end =======");
    }

public:
    Q_INVOKABLE void assistant_do_init()
    {
        init_assistant_data();
    }

signals:
    //calendar
    Q_INVOKABLE void signal_updateEvent();
    Q_INVOKABLE void signal_updateDateInfo();
    //weather
    void signal_updateEveryDayWeather();
    void signal_updateCurrentDayWeather();
    void signal_updateWeatherIndexInfo();
    void signal_load_fail();
    void signal_load_ok();

public:
    SSP_ASSISGANG_FUNC assistant_api;
    DateInfo_t stDataInfo;

    //calendar
    calendar_event_list *eventlistmodel;
};

#endif // SSP_ASSISANT_FUN_H
