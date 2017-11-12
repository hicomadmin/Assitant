import QtQuick 2.0

Item {
    id: title;
    width: 1280;
    height: 105;
    anchors.right: parent.right;
    anchors.top: parent.top;

    Image {
        anchors.left: parent.left;
        anchors.top: parent.top;
        source: "../messageimages/title.png";
    }

    Loader {
        width: 67;
        height: 67;
        source: "../Assistantqml/Button.qml";
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(title.backClicked);
        }
    }

    Text {                                  // 短信及短信对话业，上方标题。显示联系人名称/号码
        text: titleText;
        font.pixelSize: 42;
        font.family: fontFamily;
        color: "#ffffff";       
        anchors.centerIn: parent;
    }

    signal backClicked();
    property string titleText: "";
}

