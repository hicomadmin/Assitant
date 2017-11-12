#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QPalette>
#include <QCoreApplication>
#include <QTranslator>
#include "mainwindow.h"


MainWindow *g_pAppWnd = NULL;
ST_SONG_INFO *stSongInfo = NULL;


QString sWeatherTypeIconName[33] = {
    "weather_icon_0.png",
    "weather_icon_1.png",
    "weather_icon_2.png",
    "weather_icon_3.png",
    "weather_icon_4.png",
    "weather_icon_5.png",
    "weather_icon_6.png",
    "weather_icon_7.png",
    "weather_icon_8.png",
    "weather_icon_9.png",
    "weather_icon_10.png",
    "weather_icon_11.png",
    "weather_icon_12.png",
    "weather_icon_13.png",
    "weather_icon_14.png",
    "weather_icon_15.png",
    "weather_icon_16.png",
    "weather_icon_17.png",
    "weather_icon_18.png",
    "weather_icon_19.png",
    "weather_icon_20.png",
    "weather_icon_21.png",
    "weather_icon_22.png",
    "weather_icon_23.png",
    "weather_icon_24.png",
    "weather_icon_25.png",
    "weather_icon_26.png",
    "weather_icon_27.png",
    "weather_icon_28.png",
    "weather_icon_29.png",
    "weather_icon_30.png",
    "weather_icon_31.png",
    "weather_icon_32.png"
};

QString sWeatherType[34] = {
    "晴",
    "多云",
    "阴",
    "阵雨",
    "雷阵雨",
    "雷阵雨伴有冰雹",
    "雨夹雪",
    "小雨",
    "中雨",
    "大雨",
    "暴雨",
    "大暴雨",
    "特大暴雨",
    "阵雪",
    "小雪",
    "中雪",
    "大雪",
    "暴雪",
    "雾",
    "冻雨",
    "沙尘暴",
    "小到中雨",
    "中到大雨",
    "大到暴雨",
    "暴雨到大暴雨",
    "大暴雨到特大暴雨",
    "小到中雪",
    "中到大雪",
    "大到暴雪",
    "浮尘",
    "杨沙",
    "强沙尘暴",
    "霾",
    "无"
};

int main(int argc, char *argv[])
{
    char env[] = "FB_MULTI_BUFFER=3";
    putenv(env);
    // 创建应用对象
    QApplication app(argc, argv);

    // 安装翻译组件
    app.installTranslator(I108n::instance());

    // 加载字体库
    int ret = QFontDatabase::addApplicationFont(FONT_PATH);
    DEBUG_PARAM("load font ret:", ret);
    DEBUG_PARAM("Font family:", QFontDatabase::applicationFontFamilies(ret));
    // 实例化主窗口
    g_pAppWnd = new MainWindow();
    // 向QML端添加组件
    g_pAppWnd->rootContext()->setContextProperty("globalObject", g_pAppWnd);
    g_pAppWnd->rootContext()->setContextProperty("assistant", &g_pAppWnd->assistant);
    // 注册字体库
    g_pAppWnd->rootContext()->setContextProperty("fontFamily", FONT_NAME);
    // 日历事件列表
    g_pAppWnd->assistant.eventlistmodel = new calendar_event_list(g_pAppWnd);
    g_pAppWnd->rootContext()->setContextProperty("eventlistmodel", g_pAppWnd->assistant.eventlistmodel);
    // 设置语言
    g_pAppWnd->rootContext()->setContextProperty("I108n",I108n::instance());

    // 初始化画面
    g_pAppWnd->init();
    g_pAppWnd->setSource(QUrl(QStringLiteral("qrc:/Assistantqml/main.qml")));
    g_pAppWnd->setFlags(Qt::Window|Qt::FramelessWindowHint);
    //g_pAppWnd->show();
    //pass parameter values to driver
    g_pAppWnd->assistantStateReport(2);
    DEBUGLOG;
    return app.exec();
}
