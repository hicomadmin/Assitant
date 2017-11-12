import QtQuick 2.0

Item {
    id: button;
    focus: false;
    x: xPos;
    y: yPos;

    property int ispressinputboxtext:0;
    property int textsize: 38
    property bool benable:true;
    property bool bcheck:false;
    property bool bflag:false;

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
        id: check;
        anchors.fill: parent;
        source: pressSource;
        visible: button.bcheck;
    }

    Text {
        id:btntitle
        anchors.centerIn: parent;
        text: btnText;
        font.pixelSize: textsize;
        color:ispressinputboxtext==0?"#ffffff":"#6252ff";
        font.family: fontFamily;
    }

    Image {
        id: affairsFlag;
        anchors.top: btntitle.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: -1
        source: flagSource;
        visible: button.bflag;
    }

    MouseArea  {
        anchors.fill: parent;

        onPressed: {
            if(benable){
                button.focus = true;
                onButtonPressed(mouse.x, mouse.y);
                //console.log("Button--onPressed");
            }
        }

        onExited: {
             if(benable){
                 button.focus = false;
             }
        }

        onReleased: {
            if(benable){
                button.focus = false;
                //console.log("Button--onReleased");
            }
        }

        onClicked: {
            if(benable){
                button.focus = false;
                onButtonClicked(mouse.x, mouse.y);
                //console.log("Button--onClicked");
            }
        }
    }

    property int xPos;
    property int yPos;

    property string normalSource;
    property string pressSource;
    property string checkSource;
    property string flagSource;
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

