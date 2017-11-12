import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    id: calendarDialog
    width: 1280
    height: 720
    visible: true

    property int clickItemIndex :-1;
    property int isCurrDay: 0;
    property int isCheckDay: 0;
    property bool isFirstClicked: true

    onVisibleChanged: {
        if(visible){
            globalObject.onCalendarInit();
            onBtnToday();
        }
    }
    
    Image {
        id: dialogBG
        width: 1280
        height: 720
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
    }

    MouseArea{
        anchors.fill: parent;
        //enabled: false;
    }

    Loader {
        width: 67;
        height: 67;
        source: "../Assistantqml/Button.qml"
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(backClicked);
        }
    }

    Text {
        text: qsTr("日历");
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 27;
        font.pixelSize: 42;//36;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
    }

    Image {
        id: rightPlane
        x: 739
        y: 106
        source: "../CalendarImages/right_bg.png"

        Text {
            id: calendarHinit;
            objectName: "calendarHinit";
            font.pixelSize: 45;
            font.family: fontFamily;
            color: "#ffffff";
            anchors.centerIn: parent;
            visible:  false;
            text: qsTr("暂无事件");
        }

        Item {
            id: eventlist_page
            anchors.top: rightPlane.top;
            anchors.topMargin: 23;
            anchors.left: rightPlane.left;
            anchors.leftMargin: 16;
            anchors.right: rightPlane.right;
            anchors.rightMargin: 16
            anchors.bottom: rightPlane.bottom;

            ListView {
                id: eventlist
                width: 484
                height: 514
                anchors.fill: parent
                clip: true;
                delegate: listModeDelegate;

                Rectangle {
                    id: slider;
                    width: 5;
                    anchors.right: parent.right;
                    anchors.rightMargin: 20;
                    height: parent.visibleArea.heightRatio * parent.height;
                    y: parent.visibleArea.yPosition * parent.height;
                    color: "gray";
                    radius: 8;
                    visible: false; //试样没有滑块
                }

                Component{
                    id: listModeDelegate
                    Loader{
                        asynchronous:true
                        source: "../CalendarQml/EventItem.qml";
                        onLoaded: {
                            console.log("------------------------------------listModeDelegate")
                        }
                    }
                }
            }

            ListModel {
                id: listModel;
                ListElement {
                    event_id: 0;
                }
                ListElement {
                    event_id: 1;
                }
                ListElement {
                    event_id: 2;
                }
                ListElement {
                    event_id: 3;
                }
                ListElement {
                    event_id: 4;
                }
            }

            property int curselectid:-1;

            signal onclickitem(int id,int index);
            x: 18
            y: 22
            width: 484

            function setModel()
            {
                eventlist.model = eventlistmodel;
            }

        }


        Image {
            id: image4
            x: 18
            y: 22
            source: "../CalendarImages/notice_bg2.png"
            visible: false

            Text {
                id: text1
                x: 28
                y: 20
                color: "#ffffff"
                text: qsTr("10:00")
                font.pixelSize: 32
                font.family: fontFamily;
                visible: false
            }

            Text {
                id: text9
                x: 28
                y: 63
                color: "#ffffff"
                text: qsTr("11:00")
                font.pixelSize: 32
                font.family: fontFamily;
                visible: false
            }

            Button {
                id: affairs1
                x: 154
                y: 20
                width: 293
                height: 37
                transformOrigin: Item.Center
                btnText: "会议2"
                visible: false
                onClicked:{
                    onBtnAffairs(1);
                }
            }

            Button {
                id: affairs2
                x: 152
                y: 63
                width: 293
                height: 37
                btnText: "会议2"
                transformOrigin: Item.Center
                visible: false
                onClicked:{
                    onBtnAffairs(2);
                }
            }
        }
    }

    Image {
        id: leftPlane
        x: 26
        y: 106
        width: 692
        source: "../CalendarImages/left_bg.png"

        Button {
            id: btnToday
            x: 609
            y: 16
            width: 67
            height: 67
            pressSource: isCurrDay == isCheckDay ? "../CalendarImages/today_w.png" : "../CalendarImages/today_p.png"
            normalSource: isCurrDay == isCheckDay ? "../CalendarImages/today_w.png" : "../CalendarImages/today.png"
            enabled: isCurrDay != isCheckDay

            onClicked: {
                if(isCurrDay != isCheckDay)
                    onBtnToday();
            }
        }

        Text {
            id: calendarTitle
            x: 28
            y: 30
            width: 237
            height: 49
            color: "#ffffff"
            text: qsTr("-年-月")
            styleColor: "#000000"
            font.pixelSize: 38
            font.family: fontFamily;
        }

        Row {
            id: row1
            x: 23
            y: 92
            width: 653
            height: 50
            spacing: 48

            Text {
                id: text8
                color: "#b6b6b6"
                text: qsTr("周日")
                font.pixelSize: 26
                font.family: fontFamily;
            }

            Text {
                id: text7
                color: "#b6b6b6"
                text: qsTr("周一")
                font.pixelSize: 26
                font.family: fontFamily;
            }

            Text {
                id: text6
                color: "#b6b6b6"
                text: qsTr("周二")
                font.pixelSize: 26
                font.family: fontFamily;
            }

            Text {
                id: text5
                color: "#b6b6b6"
                text: qsTr("周三")
                font.pixelSize: 26
                font.family: fontFamily;
            }

            Text {
                id: text4
                color: "#b6b6b6"
                text: qsTr("周四")
                font.pixelSize: 26
                font.family: fontFamily;
            }

            Text {
                id: text3
                color: "#b6b6b6"
                text: qsTr("周五")
                font.pixelSize: 26
                font.family: fontFamily;
            }

            Text {
                id: text2
                y: 0
                color: "#b6b6b6"
                text: qsTr("周六")
                anchors.top: parent.top
                anchors.topMargin: 0
                font.pixelSize: 26
                font.family: fontFamily;
            }
        }

        Column {
            id: column1
            x: 22
            y: 140
            width: 653
            height: 382
            spacing: 2

            Row {
                id: week1
                width: 653
                height: 67
                spacing: 31

                Button {
                    id: day1
                    width: 67
                    height: 67
                    pressSource: day1.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day1.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    bflag:true
                    btnText: "1"
                    onClicked: {
                        onBtnCalendarDay(1);
                    }
                }

                Button {
                    id: day2
                    width: 67
                    height: 67
                    pressSource: day2.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day2.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "2"
                    onClicked: {
                        onBtnCalendarDay(2);
                    }
                }

                Button {
                    id: day3
                    width: 67
                    height: 67
                    pressSource: day3.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day3.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "3"
                    onClicked: {
                        onBtnCalendarDay(3);
                    }
                }

                Button {
                    id: day4
                    width: 67
                    height: 67
                    pressSource: day4.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day4.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "4"
                    onClicked: {
                        onBtnCalendarDay(4);
                    }
                }

                Button {
                    id: day5
                    width: 67
                    height: 67
                    pressSource: day5.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day5.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "5"
                    onClicked: {
                        onBtnCalendarDay(5);
                    }
                }

                Button {
                    id: day6
                    width: 67
                    height: 67
                    pressSource: day6.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day6.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "6"
                    onClicked: {
                        onBtnCalendarDay(6);
                    }
                }

                Button {
                    id: day7
                    width: 67
                    height: 67
                    pressSource: day7.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day7.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(7);
                    }
                }
            }

            Row {
                id: week2
                width: 653
                height: 67
                spacing: 31

                Button {
                    id: day8
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day8.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day8.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(8);
                    }
                }

                Button {
                    id: day9
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day9.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day9.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(9);
                    }
                }

                Button {
                    id: day10
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day10.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day10.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(10);
                    }
                }

                Button {
                    id: day11
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day11.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day11.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(11);
                    }
                }

                Button {
                    id: day12
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day12.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day12.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(12);
                    }
                }

                Button {
                    id: day13
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day13.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day13.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(13);
                    }
                }

                Button {
                    id: day14
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day14.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day14.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(14);
                    }
                }
            }

            Row {
                id: week3
                width: 653
                height: 67
                spacing: 31

                Button {
                    id: day15
                    width: 67
                    height: 67
                    pressSource: day15.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day15.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(15);
                    }
                }

                Button {
                    id: day16
                    width: 67
                    height: 67
                    pressSource: day16.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day16.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(16);
                    }
                }

                Button {
                    id: day17
                    width: 67
                    height: 67
                    pressSource: day17.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day17.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(17);
                    }
                }

                Button {
                    id: day18
                    width: 67
                    height: 67
                    pressSource: day18.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day18.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(18);
                    }
                }

                Button {
                    id: day19
                    width: 67
                    height: 67
                    pressSource: day19.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day19.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(19);
                    }
                }

                Button {
                    id: day20
                    width: 67
                    height: 67
                    pressSource: day20.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day20.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(20);
                    }
                }

                Button {
                    id: day21
                    width: 67
                    height: 67
                    pressSource: day21.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day21.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    btnText: "7"
                    onClicked: {
                        onBtnCalendarDay(21);
                    }
                }
            }

            Row {
                id: week4
                width: 653
                height: 67
                spacing: 31

                Button {
                    id: day22
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day22.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day22.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(22);
                    }
                }

                Button {
                    id: day23
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day23.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day23.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(23);
                    }
                }

                Button {
                    id: day24
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day24.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day24.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(24);
                    }
                }

                Button {
                    id: day25
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day25.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day25.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(25);
                    }
                }

                Button {
                    id: day26
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day26.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day26.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(26);
                    }
                }

                Button {
                    id: day27
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day27.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day27.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(27);
                    }
                }

                Button {
                    id: day28
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day28.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day28.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(28);
                    }
                }
            }

            Row {
                id: week5
                width: 653
                height: 67
                spacing: 31

                Button {
                    id: day29
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day29.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day29.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(29);
                    }
                }

                Button {
                    id: day30
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day30.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day30.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(30);
                    }
                }

                Button {
                    id: day31
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day31.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day31.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(31);
                    }
                }

                Button {
                    id: day32
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day32.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day32.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(32);
                    }
                }

                Button {
                    id: day33
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day33.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day33.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(33);
                    }
                }

                Button {
                    id: day34
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day34.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day34.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(34);
                    }
                }

                Button {
                    id: day35
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day35.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day35.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(35);
                    }
                }
            }

            Row {
                id: week6
                width: 653
                height: 67
                spacing: 31

                Button {
                    id: day36
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day36.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day36.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(36);
                    }
                }

                Button {
                    id: day37
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day37.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day37.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(37);
                    }
                }

                Button {
                    id: day38
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day38.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day38.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(38);
                    }
                }

                Button {
                    id: day39
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day39.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day39.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(39);
                    }
                }

                Button {
                    id: day40
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day40.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day40.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(40);
                    }
                }

                Button {
                    id: day41
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day41.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day41.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";
                    onClicked: {
                        onBtnCalendarDay(41);
                    }
                }

                Button {
                    id: day42
                    width: 67
                    height: 67
                    btnText: "7"
                    pressSource: day42.btnText == isCurrDay ? "../CalendarImages/taday_bg.png": "../CalendarImages/nothingMark.png";
                    flagSource: day42.btnText == isCheckDay ? "" : "../CalendarImages/mark.png";

                    onClicked: {
                        onBtnCalendarDay(42);
                    }
                }
            }
        }
    }

    Loader{
        id:eventDialog;
        anchors.fill: parent;
        source: "../CalendarQml/Calendar_affairs.qml";
        visible:false;

        onLoaded: {
            item.backClicked.connect(calendarBackClicked);
        }
    }

    function onBtnAffairs(a){
//        var object=Qt.createComponent("Calendar_affairs.qml").createObject(this);
    }

    function onlistclickitem(id,index)
    {
        console.log("onlistclickitem:" + index);

        globalObject.onCalendarListClicked(index);

        eventDialog.visible = true;
    }

    function calendarBackClicked(){
        eventDialog.visible = false;
    }

    function onBtnToday(){
        globalObject.setCalendarToToday();
        updateEvent();
    }

    function onBtnCalendarDay(a){
        globalObject.onCalendarDayClicked(parseInt(a));
        updateEvent();
    }

    function updateEvent(){
        globalObject.getMessageByCheckDay();
    }

    function updateDate()
    {
        if(globalObject.getCalendarYear() || globalObject.getCalendarMonth())
            calendarTitle.text = globalObject.getCalendarYear() + "年" + globalObject.getCalendarMonth() + "月";

        var month   = globalObject.getCalendarMonth();
        var currDay = globalObject.getCalendarCurrDay();
        var checkDay= globalObject.getCalendarCheckDay();
        var bCheckCurrDay = true;

        isCurrDay = currDay;    //今天的日期
        isCheckDay = checkDay;  //点击的日期
        console.log("################### currDay =", currDay);
        console.log("################### checkDay =", checkDay);

        if (checkDay > 0){
            bCheckCurrDay = false;
        }

        var myList = new Array();
        myList.push(week1.children);
        myList.push(week2.children);
        myList.push(week3.children);
        myList.push(week4.children);
        myList.push(week5.children);
        myList.push(week6.children);

        eventlist_page.visible = false;

        for(var j in myList){
            var list = myList[j];

            for ( var i in list) {
                list[i].btnText =  globalObject.getCalendarDay(parseInt(i)+7*parseInt(j));
                list[i].benable     = false;
                list[i].opacity     =  0.4;
                list[i].bflag       =  false;
                list[i].bcheck      =  false;
                if(globalObject.haveAffairsCalendarDay(parseInt(i)+7*parseInt(j))){
                    eventlist_page.visible = true;
                    eventlist_page.setModel();
                    eventlist_page.onclickitem.connect(onlistclickitem);
                    list[i].bflag =  true;
                }

                if(month === globalObject.getCalendarDayMonth(parseInt(i)+7*parseInt(j))){
                    list[i].opacity =  1;
                    list[i].benable = true;
                }
                if(bCheckCurrDay){
                    if(month === globalObject.getCalendarDayMonth(parseInt(i)+7*parseInt(j))){
                        if(currDay ===globalObject.getCalendarDay(parseInt(i)+7*parseInt(j))){
                            list[i].bcheck = true;
                        }
                    }
                }
                else{
                    if(globalObject.getCalendarCheckMonth() === globalObject.getCalendarDayMonth(parseInt(i)+7*parseInt(j))){
                        if(checkDay ===globalObject.getCalendarDay(parseInt(i)+7*parseInt(j))){
                            list[i].bcheck = true;
                        }
                    }
                }
            }
        }
    }

    function calendar_on_updateEvent()
    {
        updateDate();
    }

    function calendar_on_updateDateInfo()
    {
        updateDate();
    }


    signal backClicked();
}

