import QtQuick 2.0

Item{
    id: activationProgressBard;
    width: 1280;
    height: 720;

    property string title: qsTr("激活中，请稍后...");

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
        id: finishedPic;
        x:449
        y:166
        visible:false
        source: "../ActivationImages/common/pic2.png"
    }

    Text {
        id: activationTitle;
        x: 514
        y: 166
        text: title
        color: "#ffffff";
        font.family: fontFamily;
        font.pixelSize: 38;
    }

    Image {
        id: step1;
        x:449
        y:274
        source: "../ActivationImages/1.png"
    }

    Text {
        x: 518
        text: qsTr("1、正在初始化激活程序");
        anchors.top: parent.top;
        anchors.topMargin: 286
        color: "#ffffff";
        font.family: fontFamily;
        font.pixelSize: 34;
    }

    Image {
        id: step2;
        x:449
        y:357
        source: "../ActivationImages/1.png"
    }

    Text {
        x: 518
        text: qsTr("2、正在注册激活信息");
        anchors.top: parent.top;
        anchors.topMargin: 369
        color: "#ffffff";
        font.family: fontFamily;
        font.pixelSize: 34;
    }

    Image {
        id: step3;
        x:449
        y:443
        source: "../ActivationImages/1.png"
    }

    Text {
        x: 518
        text: qsTr("3、正在验证激活信息");
        anchors.top: parent.top;
        anchors.topMargin: 455
        color: "#ffffff";
        font.family: fontFamily;
        font.pixelSize: 34;
    }

    Image {
        id: step4;
        x:449
        y:527
        source: "../ActivationImages/1.png"
    }

    Text {
        x: 518
        text: qsTr("4、正在完成激活");
        anchors.top: parent.top;
        anchors.topMargin: 539
        color: "#ffffff";
        font.family: fontFamily;
        font.pixelSize: 34;
    }

    Image {
        x:1045
        y:668
        source: "../ActivationImages/common/logo.png"
    }

    function onSetActivationStatus(status)
    {
        console.log("onSetActivationStatus status:", status);
        switch(status)
        {
        case 4:
            step1.source = "../ActivationImages/2.png";
            break;
        case 5:
            step1.source = "../ActivationImages/2.png";
            step2.source = "../ActivationImages/2.png";
            break;
        case 6:
            step1.source = "../ActivationImages/2.png";
            step2.source = "../ActivationImages/2.png";
            step3.source = "../ActivationImages/2.png";
            break;
        case 7:
            step1.source = "../ActivationImages/2.png";
            step2.source = "../ActivationImages/2.png";
            step3.source = "../ActivationImages/2.png";
            step4.source = "../ActivationImages/2.png";
            finishedPic.visible = true;
            title = qsTr("激活成功，请断开手机！");
            break;
        case 8: //reset
            step1.source = "../ActivationImages/1.png";
            step2.source = "../ActivationImages/1.png";
            step3.source = "../ActivationImages/1.png";
            step4.source = "../ActivationImages/1.png";
            finishedPic.visible = false;
            title = qsTr("激活中，请稍后...");
            break;
        default: break;
        }
    }
}
