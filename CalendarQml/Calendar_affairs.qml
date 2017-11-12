import QtQuick 2.0

Item {
    id: affairsDialog
    width: 1280
    height: 720
    visible: true
    property string  detailText: "";
    property string noticeInfoText: "";
    property string eventIllustrateText: "";

    onVisibleChanged: {
        if(visible){
            updateDate();
        }
    }

    Image {
        id: dialogBG
        anchors.fill: parent;
        width: 1280
        height: 720
        source: "../Assistantimages/bg.png"
    }

    Loader {
        id: btnBack
        width: 67;
        height: 67;
        source: "../Assistantqml/Button.qml";
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(affairsDialog.backClicked);
        }
    }

    Text {
        text: qsTr("日历");
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 27;
        font.pixelSize: 42;
        font.family: fontFamily;
        color: "#ffffff";
    }

//    //Calendar_bg
//    Image {
//        id: affairsbg
//        x: 27
//        y: 123
//        width: 1226
//        height: 584
//        source: "../CalendarImages/notice_bg.png"
//    }
//    //date
//    Text {
//        id: eventDate
//        x: 70
//        anchors.top: affairsbg.top;
//        anchors.topMargin: 20;
//        color: "#ffffff"
//        text: qsTr("--")
//        font.pixelSize: 46;
//        font.family: fontFamily;
//    }
//    //line_1
//    Image {
//        id: line_1;
//        anchors.left: affairsbg.left
//        anchors.leftMargin: 145
//        anchors.right: affairsbg.right;
//        anchors.rightMargin: 30;
//        anchors.top: affairsbg.top;
//        anchors.topMargin: 90;
//        source: "../messageimages/List_line.png"
//    }
//    Text {
//        id:projectName;
//        x:70;
//        anchors.top: line_1.bottom;
//        anchors.topMargin: 30;
//        font.pixelSize: 30;
//        font.family: fontFamily;
//        color: "#ffffff";
//        text: qsTr("项目")
//    }
//    Text {
//        id: eventDetail
//        x:185;
//        anchors.top: projectName.top;
//        color: "#ffffff";
//        text: detailText;
//        font.pixelSize: 27
//        font.family: fontFamily;
//        wrapMode: Text.WordWrap;
//        width: 1050;
//    }
//    //line_2
//    Image {
//        id: line_2;
//        anchors.left: affairsbg.left
//        anchors.leftMargin: 145
//        anchors.right: affairsbg.right;
//        anchors.rightMargin: 30;
//        anchors.top: eventDetail.bottom;
//        anchors.topMargin: 30;
//        source: "../messageimages/List_line.png";
//    }
//    Text {
//        id: startTime
//        x: 83
//        anchors.top: line_2.bottom;
//        anchors.topMargin: 24;
//        color: "#ffffff"
//        text: qsTr("--")
//        font.pixelSize: 30
//        font.family: fontFamily;
//    }
//    Text {
//        id: endTime
//        x: 83
//        anchors.top: startTime.bottom;
//        anchors.topMargin: 24
//        color: "#ffffff"
//        text: qsTr("--")
//        font.pixelSize: 30
//        font.family: fontFamily;
//    }
//    //line_3
//    Image {
//        id: line_3;
//        anchors.left: affairsbg.left
//        anchors.leftMargin: 145
//        anchors.right: affairsbg.right;
//        anchors.rightMargin: 20;
//        anchors.top: endTime.bottom;
//        anchors.topMargin: 15;
//        source: "../messageimages/List_line.png"
//    }
//    Text {
//        id: noticeInfoTitle
//        x: 83
//        anchors.top: line_3.bottom;
//        anchors.topMargin: 40;
//        color: "#ffffff"
//        text: qsTr("提醒    ")
//        font.pixelSize: 30
//        font.family: fontFamily;
//    }
//    Text {
//        id: noticeInfo
//        x: 215;
//        anchors.top: noticeInfoTitle.top;
//        color: "#ffffff"
//        text: noticeInfoText;
//        font.pixelSize: 30
//        font.family: fontFamily;
//        width: 1005;
//        elide: Text.ElideRight;
//    }
//    //line_4
//    Image {
//        id: line_4;
//        anchors.left: affairsbg.left
//        anchors.leftMargin: 145
//        anchors.right: affairsbg.right;
//        anchors.rightMargin: 20;
//        anchors.top: noticeInfoTitle.bottom;
//        anchors.topMargin: 40;
//        source: "../messageimages/List_line.png"
//    }
//    Text {
//        id: eventIllustrateTitle;
//        x: 83;
//        anchors.top: line_4.bottom;
//        anchors.topMargin: 40;
//        color: "#ffffff";
//        text: qsTr("说明    ");
//        font.pixelSize: 30;
//        font.family: fontFamily;
//    }
//    Text {
//        id: eventIllustrate
//        x: 215;
//        anchors.top: eventIllustrateTitle.top;
//        color: "#ffffff"
//        text: eventIllustrateText;
//        font.pixelSize: 30
//        font.family: fontFamily;
//        width: 1005;
//        elide: Text.ElideRight;
//    }
    Rectangle {
        x: 27
        y: 104
        width: 1226
        height: 584
        Image {
            anchors.fill: parent;
            source: "../CalendarImages/notice_bg.png"
        }

        ListView{
            id: listPage
            width: 1226
            height: 584
            anchors.fill: parent
            anchors.bottomMargin: 1
            anchors.topMargin: 1
            model: changePageModel
            clip: true
            VisualItemModel {
                id: changePageModel
                //line_1
                Image {
                    id: line_0;
                    anchors.left: projectName.right
                    anchors.leftMargin: 45;
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    y: 0;
                    opacity: 0;
                    source: "../messageimages/List_line.png"
                }
                //date
                Text {
                    id: eventDate
                    x: 45
                    anchors.top: line_0.bottom;
                    anchors.topMargin: 20;
                    color: "#ffffff"
                    text: qsTr("--");
                    font.pixelSize: 46;
                    font.family: fontFamily;
                }

                //line_1
                Image {
                    id: line_1;
                    anchors.left: projectName.right
                    anchors.leftMargin: 45;
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    anchors.top: eventDate.bottom;
                    anchors.topMargin: 20;
                    source: "../messageimages/List_line.png"
                }

                Text {
                    id:projectName;
                    x:45;
                    anchors.top: line_1.bottom;
                    anchors.topMargin: 30;
                    font.pixelSize: 30;
                    font.family: fontFamily;
                    color: "#ffffff";
                    text: qsTr("项目")
                }

                Text {
                    id: eventDetail
                    x:160;
                    anchors.top: projectName.top;
                    color: "#ffffff";
                    text: detailText;
                    font.pixelSize: 26
                    font.family: fontFamily;
                    wrapMode: Text.WordWrap;
                    width: 1050;
                }

                //line_2
                Image {
                    id: line_2;
                    anchors.left: projectName.right
                    anchors.leftMargin: 45;
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    anchors.top: eventDetail.bottom;
                    anchors.topMargin: 30;
                    source: "../messageimages/List_line.png";
                }

                Text {
                    id: startTime
                    x: 45
                    anchors.top: line_2.bottom;
                    anchors.topMargin: 24;
                    color: "#ffffff"
                    text: qsTr("--")
                    font.pixelSize: 30
                    font.family: fontFamily;
                }

                Text {
                    id: endTime
                    x: 45
                    anchors.top: startTime.bottom;
                    anchors.topMargin: 24
                    color: "#ffffff"
                    text: qsTr("--")
                    font.pixelSize: 30
                    font.family: fontFamily;
                }

                //line_3
                Image {
                    id: line_3;
                    anchors.left: projectName.right
                    anchors.leftMargin: 45;
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    anchors.top: endTime.bottom;
                    anchors.topMargin: 15;
                    source: "../messageimages/List_line.png"
                }

                Text {
                    id: noticeInfoTitle
                    x: 45
                    anchors.top: line_3.bottom;
                    anchors.topMargin: 40;
                    color: "#ffffff"
                    text: qsTr("提醒    ")
                    font.pixelSize: 30
                    font.family: fontFamily;
                }

                Text {
                    id: noticeInfo
                    x: 190;
                    anchors.top: noticeInfoTitle.top;
                    color: "#ffffff"
                    text: noticeInfoText;
                    font.pixelSize: 30
                    font.family: fontFamily;
                    width: 1005;
                    wrapMode: Text.WordWrap;
                }

                //line_4
                Image {
                    id: line_4;
                    anchors.left: projectName.right
                    anchors.leftMargin: 45;
                    anchors.right: parent.right
                    anchors.rightMargin: 30
                    anchors.top: noticeInfo.bottom;
                    anchors.topMargin: 40;
                    source: "../messageimages/List_line.png"
                }

                Text {
                    id: eventIllustrateTitle;
                    x: 45;
                    anchors.top: line_4.bottom;
                    anchors.topMargin: 40;
                    color: "#ffffff";
                    text: qsTr("说明    ");
                    font.pixelSize: 30;
                    font.family: fontFamily;
                }

                Text {
                    id: eventIllustrate
                    x: 190;
                    anchors.top: eventIllustrateTitle.top;
                    color: "#ffffff"
                    text: eventIllustrateText;
                    font.pixelSize: 30
                    font.family: fontFamily;
                    width: 1005;
                    elide: Text.ElideRight;
                }
            }
        }
    }


    function updateDate()
    {
        var eventInfo = globalObject.getMessageByListClickedItem();

        for(var i in eventInfo)
        {
            eventDate.text= eventInfo[3];
            detailText = eventInfo[2];
            startTime.text = "开始       " + eventInfo[0];
            endTime.text = "结束       " + eventInfo[1];
            noticeInfoText = eventInfo[4];
            eventIllustrateText =  eventInfo[5];
        }
    }

    signal backClicked();
}

