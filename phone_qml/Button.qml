import QtQuick 2.0

Item {
    id: button;
    anchors.fill: parent;
    focus: false;

    Image {
        id: normal;
        anchors.fill: parent;
        source: normalSource;
        visible: !button.focus;
    }
    Image {
        id: press;
        anchors.fill: parent;
        source: pressSource;
        visible: button.focus;
    }

    Text {
        anchors.centerIn: parent;
        text: btnText;
        font.pixelSize: 24;
        font.family: fontFamily;
        color: "#ffffff";
    }

    MouseArea  {
        anchors.fill: parent;

        onPressed: {
            button.focus = true;
            onButtonPressed(mouse.x, mouse.y);
        }

        onExited: {
            button.focus = false;
        }

        onReleased: {
            button.focus = false;
        }

        onClicked: {
            button.focus = false;
            onButtonClicked(mouse.x, mouse.y);
        }
    }

    property string normalSource;
    property string pressSource;
    property string btnText: "";
    signal pressed();
    signal pressedXY(int x, int y);
    signal clicked();
    signal clickedXY(int x, int y);

    function onButtonPressed(x, y) {
        pressed();
        pressedXY(x, y);
    }
    function onButtonClicked(x, y) {
        clicked();
        clickedXY(x, y);
    }
    function setEnabled(enabled)
    {
        button.enabled = enabled;
    }
}


