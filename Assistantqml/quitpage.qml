import QtQuick 2.0

Item {
    id: quitpage;
    width: 1280;
    height: 720;

    MouseArea {
        anchors.fill: parent;
    }

    Image {
        anchors.fill: parent;
        source: "../Assistantimages/shade.png"
    }

    Image {
        id:box;
        x:91
        anchors.top: parent.top
        anchors.topMargin: 108
        source: "../Assistantimages/box_bg.png"
    }

    Image {
        anchors.horizontalCenter: box.horizontalCenter
        y:250;
        source: "../Assistantimages/box_list.png"
    }

    Text {
        text: qsTr("退出提醒",I108n.lang);
        x:332;
        y:192;
        verticalAlignment: Text.AlignTop
        font.pixelSize: 40;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
        horizontalAlignment: Text.AlignLeft
    }

    Text {
        text: I108n.lang == "en" ? "Whether to quit <font color=\"#00fffc\">SSP-Link</font>?" : "是否退出<font color=\"#00fffc\">SSP-Link</font>?";
        anchors.horizontalCenter: parent.horizontalCenter
        y:305;
        font.pixelSize: 40;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
        horizontalAlignment: Text.AlignLeft
    }

    Loader {
        id:cancel;
        width: 252;
        height: 76;
        source: "Button.qml"
        x:370;
        y:390;
        onLoaded: {
            item.normalSource = "../Assistantimages/d.png";
            item.pressSource = "../Assistantimages/n.png";
            item.btnText = Qt.binding(function(){return qsTr("取消", I108n.lang);});
            item.textsize = 36;
            item.clicked.connect(quitpage.cancelClicked);
        }
    }

    Loader {
        id:quit;
        width: 252;
        height: 76;
        source: "Button.qml"
        x:690;
        y:390;
        onLoaded: {
            item.normalSource = "../Assistantimages/d.png";
            item.pressSource = "../Assistantimages/n.png";
            item.btnText = Qt.binding(function(){return qsTr("退出", I108n.lang);});
            item.textsize = 36;
            item.clicked.connect(quitpage.quitClicked);
        }
    }
    
    signal cancelClicked();
    signal quitClicked();
}
