TEMPLATE = app

QT += qml quick widgets core dbus declarative

TRANSLATIONS += lang_en.ts lang_zh.ts  #后面你可以加你想要翻译的各种版本
CONFIG += localize_deployment


SOURCES += main.cpp \
    mainwindow.cpp \
    msgSources/msg_detaillistitem.cpp \
    msgSources/msg_listitem.cpp \
    msgSources/msg_phaseitem.cpp \
    phoneSources/phone_quicksearch.cpp \
    phoneSources/phonebooklistitem.cpp \
    phoneSources/phonerecordlistitem.cpp \
    phoneSources/phonethinkresultlistitem.cpp \
    LocalMusicListItem.cpp \
    AppListItem.cpp \
    ssp_assist_fun.cpp \
    i108n.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    SSPLInk/ssp_assist_struct.h \
    SSPLInk/ssp_assist_if.h \
    mainwindow.h \
    SSPLInk/ssp_assisant_fun.h \
    SSPLInk/common.h \
    msgHeaders/msg_listitem.h \
    msgHeaders/msg_phaseitem.h \
    msgHeaders/msg_detaillistitem.h \
    phoneHeaders/phone_quicksearch.h \
    phoneHeaders/phonebooklistitem.h \
    phoneHeaders/phonerecordlistitem.h \
    phoneHeaders/phonethinkresultlistitem.h \
    LocalMusicListItem.h \
    AppListItem.h \
    i108n.h

INCLUDEPATH += SSPLInk

QMAKE_CXXFLAGS += -O2 -g -Wall -c -fmessage-length=0 -std=c++0x -pthread -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 -mno-unaligned-access -std=c++0x -fcommon -mfpu=vfp
QMAKE_CFLAGS += -O2 -g -Wall -c -fmessage-length=0 -pthread -march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a9 -mno-unaligned-access -fcommon -mfpu=vfp

lupdate_only{
FORMS += \
#    Assistantqml/appComponent.qml \
#    Assistantqml/applist8.qml \
#    Assistantqml/applistinfo.qml \
#    Assistantqml/Button.qml \
    Assistantqml/barcode.qml \
    Assistantqml/helpPage.qml \
    Assistantqml/main.qml \
    Assistantqml/mirrorSolution.qml \
#    Assistantqml/Marquee.qml \
#    Assistantqml/progressbar.qml \
#    Assistantqml/Prompt.qml \
#    Assistantqml/quitpage.qml \
#    Assistantqml/remind.qml \
    Assistantqml/SSPLinkMain.qml
#    Assistantqml/startpage.qml \
#    Assistantqml/Title.qml \
#    Assistantqml/volumeProgressBar.qml \
#    CalendarQml/Button.qml \
#    CalendarQml/Calendar_affairs.qml \
#    CalendarQml/Calendar_month.qml \
#    CalendarQml/EventItem.qml \
#    CalendarQml/main.qml \
#    CalendarQml/Marquee.qml \
#    LocalMusicQml/Button.qml \
#    LocalMusicQml/LocalMusicList.qml \
#    LocalMusicQml/LocalMusicPlayPage.qml \
#    LocalMusicQml/MainOfLocalMusic.qml \
#    LocalMusicQml/Marquee.qml \
#    msg_qml/back_button.qml \
#    msg_qml/msg_list.qml \
#    msg_qml/msg_main.qml \
#    msg_qml/msg_replybox.qml \
#    msg_qml/PhrasesList.qml \
#    msg_qml/repeatbutton.qml \
#    msg_qml/senMsg.qml \
#    msg_qml/title.qml \
#    phone_qml/Button.qml \
#    phone_qml/CallRecord.qml \
#    phone_qml/category.qml \
#    phone_qml/Contacts.qml \
#    phone_qml/KeybordButton.qml \
#    phone_qml/Main.qml \
#    phone_qml/Marquee.qml \
#    phone_qml/phone_callAnswer.qml \
#    phone_qml/phone_dial.qml \
#    phone_qml/phone_thinkResult.qml

}

OTHER_FILES +=

