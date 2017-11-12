import QtQuick 2.0


Item {
    id:volumeProgressBar
    width:volSysBarPic.width;
    height:volSysBarPic.height;
    property int volumeValue: 15;
    property int volumeMax: 30;
    property string picSource: "../Assistantimages/volSysBar.png";

    function show()
    {
        volSysBarPic.state = "";
        volumeHideTimer.restart();
    }

    function hide()
    {
        volSysBarPic.state = "hide"
    }

    Image{
        id: volSysBarPic;
        width: 858;
        height: 103;
        source: picSource
        visible:0 !== opacity
        state:"hide"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                volSysBarPic.state = "hide"
            }
        }

        Rectangle{
            id: barLength
            x:120;y:45
            height: 12
            width: (550/volumeMax)*volumeValue
            color: "#00fffc"
        }

        Text{
            anchors.right: parent.right;
            anchors.rightMargin: 45
            anchors.verticalCenter: parent.verticalCenter
            color: "#ffffff"
            font.family: fontFamily;
            font.pixelSize: 33
            text: volumeValue
        }

        states: State{
            name: "hide"
            PropertyChanges {
                target: volSysBarPic
                opacity:0
            }
        }

    }

    Timer{
        id: volumeHideTimer;
        interval: 5000;
        running: true
        onTriggered:volSysBarPic.state = "hide";
    }

}
