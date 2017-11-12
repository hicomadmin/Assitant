import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    objectName: "mainWindow";
    id: mainWindow;
    width: 1280
    height:720

    property bool loadingMusic:          false;
    property bool loadingAppList:        false;
    property bool appListReturnClicked:  false;
    property int  progressbarValue:      -1;
    property int  appIndex:              -1;
    property int  musicPlayStatus:       -1;
    property int  playOrStopFlag:        -1;
    property bool  musicplayOrStopFlag:  false;

    property int audioStatus: 0;
    property bool delayFlag:  false;
    property bool isIgnore:   false;
    property int startMirrorSource; //0: start from desk; 1: start from applist;
    property string localMusicName;
    property string localMusicSinger;
    property string localMusicPicPath;
    property int localMusicPlayStatus;
    property string musicAppID: "ssp_music";

    Image {
        id: bkg
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
        visible:true;
    }

    Loader{
        id:ssplinkMainPage;
        anchors.fill: parent;
        source: "SSPLinkMain.qml";
        visible:false;
        onLoaded: {
            item.applistbtnClicked.connect(onAppListClicked);
            item.weatherAppClicked.connect(onWeatherAppClicked);
            item.calendarAppClicked.connect(onCalendarAppClicked);
            item.messagebtnclicked.connect(onMessagebtnclicked);
            item.phonebtnclicked.connect(onPhonebtnclicked);
            item.localMusicAppClicked.connect(onLocalMusicAppClicked);
            item.mirrorBtnClicked.connect(onMirrorBtnClicked);
            item.mirrorAOABtnClicked.connect(onMirrorAOABtnClicked);
            item.sspLinkBackClicked.connect(onBackBtnClicked);
            item.signVR.connect(onVRBtnClicked);
        }
        function onVRBtnClicked() {
            globalObject.requestVRStatus("start");
        }
    }

    Loader{
        id:connectpage;
        anchors.fill: parent;
        source: "barcode.qml"
        visible: true;
        onLoaded: {
            assistant.assistant_do_init();
            item.helpClicked.connect(onHelpBtnClicked);
            item.backBtnClicked.connect(onBackBtnClicked);
        }
    }

    //    function appPromptPage(index)
    //    {
    //        console.log("appPromptPage index", index);
    //        var appName = appListPage.item.getItemName(index);
    //        if(appName !== "")
    //        {
    //            appListPage.visible = false;
    //            startAppPhrase.visible = true;
    //            appIndex = index;
    //        }
    //    }

    Loader{
        id:startAppPhrase;
        anchors.fill: parent;
        source: "../Assistantqml/Prompt.qml";
        visible: false;
        onLoaded: {
            item.btnVisible = false;
            item.disconnectType = "正在启动应用 , 请稍后...";
        }
    }
    Timer{
        id:startAppWaitOutTime
        interval: 10000; repeat: false;
        onTriggered:
        {
            startAppPhrase.visible = false;
            retryStartApp.visible = true;
        }
        running: startAppPhrase.visible;
    }
    Loader{
        id:retryStartApp;
        anchors.fill: parent;
        source: "../Assistantqml/Prompt.qml"
        visible: false;
        onLoaded: {
            item.disconnectType = "应用启动失败 , 请稍后再试！";
            item.signRetry.connect(onRetryBtnClicked);
        }
        property int curSelectIndex;
        property string curSelectAppName;

        function onRetryBtnClicked()
        {
            retryStartApp.visible = false;
            startAppPhrase.visible = true;
            onApplistClickItem(curSelectIndex, curSelectAppName);
        }
    }

    Loader{
        id:appListPage;
        anchors.fill: parent;
        source: "applist.qml";
        visible:false;
        onLoaded: {
            item.appListClicked.connect(onBackBtnClicked);
            item.wichAppClicked.connect(onApplistClickItem);
        }
    }

    Loader{
        id:vrPage;
        anchors.fill: parent;
        source: "vrPage.qml";
        visible: false;
        onLoaded: {
            item.backBtnClicked.connect(onBackBtnClicked)
        }
        function onBackBtnClicked()
        {
            globalObject.requestVRStatus("stop");
            vrPage.visible = false;
            vrPage.item.setVREnable(true);
        }
    }
    Loader{
        id:activate_tip
        anchors.fill: parent
        source: "../Assistantqml/ActivationPrompt.qml"
        visible:false;
        onLoaded: {
            item.signStartActivating.connect(onStartActivating);
            item.signBack.connect(onActivatePageBack);
        }
    }

    Loader{
        id:activating
        anchors.fill: parent
        source: "../Assistantqml/ActivationProgressBar.qml"
        visible: false
    }

    Loader{
        id: helpPage;
        anchors.fill: parent;
        source: "helpPage.qml";
        visible: false;
        onLoaded: {
            item.helpPageBackClicked.connect(onHelpPageBackBtnClicked);
        }

        function onHelpPageBackBtnClicked()
        {
            console.log("helpPage \t progressbarValue:",progressbarValue);
            if(progressbarValue < 10 ||(progressbarValue >= 12 && progressbarValue <= 23))
            {
                helpPage.visible    = false;
                connectpage.visible = true;
                console.log("11 =====");
            }else{
                helpPage.visible        = false;
                ssplinkMainPage.visible = true;
                console.log("22 =====");
            }
        }

    }

    Loader{   // mirror AOA link Solution
        id:mirrorAOASolution;
        anchors.fill: parent;
        source: "mirrorSolution.qml"
        visible: false;
        onLoaded: {
            item.solutionbackBtnClicked.connect(onMirrorAOASolutionBackClick);
        }
    }

    Loader{
        id:quitpage;
        anchors.fill: parent;
        source: "quitpage.qml";
        visible:false;
        onLoaded: {
            item.quitClicked.connect(exitAssisantClickedSignal);
            item.cancelClicked.connect(onCancelClicked);
        }
    }

    Loader{
        id:localMusicApp;
        anchors.fill: parent;
        source: "../LocalMusicQml/MainOfLocalMusic.qml";
        visible:false;
        onLoaded: {
            item.sigPrevClicked.connect(onPrevClicked);
            item.sigPlayClicked.connect(onPlayClicked);
            item.sigPauseClicked.connect(onPauseClicked);
            item.sigNextClicked.connect(onNextClicked);
            item.mBackBtnClicked.connect(onBackBtnClicked);
        }
    }

    Loader{
        id:messageApp;
        anchors.fill: parent;
        source: "../msg_qml/msg_main.qml";
        visible: false;
        onLoaded: {
            item.msgBackButtonClicked.connect(onBackBtnClicked);
        }
    }

    Loader{
        id:phoneApp;
        anchors.fill: parent;
        source: "../phone_qml/Main.qml";
        visible: false;
        onLoaded: {
            item.phoneBackButtonCliked.connect(onBackBtnClicked);
            item.phoneCallBtnCliked.connect(onPhoneCallBtnCliked);
        }
    }

    Loader{
        id:calendarApp;
        anchors.fill: parent;
        source: "../CalendarQml/main.qml";
        visible: false;
        onLoaded: {
            item.calendarBackClicked.connect(onBackBtnClicked);
        }
    }

    Loader{
        id:weatherApp;
        anchors.fill: parent;
        source: "../weatherQml/main.qml";
        visible: false;
        onLoaded: {
            item.weatherBackClicekedSignal.connect(onBackBtnClicked);
        }
    }

    Loader{ //phone call and answer
        id: phoneCallAnswer;
        objectName: "phoneCallAnswer";
        anchors.fill: parent;
        visible: false;
        source: "../phone_qml/phone_callAnswer.qml"
        onLoaded: {
            item.hangOffIconClicked.connect(onHangOffIconClicked);
        }
    }

    Image{ //buletooth icon
        id:bluetoothIcon;
        width: 25;
        height: 41;
        anchors.top: parent.top;
        anchors.topMargin: 35;
        anchors.right: muteIcon.left;
        anchors.rightMargin: 15;
        source: "../Assistantimages/buletooth.png"
        visible: false;
    }

    Image{ //mute icon
        id:muteIcon;
        width: 34;
        height: 38;
        anchors.top: parent.top;
        anchors.topMargin: 35
        anchors.right: parent.right;
        anchors.rightMargin: 280;
        source: "../Assistantimages/mute.png";
        visible: false;
    }

    Image { //sdIcon
        id: sdIcon
        width: 34;
        height: 38;
        anchors.top: muteIcon.top;
        anchors.left: muteIcon.right;
        anchors.leftMargin: 20;
        visible: false;
        source: "../Assistantimages/ico_sd.png"
    }

    Image {  //auxIcon
        id: auxIcon
        width: 34;
        height: 38;
        anchors.top: muteIcon.top;
        anchors.right: bluetoothIcon.left;
        anchors.rightMargin: 10;
        visible: false;
        source: "../Assistantimages/ico_aux.png"
    }

    Loader {
        id: volProgressBar;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 55;
        source: "../Assistantqml/volumeProgressBar.qml";
    }

    Loader{
        id:startpage;
        anchors.fill: parent;
        source: "startpage.qml";
        visible:true;
        onLoaded: {
            item.sigSplashTimeout.connect(onSplashTimeout);
        }
    }

    Image {
        id:mirrorStartPage;
        anchors.fill: parent;
        width: 1280;
        height: 720;
        source: "../Assistantimages/start.png"
        visible: false;
        MouseArea {
            anchors.fill: parent;
        }
    }

    Timer {
        id:mirrorStartPageTimer
        interval: 2000
        onTriggered: {
            mirrorStartPage.visible = false;
            stop();
        }
        running: mirrorStartPage.visible
    }

    /********************************   FUNCTION   *******************************/
    function onStartActivating()
    {
        console.log("############### onStartActivating");
        globalObject.activate_start();
    }

    function onActivatePageBack()
    {
        console.log("############### onActivatePageBack");
        activating.item.onSetActivationStatus(8);
        globalObject.activate_return();
    }

    // phone call
    function onPhoneCallBtnCliked(contentNumber, contentName)
    {
        if(globalObject.getShowFlag() == 1)
        {
            if(audioStatus == 0)
            {
                phoneCallAnswer.visible = true;
                phoneCallAnswer.item.contectNameText = contentName;
                phoneCallAnswer.item.callStatusText = "连接中...";
                isIgnore = false;
            }
            else if(audioStatus == 1)
            {
                //不跳车机助手接听界面
                isIgnore = true;
            }
            else//(audioStatus == 2)
            {
                //跳车机助手接听界面但是挂断按钮做100毫秒延迟操作
                delayFlag = true;
                phoneCallAnswer.visible = true;
                phoneCallAnswer.item.contectNameText = contentName;
                phoneCallAnswer.item.callStatusText = "连接中...";
                isIgnore = false;
            }
        }
        globalObject.dialNumber(contentNumber);
    }

    // phone hang off 车机挂断
    function onHangOffIconClicked()
    {
        if(delayFlag)
            globalObject.mySleep(100);
        delayFlag = false;
        phoneCallAnswer.visible = false;
        phoneApp.item.setPhoneDialTextNull();   //挂电话后清空编辑区内容
        c_thinkResultListModel.clear();         //清空联想结果
        globalObject.hangOffPhone();
        if(!globalObject.getShowFlag())
            globalObject.hideAssistantWindow();
    }
    // phone hang off 手机挂断回调
    function onPhoneHangoff()
    {
        if(delayFlag)
            globalObject.mySleep(100);
        delayFlag = false;
        phoneCallAnswer.visible = false;
        phoneApp.item.setPhoneDialTextNull();   //挂电话后清空编辑区内容
        c_thinkResultListModel.clear();         //清空联想结果
        if(!globalObject.getShowFlag())
            globalObject.hideAssistantWindow();
    }

    function onBackBtnClicked()
    {
        if(localMusicApp.visible)
        {
            if(appListReturnClicked == false)
            {
                ssplinkMainPage.visible = true;
                localMusicApp.visible   = false;
            }else{
                appListPage.visible = true;
                localMusicApp.visible = false;
                appListReturnClicked = false;
            }
        }
        else if(messageApp.visible)
        {
            globalObject.flushMsgDB();
            if(appListReturnClicked == false)
            {
                ssplinkMainPage.visible = true;
                messageApp.visible      = false;
            }else{
                appListPage.visible = true;
                messageApp.visible = false;
                appListReturnClicked = false;
            }
        }
        else if(phoneApp.visible)
        {
            if(appListReturnClicked == false)
            {
                ssplinkMainPage.visible = true;
                phoneApp.visible        = false;
            }else{
                appListPage.visible = true;
                phoneApp.visible = false;
                appListReturnClicked = false;
            }
        }
        else if(weatherApp.visible)
        {
            if(appListReturnClicked == false)
            {
                ssplinkMainPage.visible = true;
                weatherApp.visible      = false;
            }else{
                appListPage.visible = true;
                weatherApp.visible = false;
                appListReturnClicked = false;
            }
        }
        else if(calendarApp.visible)
        {
            if(appListReturnClicked == false)
            {
                ssplinkMainPage.visible = true;
                calendarApp.visible     = false;
            }else{
                appListPage.visible = true;
                calendarApp.visible = false;
                appListReturnClicked = false;
            }
        }
        else if(connectpage.visible)
        {
            quitpage.visible = true;
        }
        else if(appListPage.visible)
        {
            ssplinkMainPage.visible = true;
            appListPage.visible     = false;
        }
        else
            quitpage.visible = true;
    }

    function onLocalMusicAppClicked()
    {
        console.log("onLocalMusicAppClicked");
        if(musicAppID == "ssp_music")
        {
            ssplinkMainPage.visible = false;
            localMusicApp.visible   = true;
            if(loadingMusic == false)
            {
                console.log("loadingMusic:",loadingMusic);
                globalObject.localMusic_do_LoadList(1);
                loadingMusic = true;
            }
        }
        else
        {
            globalObject.runMusicAppProcess(musicAppID);
        }
    }

    function onMessagebtnclicked()
    {
        console.log("onMessagebtnclicked");
        ssplinkMainPage.visible = false;
        messageApp.visible      = true;
        globalObject.getLatestMessages();
        c_detailListModel.clear();
    }

    function onPhonebtnclicked()
    {
        console.log("onPhonebtnclicked");
        ssplinkMainPage.visible = false;
        phoneApp.visible        = true;
        globalObject.readContactList();
    }

    function onWeatherAppClicked()
    {
        console.log("onWeatherAppClicked");
        ssplinkMainPage.visible = false;
        weatherApp.visible      = true;
    }

    function onCalendarAppClicked()
    {
        console.log("onCalendarAppClicked");
        ssplinkMainPage.visible = false;
        calendarApp.visible     = true;
    }

    function onSplashTimeout()
    {
        console.log("onSplashTimeout");
        startpage.visible = false;
    }
    
    function onAppListClicked()
    {
        console.log("onAppListClicked");
        startMirrorSource = 1;
        ssplinkMainPage.visible = false;
        if(loadingAppList == false)
        {
            globalObject.getLocalAppList();
            loadingAppList = true;
        }
        appListPage.visible     = true;
    }
    
    function exitAssisantClickedSignal()
    {
        console.log("exitAssisantClickedSignal");
        globalObject.assistantStateReport(0);
        globalObject.exitLink();
    }

    function onCancelClicked()
    {
        console.log("onCancelClicked");
        quitpage.visible = false;
    }

    function onMirrorBtnClicked()
    {
        console.log("onMirrorBtnClicked");
        startMirrorSource = 0;
        //mirrorStartPage.visible = true;
        globalObject.assistant_do_runMirror();
    }

    function onMirrorAOABtnClicked()
    {
        console.log("onMirrorAOABtnClicked");
        mirrorAOASolution.visible = true;
        ssplinkMainPage.visible   = false;
    }

    function onMirrorAOASolutionBackClick()
    {
        console.log("onMirrorAOASolutionBackClick");
        mirrorAOASolution.visible = false;
        ssplinkMainPage.visible   = true;
    }

    function onHelpBtnClicked()
    {
        console.log("onHelpBtnClicked");
        helpPage.visible = true;
        connectpage.visible = false;
    }

    function onApplistClickItem(index, appName)
    {
        console.log("onApplistClickItem index:", index);
        retryStartApp.curSelectIndex = index;
        retryStartApp.curSelectAppName = appName;
        appListPage.visible = false;
        if(appName == "电话")
        {
            onPhonebtnclicked();
            appListReturnClicked = true;
        }
        else if(appName == "短信")
        {
            onMessagebtnclicked();
            appListReturnClicked = true;
        }
        else if(appName == "日历")
        {
            onCalendarAppClicked();
            appListReturnClicked = true;
        }
        else if(appName == "音乐")
        {
            musicAppID = "ssp_music";
            globalObject.localMusicRun();
            onLocalMusicAppClicked();
            appListReturnClicked = true;
        }
        else if(appName == "天气")
        {
            onWeatherAppClicked();
            appListReturnClicked = true;
        }
        else
        {
            startAppPhrase.visible = true;
            globalObject.doLaunchApp(index);
            appListReturnClicked = true;
        }
    }

    function setAssistantConnectStatus(status)
    {
        console.log("setAssistantConnectStatus status:", status);
        connectpage.visible = true;

        if(status == 1) //connect
        {

        }
        else //disconnect
        {
            globalObject.assistantDeviceStateReport(0);
            phoneCallAnswer.visible  = false;
            loadingAppList           = false;
            helpPage.visible         = false;
            mirrorAOASolution.visible= false;
            loadingMusic             = false;
            appListReturnClicked     = false;
            messageApp.visible       = false;
            phoneApp.visible         = false;
            weatherApp.visible       = false;
            calendarApp.visible      = false;
            appListPage.visible      = false;
            ssplinkMainPage.visible  = false;
            localMusicApp.visible    = false;
            activate_tip.visible     = false;
            activating.visible       = false;
            activate_tip.item.onSwitchPage(1);
            activating.item.onSetActivationStatus(8);
            localMusicApp.item.setShowNoMusicText(0);
            globalObject.localMusic_do_ExitPhoneAPP();
            globalObject.freePhoneContactsMem();
            localmusic.clear();
            resetMusicInfo();
        }
    }

    function resetMusicInfo()
    {
        console.log("resetMusicInfo");
        localMusicApp.item.resetMusicNAmeAndSinger();
        ssplinkMainPage.item.musicName = "暂无音乐";
        ssplinkMainPage.item.musicSinger = "";
        ssplinkMainPage.item.isMusicPictureRotation = false;
    }

    function setAssistantProgressBarAndPhrase(value)
    {
        progressbarValue = value;
        console.log("############ setAssistantProgressBarAndPhrase value:",progressbarValue);

        if(progressbarValue == 10)
        {
            console.log("####### exit #######\n");
            connectpage.visible = false;
            ssplinkMainPage.visible = true;
        }

        switch(progressbarValue)
        {
        case 0:   //disconnect
            setAssistantConnectStatus(0);
            connectpage.item.promptPhrase= "";
            connectpage.item.setProgressConnectStatus(0);
            vrPage.visible = false;
            startAppWaitOutTime.stop();
            startAppPhrase.visible = false;
            break;
        case 1:   //connect
            setAssistantConnectStatus(1);
            connectpage.item.setProgressConnectStatus(1);
            break;
            //lanch success
        case 2:
            globalObject.assistantDeviceStateReport(1);
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在加载应用列表", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 3:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在获取应用图标",I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 4:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在同步应用", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 5:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在同步时间", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 6:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在获取短信记录", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 7:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在获取日历事件", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 8:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在获取音乐信息", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 9:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("正在获取天气信息", I108n.lang);});
            connectpage.item.setProgressConnectStatus(2);
            break;
        case 10:
            connectpage.item.setProgressConnectStatus(3);
            break;
            //lanch Failed
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15:
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("手机助手启动失败,请扫码安装手机助手并允许其运行", I108n.lang);});
            connectpage.item.setProgressConnectStatus(12);
            break;
        case 21:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("互联初始化失败,您的手机系统可能不被支持", I108n.lang);});
            connectpage.item.setProgressConnectStatus(12);
            break;
        case 22:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("互联初始化失败,请尝试重新连接USB", I108n.lang);});
            connectpage.item.setProgressConnectStatus(12);
            break;
        case 23:
            connectpage.item.promptPhrase= Qt.binding(function(){return qsTr("应用列表加载失败,请尝试重新连接USB", I108n.lang);});
            connectpage.item.setProgressConnectStatus(12);
            break;
        case 100:
            connectpage.item.promptPhrase= "不升级";
            break;
        case 101:
            connectpage.item.promptPhrase= "升级中";
            break;
        case 102:
            connectpage.item.promptPhrase= "升级失败";
            connectpage.item.setProgressConnectStatus(12);
            break;
        default:  break;
        }
    }

    function setVolumeValue(volumeValue, type)
    {
        console.log("\nsetVolumeValue volumeValue:", volumeValue);
        if(type == 0) //系统音量
        {
            volProgressBar.item.volumeValue = 15;
            volProgressBar.item.volumeMax = 30;
            volProgressBar.item.picSource = "../Assistantimages/volSysBar.png";
            volProgressBar.item.volumeValue = volumeValue;
            if(volumeValue ||volumeValue == 0)
            {
                if(volumeValue == 0)
                    muteIcon.visible = true;
                else
                    muteIcon.visible = false;
                volProgressBar.item.show();
            }
            else
                volProgressBar.item.hide();
        }
        else //倒车雷达音量
        {
            volProgressBar.item.volumeValue = 4;
            volProgressBar.item.volumeMax = 10;
            volProgressBar.item.picSource = "../Assistantimages/volNaviBar.png";
            volProgressBar.item.volumeValue = volumeValue;
            if(volumeValue ||volumeValue == 0)
            {
                if(volumeValue == 0)
                    muteIcon.visible = true;
                else
                    muteIcon.visible = false;
                volProgressBar.item.show();
            }
            else
                volProgressBar.item.hide();
        }
    }

    //flag instruction   0 unmute     1 mute
    function setMuteIcon(flag)
    {
        if(flag == 0)
            muteIcon.visible = false;
        else
            muteIcon.visible = true;
    }
    //flag instruction   0 disconnect  1:connect
    function setBluetoothIcon(flag)
    {
        if(flag == 0)
            bluetoothIcon.visible = false;
        else
            bluetoothIcon.visible = true;
    }
    // flag instruction   1: SDIcon Display
    function setSDIconDisplay(flag)
    {
        if(flag == 0)
            sdIcon.visible = false;
        else
            sdIcon.visible = true;
    }
    // flag instruction  1: AUX Display
    function setAUXIcondisplay(flag)
    {
        if(flag == 0)
            auxIcon.visible = false;
        else
            auxIcon.visible = true;
    }

    function setDisplayStatus(value)
    {
        console.log("\n #################  vale:",value);
        if(value == 1)
        {
            if(musicPlayStatus == 1 || musicPlayStatus == 2)
            {
                globalObject.localMusic_do_PlayOrPause('1');
                playOrStopFlag = 2;
                musicPlayStatus = -1;
            }

            globalObject.hideAssistantWindow();
            globalObject.assistantDisplayStateReport(0);
        }
        else if(value == 2)
        {
            if(playOrStopFlag == 2 && musicplayOrStopFlag == false)
            {
                globalObject.localMusic_do_PlayOrPause('0');
                playOrStopFlag = -1;
                musicPlayStatus = 2;
            }
            if(localMusicApp.visible)
            {
                if(appListReturnClicked == false)
                {
                    ssplinkMainPage.visible = true;
                    localMusicApp.visible   = false;
                }else{
                    appListPage.visible = true;
                    localMusicApp.visible = false;
                    appListReturnClicked = false;
                }
            }
            else if(messageApp.visible)
            {
                if(appListReturnClicked == false)
                {
                    ssplinkMainPage.visible = true;
                    messageApp.visible      = false;
                }else{
                    appListPage.visible = true;
                    messageApp.visible = false;
                    appListReturnClicked = false;
                }
            }
            else if(phoneApp.visible)
            {
                if(appListReturnClicked == false)
                {
                    ssplinkMainPage.visible = true;
                    phoneApp.visible        = false;
                }else{
                    appListPage.visible = true;
                    phoneApp.visible = false;
                    appListReturnClicked = false;
                }
            }
            else if(weatherApp.visible)
            {
                if(appListReturnClicked == false)
                {
                    ssplinkMainPage.visible = true;
                    weatherApp.visible      = false;
                }else{
                    appListPage.visible = true;
                    weatherApp.visible = false;
                    appListReturnClicked = false;
                }
            }
            else if(calendarApp.visible)
            {
                if(appListReturnClicked == false)
                {
                    ssplinkMainPage.visible = true;
                    calendarApp.visible     = false;
                }else{
                    appListPage.visible = true;
                    calendarApp.visible = false;
                    appListReturnClicked = false;
                }
            }

            globalObject.showAssistantWindow();
        }
        else if(value == 3)
        {
            globalObject.hideAssistantWindow();
        }
    }

    function onPrevClicked()
    {
        globalObject.localMusic_do_PlayPrevMusic();
    }

    function onPlayClicked()
    {
        globalObject.localMusic_do_PlayOrPause('0');
        musicPlayStatus = 1;
        musicplayOrStopFlag = false;
    }

    function onPauseClicked()
    {
        globalObject.localMusic_do_PlayOrPause('1');
        musicplayOrStopFlag = true;
    }

    function onNextClicked()
    {
        globalObject.localMusic_do_PlayNextMusic();
    }

    function getMusicInfo(songName,singer,songID,playStatus)
    {
        if(songName != "")
        {
            localMusicName = songName;
            ssplinkMainPage.item.musicName = songName;
            localMusicApp.item.setLocalMusicName(songName);
        }else{
            localMusicName = "未知";
            ssplinkMainPage.item.musicName = "未知";
            localMusicApp.item.setLocalMusicName("未知");
        }
        if(singer != "")
        {
            localMusicSinger = singer;
            ssplinkMainPage.item.musicSinger = singer;
            localMusicApp.item.setLocalMusicSinger(singer)
        }else{
            localMusicSinger = "未知";
            ssplinkMainPage.item.musicSinger = "未知";
            localMusicApp.item.setLocalMusicSinger("未知");
        }
        if(songID)
        {
            console.log("\n################# songID = ",songID);
            localMusicApp.item.setMusicListMusicId(songID);
        }
        if(playStatus == 0)
        {
            ssplinkMainPage.item.isMusicPictureRotation = true;
            localMusicApp.item.setMusicPageAndListAnimation(0);
            localMusicApp.item.setMusicPlayStatus(playStatus);
        }else{
            ssplinkMainPage.item.isMusicPictureRotation = false;
            localMusicApp.item.setMusicPageAndListAnimation(1);
            localMusicApp.item.setMusicPlayStatus(playStatus);
        }
    }

    function getPhonePlayOrPause(playStatus)
    {
        if(playStatus == 0)
        {
            ssplinkMainPage.item.isMusicPictureRotation = true;
            localMusicApp.item.setMusicPageAndListAnimation(0);
            localMusicApp.item.setMusicPlayStatus(playStatus);
        }else{
            ssplinkMainPage.item.isMusicPictureRotation = false;
            localMusicApp.item.setMusicPageAndListAnimation(1);
            localMusicApp.item.setMusicPlayStatus(playStatus);
        }
    }

    function getPlayOrPause(playStatus)
    {
        localMusicPlayStatus = playStatus;
        if(playStatus == 0)
        {
            ssplinkMainPage.item.isMusicPictureRotation = true;
            localMusicApp.item.setMusicPageAndListAnimation(0);
            localMusicApp.item.setMusicPlayStatus(playStatus);
        }else{
            ssplinkMainPage.item.isMusicPictureRotation = false;
            localMusicApp.item.setMusicPageAndListAnimation(1);
            localMusicApp.item.setMusicPlayStatus(playStatus);
        }
    }

    function getLocalPicture(picPath)
    {
        console.log("############# 111 ######### picPath= ",picPath);
        if(picPath == "1")
        {
            localMusicPicPath = "../Assistantimages/music_default.png";
            ssplinkMainPage.item.singerPicture = "../Assistantimages/music_default.png";
            localMusicApp.item.setLocalMusicSingerPicture("1");
        }else{
            localMusicPicPath = "file://"+picPath;
            ssplinkMainPage.item.singerPicture = "file://"+picPath;
            localMusicApp.item.setLocalMusicSingerPicture(picPath);
        }
    }

    function noMusic()
    {
        ssplinkMainPage.item.musicName = "暂无音乐";
        ssplinkMainPage.item.musicSinger = "";
        localMusicApp.item.setLocalMusicName("1");
        localMusicApp.item.setLocalMusicSinger("");
        localMusicApp.item.setShowNoMusicText(1);
    }

    function getWeatherIconPath(path)
    {
        ssplinkMainPage.item.weatherSourcePic = String(path);
    }

    function setAssistantAOAOrADB(flags)
    {
        console.log("\nsetAssistantAOAOrADB flags = ", flags);
        if(flags == 0)
            ssplinkMainPage.item.isOpenAdb = true;  //ADB
        else
            ssplinkMainPage.item.isOpenAdb = false; //AOA
    }

    function getActivateStatus(status)
    {
        console.log("############ getActivateStatus status", status);
        switch(status)
        {
        case 1:
            activate_tip.visible = true;
            activating.visible = false;
            activate_tip.item.onSwitchPage(1);
            activate_tip.item.onSetActivateBtn(false);
            activating.item.onSetActivationStatus(8);
            break;
        case 2:
            activate_tip.visible = true;
            activating.visible = false;
            activate_tip.item.onSwitchPage(1);
            activate_tip.item.onSetActivateBtn(true);
            activating.item.onSetActivationStatus(8);
            break;
        case 3:
            activate_tip.visible = false;
            activating.visible = true;
            activating.item.onSetActivationStatus(8);
            break;
        case 4:
            activate_tip.visible = false;
            activating.visible = true;
            activating.item.onSetActivationStatus(4);
            break;
        case 5:
            activate_tip.visible = false;
            activating.visible = true;
            activating.item.onSetActivationStatus(5);
            break;
        case 6:
            activate_tip.visible = false;
            activating.visible = true;
            activating.item.onSetActivationStatus(6);
            break;
        case 7:
            activate_tip.visible = false;
            activating.visible = true;
            activating.item.onSetActivationStatus(7);
            break;
        case 8:
            activate_tip.item.onSwitchPage(2);
            activate_tip.visible = true;
            activating.visible = false;
            activating.item.onSetActivationStatus(8);
            break;
        default: break;
        }
    }

    function calendar_on_updateEvent()
    {
        console.log("calendar_on_updateEvent");
        calendarApp.item.onClendarUpdateEvent();
    }

    function calendar_on_updateDateInfo()
    {
        console.log("calendar_on_updateDateInfo");
        calendarApp.item.onCalendarUpdateDateInfo();
    }

    function setPhoneCall(name, flag)
    {
        if(!isIgnore)
        {
            if(flag == 0)
            {
                phoneCallAnswer.item.callStatusText = "连接中...";
                phoneCallAnswer.item.callFlag = false;
            }
            else
            {
                phoneCallAnswer.item.callStatusText = "来电";
                phoneCallAnswer.item.callFlag = true;
            }
            phoneCallAnswer.visible = true;
            phoneCallAnswer.item.contectNameText = name;
            globalObject.specialShow();
        }
    }
    function setCallingText()
    {
        phoneCallAnswer.item.callStatusText = "通话中...";
    }
    function setAudioStatus(status)
    {
        audioStatus = status;
    }
    
    function getVRStatus(status, failStatus)
    {
        switch(status) {
        case 0:
            vrPage.item.setVRTips("<font color=\"#ee4545\">网络异常，请检查网络！</font>","");
            vrPage.item.setVREnable(false);
            break;
        case 1:
            vrPage.item.startLoading();
            vrPage.item.setVRTips("语音功能启动中...",
                                  "<font color=\"#b5b5b5\">请确认手机端是否允许获取录音（麦克风）权限，可勾选默认选区并点击允许。</font>");
            vrPage.visible = true;
            break;
        case 2:
            vrPage.item.setVRTips("<font color=\"#ee4545\">语音功能启动失败，请点击语音按钮重试！</font>",
                                  "<font color=\"#b5b5b5\">请确定手机端是否允许获取录音（麦克风）权限。</font>");
            vrPage.item.stopLoading();
            break;
        case 3:
            vrPage.item.setVRTips("请说话...",
                                  "<font color=\"#ee4545\">小萌正在倾听...</font>");
            vrPage.item.stopLoading();
            vrPage.item.startListening();
            break;
        case 4:
            vrPage.item.setVRTips("语音提交中...",
                                  "<font color=\"#ee4545\">小萌正在提交...</font>");
            vrPage.item.startLoading();
            vrPage.item.stopListening();
            break;
        case 5:
            vrPage.item.setVRTips("正在识别...",
                                  "<font color=\"#ee4545\">小萌好像听清了...</font>");
            vrPage.item.startLoading();
            vrPage.item.stopListening();
            break;
        case 6:
            vrPage.item.stopLoading();
            vrPage.item.stopListening();
            if(failStatus == 0xb0001)
                vrPage.item.setVRTips("<font color=\"#ee4545\">语音识别启动失败</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0002)
                vrPage.item.setVRTips("<font color=\"#ee4545\">你好像没有说话</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0003)
                vrPage.item.setVRTips("<font color=\"#ee4545\">识别失败，功能异常</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0004)
                vrPage.item.setVRTips("<font color=\"#ee4545\">网络出现异常</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0005)
                vrPage.item.setVRTips("<font color=\"#ee4545\">暂无此联系人</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0006)
                vrPage.item.setVRTips("<font color=\"#ee4545\">联系人异常，无法拨打</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0007)
                vrPage.item.setVRTips("<font color=\"#ee4545\">暂无音乐，快去下载吧</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0008)
                vrPage.item.setVRTips("<font color=\"#ee4545\">播放异常</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0009)
                vrPage.item.setVRTips("<font color=\"#ee4545\">没有上一首音乐</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb000a)
                vrPage.item.setVRTips("<font color=\"#ee4545\">没有下一曲音乐</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb000b)
                vrPage.item.setVRTips("<font color=\"#ee4545\">无此应用</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb000c)
                vrPage.item.setVRTips("<font color=\"#ee4545\">请到手机端安装此应用，安装成功后再次互联，即可使用！</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb000d)
                vrPage.item.setVRTips("<font color=\"#ee4545\">天气数据获取失败</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0010)
                vrPage.item.setVRTips("<font color=\"#ee4545\">检索失败</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0011)
                vrPage.item.setVRTips("<font color=\"#ee4545\">网络异常</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0012)
                vrPage.item.setVRTips("<font color=\"#ee4545\">地图功能异常</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0xb0013)
                vrPage.item.setVRTips("<font color=\"#ee4545\">算路失败</font>",
                                      "请点击麦克风重新说话");
            else if(failStatus == 0x00000)
                vrPage.item.setVRTips("<font color=\"#ee4545\">其他错误</font>",
                                      "请点击麦克风重新说话");
            break;
        case 7:
            vrPage.visible = false;
            break;
        default:  break;
        }
    }
    
    function dealwithSubAppStatus(status)
    {
        if(status == 1)
        {
            startAppWaitOutTime.stop();
            startAppPhrase.visible = false;
            if(startMirrorSource == 1)
                onAppListClicked();
        }
    }
    function runSubAppFromVR(appName)
    {
        if(appName == "otherApp")
        {
            appListPage.visible = false;
            startAppPhrase.visible = true;
            appListReturnClicked = true;
            vrPage.visible = false;
        }
        else
        {
            if(appName == "phone")
                onPhonebtnclicked();
            else if(appName == "message")
                onMessagebtnclicked();
            else if(appName == "calendar")
                onCalendarAppClicked();
            else if(appName == "music")
                onLocalMusicAppClicked();
            else if(appName == "weather")
                onWeatherAppClicked();
            vrPage.visible = false;
        }
    }

    function musicRunAppInfo(appID, appName, iconPath) {
        musicAppID = appID;
        if(appName != "")
        {
            if(!localMusicPlayStatus) {
                globalObject.localMusic_do_PlayOrPause('1');
            }

            ssplinkMainPage.item.musicName = appName;
            ssplinkMainPage.item.musicSinger = "";
            if(iconPath != "")
                ssplinkMainPage.item.singerPicture = "file://"+iconPath;
            else
                ssplinkMainPage.item.singerPicture = "../Assistantimages/music_default.png";
        }
        else
        {
            ssplinkMainPage.item.musicName = localMusicName;
            ssplinkMainPage.item.musicSinger = localMusicSinger;
            ssplinkMainPage.item.singerPicture = localMusicPicPath;
        }
    }

    Connections{
        target: globalObject;
        onGetVolumeValue:setVolumeValue(volumeValue, type);
        onSigSetDisplayStatus:setDisplayStatus(value);
        onSetMute:setMuteIcon(flag);
        onSdIconDisplayFlag:setSDIconDisplay(flag);
        onAuxIconDisplayFlag:setAUXIcondisplay(flag);
        onSetBluetooth:setBluetoothIcon(flag);
        onSigNoMusic:noMusic();
        onSigGetPhonePlayOrPause:getPhonePlayOrPause(playStatus);
        onSigGetPlayorPause:getPlayOrPause(playStatus);
        onSigGetLocalPicture:getLocalPicture(picPath);
        onSigGetMusicInfo:getMusicInfo(songName,singer,songID,playStatus);
        onGetSSPmainWeatherIconPath:getWeatherIconPath(path);
        onSigSetAssistantProgressBarAndPhrase:setAssistantProgressBarAndPhrase(value);
        onSigSetAssistantAOAOrADB:setAssistantAOAOrADB(flags);
        onSigAssistantActivationReminder:getActivateStatus(status);
        onSigSubAppStatus: dealwithSubAppStatus(status);
        onPhoneNoAnwer:onPhoneHangoff();
        onPhoneCall:setPhoneCall(name, flag);
        onPhoneCalling:setCallingText();
        onSigVRStatus:getVRStatus(status, failStatus);
        onSigrunSubAppFromVR:runSubAppFromVR(appName);
        onSigMusicRunAppInfo:musicRunAppInfo(appID, appName, iconPath);
        onSetTextNull:{
            c_thinkResultListModel.clear();      //清空联想结果
            phoneApp.item.setPhoneDialTextNull();//清空号码输入框内容
            phoneApp.item.onCategoryChanged(0);  //回到拨号界面
            phoneApp.item.setCategoryFocus(0);
        }
        onSigAudioStatus:setAudioStatus(status)
    }
    Connections{
        target:assistant
        onSignal_updateEvent:calendar_on_updateEvent();
        onSignal_updateDateInfo:calendar_on_updateDateInfo();
    }

}
