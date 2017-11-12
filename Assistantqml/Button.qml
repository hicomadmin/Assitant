import QtQuick 2.0


Item {
    id: button;
    anchors.fill: parent;
    focus: false;

    property int ispressinputboxtext:0;
    property int textsize: 24


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
        font.pixelSize: textsize;
        color:ispressinputboxtext==0?"#ffffff":"#6252ff";
        font.family: fontFamily;
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
}

