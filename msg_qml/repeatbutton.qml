//短信快速回复，失败后可重发  参考--T15 Button.qml
import QtQuick 2.0


Item {
    id: button;
    width: 60;
    height: 60;
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
    Image {
        id: disabled;
        anchors.fill: parent;
        source: disableSource;
        visible: !button.enabled;
    }
    onEnabledChanged: {
        if(enabled) {
            normal.visible = !button.focus;
            press.visible = button.focus;
            disabled.visible = false;
        }else{
            normal.visible = false;
            press.visible = false;
            disabled.visible = true;
        }
    }
    onFocusChanged: {
        if(focus) {
            normal.visible = false;
            press.visible = true;
        }else{
            normal.visible = true;
            press.visible = false;
        }
    }

    Text {
        anchors.centerIn: parent;
        text: btnText;
        font.pixelSize: 24;
        color: "#ffffff";
        //font.family: fontFamily;
    }

    MouseArea  {
        anchors.fill: parent;

        onPressed: {
            button.focus = true;
            onButtonPressed(mouse.x, mouse.y);
           // console.log("Button--onPressed");
        }

        onExited: {
            button.focus = false;
            //console.log("Button--onReleased");
        }

        onClicked: {
            button.focus = false;
            onButtonClicked(mouse.x, mouse.y);
            //console.log("Button--onClicked");
        }
    }

    property string normalSource;
    property string pressSource;
    property string disableSource;
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

