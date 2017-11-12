#ifndef _SSP_ASSIST_IF_H_
#define _SSP_ASSIST_IF_H_

#include "ssp_assist_struct.h"

#ifdef __cplusplus
extern "C"{
#endif

/*
å©æåå§ååœæ°
åæ°ïŒæ 
è¿åïŒ_SSP_OK æ³šåæå
     _SSP_ERROR æ³šåå€±èŽ¥
*/
ssp_uint8 SSP_iAssistant_Init();


/*
åå§ååºçšåè¡š
è¿åïŒ_SSP_OK æå
     _SSP_ERROR å€±èŽ¥
*/
//ssp_uint8 SSP_iAssistant_InitList();


/*
å©æååå§å
*/
ssp_uint8 SSP_iAssistant_UnInit(); 

/*
æ³šååè°åœæ°
*/
void SSP_vAssistant_RegiestCallBack(ST_CALLBACK stCallBack); 

/*
å¯åšå­åºçšåè°åœæ°
*/
#if 1 // diff 20160905
ssp_uint8 SSP_iAssistant_RunProcess(char* appId, ssp_uint8 appType);
#endif

/*
éåºå­åºçš
*/
void SSP_vAssistant_ExitProcess(char *appId); 

/*
è·åæ¬å°åºçšåè¡š
*/
PST_LOCALAPP_LIST SSP_ptAssistant_GetLocalAppList(); 


/*
åæ­¢éåæš¡åŒæ¥å£
*/
void SSP_vAssistant_StopMirrorMode(); 


/*
å¯åšéåæš¡åŒæ¥å£
*/
void SSP_iAssistant_StartMirrorMode();

/*
è·åéè®¯åœå€ŽååŸæ 
*/
void SSP_iAssistant_GetContactsIcons(ssp_uint8 count,char* iconId[]);

/*
send assistant state
0: not start, 1: starting, 2:start end
*/
void SSP_iAssistant_AssisStateReport(int state);
/*
send phone connect state
0: disconnect, 1: connect
*/
void SSP_iAssistant_DeviceStateReport(int state);
/*
send display state
0: hide, 1: show, 2: exit
*/
void SSP_iAssistant_DisplayStateReport(int state);
/*
 * send mirror state
 * 0:hide 1:loading 2:show
 */
void SSP_iAssistant_MirrorStateReport(int state);
/*
è·åå°åºçšiconåè°åœæ°æ¥å£
*/
typedef void (*lpAssistant_PhoneAppIconPath)(char* iconId,const char* iconPath,void* pUserData);


/*
è·åéè®¯åœå€ŽååŸæ çåè°åœæ°
åæ°ïŒpstContactIconFrm å€Žåæ°æ®ç»æ
     pUserData  çšæ·æ°æ®
*/
typedef void (*lpAssistant_ContactsIconsPath)(PST_CONTACT_ICON_FRM pstContactIconFrm,void* pUserData);

/*
å©æåå§åè¿åº? åè°åœæ°
åæ°ïŒret  åæ­¥ç¶æ INIT_ASSIST_STATUS ïŒåäžºæ­£åžžãå€±èŽ¥ãå®æäžç§ç¶æ
     iProc åæ­¥è¿åº?  INIT_ASSIST_PROCESSïŒè¡šç€ºåœåè¿è¡åå®¹
     sProcess å¯¹ iProc æå­æè¿°
     pUserData çšæ·æ°æ®
*/
#if 1 // diff 20160905
typedef void (*lpAssistant_InitListProcess)(enum INIT_ASSIST_STATUS ret, enum INIT_ASSIST_PROCESS iProc, enum INIT_ASSIST_STRING iString, void* pUserData);
#endif
/*
è¿æ¥ç¶æåè°åœæ°
åæ°ïŒret  CONNECT_STATUS è¿åè¿æ¥ç¶æ
     pUserData çšæ·æ°æ®
*/
//typedef void (*lpAssistant_ConnectStatus)(enum CONNECT_STATUS ret,void* pUserData);

/*
é³é¢ç¶æåååè°åœæ°
åæ°ïŒaudioState  é³æºç¶æ
     pUserData   çšæ·æ°æ®
*/
typedef void (*lpAssistant_AudioStatus)(enum AUDIO_STATUS audioState, void * pUserData);

/*
åºçšçšåºå¯åšå®æåè°åœæ°
*/
typedef void (*lpAssistant_RunProcess)(ssp_uint8 ret,void* pUserData);   


/*
ææºç«¯åºçšååšåè°åœæ°
*/
typedef void (*lpAssistant_PhoneAppChanged)(void* pUserData); 


/*
å¯åšéåç»æåè°åœæ°
åæ°ïŒret  éåå¯åšç¶æ
	 pUserData çšæ·æ°æ®
*/
typedef void (*lpAssistant_MirrorState)(enum MIRROR_STATUS ret,void* pUserData);

/*
镜像可用状态回调函数
*/
typedef void (*lpAssistant_MirrorEnableStatus)(ssp_uint8 ret,void* pUserData);

/* 
notify assistant show/hide; 
state 1:show, state 0:hide
*/
typedef void (*lpAssistant_SetDisplayState)(int state,void* pUserData);

/* 
notify assistant audio source state;
state 1:ssplink source, state 0:other source
*/
typedef void (*lpAssistant_SetAudioState)(int state,void* pUserData);

/* 
notify assistant hardkey type;
keyType :
typedef enum
{
    SSP_KEY_SEEK_UP = 0,  // previous
    SSP_KEY_SEEK_DOWN,    // next
    SSP_KEY_VOL_UP,       // 
    SSP_KEY_VOL_DOWN,     // 
    SSP_KEY_MODE,  // 
    SSP_KEY_MUTE,  // MUTE
    SSP_KEY_PHONE, //
    SSP_KEY_RELEASE//not used
}SSP_HARD_KEY_TYPE;
*/
typedef void (*lpAssistant_SetHardKeyType)(int keyType, int flag,void* pUserData);

/*
 * set languge
 * iLang 0:chinese 1:English
 *
 */
typedef void (*lpAssistant_SetLanguage)(int iLang,void* pUserData);

/* 
notify assistant volume change; 
type 0: system volume, 1: navi volume
*/
typedef void (*lpAssistant_NotifyVolChange)(int type, int volue);

/*
notify assistant mute change;
flag 0: 1:
*/
typedef void (*lpAssistant_SetMuteState)(int flag);

/*
set assistant bt link state;
flag 0: 1:
*/
typedef void (*lpAssistant_SetBtLinkState)(int flag,char* addr);

/*
 * set SD State
 * iFlag 0:hide 1:show
 *
 */
typedef void (*lpAssistant_SetSDState)(int iFlag,void* pUserData);

/*
 * set AUX State
 * iFlag 0:hide 1:show
 *
 */
typedef void (*lpAssistant_SetAUXState)(int iFlag,void* pUserData);

/*
 * exit Assistant subapp process
 *
 */
typedef void (*lpAssistant_SubAppProcessExit)(char *process,void* pUserData);

/***************************************************************************************/
//  éè®¯åœçžå³æ¥å£

/*
è®Ÿçœ®éè®¯åœæ°æ®åºè·¯åŸ
*/
void SSP_vContacts_SetDBPath(char* databasePath);

/*
è¯»åéè®¯åœåè¡š
*/
ssp_uint8 SSP_iContacts_ReadContactList(PST_CONTACT_DATA_FRM  pstContactDataFrm);


/*
å§åæ£çŽ¢
*/
void SSP_iContacts_SearchByName(char * cPhoneName,PST_CONTACT_DATA_FRM  pstContactDataFrm);

/*
å·ç æ£çŽ¢
*/
void SSP_iContacts_SearchByNumber(char * cPhoneNum,PST_CONTACT_DATA_FRM  pstContactDataFrm);

void SSP_iContacts_SearchName(char * cPhoneNum, char cPhoneName[]);
/*
èç³»äººé? å­æ¯æ£çŽ¢
*/
void SSP_iContacts_SearchByFirstChar(char * cPhoneNameSzm,PST_CONTACT_DATA_FRM  pstContactDataFrm);

void SSP_vContacts_CallStateReq();

/*
çµè¯ç¶æåè°åœæ°
*/
typedef void (*lpContacts_CallState)(PST_CALL_STATE_INFO pstCallStateInfo,void* pUserData);

typedef void (*SSPLinkContacts)(void* pUserData); 

/***************************************************************************************/


/***************************************************************************************/
// æ¥åæ¥å£

void SSP_vCalendar_SetDBPath(char* databasePath);

void SSP_vCalendar_RequestEventInfoByYear(uint year);

void SSP_vCalendar_RequestPhoneTime();
/***************************
 * Get Today Date 
 **************************/
int iGetTodayDate(DateInfo_t *pstTodayDate);
/*******************************************
 * Get  lunar calendar Date   
 *******************************************/
int iGetTodayLunarDate(DateInfo_t stTodayDate,Lunar_DateInfo_t * pstlunTodayDate);

/*******************************************
 * Get all lunar calendar days date of one month
 *******************************************/
int iGetLunarCurrentMonthDays(uint uiYear,uchar ucCurMonth,Month_Calendar_Item_t *pstLunarMonthArr);


/*******************************************
 * Get holiday
 *******************************************/
int iGetHoliday(uint uiYear,uchar ucMonth,uchar ucDay, char* pcHoliday);

/*******************************************
 * Get Lunar calendar holiday
 *******************************************/
int iGetLunarHoliday(uint uiYear,uchar ucMonth,uchar ucDay, Boolean isLeapMonthDay,char* pcHoliday);


/*******************************************
 * Get Event info
 *******************************************/
int iGetEventInfo(DateInfo_t stTodayDate,Message_t *pstMessages,uint *uiMesNum);

/*******************************************
 * Get Week of  fisrt day in current month    
 *******************************************/
int iGetFirstDayWeekNo(uint uiYear,uchar ucMonth,uchar * pcWeek);


/*******************************************
 * Get Week of  fisrt day in current month    
 *******************************************/
int iGetDaysNumofMonth(uint uiYear,uchar ucMonth,uchar * pcDayNum);

/*******************************************
 * Get  Date from lunar calendar   
 *******************************************/
int iGetDateFromLunarDate(Lunar_DateInfo_t stlunTodayDate,DateInfo_t *pstTodayDate);

/*******************************************
 * Get  Date from holiday   
 *******************************************/
int iGetDateFromHoliday(int iHolidayID,uchar *ucMonth,uchar *ucDay);

/*******************************************
 * Get  Date from lunar holiday   
 *******************************************/
int iGetDateFromLunarHoliday(int iHolidayID,uchar *ucMonth,uchar *ucDay);

/*******************************************
 * Get All lunar month Num and  LeapMonth
 *******************************************/
int iGetAllLunarMonthNumOfoneYear(uint uiYear,uchar * pcMonthNum,uchar *pucLeapMonth);


/*******************************************
 * Get All lunar days Num of one lunar month
 *uint uiYear,
 *uchar cMonth,
 *Boolean isLeapMonthDay ï¿œÇ·ï¿œï¿œï¿œï¿œï¿œï¿œï¿œ
 *******************************************/
int iGetAllLunarDaysNumOfoneMonth(uint uiYear,uchar cMonth,Boolean isLeapMonthDay, uchar *pucDayNum);

/*******************************************
 * Get all Event of one month
 *******************************************/
int iGetAllEventInfoOfMonth(uint uiYear,uchar ucCurMonth, int *iEventCount);


/*******************************************
 è·åæžæèæ¥å£
 *******************************************/
int iGetQMHolidayDate(uint uiYear,uchar *pucDay);


/*******************************
*æ¥ååèœåè°åœæ°å®ä¹
********************************/
//äºä»¶ä¿¡æ¯åè°åœæ°
typedef void (*SSPLinkCanlendarReciveEventCallBack)(void* pUserData);

//ææºæ¶éŽä¿¡æ¯åè°åœæ°
typedef void (*SSPLinkCanlendarReciveTimeCallBack)(DateInfo_t *pstPhoneDateInfo, void* pUserData);

/***************************************************************************************/


/***************************************************************************************/
//  ç­ä¿¡

ssp_uint8 iSms_iSendMsg(char* pNumberString, char* msg);

//éåç­ä¿¡(éå)
ssp_uint8 iSms_iReSendMsg(char* pNumberString, char* msg,char* pRankNumString);

//  æžç©ºä¿¡æ¯
ssp_uint8 iSms_iClearMsg();															
//æåŒDBïŒå? ææ²¡æMsgTableååå»ºMsgTable
ssp_uint8 iSms_iCreateMsgTable();							//	
//æIDå é€æå®æ¡è®°åœ
ssp_uint8 iSms_iDeleteMsgRecord(int iRank);

//æNumberå é€æå®æ¡è®°åœ å é€äžäžªäººçææç­ä¿¡
ssp_uint8 iSms_iDeleteOnePersonMsgRecord(char* pNum);		//	

//mailboxäž­ç¹å»listæånumberäžºpNumçè®°åœå¹¶æRankæåº
ssp_uint8 iSms_iOrderBynumberMsgRecord(char* pNum,PST_SMS_REPLY_INFOR_FRM pstSmsReplyInforFrm);	//	
//æ ¹æ®IDè¯»åinfor(èœ¬åçš)
ssp_uint8 iSms_iSelectInforByIDMsgRecord(int iRank,char** cMsgInfor);				//	
//ä»DBäž­è¯»ååºåšéšlistïŒæ¯äžªnumberåªè¯»åæ¶éŽæè¿çäžæ¡ïŒè¯»ånumberïŒnameïŒdateïŒtimeïŒreadstatusïŒ
ssp_uint8 iSms_iOrderByTimeMsgRecord(PST_SMS_LIST_INFO_FRM pstSmsListInforFrm);

//æ¥è¯¢MsgTableäž­æå€å°æ¡Numberäžéå€çMsg
ssp_int32 iSms_iSelectCountInMailBox();					//	
//æ¥è¯¢æå®Numberæ¶æå€å°æ¡Msg
ssp_int32 iSms_iSelectCountByNumberInReply(char *pNum);	//	

//æ ¹æ®Rankç¡®å®Result
ssp_uint8 iSms_iSelectResultByRankMsgRecord(int iRank,int  iExecStatus);//	
//æ ¹æ®NumberæŽæ°å·²è¯»æªè¯»ç¶æ
ssp_uint8 iSms_iUpdateReadStatusByNumber(char *pNumber);

ssp_uint8 iSms_iRequestPhoneDateTime(void);

ssp_uint8 iSms_iRequestAddresslist(void);

ssp_uint8 iSms_iRequestMsgDB(void);

ssp_uint8 iSms_iUnReadMsg(char *unReadNum);

//æ¥æ¶ç­ä¿¡åè°åœæ°
typedef void (*lpSmsReciveMsgCallBack)(PST_SMS_INFO pstSmsInfo,void* pUserData);

//ç­ä¿¡æ§è¡ç¶æåè°åœæ°
typedef void (*lpSmsSendStatusCallBack)(PST_SMS_STATUS_FRM pstSmsStatusFrm,void* pUserData);

//ç­ä¿¡åéç¶æåè°åœæ°(ææºäž»åšåèœ? æºåé)
typedef void (*lpSmsInitiativeSendCallBack)(PST_SMS_STATUS_FRM pstSmsStatusFrm,void* pUserData);

//ææºæ¶éŽä¿¡æ¯åè°åœæ°
typedef void (*lpSmsReciveTimeCallBack)(DateTimeInfo_t *pstPhoneDateInfo,void* pUserData);

//ææºéè®¯åœçåè°åœæ°
typedef void (*lpSmsReciveContactCallBack)(void* pUserData);

typedef void (*lpSmsReciveMsgDBRsp)(void* pUserData);

/***************************************************************************************/




/***************************************************************************************/
// å€©æ°æ¥å£

/************************************************************************/
/*
\ufffd\ufffd\u0221\ufffd\ufffd\u01f0\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetCurrentCityWeather();

/************************************************************************/
/* 
SSP_iWeather_GetCityWeather:\ufffd\ufffd\u0221\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03e2
\ufffd\ufffd\ufffd\ufffdcityCode	\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0435\u0133\ufffd\ufffd\u0434\ufffd\ufffd\ufffd
\ufffd\ufffd\ufffd\u0623\ufffd_SSP_OK	\ufffd\u0279\ufffd
	  \ufffd\ufffd\ufffd\ufffd		\u02a7\ufffd\ufffd
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetCityWeather(char* cityCode); 

/************************************************************************/
/*
\ufffd\ufffd\u0221ÿ\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetEverydayWeather(char* cityCode);

/************************************************************************/
/*
\ufffd\ufffd\u022124\u0421\u02b1\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_Get24hourWeather(char* cityCode);

/************************************************************************/
/*
\ufffd\ufffd\u0221\u0133\u04bb\ufffd\ufffd\ufffd\u06b5\ufffd\ufffd\ufffd\u03f8\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03e2
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetWeatherDetail(char* cityCode,ssp_uint8 dateIndex);


/************************************************************************/
/*
\ufffd\ufffd\u0221\ufffd\ufffd\ufffd\u0435\u013f\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03e2
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetAirQuality(char* cityCode);

/************************************************************************/
/*
\ufffd\ufffd\u0221\u05b8\ufffd\ufffd\ufffd\ufffd\u03e2
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetIndexData(char* cityCode);

/************************************************************************/
/*
\ufffd\ufffd\u0221\ufffd\ufffd\ufffd\u043f\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
\ufffd\ufffd\ufffd\ufffdAQI_RANK_BEST		\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffdó\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	  AQI_RAND_WORST	\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetAQIRank(ssp_uint8 flag);

/************************************************************************/
/*
\ufffd\ufffd\u0221\u0524\ufffd\ufffd\ufffd\ufffd\u03e2
*/
/************************************************************************/
ssp_uint8 SSP_iWeather_GetWarningInfo(char* cityCode);


/************************************************************************/
/*
SSP_vWeather_SetCityDbPath:\ufffd\ufffd\ufffdó\ufffd\ufffd\ufffd\ufffd\u0431\ufffd
\ufffd\ufffd\ufffd\ufffddbPath \ufffd\ufffd\u077f\ufffd\ufffd\u013c\ufffd·\ufffd\ufffd
*/
/************************************************************************/
void SSP_vWeather_SetCityDbPath(char* dbPath);

/************************************************************************/
/*
SSP_vWeather_GetCityList:\ufffd\ufffd\u0221\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0461\ufffd\ufffd\ufffd\u0431\ufffd
\ufffd\ufffd\ufffd\u0623\ufffd\ufffd\ufffd
*/
/************************************************************************/
PST_CITY_INFO_FRM SSP_vWeather_GetCityList(char* keyWord);

ssp_uint8 SSP_iWeather_GetWeatherSummary();

/************************************************************************/
/*
lpWeather_CityWeather:\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03e2\ufffd\u0635\ufffd\ufffd\ufffd\ufffd\ufffd
\ufffd\ufffd\ufffd\ufffdpstWeatherData	\ufffd\ufffd\ufffd\u0635\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u077d\u1e79\ufffd\ufffd\u05b8\ufffd\ufffd
	  pUserData			\ufffdû\ufffd\ufffd\ufffd\u0763\ufffd\u0368\ufffd\ufffdSSP_vWeather_RegiestCallBack \ufffd\u03b2\ufffdstCallBack.lParam \ufffd\ufffd\ufffd\ufffd\ufffd\u05b5
\ufffd\ufffd\ufffd\u0623\ufffd\ufffd\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_CityWeather)(PST_WEATHER_DATA pstWeatherData,void * pUserData);


/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0635\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_GetEverydayWeather)(PST_WEATHER_EVERYDAY_FRM pstWeatherEverydayFrm,void *pUserData);

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd24\u0421\u02b1\ufffd\ufffd\ufffd\ufffd\u0635\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_Get24hourWeather)(PST_WEATHER_24H_FRM pstWeather24hFrm,void* pUserData);

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03f8\ufffd\ufffd\u03e2\ufffd\u0635\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_GetWeatherDetail)(PST_WEATHER_DETAIL pstWeatherDetail,void* pUserData);

/************************************************************************/
/* 
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0635\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_GetAirQuality)(PST_AIR_QUALITY pstAirQuality,void* pUserData);

/************************************************************************/
/* 
\ufffd\ufffd\ufffd\ufffd\u05b8\ufffd\ufffd\u0635\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_GetIndexData)(PST_INDEX_DATA pstIndexData,void* pUserData);

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0635\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
typedef void (*lpWeather_GetAQIRank)(PST_AQI_RANK pstAQIRank,void* pUserData);

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\u0524\ufffd\ufffd\ufffd\ufffd\u03e2\ufffd\u0635\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
typedef void(*lpWeather_GetWarningInfo)(PST_WARNING_DATA pstWarningData,void* pUserData);

/*
å€©æ°æ? è? ä¿¡æ¯åè°åœæ°
åæ°ïŒweatherSummary å€©æ°æ? è? ä¿¡æ¯
     pUserData   çšæ·æ°æ®
*/
typedef void (*lpWeatherSummaryInfo)(PST_WEATHER_SUMMARY weatherSummary, void* pUserData);

/***************************************************************************************/
//  é³ä¹çžå³æ¥å£

/*
é³ä¹æ­æŸæåæ¥å£
åæ°ïŒplayFlag  æ­æŸææå
*/
void SSP_vMusic_PlayOrPause(ssp_uint8 playFlag);

/*
é³ä¹äžäžé? 
*/
void SSP_vMusic_Next();

/*
é³ä¹äžäžé? 
*/
void SSP_vMusic_Prev();




/************************************************************************/
/* Function Name : SSP_iMusic_Request_LocalSongList						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7ó±ŸµØž\E8\C7\FA\C1Ð±\ED							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_LocalSongList(ssp_int32 pageNum);


/************************************************************************/
/* Function Name : SSP_iMusic_Request_SelectList						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3\BE\ABÑ¡\BC\AF\C1Ð±\ED								*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_SelectList(ssp_int32 pageNum);


/***************************iGetFirstDayWeekNo*********************************************/
/* Function Name : SSP_iMusic_Request_SelectSongList					*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3\BE\ABÑ¡\BC\AF\B6\FE\BC\B6\C1Ð±\ED							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_SelectSongList(char* selectID);

/************************************************************************/
/* Function Name : SSP_iMusic_Request_ChangePlayMode					*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3\B8Ä±ä²¥\B7\C5Ä£Êœ							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_ChangePlayMode(ssp_int32 playMode);


/************************************************************************/
/* Function Name : SSP_iMusic_Request_AlbumList							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3×š\BC\AD\C1Ð±\ED								*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_AlbumList(ssp_int32 pageNum);


/************************************************************************/
/* Function Name : SSP_iMusic_Request_AlbumSongList						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3×š\BC\AD\B8\E8\C7\FA\C1Ð±\ED							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_AlbumSongList(char* albumID);


/************************************************************************/
/* Function Name : SSP_iMusic_Request_ArtistList						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3\D2\D5\C8\CB\C1Ð±\ED								*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_ArtistList(ssp_int32 pageNum);


/************************************************************************/
/* Function Name : SSP_iMusic_Request_ArtistSongList					*/
/* Author : zhangxiaorui												*/
/* Function Introduction :  \C7\EB\C7\F3\D2\D5\C8\CB\C8\C8\C3Åž\E8\C7\FA\C1Ð±\ED						*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_ArtistSongList(char* artistID);




/************************************************************************/
/* Function Name : SSP_iMusic_Request_LocalPic							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\B8\F9\BEÝž\E8\C7\FAÂ·\BE\B6\BB\F1È¡ÍŒÆ¬						*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_LocalPic(char* picAddr);



/************************************************************************/
/* Function Name : SSP_iMusic_Request_PlayLocalSong						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7ó²¥·Å±\BE\B5Øž\E8\C7\FA							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_PlayLocalSong(char* songID);



/************************************************************************/
/* Function Name : SSP_iMusic_Request_ExitPhoneAPP						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7\F3\CDË³\F6\CAÖ»\FA\B1\BE\B5\D8\D2\F4\C0\D6							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_ExitPhoneAPP();


/************************************************************************/
/* Function Name : SSP_iMusic_Request_PlayMode						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\C7\EB\C7ó²¥·\C5Ä£Êœ							*/
/* Data : 2016.03.19													*/
/************************************************************************/
ssp_int32 SSP_iMusic_PlayMode();

ssp_int32 SSP_iMusic_GetSongInfo();

ssp_int32 SSP_iMusic_WakeUp();

ssp_int32 SSP_iAssistant_LocalMusicRun();

#if 1 // for activate
ssp_uint8 SSP_iActivate_Start();
ssp_uint8 SSP_iActivate_Return();
#endif
// for vr
ssp_int32 SSP_iVR_Request_StartVr();
ssp_int32 SSP_iVR_Request_VoiceEnd();
ssp_int32 SSP_iVR_Request_StopVr();

/************************************************************************/
/* Function Name : lpMusic_Get_Wakeup_PhoneApp							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : \BBØµ\F7\BA\AF\CA\FD\A3\AC\BB\BD\D0\D1								*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_Wakeup_PhoneApp)(void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_Song_Info								*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\B2\A5\B7ÅµÄœ\DAÄ¿\D0\C5Ï¢					*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_Song_Info)(PST_SONG_INFO pstSongInfo,void* pUserData);



/************************************************************************/
/* Function Name : lpMusic_Get_LocalSongList							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\B1\BE\B5Øž\E8\C7\FA\C1Ð±\ED						*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_LocalSongList)(PST_LOCALSONG_LIST pstLocalSongList,void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_SelectList								*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\BE\ABÑ¡\BC\AF\C1Ð±\ED						*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_SelectList)(PST_SELECT_LIST pstSelectList,void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_SelectSongList							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\BE\ABÑ¡\BC\AF\B8\E8\C7\FA\C1Ð±\ED					*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_SelectSongList)(PST_SELECTSONG_LIST pstSelSongList,void* pUserData);



/************************************************************************/
/* Function Name : lpMusic_Get_PlayorPause								*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\B2\A5\B7\C5×ŽÌ¬							*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_PlayorPause)(ssp_int32 playStatus,ssp_int32 curTime,void* pUserData);



/************************************************************************/
/* Function Name : lpMusic_Get_Phone_PlayorPause						*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\B2\A5\B7\C5×ŽÌ¬							*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_Phone_PlayorPause)(ssp_int32 playStatus,ssp_int32 curTime,void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_AlbumList								*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC×š\BC\AD\C1Ð±\ED							*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_AlbumList)(PST_ALBUM_LIST pstAlbumList,void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_AlbumSongList							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC×š\BC\AD\B8\E8\C7\FA\C1Ð±\ED						*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_AlbumSongList)(PST_ALBUMSONG_LIST pstAlbumList,void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_ArtistList								*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\D2\D5\C8\CB\C1Ð±\ED							*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_ArtistList)(PST_ARTIST_LIST pstArtistList,void* pUserData);


/************************************************************************/
/* Function Name : lpMusic_Get_ArtistSongList							*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\D2\D5\C8Ëž\E8\C7\FA\C1Ð±\ED						*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_ArtistSongList)(PST_ARTISTSONG_LIST pstArtistSongList,void* pUserData);



/************************************************************************/
/* Function Name : lpMusic_Get_LocalPic									*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\C9\EA\C7\EB\B5Ä±\BE\B5Øž\E8\C7\FAÍŒÆ¬				*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_LocalPicture)(ssp_int32 ret,const char* picPath,void* pUserData);

/************************************************************************/
/* Function Name : lpMusic_Get_PlayMode									*/
/* Author : zhangxiaorui												*/
/* Function Introduction : 	\BBØµ\F7\BA\AF\CA\FD\A3\AC\C9\EA\C7\EB\B5Ä±\BE\B5Øž\E8\C7\FAÍŒÆ¬				*/
/* Data : 2016.03.19													*/
/************************************************************************/
typedef void (*lpMusic_Get_PlayMode	)(ssp_int32 ret,ssp_int32 playmode,void* pUserData);

/*
é³ä¹ç¶æåè°åœæ°
åæ°ïŒmusicInfo é³ä¹æ²ç®ä¿¡æ¯åæ­æŸç¶æ

*/
typedef void (*lpMusicInfo)(ST_MUSIC_INFO musicInfo,void* pUserData);

/***************************************************************************************/

/***************************************************************************************/
ssp_int32 SSP_iPhone_Call_Phone(char *phoneNumber);
ssp_int32 SSP_iPhone_Answer_Call();
ssp_int32 SSP_iPhone_Hang_Off();
ssp_int32 SSP_iPhone_Silence();
ssp_int32 SSP_iPhone_Address_List();
ssp_int32 SSP_iPhone_Call_Logs();
ssp_int32 SSP_iPhone_Received_Calls();
ssp_int32 SSP_iPhone_Dialed_Calls();
ssp_int32 SSP_iPhone_Missed_Calls();
ssp_int32 SSP_iPhone_Call_Reply_Sms(char *phoneNumber, char *msg);
ssp_int32 SSP_iPhone_Start_Recognize();
ssp_int32 SSP_iPhone_Stop_Speech();

typedef void (*lpPhone_CallFeedBack_Func)(ssp_int32 callStatus, ssp_int32 type, void* pUserData);
typedef void (*lpPhone_PhoneSendCallStatus_Func)(PST_CALL_INFO pStCallInfo, void* pUserData);
typedef void (*lpPhone_Address_List)(char *addresslist, void* pUserData);
typedef void (*lpPhone_Call_Logs)(PST_CALL_LIST_INFO_FRM pStCalListInfoFrm, void* pUserData);
typedef void (*lpPhone_Received_Calls)(PST_CALL_LIST_INFO_FRM pStCalListInfoFrm, void* pUserData);
typedef void (*lpPhone_Dialed_Calls)(PST_CALL_LIST_INFO_FRM pStCalListInfoFrm, void* pUserData);
typedef void (*lpPhone_Missed_Calls)(PST_CALL_LIST_INFO_FRM pStCalListInfoFrm, void* pUserData);
typedef void (*lpPhone_Call_Reply_Sms)();
//typedef void (*lpPhone_Send_Call_Phone)();
typedef void (*lpPhone_Start_Recognize)(int ret, void* pUserData);
typedef void (*lpPhone_Voice_Start)(void* pUserData);
typedef void (*lpPhone_Voice_End)(void* pUserData);
typedef void (*lpPhone_Voice_Result)(int ret, char *voiceData, void* pUserData);

#if 1 // for activate
typedef void (*lpAssistant_Activate_Status)(int status, void* pUserData);
#endif

typedef void (*lpVr_Status)(VR_STATUS status, int errorCode, void* pUserData);   // for vr

typedef void (*lpVr_Start_App)(int type, char * appid, void* pUserData);   // for vr
#if 1 // for upgrade
typedef void (*lpAssistant_Upgrade_Status)(int status, void* pUserData);
#endif

typedef void (*lpAssistant_MusicAppRun)(char * appId, char * appName, char * iconPath, void * pUserData);

/***************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif
