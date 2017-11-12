import QtQuick 2.0

Item{
    id: connectPage;
    width: 1280;
    height: 720;

    property int  progressValue:      0;


    Image {
        anchors.fill: parent;
        source: "../Assistantimages/shade.png"
    }

    Image {
        id: background
        x:91
        anchors.top: parent.top
        anchors.topMargin: 108
        anchors.horizontalCenter: parent.horizontalCenter;
        source: "../Assistantimages/box_bg.png"
    }

    Text {
        text: "正在同步手机应用，请稍候..."; 
        anchors.horizontalCenter: background.horizontalCenter;
        y:280
        verticalAlignment: Text.AlignTop
        font.pixelSize: 30;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
        horizontalAlignment: Text.AlignLeft
    }

    Image {
        id: progressBackgroudPic;
        anchors.centerIn: parent;
        width: 620;
        height: 13;
        source:"../Assistantimages/laoding_down.png"
        visible: true;
    }

    Rectangle{
        id:progressLoadingPic;
        anchors.top: progressBackgroudPic.top;
        anchors.left:progressBackgroudPic.left;
        height: 13;
        width: progressValue;
        radius: 8;
        color: "#20d4da";
        visible:0 !== opacity
        state: "visual";

        states: State{
            name: "visual"
            PropertyChanges {
                target: progressLoadingPic
                opacity:0
            }
        }
    }

    function progressLoadingShow()
    {
        progressLoadingPic.state = "";
    }

    function progressLoadingHide()
    {
        progressLoadingPic.state = "visual";
    }

}

