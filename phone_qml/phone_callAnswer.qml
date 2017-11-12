import QtQuick 2.0

Item {
    property bool   callFlag: false;     //来电标识
    property string callStatusText: "";  //电话状态
    property string contectNameText: ""; //联系人姓名
    signal hangOffIconClicked();

    Image {
        anchors.fill: parent
        source: "../Assistantimages/bg.png"
    }
    
    MouseArea{
        anchors.fill: parent
    }
    Text {
        id: title;
        x: 597
        y: 31
        color: "#ffffff"
        text: qsTr("电话", I108n.lang);
        font.pixelSize: 43
        font.family: fontFamily;
    }

    Image {
        id: bg_callAnswer
        anchors.left: parent.left
        anchors.leftMargin: 32;
        anchors.top: parent.top;
        anchors.topMargin: 104;
        anchors.right: parent.right
        anchors.rightMargin: 32;
        source: "../phoneimages/callAnswer_bg.png" //32

    }

    Text {
        id: friendHint
        anchors.horizontalCenter: bg_callAnswer.horizontalCenter;
        anchors.top: bg_callAnswer.bottom;
        anchors.topMargin: 10;
        color: "#ffffff";
        font.pixelSize: 30;
        font.family: fontFamily;
        visible: false;
        text: qsTr("友好提醒：你的手机不支持车机调取免提功能，请通过手机端接听电话。", I108n.lang);
    }

    Image{
        id:contectIcon;
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: bg_callAnswer.top;
        anchors.topMargin: 30;
        width: 172;
        height: 171;
        source: "../phoneimages/photo.png"
    }

    Text {
        id: contectName;
        objectName: "contectName";
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: contectIcon.bottom;
        anchors.topMargin:20;
        text: contectNameText;
        font.family: fontFamily;
        font.pixelSize: 36;
    }
    Text {
        id: callStatus;
        //objectName: "callStatus";
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: contectName.bottom;
        anchors.topMargin:20;
        text: callStatusText;
        font.family: fontFamily;
        font.pixelSize: 36;
    }

    //加载挂断键 中间
    Loader{
        id:hodeOff_key;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: bg_callAnswer.bottom;
        anchors.bottomMargin:  32;
        width: 150;
        height: 150;
        visible: !callFlag;
        source: "../Assistantqml/Button.qml";
        onLoaded: {
            item.normalSource = "../phoneimages/done.png"
            item.pressSource = "../phoneimages/done_p.png";
            item.clicked.connect(onHodeOffKeyClicked);
        }
    }

    //加载挂断键 旁边
    Loader{
        id:hodeOff_key_RightBy;
        anchors.left: hodeOff_key.right;
        anchors.leftMargin: 100;
        anchors.bottom: bg_callAnswer.bottom;
        anchors.bottomMargin:  32;
        width: 150;
        height: 150;
        visible: callFlag;
        source: "../Assistantqml/Button.qml";
        onLoaded: {
            item.normalSource = "../phoneimages/done.png"
            item.pressSource = "../phoneimages/done_p.png";
            item.clicked.connect(onHodeOffKeyClicked);
        }
    }

    //接听键 旁边
    Loader{
        id:answer_key;
        anchors.right: hodeOff_key.left;
        anchors.rightMargin: 100;
        anchors.bottom: bg_callAnswer.bottom;
        anchors.bottomMargin:  32;
        width: 150;
        height: 150;
        visible: callFlag;
        source: "../Assistantqml/Button.qml";
        onLoaded: {
            item.normalSource = "../phoneimages/take.png"
            item.pressSource = "../phoneimages/take_p.png";
            item.clicked.connect(onAnswerKeyClicked);
        }
    }

    function onHodeOffKeyClicked()
    {
        callFlag = false;
        hangOffIconClicked();
    }

    function onAnswerKeyClicked()
    {
        callFlag = false;
        console.log("############################ onAnswerKeyClicked");
        globalObject.phoneAnswerCall();
    }
}

