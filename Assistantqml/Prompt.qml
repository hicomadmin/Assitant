import QtQuick 2.0

Item {
    id: promptWindow;
    width: 1280;
    height: 720;
    property string disconnectType: "";
    property bool btnVisible: true;
    property string btnOK: "重试";

    Image {
        anchors.fill: parent;
        source: "../Assistantimages/shade.png"
    }

    MouseArea {
        anchors.fill: parent;
    }

    Image {
        x:91
        anchors.top: parent.top
        anchors.topMargin: 108
        source: "../Assistantimages/box_bg.png"
    }

    Image {
        anchors.horizontalCenter: parent.horizontalCenter
        y:270;
        source: "../Assistantimages/box_list.png"
    }

    Text {
        id: topPrompt
        x: 331
        y:218
        verticalAlignment: Text.AlignTop
        font.pixelSize: 36;
        font.family: fontFamily;
        color: "#ffffff";
        text: "提醒"
        wrapMode: Text.Wrap;
    }

    Text {
        id: textContent
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: retryBtn.top
        anchors.bottomMargin: 30
        color: "#ffffff"
        font.family: fontFamily;
        text:disconnectType;
        wrapMode: Text.WordWrap
        font.pixelSize: 29
    }

    Loader {
        id:retryBtn
        width: 252;
        height: 76;
        source: "Button.qml"
        y:400;
        anchors.horizontalCenter: parent.horizontalCenter;
        visible: btnVisible;
        onLoaded: {
            item.normalSource = "../Assistantimages/d.png";
            item.pressSource = "../Assistantimages/n.png";
            item.btnText = btnOK;
            item.textsize = 39;
            item.clicked.connect(promptWindow.signRetry);
        }
    }

    signal signRetry();
}
