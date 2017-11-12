#ifndef _SSP_ASSIST_STRUCT_H_
#define _SSP_ASSIST_STRUCT_H_

//返回值
#define _SSP_OK						0x00
#define _SSP_ERROR					0x01

// 注册回调函数宏
enum CB_ASSISTANT_MARCO
{	
	CB_ASSISTANT_CONNECT_STATUS	= 0x01,
	CB_ASSISTANT_GET_PHONE_APP_DETAIL,
	CB_ASSISTANT_SYNC_APP_FROM_PONE,
	CB_ASSISTANT_PHONE_APP_ICON_PATH,
	CB_ASSISTANT_INIT_LIST_PROCESS,
	CB_ASSISTANT_APP_CONTEXT_PIC,
	CB_ASSISTANT_RUNPROCESS,
	CB_ASSISTANT_MIRROR_APP_ABNORMAL,
	CB_ASSISTANT_PHONE_APP_CHANGED,
	CB_ASSISTANT_AUDIO_STATUS,
	CB_ASSISTANT_MIRROR_STATE,
	CB_ASSISTANT_MIRROR_ENABLE_STATUS,
	CB_MUSIC_INFO,
	CB_CALENDAR_EVENT_CALLFEEDBACK,
	CB_SMS_RECIVE_MSG,
	CB_SMS_SEND_STATUS,		  
	CB_SMS_INITIATIVE_STATUS, 
	CB_SMS_RECIVE_DATETIME,
	CB_SMS_RECIVE_CONTACT,
	CB_SMS_RECIVE_MSGDB,
	CB_CALENDAR_TIME_CALLFEEDBACK,
	CB_CONTACT_RECIVE_LIST,  // add by taoms for 50
	CB_CONTACT_ICONPATH,
	CB_CONTACT_CALLSTATE,
    CB_WEATHER_SUMMARY_INFO,
	CB_WEATHER_GET_CITY_WEATHER,
	CB_WEATHER_GET_EVERYDAY_WEATHER,
	CB_WEATHER_GET_24HOUR_WEATHER,
	CB_WEATHER_GET_WEATHER_DETAIL,
	CB_WEATHER_GET_AIR_QUALITY,
	CB_WEATHER_GET_INDEXDATA,
	CB_WEATHER_GET_AQIRANK,
	CB_WEATHER_GET_WARNING_INFO,
	//CB_WEATHER_PHONE_APP_RUN,
	CB_MUSIC_SONG_INFO,
	CB_MUSIC_WAKEUP,
	CB_MUSIC_LOCALSONGLIST,
	CB_MUSIC_SELECTLIST,
	CB_MUSIC_SELECTSONGLIST,
	CB_MUSIC_PLAYORPAUSE,
	CB_MUSIC_PHONE_PLAYORPAUSE,
	CB_MUSIC_ALBUMLIST,
	CB_MUSIC_ALBUMSONGLIST,
	CB_MUSIC_ARTISTLIST,
	CB_MUSIC_ARTISTSONGLIST,
	CB_MUSIC_LOCALPICTURE,
	CB_MUSIC_PLAYMODE,
	
    CB_PHONE_CALLFEEDBACK,
    CB_PHONE_ADDRESS_LIST,
    CB_PHONE_CALL_LOGS,
    CB_PHONE_RECEIVED_CALLS,
    CB_PHONE_DIALED_CALLS,
    CB_PHONE_MISSED_CALLS,
    CB_PHONE_CALL_REPLY_SMS,
    CB_PHONE_PHONE_SEND_CALLSTATUS,
    CB_PHONE_START_RECOGNIZE,
    CB_PHONE_VOICE_START,
    CB_PHONE_VOICE_END,
    CB_PHONE_VOICE_RESULT,

    CB_ASSISTANT_DISPLAY_STATE,
    CB_ASSISTANT_AUDIO_STATE,
    CB_ASSISTANT_VOL_CHANGE,
    CB_ASSISTANT_MUTE_STATE,
    CB_ASSISTANT_BT_STATE,
    CB_ASSISTANT_HARDKEY_TYPE,
    CB_ASSISTANT_SET_LANGUAGE,
    CB_ASSISTANT_SET_SD_STATE,
    CB_ASSISTANT_SET_AUX_STATE,
#if 1 // for activate
    CB_ASSISTANT_ACTIVATE_STATUS,
#endif

    CB_VR_STATUS,   // for vr
    CB_VR_START_APP,    // for vr
#if 1 // for upgrade
	CB_ASSISTANT_SUBAPPPROCESSEXIT,
    CB_ASSISTANT_UPGRADE_STATUS,
#endif
    CB_ASSISTANT_MUSIC_APP_RUN,
};

#if 1 // for activate
typedef enum
{
    ACTIVATE_STATUS_ENABLE = 0,
    ACTIVATE_STATUS_DISABLE,
    ACTIVATE_STATUS_READY,
    ACTIVATE_STATUS_DOING,
    ACTIVATE_STATUS_STEP_1,
    ACTIVATE_STATUS_STEP_2,
    ACTIVATE_STATUS_STEP_3,
    ACTIVATE_STATUS_SUCCESSFUL,
    ACTIVATE_STATUS_FAILED,
} ACTIVATE_STATUS;
#endif

// for vr
typedef enum
{
    VR_STATUS_NO_NET,
    VR_STATUS_STARTING,
    VR_STATUS_START_ERROR,
    VR_STATUS_LISTENING,
    VR_STATUS_UPLOADING,
    VR_STATUS_RECOGNIZING,
    VR_STATUS_FAILED,
    VR_STATUS_OVER,
} VR_STATUS;
#if 1 //for upgrade
typedef enum
{
    UPGRADE_STATUS_DISABLE = 0, //不升级
    UPGRADE_STATUS_DOING,       //升级中
    UPGRADE_STATUS_FAILED,      //升级失败
} SSP_UPGRADE_STATUS;
#endif

// 连接状???
//enum CONNECT_STATUS
//{
//	CONN_STATUS_CONNECTED = 0x00,
//	CONN_STATUS_DISCONNECT,
//	CONN_STATUS_CONN_FAIL,
//	CONN_STATUS_CONNECTING,
//	CONN_STATUS_USB_DETACH
//};

enum MIRROR_ENABLE_STATUS
{
    MIRROR_STATUS_ENABLE,
    MIRROR_STATUS_DISABLE
};

enum AUDIO_STATUS
{
	AUDIO_BT_OK = 0x00,
	AUDIO_BT_NOT_SAME,
	AUDIO_USB_OK,
	AUDIO_NOT_WORK
};

// 初始化应用列表状态
enum INIT_ASSIST_STATUS
{
    INIT_ASSIST_STATUS_START = 0x00,
    INIT_ASSIST_STATUS_FAILTH,
    INIT_ASSIST_STATUS_SUCCESSFUL,
};
#if 1 //process init
enum INIT_ASSIST_PROCESS
{
    INIT_ASS_PROCESS_DISCONNECT = -1,
    INIT_ASS_PROCESS_CONNECT = 0x00,
    INIT_ASS_PROCESS_LIST, //1
    INIT_ASS_PROCESS_APP_ICON,//2
    INIT_ASS_PROCESS_APP,//3
    INIT_ASS_PROCESS_TIME,//4
    INIT_ASS_PROCESS_SMS_DB,//5
    INIT_ASS_PROCESS_CALENDAR_DB,//6
    INIT_ASS_PROCESS_MUSIC_INFO,//7
    INIT_ASS_PROCESS_WEATHER_INFO,//8
    INIT_ASS_PROCESS_TOTAL//9
};
#endif
#if 1 // diff 20160905
enum INIT_ASSIST_STRING
{
    INIT_ASSIST_STRING_INVALID = 0x00,
    INIT_ASSIST_STRING_PROCESS_LIST, //正在加载应用列表
    INIT_ASSIST_STRING_PROCESS_APP_ICON,    //正在获取应用图标
    INIT_ASSIST_STRING_PROCESS_APP, //正在同步应用
    INIT_ASSIST_STRING_PROCESS_TIME,    //正在同步时间
    INIT_ASSIST_STRING_PROCESS_SMS_DB,  //正在获取短信记录
    INIT_ASSIST_STRING_PROCESS_CALENDAR_DB, //正在获取日历事件
    INIT_ASSIST_STRING_PROCESS_MUSIC_INFO,  //正在获取音乐信息
    INIT_ASSIST_STRING_PROCESS_WEATHER_INFO,    //正在获取天气信息
    INIT_ASSIST_STRING_ERROR_PHONE_APP_FAILED,   //手机助手启动失败，请扫码安装手机助手并允许其运行
    INIT_ASSIST_STRING_ERROR_NONE_SUPPORT,  //互联初始化失败，您的手机系统可能不被支持
    INIT_ASSIST_STRING_ERROR_CONNECT_FAILED,  //互联初始化失败，请尝试重新连接USB
    INIT_ASSIST_STRING_ERROR_LIST,  //应用列表加载失败，请尝试重新连接USB
};
#endif
enum  MIRROR_STATUS
{
	MIRROR_ON_OK,
	MIRROR_OFF_OK,
	MIRROR_NG
};

enum AQI_RANK
{
	AQI_RANK_BEST = 0,
	AQI_RAND_WORST
};

#define  MAX_SSP_STRING_LEN			512
#define DEFAULT_NUMMBER_SIZE	32
#define DEFAULT_NAME_LEN    32
#define DEFAULT_TIME_LEN    16
#define DEFAULT_MSGDATA_LEN    1024
#define DEFAULT_DATE_LEN    16
#define DEFAULT_SMSID_LEN    16
#define DEFAULT_MSGID_LEN    8
#define DEFAULT_MSGDATE_LEN    16
#define DEFAULT_MSGTIME_LEN     16

#define DEFAULT_ID_LEN    16
#define DEFAULT_TYPE_LEN    32
#define DEFAULT_GROUPNAME_LEN    4
#define DEFAULT_SMS_LEN    100
#define DEFAULT_WCHAR_LEN    4

// 重定义数据类型
typedef unsigned char	ssp_uint8;
typedef char			ssp_int8;
typedef unsigned short	ssp_uint16;
typedef short			ssp_int16;
typedef unsigned int	ssp_uint32;
typedef int				ssp_int32;
typedef unsigned long	ssp_uint64;
typedef long			ssp_int64;
typedef char			ssp_string[MAX_SSP_STRING_LEN];

typedef signed int sint;
typedef unsigned char uchar;
typedef signed char schar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long ulint;
typedef	int Boolean;

typedef unsigned int		AL_UINT32;
typedef int					AL_INT32;
typedef unsigned short		AL_UINT16;
typedef short				AL_INT16;
typedef unsigned char		AL_UINT8;
typedef char				AL_INT8;
typedef float				AL_FLOAT;
typedef unsigned long		AL_UINT64;
typedef long				AL_INT64;

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILURE
#define FAILURE -1
#endif

#ifndef AL_ERROR
#define AL_ERROR   1
#endif

#ifndef AL_OK
#define AL_OK     0
#endif

#define  AL_ER_REPORT_FORMAT			0x20
#define  AL_ER_SEND_FORMAT					0x21
#define  AL_ER_NET_OVERTIME					0x22
#define  AL_ER_NEW_TYPE_NOT_EXIST	0x23
#define  AL_ER_WEATHER_CITY					0x24
#define  AL_ER_REQUEST_SERVER			0x25
#define  AL_ER_NEWS_NO_ITEM				0x26
#define  AL_ER_ALLOC_MEMORY				0x27
#define  AL_ER_MUSIC_NO_PIC					0x28
#define  AL_ER_MUSIC_NO_PIC					0x28
#define  AL_ER_OPEN_FILE							0x29
#define  AL_ER_VR_OVERTIME					0x01
#define  AL_EV_VR_NOT_IDENTIFIED			0x02
#define  AL_ER_STOCK								0x2a
#define  AL_ER_MAP_START_NAVI				0x2b
#define  AL_ER_MAP_STOP_NAVI				0x2c


#define CONTACT_ICON_ID_LEN 128
#define CONTACT_ICON_PATH_LEN 256

/*#define  WEATHER_ICON_SUNNY			0x01*/

// 注册回调函数数据类型
typedef struct _stCallBack
{
	ssp_uint8 funcType;						/*type of callback*/
	void *pFunc;							/*callback function*/
	void * lParam;							/*callback function param*/
}ST_CALLBACK,PST_CALLBACK;

// 本地应用数据结构
typedef struct _stLocalApp
{
	char id[61];							// appid
	ssp_int32 type;							// 应用类型 0 ssplink 1 mirrorlink
	char name[61];							// 应用名称
	char ExeName[61];						// 可执行文件名称
	char ExePath[255];						// 可执行文件全路径
	char appPath[255];						// 应用路径
    char iconPath[255];						// 应用图全路径
	char version[31];						// 版本号
	ssp_int32 isUpdate;						// 是否可以被更新
	ssp_int32 isPreInstall;					// 是否是预装应用
}ST_LOCALAPP,*PST_LOCALAPP;

// 本地应用列表数据结构
typedef struct _stLocalAppList
{
	ssp_uint8 ret;							// 列表返回值 成功 _SSP_OK ，失败 _SSP_ERROR
	ssp_int32 count;						// 应用个数
	ssp_int32 preInstallCount;				// 预装应用个数
	PST_LOCALAPP pstLocalApp;				// 应用数组
}ST_LOCALAPP_LIST,*PST_LOCALAPP_LIST;


#define MUSIC_NAME_LEN 128
#define MUSIC_SINGER_LEN 128
#define MUSIC_PICURL_LEN 256
#define MUSIC_ID_LEN 128
#define MUSIC_TITLE_LEN 128
#define MUSIC_AUTHOR_LEN 128
#define MUSIC_ICONPATH_LEN 256
#define MUSIC_SONGADD_LEN 256
#define MUSIC_DESCR_LEN 256
#define MUSIC_RELEASETIME_LEN 128


typedef struct _stMusicInfo
{
	ssp_uint8 ret;							// 结果返回值
    char programeId[MUSIC_ID_LEN];					// 节目id
	char title[MUSIC_TITLE_LEN];							// ? ?题
	char author[MUSIC_AUTHOR_LEN];						// 作者
	char iconId[MUSIC_ID_LEN];						// 图片id
	char iconPath[MUSIC_ICONPATH_LEN];						// icon全路径
	ssp_uint8 playState;					// 播放列表
}ST_MUSIC_INFO,*PST_MUSIC_INFO;

/************************************************************************/
/*
本地歌曲
*/
/************************************************************************/
typedef struct _stLocalSongInfo
{
    char songID[MUSIC_ID_LEN];				// 歌曲id
	char songName[MUSIC_NAME_LEN];				// 歌曲名称
	char singer[MUSIC_SINGER_LEN];				// 歌手名
	char songAdd[MUSIC_SONGADD_LEN];				// 手机中存放位置
}ST_LOCALSONG_INFO,*PST_LOCALSONG_INFO;

typedef struct _stLocalSongList
{
	ssp_int32 ret;							// 结果 0成功 1失败
    ssp_int32 allPageNumber;
    ssp_int32 count;
    ssp_int32 pageNumber;						// 歌曲个数
	PST_LOCALSONG_INFO pstLocalSongInfo;	// 列表内容
}ST_LOCALSONG_LIST,*PST_LOCALSONG_LIST;



/************************************************************************/
/*
精选歌曲
*/
/************************************************************************/
typedef struct _stSelectInfo
{
    char selectID[MUSIC_ID_LEN];				// 精选集ID
	char selectName[MUSIC_NAME_LEN];			// 精选集名称
	char author[MUSIC_AUTHOR_LEN];				// 作者
	char selectDescr[MUSIC_DESCR_LEN];			// 描述
	char picUrl[MUSIC_PICURL_LEN];				// 精选集封面url
}ST_SELECT_INFO,*PST_SELECT_INFO;

typedef struct _stSelectList
{
	ssp_int32 ret;						// 结果 0成功 1 О?
	ssp_int32 pageNum;					// 页码
	ssp_int32 count;					// 个 ?
	PST_SELECT_INFO pstSelectInfo;		// 精选集列表内容
}ST_SELECT_LIST,*PST_SELECT_LIST;



/************************************************************************/
/*
精选集二级列表
*/
/************************************************************************/
typedef struct _stSelectSongList
{
	ssp_int32 ret;							// 结果 0成功 1失败
	char selectID[MUSIC_ID_LEN];						// 精选集id
	ssp_int32 count;						// 个数
	PST_LOCALSONG_INFO pstSelSongInfo;		// 精选集二级歌曲列表内容
}ST_SELECTSONG_LIST,*PST_SELECTSONG_LIST;




/************************************************************************/
/*
专辑
*/
/************************************************************************/
typedef struct _stAlbumInfo
{
    char albumID[MUSIC_ID_LEN];				// 专辑id
	char albumName[MUSIC_NAME_LEN];			// 专辑名称
	char singer[MUSIC_SINGER_LEN];				// 歌手名称
	char releaseTime[MUSIC_RELEASETIME_LEN];			// 发布时间
	char picUrl[MUSIC_PICURL_LEN];				// 图片url
}ST_ALBUM_INFO,*PST_ALBUM_INFO;

typedef struct _stAlbumList
{
	ssp_int32 ret;					// 结果 0成功 1 О?
	ssp_int32 pageNum;				// 页码
	ssp_int32 count;				// 个 ?
	PST_ALBUM_INFO pstAlbumInfo;	// 列表内容
}ST_ALBUM_LIST,*PST_ALBUM_LIST;



/************************************************************************/
/*
专辑歌曲列表
*/
/************************************************************************/
typedef struct _stAlbumSongList
{
	ssp_int32 ret;						// 结果 0成功 1失败
       char albumID[MUSIC_ID_LEN];				// 专辑id
	ssp_int32 count;					// 个数
	PST_LOCALSONG_INFO pstAlbumSongInfo;	// 列表内容
}ST_ALBUMSONG_LIST,*PST_ALBUMSONG_LIST;



/************************************************************************/
/*
艺人
*/
/************************************************************************/
typedef struct _stArtistInfo
{
    char artistID[MUSIC_ID_LEN];				// 艺人id
	char artistName[MUSIC_NAME_LEN];			// 艺人名称
	char picUrl[MUSIC_PICURL_LEN];				// 图片url
}ST_ARTIST_INFO,*PST_ARTIST_INFO;

typedef struct _stArtistList
{
	ssp_int32 ret;					// 结果 0成功 1 О?
	ssp_int32 pageNum;				// 页码
	ssp_int32 count;				// 个 ?
	PST_ARTIST_INFO pstArtistInfo;	// 列表内容
}ST_ARTIST_LIST,*PST_ARTIST_LIST;



/************************************************************************/
/*
艺人热门歌曲列表
*/
/************************************************************************/
typedef struct _stArtistSongList
{
	ssp_int32 ret;					// 结果 0成功 1失败
	char artistID[MUSIC_ID_LEN];				// 艺人ID
	ssp_int32 count;				// 个数
	PST_LOCALSONG_INFO pstArtistSong;	// 列表内容
}ST_ARTISTSONG_LIST,*PST_ARTISTSONG_LIST;



/************************************************************************/
/*
正在播放的歌曲信息
*/
/************************************************************************/
typedef struct _stSongInfo
{
	ssp_int32 songType;				// 歌曲类型 0本地，1网络
	ssp_int32 playStatus;			// 播放状态，0播放，1暂停
	ssp_int32 curTime;				// 已播放时长（s）
	ssp_int32 totalTime;			// 总时长（s）
	char songName[MUSIC_NAME_LEN];				// 歌曲名
	char singer[MUSIC_SINGER_LEN];				// 歌手名
	char picUrl[MUSIC_PICURL_LEN];				// 图片url/歌曲路径
    char songID[MUSIC_ID_LEN];
}ST_SONG_INFO,*PST_SONG_INFO;


//通讯录详细信息
typedef struct _stContact_Data
{
    char ID[DEFAULT_ID_LEN];             // 联系人id
    char Number[DEFAULT_NUMMBER_SIZE];   // 号? ?
    char Type[DEFAULT_TYPE_LEN];         // 类型
    char Name[DEFAULT_NAME_LEN];         // 姓名
    char NameSZM[DEFAULT_NAME_LEN];      // 姓名首字母
    char GroupName[DEFAULT_GROUPNAME_LEN];    // 组别
}ST_CONTACT_DATA,*PST_CONTACT_DATA;

typedef struct _stContact_DataFrm
{
	ssp_uint8	result;							// 返回结果
	ssp_uint32  count;							// 个数
	PST_CONTACT_DATA pstContactData;			// 数组
}ST_CONTACT_DATA_FRM,*PST_CONTACT_DATA_FRM;

typedef struct _stCallStateInfo
{
	ssp_uint8 state;								// 通话状态
	char Number[31];								// 电话号? ?
	char name[256];									// 姓名
}ST_CALL_STATE_INFO,*PST_CALL_STATE_INFO;



/*************************************************
 阳历1900.1.1
 在阳历为1900.1.31  时阴历为1900.1.1 即1900年正月初一
 ****************************************************/
#define CALC_MIN_YEAR	1900				//日期计算开始年
#define CALC_MAX_YEAR	2050				//日期计算结束年
#define CALC_MIN_MONTH 1					//日期计算开始月
#define CALC_MAX_MONTH 12					//日期计算结束月
#define CALC_MIN_DAY 1						//日期计算开始日
#define CALC_MAX_DAY 31						//日期计算结束日
#define CALC_MIN_HOUR 0						//日期计算开始小时
#define CALC_MAX_HOUR 23					//日期计算结束小时
#define CALC_MIN_MINUTE 0					//日期计算开始分钟
#define CALC_MAX_MINUTE 59					//日期计算结束分钟
#define CALC_MIN_WEEK 0						//日期计算开始周
#define CALC_MAX_WEEK 6						//日期计算结束周
#define LUNAR_MONTH_DAYS_B 30				//农历大月的天数
#define LUNAR_MONTH_DAYS_S 29				//农历小月的天数
#define YEAR_DAYS 365						//阳历年总天数
#define LEAP_YEAR_DAYS 366					//闰年总天数
#define TWO_MONTH_DAYS 28					//二月份的天数
#define LEAP_TWO_MONTH_DAYS 29				//闰年二月份的天数
#define SOLAR_MAX 24						//24节气
#define HEAV_EAR_LENGTH			10			//天干地支字符串长度
#define DEFAULT_TITLE_SIZE 512
#define DEFAULT_LOCATION_SIZE 512
#define DEFAULT_REMARKS_SIZE 2048
#define DEFAULT_SIZE 512
#define DEFAULT_MAX_MESSAGE 100

/*阳历和农历的日期结构体声明*/
typedef struct Lunar_DateInfo_t {
	ssp_uint32 year; 										/*	农历的年	*/
	ssp_uint8 month; 									/*	农历的月	*/
	ssp_uint8 day; 										/*	农历的日	*/
	ssp_int8 solarTermIndex; 							/*	节气编号	*/
	ssp_uint8 isLeapMonthDay; 						/* 闰月日 0：不是，1：是 */
	ssp_uint8	DaysOfMonth;							/* 当前月天数 */
	ssp_int8 holidayIndex; 							/*	农历的假日编号	*/
	ssp_uint8 isHoliday; 								/*	农历的假日休息日判定 0：不休息，1：休息	*/
	char HeavenlyEarthly[HEAV_EAR_LENGTH];			/*	天干地支字符串	*/
} Lunar_DateInfo_t;

typedef struct DateInfo_t {
	ssp_uint32 year; 											/*	阳历的年	*/
	ssp_uint8 month; 										/*	阳历的月	*/
	ssp_uint8 day; 											/*	阳历的日	*/
	ssp_uint8 hour; 										/*	阳历的小时	*/
	ssp_uint8 minute; 										/*	阳历的分钟	*/
	ssp_uint8 week; 										/*	阳历的星期	*/
	ssp_int8 holidayIndex; 								/*	阳历的假日编号	*/
	ssp_uint8 isHoliday; 									/*	阳历的假日休息日判定 0：不休息，1：休息	*/
} DateInfo_t;


typedef struct Month_Calendar_Item_t {
	DateInfo_t stDate;
	Lunar_DateInfo_t stLunarDate;
} Month_Calendar_Item_t;


/************************
*	Event info 	*
************************/
typedef struct Message_t{
	DateInfo_t stStartDateInfo;
	DateInfo_t stEndDateInfo;
	ssp_int32  iAllDay;
	char cTitle[DEFAULT_TITLE_SIZE];
	char cDetail[DEFAULT_REMARKS_SIZE];
	char cLocation[DEFAULT_LOCATION_SIZE];
}Message_t;


typedef struct dateTimeInfo_t {
	ssp_int32 year; 											/*	年	*/
	ssp_uint8 month; 										/*	月	*/
	ssp_uint8 day; 											/*	日	*/
	ssp_uint8 hour; 											/*	小时	*/
	ssp_uint8 minute; 										/*	分钟	*/
} DateTimeInfo_t;


/*------------------SMS--------------------------------*/
typedef struct _stSmsInfo
{
	char number[DEFAULT_NUMMBER_SIZE]; // 收件人号? ?
	char smsID[DEFAULT_SMSID_LEN]; // 短信id
	char msgData[DEFAULT_MSGDATA_LEN]; // 信息内容
	char Date[DEFAULT_DATE_LEN];
	char Time[DEFAULT_TIME_LEN];
	char name[DEFAULT_NAME_LEN];
}ST_SMS_INFO,*PST_SMS_INFO;

typedef struct _stSmsStatus
{
    //ssp_int32 rankNum;
	char smsNum[DEFAULT_NUMMBER_SIZE];
	char smsID[DEFAULT_SMSID_LEN];
	char name[DEFAULT_NAME_LEN];
	ssp_uint8 SimStatus;
	ssp_uint8 status;
	char Date[DEFAULT_DATE_LEN];
	char Time[DEFAULT_TIME_LEN];
}ST_SMS_STATUS,*PST_SMS_STATUS;

typedef struct _stSmsStatusFrm
{
	ssp_uint8 result;
	ssp_uint8 count;
	PST_SMS_STATUS pstSmsStatus;
}ST_SMS_STATUS_FRM,*PST_SMS_STATUS_FRM;

// typedef struct _stSmsOtherInfor
// {
// 	char Date[11];
// 	char Time[9];
// 	AL_UINT8 ReadStatus;
// 	AL_UINT8 Type;
// 
// }ST_SMS_OTHER_INFOR,*PST_SMS_OTHER_INFOR;
typedef struct  
{
	char cStrTest[DEFAULT_MSGDATA_LEN];
	char iName[DEFAULT_NAME_LEN];
	char iNumber[DEFAULT_NUMMBER_SIZE];
	char cMsgID[DEFAULT_MSGID_LEN];
	ssp_int32 iMsgType ;//0 为接收到的Msg，1 为发送出的Msg
	ssp_int32 iSimStatus;
	ssp_int32	iExecStatus;
	ssp_int32	iResult;
	ssp_int32	iReadStatus;
	ssp_int32 Rank;
	char cMsgDate[DEFAULT_MSGDATE_LEN];
	char cMsgTime[DEFAULT_MSGTIME_LEN];
}ST_SMS_REPLY_INFOR,*PST_SMS_REPLY_INFOR;


typedef struct _stSms_Reply_InfoFrm
{
	ssp_uint8		 result;
	ssp_uint32		 count;
	PST_SMS_REPLY_INFOR pstSmsReplyInfor;
}ST_SMS_REPLY_INFOR_FRM,*PST_SMS_REPLY_INFOR_FRM;

typedef struct {
	char cMsgListName[DEFAULT_NAME_LEN];
	char cMsgListNum[DEFAULT_NUMMBER_SIZE];
	char cMsgListDate[DEFAULT_MSGDATE_LEN];
	char cMsgListTime[DEFAULT_MSGTIME_LEN];
	char pcMsgInfo[DEFAULT_MSGDATA_LEN];
	ssp_int32  iReadStatus;//是否已读 0未读 1是已读
	ssp_int32 iSimStatus;	//
	ssp_int32	iExecStatus;//
	ssp_int32  iSendResult; //是否发送成功
}ST_SMS_LIST_INFOR,*PST_SMS_LIST_INFOR;


typedef struct _stSms_List_InfoFrm
{
	ssp_uint8		 result;
	ssp_uint32		 count;
	PST_SMS_LIST_INFOR pstSmsListInfor;
}ST_SMS_LIST_INFO_FRM,*PST_SMS_LIST_INFO_FRM;

typedef struct  _stContactIconData
{
	char iconid[CONTACT_ICON_ID_LEN];
	char iconPath[CONTACT_ICON_PATH_LEN];
}ST_CONTACT_ICON_DATA,*PST_CONTACT_ICON_DATA;

typedef struct  _stContactIconFrm
{
	ssp_uint8 ret;
	ssp_int32 count;
	PST_CONTACT_ICON_DATA pstContactIconData;
}ST_CONTACT_ICON_FRM,*PST_CONTACT_ICON_FRM;

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
(issssissssssis)
*/
/************************************************************************/
#define WEATHER_DATE_LEN 32 //2012-11-22
#define WEATHER_TEMP_LEN 32
#define WEATHER_CITYNAME_LEN 32
#define WEATHER_CITYAREA_LEN 320
#define WEATHER_CITYCODE_LEN 16
#define WEATHER_WARNING_CONTEXT_LEN 320
#define WEATHER_WARNING_TITLE_LEN 32
#define WEATHER_WARNING_LEVEL_LEN 16
#define WEATHER_CITY_LEN 32
#define WEATHER_WARNING_STATUS_LEN 32
#define WEATHER_REPORT_TIME_LEN 64
#define WEATHER_TIME_LEN 16
#define WEATHER_SUNRISE_TIME_LEN 32
#define WEATHER_SUNSET_TIME_LEN 32
#define WEATHER_WEEK_LEN 16
#define WEATHER_REP_TIME_LEN 32
#define WEATHER_WEA_WARNING_LEN 64
#define WEATHER_WEATHER_LEN 32
#define WEATHER_WIND_LEN 64
#define WEATHER_FESTIVAL_LEN 32
#define WEATHER_TIPS_LEN 128
#define WEATHER_INDEX_LEN 16
#define WEATHER_AQI_ONEDAY 24
#define WEATHER_AQI_LEVEL_LEN 32
#define WEATHER_AQI_INFO_LEN 128
#define WEATHER_WET_LEN 8
#define WEATHER_KEYWORD_LEN 64

typedef struct _stWeatherSummary
{
	ssp_uint8 ret;							// 获取信息返回值
	ssp_uint8 weatherId;					// 天气id
    char date[WEATHER_DATE_LEN];              				// 发布日期
    char sNowTemp[WEATHER_TEMP_LEN];                          // 当前温度 12℃
	char cityName[WEATHER_CITYNAME_LEN];							// 城市名称
}ST_WEATHER_SUMMARY,*PST_WEATHER_SUMMARY;

typedef struct _stWeatherData
{
	ssp_uint8 result;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd _SSP_OK \u03aa\ufffd\u0279\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u02a7\ufffd\ufffd
	char cityCode[WEATHER_CITYCODE_LEN];						// \ufffd\ufffd\ufffd\u0434\ufffd\ufffd\ufffd
	char repTime[WEATHER_REP_TIME_LEN];                       // \u0524\ufffd\ufffd\u02b1\ufffd\ufffd
    char weaWarring[WEATHER_WEA_WARNING_LEN];                    // \ufffd\ufffd\ufffd\ufffd\u0524\ufffd\ufffd
	char todayWeather[WEATHER_WEATHER_LEN];					// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd  1   \ufffd\ufffd\ufffd\ufffd \ufffd\ufffd\ufffd\ufffd\u05ea\ufffd\ufffd\ufffd\ufffd
    char nowTemp[WEATHER_TEMP_LEN];                       // \ufffd\ufffd\u01f0\ufffd?\ufffd
    ssp_uint8 weatherID;                    // \ufffd\ufffd\u01f0\ufffd\ufffd\ufffd\ufffdid
    char cityName[WEATHER_CITYNAME_LEN];                      // \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
    char chineseDate[WEATHER_DATE_LEN];                   // \u0169\ufffd\ufffd
    char highTemp[WEATHER_TEMP_LEN];                      // \ufffd\ufffd\ufffd\ufffd?\ufffd
    char lowTemp[WEATHER_TEMP_LEN];                       // \ufffd\ufffd\ufffd\ufffd?\ufffd
    char wet[WEATHER_WET_LEN];                            // \u02aa\ufffd\ufffd 
	char wind[WEATHER_WIND_LEN];							// \ufffd\ufffd 1
    ssp_uint32 aqi;                          // aqi   1
	char aqiLevel[WEATHER_AQI_LEVEL_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd 1
}ST_WEATHER_DATA,*PST_WEATHER_DATA;

/************************************************************************/
/* 
\u0524\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
(iia(ssiiiis))
*/
/************************************************************************/
typedef struct _stWeather_EveryDay
{
	char date[WEATHER_DATE_LEN];							// \ufffd\ufffd\ufffd\ufffd	
	char week[WEATHER_WEEK_LEN];							// \ufffd\ufffd\ufffd\ufffd 1
	ssp_int32 highTemp;						// \ufffd\ufffd\ufffd\ufffd?\ufffd    int
	ssp_int32 lowTemp;						// \ufffd\ufffd\ufffd\ufffd?\ufffd    int
	ssp_uint8 dayWeatherID;					// \ufffd\u057c\ufffd\ufffd\ufffd\ufffd\ufffdid
	ssp_uint8 nightWeatherID;				// \u04b9\ufffd\ufffd\ufffd\ufffd\ufffd\ufffdid
	char windPower[WEATHER_WIND_LEN];						// \ufffd\ufffd 1 \ufffd\ufffd\ufffd\u78fa\ufffd\ufffd\ufffd\u03f7\ufffd\u05ea\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd5~6\ufffd\ufffd
	char windDir[WEATHER_WIND_LEN];						// \ufffd\ufffd\ufffd\ufffd
}ST_WEATHER_EVERYDAY,*PST_WEATHER_EVERYDAY;

typedef struct _stWeather_Everyday_frm
{
	char cityCode[WEATHER_CITYCODE_LEN];
	ssp_uint8 result;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd _SSP_OK \u03aa\ufffd\u0279\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u02a7\ufffd\ufffd
	ssp_uint8 count;						// \u0524\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	PST_WEATHER_EVERYDAY pstWeather_Everyday;			
}ST_WEATHER_EVERYDAY_FRM,*PST_WEATHER_EVERYDAY_FRM;

/************************************************************************/
/*
24h\ufffd\ufffd\ufffd\ufffd
(issia(sii))
*/
/************************************************************************/
typedef struct _stWeather_24h
{
	char time[WEATHER_TIME_LEN];							// \u02b1\ufffd\ufffd
	ssp_uint8 weatherID;					// \ufffd\ufffd\ufffd\ufffdid
	ssp_int32 nowTemp;						// \ufffd\ufffd\u01f0\ufffd?\ufffd    \ufffd\ufffdint 
}ST_WEATHER_24H,*PST_WEATHER_24H;
typedef struct _stWeather_24h_Frm
{
	ssp_uint8 result;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	char cityCode[WEATHER_CITYCODE_LEN];
	char sunriseTime[WEATHER_SUNRISE_TIME_LEN];					// \ufffd\u0573\ufffd\u02b1\ufffd\ufffd
	char sunsetTime[WEATHER_SUNSET_TIME_LEN];					// \ufffd\ufffd\ufffd\ufffd\u02b1\ufffd\ufffd
	ssp_uint8 count;						// \u0524\ufffd\ufffd\u0421\u02b1\ufffd\ufffd
	PST_WEATHER_24H pstWeather_24h;			// \u0421\u02b1\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03e2
}ST_WEATHER_24H_FRM,*PST_WEATHER_24H_FRM;

/************************************************************************/
/*
\u05b8\ufffd\ufffd\ufffd\ufffd\ufffd
(issssssssssssssssss)
*/
/************************************************************************/
typedef struct _stIndexData
{
	ssp_uint8 result;
	char cityCode[WEATHER_CITYCODE_LEN];
	char xy_index[WEATHER_INDEX_LEN];						// \u03f4\ufffd\ufffd\u05b8\ufffd\ufffd
	char xy_tips[WEATHER_TIPS_LEN];						// \u03f4\ufffd\ufffd\ufffd\ufffd\u02be
	char xc_index[WEATHER_INDEX_LEN];						// \u03f4\ufffd\ufffd\u05b8\ufffd\ufffd
	char xc_tips[WEATHER_TIPS_LEN];						// \u03f4\ufffd\ufffd\ufffd\ufffd\u02be
	char yd_index[WEATHER_INDEX_LEN];						// \ufffd\u02f6\ufffd\u05b8\ufffd\ufffd
	char yd_tips[WEATHER_TIPS_LEN];						// \ufffd\u02f6\ufffd\ufffd\ufffd\u02be
	char zwx_index[WEATHER_INDEX_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u05b8\ufffd\ufffd
	char zwx_tips[WEATHER_TIPS_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u02be
	char gm_index[WEATHER_INDEX_LEN];						// \ufffd\ufffd?\u05b8\ufffd\ufffd
	char gm_tips[WEATHER_TIPS_LEN];						// \ufffd\ufffd?\ufffd\ufffd\u02be
	char hz_index[WEATHER_INDEX_LEN];						// \ufffd\ufffd\u05f1\u05b8\ufffd\ufffd
	char hz_tips[WEATHER_TIPS_LEN];						// \ufffd\ufffd\u05f1\ufffd\ufffd\u02be
	char dy_index[WEATHER_INDEX_LEN];						// \ufffd\ufffd\ufffd\ufffd\u05b8\ufffd\ufffd
	char dy_tips[WEATHER_TIPS_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u02be
	char ls_index[WEATHER_INDEX_LEN];						// \ufffd\ufffd\u0279\u05b8\ufffd\ufffd
	char ls_tips[WEATHER_TIPS_LEN];						// \ufffd\ufffd\u0279\ufffd\ufffd\u02be
	char ys_index[WEATHER_INDEX_LEN];						// \ufffd\ufffd\u0261\u05b8\ufffd\ufffd
	char ys_tips[WEATHER_TIPS_LEN];						// \ufffd\ufffd\u0261\ufffd\ufffd\u02be
}ST_INDEX_DATA,*PST_INDEX_DATA;

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
(iiiiiiiia(si)sis)
*/
/************************************************************************/
typedef struct _stAQI_Onehour
{
	char time[WEATHER_TIME_LEN];							// \u0524\ufffd\ufffd\u02b1\ufffd\ufffd
	ssp_uint8 aqiValue;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
}ST_AQI_ONEHOUR,*PST_AQI_ONEHOUR;

typedef struct _stAirQuality
{
	ssp_uint8 result;						// \ufffd\ufffd\ufffd
	char cityCode[WEATHER_CITYCODE_LEN];
	ssp_uint32 pm25;							
	ssp_uint32 aqi;							//\ufffd\ufffd\u01f0AQI
	ssp_uint32 pm10;
	ssp_uint32 so2;
	ssp_uint32 no2;
	ssp_uint32 co;
	ssp_uint32 o3;							//\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u04e6\ufffd\ufffd\ufffd\ufffdO3  1
	//ssp_uint8 count;						// \u0524\ufffd\ufffd\ufffd\u02fc\ufffd\ufffd\ufffd\u0421\u02b1\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd24\u0421\u02b1\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd  0
	ST_AQI_ONEHOUR stAQI_Onehour[WEATHER_AQI_ONEDAY];			//\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0231\ufffd\u0675\ufffd\u01f0\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u023e\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u023e\ufffd\u023c\ufffd
	char aqiLevel[WEATHER_AQI_LEVEL_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd 1 
	ssp_uint32 cityRank;					// \ufffd\ufffd\u01f0\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd 1						
	char aqiInfo[WEATHER_AQI_INFO_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u02f5\ufffd\ufffd
}ST_AIR_QUALITY,*PST_AIR_QUALITY;

/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u03f8\ufffd\ufffd\u03e2
(isssssssssss)
*/
/************************************************************************/
typedef struct _stWeather_Detail
{
	ssp_uint8 result;						// \ufffd\ufffd\ufffd
	char cityCode[WEATHER_CITYCODE_LEN];
	char date[WEATHER_DATE_LEN];							// \ufffd\ufffd\ufffd\ufffd
	char week[WEATHER_WEEK_LEN];							// \ufffd\ufffd\ufffd\ufffd
	char chineseDate[WEATHER_DATE_LEN];					// \u0169\ufffd\ufffd
	char festival[WEATHER_FESTIVAL_LEN];						// \ufffd\ufffd\ufffd\ufffd
	char tips[WEATHER_TIPS_LEN];							// \u02f5\ufffd\ufffd
	char nowWeather[WEATHER_WEATHER_LEN];					// \ufffd\ufffd\u01f0\ufffd\ufffd\ufffd\ufffd 1 \ufffd\ufffd\ufffd\ufffd\u05ea\ufffd\ufffd
	char highTemp[WEATHER_TEMP_LEN];						// \ufffd\ufffd\ufffd\ufffd?\ufffd
	char lowTemp[WEATHER_TEMP_LEN];						// \ufffd\ufffd\ufffd\ufffd?\ufffd
	char wind[WEATHER_WIND_LEN];							// \ufffd\ufffd 1
	char sunriseTime[WEATHER_SUNRISE_TIME_LEN];					// \ufffd\u0573\ufffd\u02b1\ufffd\ufffd 1
	char sunsetTime[WEATHER_SUNSET_TIME_LEN];					// \ufffd\ufffd\ufffd\ufffd\u02b1\ufffd\ufffd 1
}ST_WEATHER_DETAIL,*PST_WEATHER_DETAIL;

/************************************************************************/
/* 
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
(iia(isi))
*/
/************************************************************************/
typedef struct _stAQI_City
{
	ssp_uint8 index;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd 
	char cityName[WEATHER_CITYNAME_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	ssp_int32 aqiValue;						// aqi\u05b5
}ST_AQI_CITY,*PST_AQI_CITY;

typedef struct _stAQI_Rank
{
	ssp_uint8 result;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	ssp_uint8 count;						// \ufffd\ufffd\ufffd\u0438\ufffd\ufffd\ufffd
	PST_AQI_CITY pstAQI_City;				// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
}ST_AQI_RANK,*PST_AQI_RANK;

/************************************************************************/
/* 
\u0524\ufffd\ufffd\ufffd\ufffd\u03e2
(isssss)
*/
/************************************************************************/
typedef struct _stWarningData
{
	ssp_uint8 result;						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	char cityCode[WEATHER_CITYCODE_LEN];
	char reportTime[WEATHER_REPORT_TIME_LEN];					// \ufffd\ufffd\ufffd\ufffd\u02b1\ufffd\ufffd
	char warringStatus[WEATHER_WARNING_STATUS_LEN];					// \u0524\ufffd\ufffd\u05f4\u032c
	char city[WEATHER_CITY_LEN];							// \u04f0\ufffd\ufffd\ufffd\ufffd\ufffd
	char warningLevel[WEATHER_WARNING_LEVEL_LEN];					// \u0524\ufffd\ufffd\ufffd\u023c\ufffd
	char warningTitle[WEATHER_WARNING_TITLE_LEN];					// \u0524\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	char warningContext[WEATHER_WARNING_CONTEXT_LEN];				// \u0524\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
}ST_WARNING_DATA,*PST_WARNING_DATA;


/************************************************************************/
/*
\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
*/
/************************************************************************/
typedef struct _stCityInfo
{
	char cityName[WEATHER_CITYNAME_LEN];						// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd	
	char cityArea[WEATHER_CITYAREA_LEN];					// \ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd
	char cityCode[WEATHER_CITYCODE_LEN];						// \ufffd\ufffd\ufffd\u0434\ufffd\ufffd\ufffd
}ST_CITY_INFO,*PST_CITY_INFO;

typedef struct _stCityInfoFrm
{
	unsigned int cityCount;					//\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\ufffd\u0133\ufffd\ufffd\u0438\ufffd\ufffd\ufffd
	PST_CITY_INFO pstCityInfo;				//  \ufffd\ufffd\ufffd\ufffd\ufffd\u0431\ufffd
}ST_CITY_INFO_FRM,*PST_CITY_INFO_FRM;

enum Weather_Icon_Id
{
	//00 \u6674
	ICON_ID_Sunny = 0,
	//01 \u591a\u4e91
	ICON_ID_Cloudy,
	//02 \u9634
	ICON_ID_Overcast,
	//03 \u9635\u96e8
	ICON_ID_Shower,
	//04 \u96f7\u9635\u96e8
	ICON_ID_Thundershower,
	//05 \u96f7\u9635\u96e8\u4f34\u6709\u51b0\u96f9
	ICON_ID_Thundershower_with_hail,
	//06 \u96e8\u5939\u96ea
	ICON_ID_Sleet,
	//07 \u5c0f\u96e8
	ICON_ID_Light_rain,
	//08 \u4e2d\u96e8
	ICON_ID_Moderate_rain,
	//09 \u5927\u96e8
	ICON_ID_Heavy_rain,
	//10 \u66b4\u96e8
	ICON_ID_Storm,
	//11 \u5927\u66b4\u96e8
	ICON_ID_Heavy_storm,
	//12 \u7279\u5927\u66b4\u96e8
	ICON_ID_Severe_storm,
	//13 \u9635\u96ea
	ICON_ID_Snow_flurry,
	//14 \u5c0f\u96ea
	ICON_ID_Light_snow,
	//15 \u4e2d\u96ea
	ICON_ID_Moderate_snow,
	//16 \u5927\u96ea
	ICON_ID_Heavy_snow,
	//17 \u66b4\u96ea
	ICON_ID_Snowstorm,
	//18 \u96fe
	ICON_ID_Foggy,
	//19 \u51bb\u96e8
	ICON_ID_Ice_rain,
	//20 \u6c99\u5c18\u66b4
	ICON_ID_Duststorm,
	//21 \u5c0f\u5230\u4e2d\u96e8
	ICON_ID_Light_to_moderate_rain,
	//22 \u4e2d\u5230\u5927\u96e8
	ICON_ID_Moderate_to_heavy_rain,
	//23 \u5927\u5230\u66b4\u96e8
	ICON_ID_Heavy_rain_to_storm,
	//24 \u66b4\u96e8\u5230\u5927\u66b4\u96e8
	ICON_ID_Storm_to_heavy_storm,
	//25 \u5927\u66b4\u96e8\u5230\u7279\u5927\u66b4\u96e8
	ICON_ID_Heavy_to_severe_storm,
	//26 \u5c0f\u5230\u4e2d\u96ea
	ICON_ID_Light_to_moderate_snow,
	//27 \u4e2d\u5230\u5927\u96ea
	ICON_ID_Moderate_to_heavy_snow,
	//28 \u5927\u5230\u66b4\u96ea
	ICON_ID_Heavy_snow_to_snowstorm,
	//29 \u6d6e\u5c18
	ICON_ID_Dust,
	//30 \u626c\u6c99
	ICON_ID_Sand,
	//31 \u5f3a\u6c99\u5c18\u66b4
	ICON_ID_Sandstorm,
	//53 \u973e
	ICON_ID_Haze = 53,
	//99 \u65e0
	ICON_ID_Unknown = 99
};

/*********************************phone begin**********************************/
#define PHONE_DATE_LEN        64
#define PHONE_NAME_LEN       256
#define PHONE_NUMBER_LEN        256
#define PHONE_NUMTYPE_LEN       16
//#define SSPLINK_PHONE_PICTURE_PATH "/media/mmcblk2p6/applink/userdata/picture.png"

enum CALL_FEEDBACK_STATUS
{
    CALL_PHONE_FEEDBACK = 1,
    ANSWER_CALL_FEEDBACK,
    HANG_OFF_FEEDBACK,
    SILENCE_FEEDBACK
};

enum PHONE_SEND_CALL_STATUS
{
    PHONE_SEND_CALL_PHONE = 1,
    PHONE_SEND_ANSWER_CALL,
    PHONE_SEND_HANG_OFF,
    PHONE_SEND_SILENCE,
    PHONE_SEND_REMIND,
    PHONE_SEND_RESPONSE
};

enum PHONE_CALL_STATUS
{
    PHONE_SIM_INVALID = 0,
    PHONE_CALL_SUCCESS = 1,
    PHONE_CALL_FAILED
};

enum SUBAPP_DISPLAY_CONTROL
{
    SUBAPP_DISPLAY_LOADING = 0,
    SUBAPP_DISPLAY_SHOW ,
    SUBAPP_DISPLAY_BACK,
    SUBAPP_DISPLAY_EXIT,
    SUBAPP_DISPLAY_PAUSE,
    SUBAPP_DISPLAY_RECOVER,
};

typedef enum
{
    SSP_IMAGE_HIDE = 0,//镜像退出或已经隐藏
    SSP_IMAGE_LOADING,//镜像正在启动中
    SSP_IMAGE_SHOW//镜像已显示
}SSP_IMAGE_STATE;

typedef struct _stCallInfo
{
    ssp_int32 type;
    char name[PHONE_NAME_LEN];
    char number[PHONE_NUMBER_LEN];
    char numType[PHONE_NUMTYPE_LEN];
    ssp_int32 iPicFlag;
}ST_CALL_INFO, *PST_CALL_INFO;

typedef struct _stCallListInfo
{
    char date[PHONE_DATE_LEN];
    ssp_int32 type;
    char name[PHONE_NAME_LEN];
    char number[PHONE_NUMBER_LEN];
    char numType[PHONE_NUMTYPE_LEN];
}ST_CALL_LIST_INFO, *PST_CALL_LIST_INFO;

typedef struct _stCallListInfoFrm
{
    ssp_int32 result;
    ssp_int32 count;
    PST_CALL_LIST_INFO pstCallListInfo;
}ST_CALL_LIST_INFO_FRM, *PST_CALL_LIST_INFO_FRM;

/*********************************phone end**********************************/
#endif























