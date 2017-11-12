import QtQuick 2.0
//import QtGraphicalEffects 1.0

Item {
    id: splash_page
    x: 0
    width: 1280
    height: 720

    MouseArea {
        anchors.fill: parent;
        enabled: false;
    }

    Image {
        id: bk
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        source: "../weatherImages/bg/begin.png"
    }

        Timer {
            interval: 300; running: visible; repeat: false
            onTriggered: {
                visible = false;
                sigsplashtimeout();
            }
    }
    signal sigsplashtimeout();
}

