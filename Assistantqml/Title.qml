import QtQuick 2.0

Item {
    id:titlepage;
    width: 1280;
    height: 104;
    property string titleText: "";

    Loader {
        width: 67;
        height: 67;
        source: "Button.qml"
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(titlepage.backClicked);
        }
    }

    Text {
        text:titleText;
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 42;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
    }

    signal backClicked();
}
