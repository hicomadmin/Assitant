import QtQuick 2.0


Item {
    id:barcode
    width: 1280;
    height: 720;

    property  int  progressValue: 0;
    property  string promptText: "提醒：了解更多详情，请查看车机帮助。";
    property  string promptPhrase:  "";


    // 构造函数
    Component.onCompleted: {
        // 连接信号和槽
        I108n.languageChanged.connect(translator)
        // 初始化
        translator()
    }

    // 翻译
    function translator() {
        helpBtn.item.btnText = qsTr("帮助")
        connectText.text = qsTr("正在同步手机应用,请稍后...")
        failedText.text = qsTr("连接失败")
        prompt1.text = qsTr("提醒：了解更多详情，请查看车机帮助。");
        if(I108n.lang == "en")
            prompt1.y = 600;
        else
           prompt1.y = 620;
    }

    Image {
        id:bkg;
        width: 1280;
        height: 720;
        source: "../Assistantimages/barcode/bg.png"
        Text {
            id: text1;
            x: 575;
            y: 154;
            font.family: fontFamily;
            font.pixelSize: I108n.lang == "en" ? 26 : 32;
            color: "#ffffff"
            text: qsTr("①扫描左侧二维码，下载手机助手APP", I108n.lang)
        }
        Text {
            id: text2
            x: 575;
            anchors.top: text1.bottom;
            anchors.topMargin: I108n.lang == "en" ? 5 : 10;
            font.family: fontFamily;
            font.pixelSize: I108n.lang == "en" ? 26 : 32;
            color: "#ffffff"
            text: qsTr("②将手机的USB与车机进行连接", I108n.lang)
        }
        Text {
            x: 575;
            anchors.top: text2.bottom;
            anchors.topMargin: I108n.lang == "en" ? 5 : 10;
            font.family: fontFamily;
            font.pixelSize: I108n.lang == "en" ? 26 : 32;
            color: "#ffffff"
            text: qsTr("③连接成功后，自动同步手机中的APP", I108n.lang)
        }
    }

    Image {
        id: barcodePic
        width:351;
        height:351;
        x:172;
        y:96;
        source: "../Assistantimages/barcode/barcodePic.png"
    }

    Image {
        id: rectangPic
        width:871;
        height:185;
        anchors.top: barcodePic.bottom;
        anchors.topMargin: 50;
        x:205;
        source: "../Assistantimages/barcode/pic1.png"
    }
    
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
            item.clicked.connect(backBtnClicked);
        }
    }

    Loader {
        id: helpBtn
        width: 162;
        height: 70;
        source: "Button.qml"
        anchors.left: barcodePic.right;
        anchors.leftMargin: 53;
        anchors.top: parent.top;
        anchors.topMargin: 370;
        onLoaded: {
            item.normalSource = "../Assistantimages/barcode/1_n.png"
            item.pressSource = "../Assistantimages/barcode/1_p.png"
            item.btnText = "帮助";
            item.textsize = 30;
            item.clicked.connect(barcode.helpClicked);
        }
    }

    Text {
        id: reminder
        anchors.left: rectangPic.left;
        anchors.leftMargin: 108;
        anchors.top: barcodePic.bottom;
        anchors.topMargin: 33;
        font.family: fontFamily;
        font.pixelSize: 32;
        color: "#06a9e9"
        text: qsTr("连接中,请稍候...", I108n.lang)
        visible: false;
    }

    Text {
        id: connectText;
        anchors.left: rectangPic.left;
        anchors.leftMargin: 108;
        anchors.top: barcodePic.bottom;
        anchors.topMargin: 33;
        font.family: fontFamily;
        font.pixelSize: 32;
        color: "#06a9e9"
        text: qsTr("正在同步手机应用,请稍候...", I108n.lang)
        visible: false;
    }

    Text {
        id: failedText;
        anchors.left: rectangPic.left;
        anchors.leftMargin: 168;
        anchors.top: barcodePic.bottom;
        anchors.topMargin: 33;
        font.family: fontFamily;
        font.pixelSize: 32;
        color: "#ff3333"
        text: qsTr("连接失败", I108n.lang)
        visible: false;
    }

    Image {
        id:failIcon;
        width: 43;
        height: 44;
        anchors.left: rectangPic.left;
        anchors.leftMargin: 108;
        anchors.top: barcodePic.bottom;
        anchors.topMargin: 33;
        visible: false;
        source: "../Assistantimages/barcode/pic.png"
    }

    Image {
        id: prompt
        width: 694;
        height: 125;
        y: 460;
        anchors.horizontalCenter: rectangPic.horizontalCenter;
        visible: true;
        source: "../Assistantimages/barcode/pic2.png"
    }

    Text {
        id: prompt1;
        x: 310;
        y: 620;
        color: "#059ed9";
        font.pixelSize: 32
        font.family: fontFamily;
        visible: true;
        wrapMode: Text.WordWrap;
        width: 760;
        text: qsTr(promptText)
    }

    Text {
        id: failText;
        anchors.top: progressbarBkg.bottom;
        anchors.topMargin: 22;
        anchors.left: progressbarBkg.left;
        color: "#059ed9";
        font.pixelSize: 32;
        font.family: fontFamily;
        visible: false;
        text: qsTr("失败原因：", I108n.lang);
    }

    Text {
        id: commonText;
        text: promptPhrase;
        width: 420;
        anchors.top: progressbarBkg.bottom;
        anchors.topMargin: 22;
        anchors.left: failText.right;
        anchors.leftMargin: 30;
        color: "#059ed9";
        font.pixelSize: 32;
        font.family: fontFamily;
        wrapMode: Text.Wrap;
        horizontalAlignment: Text.AlignLeft
        clip: true;
        visible: false;
    }

    Item {
        id:progressAnimation;
        width: 682;
        height: 33;
        anchors.left: rectangPic.left;
        anchors.leftMargin: 105;
        anchors.top: rectangPic.top;
        anchors.topMargin: 47;
        visible: false;
        property int status: 1

        Image {
            id:pic1;
            width: 682;
            height: 33;
            anchors.left: parent.left;
            anchors.top: parent.top;
            visible: true;
            source: "../Assistantimages/barcode/laoding1.png"
        }

        Image {
            id:pic2;
            width: 682;
            height: 33;
            anchors.left: parent.left;
            anchors.top: parent.top;
            visible: false;
            source: "../Assistantimages/barcode/laoding2.png"
        }

        Timer {
            id:timer;
            interval: 1000; repeat: true;
            onTriggered: {
                if(progressAnimation.status)
                {
                    pic2.visible = true;
                    pic1.visible = false;
                    progressAnimation.status = 0;
                }
                else
                {
                    pic2.visible = false;
                    pic1.visible = true;
                    progressAnimation.status = 1;
                }
            }
        }

        function stopProgressAnimation()
        {
            timer.stop();
        }

        function startProgressAnimation()
        {
            timer.start();
        }
    }

    //progressbar  bkg
    Image {
        id:progressbarBkg;
        width: 682;
        height: 33;
        anchors.left: rectangPic.left;
        anchors.leftMargin: 105;
        anchors.top: rectangPic.top;
        anchors.topMargin: 47;
        visible: false;
        source: "../Assistantimages/barcode/laoding3.png"
    }

/*    Rectangle{
        id:progressLoadingPic;
        anchors.top: progressbarBkg.top;
        anchors.left:progressbarBkg.left;
        height: 33;
        width: progressValue;
        radius: 8;
        color: "#059ed9";
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
    }*/

    function setProgressConnectStatus(status)
    {
        if(status == 0)  //disconnect
        {
            console.log("\n ################ setProgressConnectStatus  disconnect 00 \n");
            progressValue = 0;
            reminder.visible    = false;
            connectText.visible = false;
            failIcon.visible    = false;
            failedText.visible  = false;
            failText.visible    = false;
            commonText.visible  = false;
            prompt.visible      = true;
            prompt1.visible     = true;
            progressbarBkg.visible = false;
            progressAnimation.visible = false;
            progressAnimation.stopProgressAnimation();
        }
        else if(status >= 1 && status <= 3) //connect
        {
            console.log("\n ################ setProgressConnectStatus  connect 11 \n");
            failIcon.visible    = false;
            failedText.visible  = false;
            failText.visible    = false;
            commonText.visible  = true;
            prompt.visible      = false;
            prompt1.visible     = false;
            progressbarBkg.visible = false;
            progressAnimation.visible = true;
            progressAnimation.startProgressAnimation();
            if(status == 1)
                reminder.visible = true;
            else
            {
                reminder.visible = false;
                connectText.visible = true;
            }
            if(status == 3)
                progressAnimation.stopProgressAnimation();
        }
        else   //error
        {
            console.log("\n ################ setProgressConnectStatus error 22 \n");
            reminder.visible    = false;
            connectText.visible = false;
            failIcon.visible    = true;
            failedText.visible  = true;
            failText.visible    = true;
            commonText.visible  = true;
            prompt.visible      = false;
            prompt1.visible     = false;
            progressbarBkg.visible = true;
            progressAnimation.visible = false;
            progressAnimation.stopProgressAnimation();
        }
    }


    signal helpClicked();
    signal backBtnClicked();
}
