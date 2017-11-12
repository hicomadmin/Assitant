import QtQuick 2.2

Item {
    id: startPage;
    width: 1280;
    height: 720;

    Image {
        id:background;
        anchors.fill: parent;
        width: 1280;
        height: 720;
        source: "../Assistantimages/start.png"
    }

    MouseArea {
        anchors.fill: parent;
    }

    Timer {
        interval: 3000; running: visible; repeat: false
        onTriggered: {
            visible = false;
            sigSplashTimeout();
        }
    }

    MouseArea {
        anchors.fill: parent;
    }

    signal sigSplashTimeout();
}
