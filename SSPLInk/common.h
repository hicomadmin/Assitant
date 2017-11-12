#ifndef COMMON_H
#define COMMON_H


#define FONT_PATH "/usr/lib/fonts/MicroHei.ttc"
#define FONT_NAME "WenQuanYi Micro Hei"
#define SSP_SDK_CORE_LIBRARY_PATH "/var/applink/lib/SSP_SDK_Core"
#define SSP_ASSISTANT_LIBRARY_PATH "/var/applink/lib/SSP_Assistant"

#ifndef DEBUG
 #define DEBUG 0
#endif

#if DEBUG
 #define DEBUGLOG                qDebug()<<"========= DEBUG ========="<<"["<<__FILE__<<"]"<<"["<<__FUNCTION__<<":"<<__LINE__<<"]"
 #define DEBUG_PARAM(str, param) qDebug()<<"========= DEBUG ========="<<"["<<__FILE__<<"]"<<"["<<__FUNCTION__<<":"<<__LINE__<<"]"<<str<<param
 #define DEBUG_CHAR(str)         qDebug()<<"========= DEBUG ========="<<"["<<__FILE__<<"]"<<"["<<__FUNCTION__<<":"<<__LINE__<<"]"<<str
#else
 #define  DEBUGLOG
 #define  DEBUG_PARAM(str, param)
 #define  DEBUG_CHAR(str)
#endif


#endif // COMMON_H
