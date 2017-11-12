import QtQuick 2.0

Item {
    id: ssplinkmainpage;
    width: 1280;
    height: 720;

    property bool isOpenAdb:              true;
    property bool isMusicPictureRotation: false;
    property string weatherSourcePic :    "../weatherImages/weather_icon_big/weather_icon_0.png";
    property string weatherTemperature :  "--";
    property string weatherDate :         "-月-日";
    property string currentLocation:      "北京";
    property string weatherCondition:     "晴";
    property string musicName:            "未知";
    property string musicSinger:          "未知";
    property string singerPicture:        "../Assistantimages/music_default.png";


    Image {
        id: bkg
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
        visible:true;
    }

    Title{
        id:title;
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: parent.width;
        titleText: qsTr("SSP-Link");
        onBackClicked: {
            sspLinkBackClicked();
        }
        Loader {
            width: 41
            height: 61
            anchors.right: parent.right;
            anchors.rightMargin: 66;
            anchors.top: parent.top;
            anchors.topMargin: 20;
            source: "Button.qml"
            onLoaded: {
                item.normalSource = "../Assistantimages/btn_voice_n.png";
                item.pressSource = "../Assistantimages/btn_voice_p.png";
                item.clicked.connect(onButtonClicked);
            }
            function onButtonClicked()
            {
                signVR();
            }
        }
    }

    Image {
        id:bg1;
        width: 710;
        height: 280;
        x:39;
        y:104;
        focus: false;
        source: focus ? "../Assistantimages/ssp1_p.png":"../Assistantimages/bg1.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                bg1.scale = 0.95;
                bg1.focus = true;
                localMusicAppClicked();
            }
            onPressAndHold: { bg1.scale = 0.95; bg1.focus = true; console.log("onPressAndHold");}
            onPressed:  { bg1.scale = 0.95; bg1.focus = true; console.log("onPressed");}
            onExited:   { bg1.scale = 1.0; bg1.focus = false; console.log("onExited");}
            onReleased: { bg1.scale = 1.0; bg1.focus = false; console.log("onReleased");}
        }

        Image {
            id:musicPic;
            width: 230;
            height: 230;
            anchors.top: parent.top;
            anchors.topMargin: 26;
            anchors.left: parent.left;
            anchors.leftMargin: 35
            source: singerPicture;
//            RotationAnimation on rotation {
//                loops: Animation.Infinite;
//                from: 0;
//                to: 360;
//                duration: 10000;
//                paused: !isMusicPictureRotation;
//            }
        }

        Marquee {
            id:marqueeName;
            maxWidth: 350;
            interval: 40;
            anchors.left: musicPic.right;
            anchors.leftMargin: 40;
            anchors.top: bg1.top;
            anchors.topMargin: 83;
            Text {
                color: "#00fffc";
                text: musicName;
                font.pixelSize: 46;
                font.family: fontFamily;
            }
        }

        Text {
            id:singer;
            text: musicSinger;
            width: 300
            anchors.left: musicPic.right;
            anchors.leftMargin: 40;
            anchors.bottom: bg1.bottom;
            anchors.bottomMargin: 80;
            font.pixelSize: 40;
            font.family: fontFamily;
            color: "#ffffff";
            horizontalAlignment: Text.AlignLeft
            elide: Text.ElideRight;
            clip: true;
        }
    }

    Image {
        id:bg2;
        width: 480;
        height: 280;
        x:759;
        y:104;
        focus: false;
        source: focus ? "../Assistantimages/ssp2_p.png":"../Assistantimages/bg2.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                bg2.scale = 0.95;
                bg2.focus = true;
                weatherAppClicked();
            }
            onPressAndHold: { bg2.scale = 0.95;bg2.focus = true; console.log("onPressAndHold");}
            onPressed:  { bg2.scale = 0.95; bg2.focus = true;console.log("onPressed");}
            onExited:   { bg2.scale = 1.0; bg2.focus = false; console.log("onExited");}
            onReleased: { bg2.scale = 1.0; bg2.focus = false; console.log("onReleased");}
        }

        Image {
            id:weathericon;
            objectName: "weatherSourcePic"
            width: 120;
            height: 120;
            anchors.left: bg2.left;
            anchors.leftMargin: 68//78;
            anchors.top: bg2.top;
            anchors.topMargin: 32;
            source: weatherSourcePic;
        }

        Text {
            id:weathertemp;
            objectName: "weatherTemperature";
            text: weatherTemperature;
            anchors.left: bg2.left;
            anchors.leftMargin: 46;
            //anchors.top: weathericon.bottom;
            //anchors.topMargin: 8 //28;
            anchors.top: weathericon.top;
            anchors.topMargin: 108;
            verticalAlignment: Text.AlignTop
            font.pixelSize: 110;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id:temperatureId;
            text:  "°C";
            anchors.left: weathertemp.right;
            //anchors.top: weathericon.bottom;
            //anchors.topMargin: 12 //40;
            anchors.top: weathericon.top;
            anchors.topMargin: 120;
            font.pixelSize: 50;
            font.family: fontFamily;
            color: "#ffffff";
        }

        Text {
            id:weatherdate;
            objectName: "weatherDate";
            text: weatherDate;
            anchors.right: bg2.right;
            anchors.rightMargin: 40;
            anchors.top: bg2.top;
            anchors.topMargin: 55;
            verticalAlignment: Text.AlignTop
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id:weatheraddr;
            objectName: "currentLocation";
            text: currentLocation;
            anchors.right: bg2.right;
            anchors.rightMargin: 40;
            anchors.top: weatherdate.bottom;
            anchors.topMargin: 30;
            verticalAlignment: Text.AlignTop
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft
        }

        Text {
            id:weathersituation;
            width: 216;
            objectName: "weatherCondition";
            text: weatherCondition;
            anchors.right: bg2.right;
            anchors.rightMargin: 40;
            anchors.top: weatheraddr.bottom;
            anchors.topMargin: 30;
            verticalAlignment: Text.AlignTop
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignRight
        }
    }

    Image {
        id:messagebtn;
        width: 230;
        height: 282;
        anchors.left: parent.left;
        anchors.leftMargin: 39;
        y:400;
        focus: false;
        source: focus ? "../Assistantimages/ssp3_p.png" : "../Assistantimages/bg_icon.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                messagebtn.scale = 0.95;
                messagebtn.focus = true;
                messagebtnclicked();
            }
            onPressAndHold: {messagebtn.scale = 0.95; messagebtn.focus = true;}
            onPressed:  {messagebtn.scale = 0.95; messagebtn.focus = true;}
            onExited:   {messagebtn.scale = 1.0; messagebtn.focus = false;}
            onReleased: {messagebtn.scale = 1.0; messagebtn.focus = false;}
        }

        Image {
            id: recvMessage;        //有新信息显示红点
            objectName: "recvMessage";
            anchors.bottom: messagebg.bottom;
            anchors.bottomMargin: 63;
            anchors.left: messagebg.left;
            anchors.leftMargin: 57;
            z:3
            visible: false;
            width: 14
            height: 14
            source: "../messageimages/new.png"
        }

        Image {
            id:messagebg;
            width: 70;
            height: 70;
            anchors.top: messagebtn.top;
            anchors.topMargin: 84
            anchors.horizontalCenter: messagebtn.horizontalCenter;
            visible:true;
            source: "../Assistantimages/main_message.png"
        }

        Text {
            id:messagename;
            text: qsTr("短信",I108n.lang);
            anchors.horizontalCenter: messagebtn.horizontalCenter;
            anchors.top: messagebg.bottom;
            anchors.topMargin: 30
            verticalAlignment: Text.AlignTop
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft
        }
    }

    Image {
        id:calendarbtn;
        width: 230;
        height: 282;
        x:279;
        y:400;
        focus: false;
        source: focus ? "../Assistantimages/ssp3_p.png":"../Assistantimages/bg_icon.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                calendarbtn.scale = 0.95;
                calendarbtn.focus = true;
                calendarAppClicked();
            }
            onPressAndHold: {calendarbtn.scale = 0.95;calendarbtn.focus = true;}
            onPressed:  {calendarbtn.scale = 0.95;calendarbtn.focus = true;}
            onExited:   {calendarbtn.scale = 1.0;calendarbtn.focus = false;}
            onReleased: {calendarbtn.scale = 1.0;calendarbtn.focus = false;}
        }

        Image {
            id:calendarbg;
            width: 70;
            height: 70;
            anchors.top: calendarbtn.top;
            anchors.topMargin: 84
            anchors.horizontalCenter: calendarbtn.horizontalCenter;
            visible:true;
            source: "../Assistantimages/main_Calendar.png"
        }

        Text {
            id:calendarname;
            text: qsTr("日历",I108n.lang);
            anchors.horizontalCenter: calendarbtn.horizontalCenter;
            anchors.top: calendarbg.bottom;
            anchors.topMargin: 30
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft
        }
    }

    Image {
        id:applistbtn;
        width: 230;
        height: 282;
        x:519;
        y:400;
        focus: false;
        source: focus ? "../Assistantimages/ssp3_p.png":"../Assistantimages/bg_icon.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                applistbtn.scale = 0.95;
                applistbtn.focus = true;
                applistbtnClicked();
            }
            onPressAndHold: {applistbtn.scale = 0.95;applistbtn.focus = true;}
            onPressed:  {applistbtn.scale = 0.95;applistbtn.focus = true;}
            onExited:   {applistbtn.scale = 1.0;applistbtn.focus = false;}
            onReleased: {applistbtn.scale = 1.0;applistbtn.focus = false;}
        }

        Image {
            id:applistbg;
            width: 70;
            height: 70;
            anchors.top: applistbtn.top;
            anchors.topMargin: 84
            anchors.horizontalCenter: applistbtn.horizontalCenter;
            visible:true;
            source: "../Assistantimages/main_pic.png"
        }

        Text {
            id:applistname;
            text: qsTr("应用列表",I108n.lang);
            anchors.horizontalCenter: applistbtn.horizontalCenter;
            anchors.top: applistbg.bottom;
            anchors.topMargin: 30
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            horizontalAlignment: Text.AlignLeft
        }
    }

    Image {
        id:adbphonebtn;
        width: 235;
        height: 282;
        x:759;
        y:400;
        focus: false;
        source: focus ? "../Assistantimages/ssp5_p.png":"../Assistantimages/bg_call.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                adbphonebtn.scale = 0.95;
                adbphonebtn.focus = true;
                phonebtnclicked();
            }
            onPressAndHold: {adbphonebtn.scale = 0.95;adbphonebtn.focus = true;}
            onPressed:  {adbphonebtn.scale = 0.95;adbphonebtn.focus = true;}
            onExited:   {adbphonebtn.scale = 1.0;adbphonebtn.focus = false;}
            onReleased: {adbphonebtn.scale = 1.0;adbphonebtn.focus = false;}
        }

        Image {
            id:adbphoneicon;
            anchors.top: adbphonebtn.top;
            anchors.topMargin: 70;
            anchors.horizontalCenter: adbphonebtn.horizontalCenter;
            visible:true;
            source: "../Assistantimages/main_call.png"
        }

        Text {
            id:adbphonename;
            text: qsTr("电话",I108n.lang);
            anchors.horizontalCenter: adbphonebtn.horizontalCenter;
            anchors.top: adbphoneicon.bottom;
            anchors.topMargin: 20;
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            visible:true;
            horizontalAlignment: Text.AlignLeft
        }
    }

    Image {
        id:mirrorlinkbtn;
        width: 235;
        height: 282;
        anchors.left: adbphonebtn.right;
        anchors.leftMargin: 10;
        y:400;
        focus: false;
        source: focus ? "../Assistantimages/ssp4_p.png":"../Assistantimages/bg_phone.png";
        visible:isOpenAdb;
        scale: 1.0;
        MouseArea{
            id: mirrorlinkbtnMouseArea;
            anchors.fill: parent;
            onClicked: {
                mirrorlinkbtn.scale = 0.95;
                mirrorlinkbtn.focus = true;
                console.log("***************** mirrorlinkbtn 1111111111***************");
                if(iabled)
                {
                    console.log("***************** mirrorlinkbtn 222222222***************");
                    iabled = false;
                    mirrorBtnAbleTimer.start();
                    mirrorBtnClicked();
                }
            }
            onPressAndHold: {mirrorlinkbtn.scale = 0.95;mirrorlinkbtn.focus = true;}
            onPressed:  {mirrorlinkbtn.scale = 0.95;mirrorlinkbtn.focus = true;}
            onExited:   {mirrorlinkbtn.scale = 1.0;mirrorlinkbtn.focus = false;}
            onReleased: {mirrorlinkbtn.scale = 1.0;mirrorlinkbtn.focus = false;}
        }

        Image {
            id:mirrorlinkicon;
            anchors.horizontalCenter: mirrorlinkbtn.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 70;
            visible:isOpenAdb;
            source: "../Assistantimages/main_phone.png"
        }

        Text {
            id:mirrorlinkname;
            text: qsTr("手机",I108n.lang);
            anchors.horizontalCenter: mirrorlinkbtn.horizontalCenter;
            anchors.top: mirrorlinkicon.bottom;
            anchors.topMargin: 20;
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            visible:isOpenAdb;
            horizontalAlignment: Text.AlignLeft
        }
    }

    Image {
        id:mirrorAOAlinkbtn;
        width: 235;
        height: 282;
        anchors.left: adbphonebtn.right;
        anchors.leftMargin: 10;
        y:400;
        visible:!isOpenAdb;
        focus: false;
        source: focus ? "../Assistantimages/ssp4_p.png":"../Assistantimages/bg_phone.png";
        scale: 1.0;
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                mirrorAOAlinkbtn.scale = 0.95;
                mirrorAOAlinkbtn.focus = true;
                mirrorAOABtnClicked();
            }
            onPressAndHold: {mirrorAOAlinkbtn.scale = 0.95;mirrorAOAlinkbtn.focus = true;}
            onPressed:  {mirrorAOAlinkbtn.scale = 0.95;mirrorAOAlinkbtn.focus = true;}
            onExited:   {mirrorAOAlinkbtn.scale = 1.0;mirrorAOAlinkbtn.focus = false;}
            onReleased: {mirrorAOAlinkbtn.scale = 1.0;mirrorAOAlinkbtn.focus = false;}
        }

        Image {
            id:mirrorAOAIcon;
            anchors.horizontalCenter: mirrorAOAlinkbtn.horizontalCenter;
            anchors.top: parent.top;
            anchors.topMargin: 50;
            visible:!isOpenAdb;
            source: "../Assistantimages/barcode/1.png";
        }

        Text {
            id:mirrorAOAName;
            text: qsTr("手机",I108n.lang);
            anchors.horizontalCenter: mirrorAOAlinkbtn.horizontalCenter;
            anchors.top: mirrorAOAIcon.bottom;
            anchors.topMargin: 20;
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            wrapMode: Text.Wrap;
            visible:!isOpenAdb;
            horizontalAlignment: Text.AlignLeft
        }
    }
    Timer {
        id:mirrorBtnAbleTimer
        interval: 2000
        onTriggered: {
            iabled = true;
            stop();
        }
    }
    property bool iabled: true
    
    signal localMusicAppClicked();
    signal applistbtnClicked();
    signal mirrorBtnClicked();
    signal calendarAppClicked();
    signal weatherAppClicked();
    signal messagebtnclicked();
    signal phonebtnclicked();
    signal mirrorAOABtnClicked();
    signal sspLinkBackClicked();
    signal signVR();
    
}

