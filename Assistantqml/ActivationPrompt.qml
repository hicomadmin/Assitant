import QtQuick 2.0

Item{
    id: activationProgressBard;
    width: 1280;
    height: 720;
    property string activationBtnText: activationBtn.enabled?qsTr("<font color=\"#ffffff\">开始激活</font>"):qsTr("<font color=\"#818181\">开始激活</font>");

    signal signStartActivating();
    signal signBack();

    Image {
        id: background;
        anchors.fill: parent;
        source: "../ActivationImages/bg.png";
        visible: true;
        MouseArea {
            anchors.fill: parent
            onClicked: {}
        }
    }

    Image {
        anchors.fill: parent;
        source: "../ActivationImages/box_bg.png";
        visible: true;
    }

    Image {
        y:225
        anchors.horizontalCenter: parent.horizontalCenter
        source: "../ActivationImages/box_list.png"
    }

    Item{
        id:activate_tipsPage
        width: 1280;
        height: 720;
        visible:false
        Image {
            id: tipPic;
            x:505
            y:165
            source: "../ActivationImages/common/pic3.png"
        }

        Text {
            id: activationTitle;
            x: 570
            y: 165
            text:qsTr("激活提醒");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 38;
        }

        Text {
            id: activationContent;
            text: qsTr("<font color=\"#00fffc\">版本尚未激活,</font> 请连接手机激活程序进行激活。");
            x:290
            y:255
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 34;
        }

        Text {
            id: attation;
            x: 290
            y: 320
            text: qsTr("<font color=\"#00fffc\">注意: </font>激活过程中,");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 34;
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft;
        }

        Text {
            x: 374
            y: 369
            text: qsTr("车机端：请勿<font color=\"#ff3131\">断电、车机点火、断开手机；</font>");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 34;
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft;
        }

        Text {
            x: 374
            y: 414
            text: qsTr("手机端：保持<font color=\"#ff3131\">手机电量充足、网络顺畅、</font>")
            color: "#ffffff"
            font.family: fontFamily;
            font.pixelSize: 34;
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft;
        }

        Text {
            x: 495
            y: 455
            text: qsTr("请勿<font color=\"#ff3131\">断开手机USB连接。</font>");
            color: "#ffffff"
            font.family: fontFamily;
            font.pixelSize: 34;
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft;
        }

        Loader {
            id:activationBtn_Unable
            y:512
            anchors.horizontalCenter: parent.horizontalCenter;
            width: 252
            height: 76
            source: "Button.qml"
            visible: !activationBtn.enabled
            enabled: false
            onLoaded: {
                item.normalSource = "../ActivationImages/n1.png";
                item.pressSource = "../ActivationImages/n1.png";
                item.btnText = activationBtnText;
            }
        }

        Loader {
            id:activationBtn
            y:512
            anchors.horizontalCenter: parent.horizontalCenter;
            width: 252
            height: 76
            source: "Button.qml"
            visible: !activationBtn_Unable.visible
            onLoaded: {
                item.normalSource = "../ActivationImages/n.png";
                item.pressSource = "../ActivationImages/n1.png";
                item.btnText = activationBtnText;
                item.clicked.connect(onStartActivating);
            }
        }

    }

    Item {
        id:activate_failPage
        visible:true;
        width: 1280;
        height: 720;
        Image {
            x:505
            y:165
            source: "../ActivationImages/common/pic1.png"
        }

        Text {
            x: 570
            y: 165
            text:qsTr("激活失败！");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 38;
        }

        Text {
            x:250
            y:320
            text: qsTr("<font color=\"#00fffc\">失败原因：</font> 互联断开或网络异常原因断开、网络不可用、");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 34;
        }


        Text {
            x:413
            y:370
            text: qsTr("服务器响应失败、激活超时等。");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 34;
        }

        Text {
            x:413
            y:416
            text: qsTr("<font color=\"#00fffc\">请重新插拔手机进行重试！</font>");
            color: "#ffffff";
            font.family: fontFamily;
            font.pixelSize: 34;
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft;
        }

        Loader {
            x:110;
            y:120
            width: 68;
            height: 72;
            source: "Button.qml"
            onLoaded: {
                item.normalSource = "../Assistantimages/back_icon_n.png";
                item.pressSource = "../Assistantimages/back_icon_p.png";
                item.clicked.connect(onBackClicked);
            }
        }

    }


    Image {
        x:1045
        y:668
        source: "../ActivationImages/common/logo.png"
    }

    function onStartActivating()
    {
        signStartActivating();
    }

    function onBackClicked()
    {
        activate_tipsPage.visible = true;
        activate_failPage.visible = false;
        signBack();
    }

    function onSetActivateBtn(iStatus)
    {
        activationBtn.enabled = iStatus;
    }

    function onSwitchPage(iPage)
    {
        if(iPage == 1){
            activate_tipsPage.visible = true;
            activate_failPage.visible = false;
        }
        else{
            activate_tipsPage.visible = false;
            activate_failPage.visible = true;
        }

    }
}
