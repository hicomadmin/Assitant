import QtQuick 2.0

Item {
    width: parent.width
    height: parent.height
    anchors.fill: parent

    Image {
        id: bg
        anchors.fill: parent
        source: "../Assistantimages/VRcutting/bg.png"
    }

    MouseArea {
        anchors.fill: parent
    }

    Loader {
        width: 67;
        height: 67;
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        source: "Button.qml"
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(backBtnClicked);
        }
    }

    Text {
        id:title
        text:titleText
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 90;
        font.pixelSize: 40;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Text {
        id:subtitle
        text:subTitleText
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: title.bottom;
        anchors.topMargin: 25;
        font.pixelSize: 25;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Item {
        id:voiceBtn
        width: 227
        height: 229
        anchors.left: parent.left
        anchors.leftMargin: 70
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 196

        Image {
            id:iconNormal
            anchors.fill: parent
            source: "../Assistantimages/VRcutting/icon-bg.png"
        }

        Image {
            anchors.centerIn: parent
            source: "../Assistantimages/VRcutting/pic0.png"
        }

        Image {
            id:listening1
            anchors.centerIn: parent
            source: "../Assistantimages/VRcutting/small.png"
            visible: false;
        }

        Image {
            id:listening2
            anchors.centerIn: parent
            source: "../Assistantimages/VRcutting/big.png"
            visible: false;
        }

        Image {
            anchors.fill: parent
            source: "../Assistantimages/VRcutting/icon_bg_B.png"
            visible: !voiceBtn.enabled;
        }

        Image {
            id: iconPress
            anchors.fill: parent
            source: "../Assistantimages/VRcutting/icon_bg_B.png"
            visible: false;
        }

        Image {
            anchors.centerIn: parent
            source: "../Assistantimages/VRcutting/laoding.png"
            visible: loading.running
            RotationAnimation on rotation {
                id:loading;
                loops: Animation.Infinite;
                from: 0;
                to: 360;
                duration: 1000;
                running: false;
            }
        }

        MouseArea {
            anchors.fill: parent
            onReleased: {
                iconPress.visible = false;
            }
            onPressed: {
                if(!loading.running) {
                    iconPress.visible = true;
                }
            }
            onClicked: {
                iconPress.visible = false;
                if(!loading.running) {
                    if(!listenTimerStart)
                    {
                        globalObject.requestVRStatus("start");
                    }
                    else
                    {
                        stopListening();
                        globalObject.requestVRStatus("end");
                    }
                }
            }
        }

//        Timer {
//            id:loadingcheckTime
//            interval: 60000
//            onTriggered: {
//                loading.running = false;
//            }
//            running: loading.running
//        }

    }

    Image {
        id:appIcon
        anchors.left: voiceBtn.right
        anchors.leftMargin: 147
        anchors.top: parent.top
        anchors.topMargin: 342
        source: "../Assistantimages/VRcutting/pic1.png"
    }

    Text {
        text:appText
        anchors.left: appIcon.right
        anchors.leftMargin: 28
        anchors.top: parent.top;
        anchors.topMargin: 346;
        font.pixelSize: 30;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Image {
        id: phoneIcon
        anchors.left: voiceBtn.right
        anchors.leftMargin: 147
        anchors.top: appIcon.bottom
        anchors.topMargin: 13
        source: "../Assistantimages/VRcutting/pic2.png"
    }

    Text {
        text:phoneText
        anchors.left: phoneIcon.right
        anchors.leftMargin: 28
        anchors.top: appIcon.bottom;
        anchors.topMargin: 18;
        font.pixelSize: 30;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Image {
        id: musicIcon
        anchors.left: voiceBtn.right
        anchors.leftMargin: 147
        anchors.top: phoneIcon.bottom
        anchors.topMargin: 13
        source: "../Assistantimages/VRcutting/pic3.png"
    }

    Text {
        text:musicText
        anchors.left: musicIcon.right
        anchors.leftMargin: 28
        anchors.top: phoneIcon.bottom;
        anchors.topMargin: 20;
        font.pixelSize: 30;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Timer {
        id:startListenTime
        interval: 500;
        repeat: true;
        onTriggered: {
            if(listeningFlag)
            {
                listening1.visible = true;
                listening2.visible = false;
                listeningFlag = 0;
            }
            else
            {
                listening1.visible = false;
                listening2.visible = true;
                listeningFlag = 1;
            }
        }
    }

    function startLoading() {
        loading.running = true;
    }

    function stopLoading() {
        loading.running = false;
    }

    function setVRTips(ititle, isubtitle) {
        titleText = ititle;
        subTitleText = isubtitle;
    }

    function setVREnable(flag) {
        voiceBtn.enabled = flag;
    }

    function startListening() {
        listenTimerStart = true;
        startListenTime.start();
    }

    function stopListening() {
        listenTimerStart = false;
        startListenTime.stop();
        listening1.visible = false;
        listening2.visible = false;
    }

    signal backBtnClicked();

    property string titleText: "语音功能启动中...";
    property string subTitleText: "<font color=\"#b5b5b5\">小萌正在倾听...</font>";
    property string appText: "进应用 : <font color=\"#b5b5b5\">“ 启动虾米音乐 ” 或 “ 打开日历 ”</font>";
    property string musicText: "听音乐 : <font color=\"#b5b5b5\">“ 上一首 ”“ 下一首 ”“ 播放音乐 ”“ 暂停音乐 ”</font>";
    property string phoneText: "打电话 : <font color=\"#b5b5b5\">“ 打电话给妈妈 ” 或 “ 拨打电话给妈妈 ”</font>";
    property int listeningFlag: 1;
    property bool listenTimerStart: false;

}
