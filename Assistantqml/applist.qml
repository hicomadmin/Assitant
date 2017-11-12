import QtQuick 2.0

Item {
    id: applist;
    width: 1280;
    height: 720;

    property int  appCount: 16;
    property int listPageID: 0;

    Image {
        id: backgroud;
        anchors.fill: parent;
        source: "../Assistantimages/bg.png";
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
            item.clicked.connect(appListClicked);
        }
    }

    Text {
        id:title
        text:"应用列表"
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 32;
        font.pixelSize: 42;
        font.family: fontFamily;
        color: "#ffffff";
    }

//    Image {
//        id:point1
//        width: 17;
//        height: 17;
//        anchors.left: parent.left;
//        anchors.leftMargin: 612;
//        anchors.bottom: parent.bottom;
//        anchors.bottomMargin: 10
//        source: page == 1 ? "../appListImages/pic.png":"../appListImages/pic1.png";
//        visible: appCount <= 4 ? false : true;
//    }

//    Image {
//        id:point2
//        width: 17;
//        height: 17;
//        anchors.left: point1.right;
//        anchors.leftMargin: 22;
//        anchors.bottom: parent.bottom;
//        anchors.bottomMargin: 10
//        source: page == 2 ? "../appListImages/pic.png":"../appListImages/pic1.png";
//        visible: appCount <= 4 ? false : true;
//    }


    ListModel{
        id:gridModel;
        ListElement{
            AppListIndex : 0;
            AppListName  : "电话";
            AppListIconPath : "../appListImages/icon_call_n.png";
        }
        ListElement{
            AppListIndex : 1;
            AppListName  : "短信";
            AppListIconPath : "../appListImages/icon_message_n.png";
        }
        ListElement{
            AppListIndex : 2;
            AppListName  : "日历";
            AppListIconPath : "../appListImages/icon_Calendar_n.png";
        }
        ListElement{
            AppListIndex : 3;
            AppListName  : "音乐";
            AppListIconPath : "../appListImages/icon_music_n.png";
        }
        ListElement{
            AppListIndex : 4;
            AppListName  : "蜻蜓FM";
            AppListIconPath : "../appListImages/icon_qingting_n.png";
        }
        ListElement{
            AppListIndex : 5;
            AppListName  : "企鹅FM";
            AppListIconPath : "../appListImages/icon_qie_n.png";
        }
        ListElement{
            AppListIndex : 6;
            AppListName  : "天气";
            AppListIconPath : "../appListImages/icon_weather_n.png";
        }
        ListElement{
            AppListIndex : 7;
            AppListName  : "考拉车载电台";
            AppListIconPath : "../appListImages/icon_kaola_n.png";
        }
        ListElement{
            AppListIndex : 8;
            AppListName  : "天气";
            AppListIconPath : "../appListImages/icon_weather_n.png";
        }
        ListElement{
            AppListIndex : 9;
            AppListName  : "考拉车载电台";
            AppListIconPath : "../appListImages/icon_kaola_n.png";
        }
        ListElement{
            AppListIndex : 10;
            AppListName  : "企鹅FM";
            AppListIconPath : "../appListImages/icon_qie_n.png";
        }
        ListElement{
            AppListIndex : 11;
            AppListName  : "考拉车载电台";
            AppListIconPath : "../appListImages/icon_kaola_n.png";
        }
        ListElement{
            AppListIndex : 12;
            AppListName  : "企鹅FM";
            AppListIconPath : "../appListImages/icon_qie_n.png";
        }
        ListElement{
            AppListIndex : 13;
            AppListName  : "考拉车载电台";
            AppListIconPath : "../appListImages/icon_kaola_n.png";
        }
        ListElement{
            AppListIndex : 14;
            AppListName  : "企鹅FM";
            AppListIconPath : "../appListImages/icon_qie_n.png";
        }
        ListElement{
            AppListIndex : 15;
            AppListName  : "考拉车载电台";
            AppListIconPath : "../appListImages/icon_kaola_n.png";
        }
    }

    GridView{
        id:gridView;
        width: 1168;
        height: 584;
        anchors.left: parent.left;
        anchors.leftMargin: 55;
        anchors.top: parent.top;
        anchors.topMargin: 104;
        cellWidth: 280+12;
        cellHeight: appCount <= 4 ? 584 : 280+12;
        interactive: false;
        contentX: listView.contentX;
        model: AppList
        flow:GridView.FlowTopToBottom;
        delegate: gridDelegate;
        clip: true;
        property int curSelectIndex: -1
    }

    ListView{
        id:listView;
        width: 1168;
        height: 584;
        anchors.left: parent.left;
        anchors.leftMargin: 60;//55;
        anchors.top: parent.top;
        anchors.topMargin: 104;
        model: AppListPge;
        delegate: listDelegate;
        orientation: ListView.Horizontal;
        snapMode: ListView.SnapOneItem;
        clip: true;

        highlightRangeMode: ListView.StrictlyEnforceRange
        cacheBuffer: listView.count // 缓存区域高度、宽度、元素个数
    }
    // page indicator
    Row {
        id:pageIndicator
        anchors.horizontalCenter: backgroud.horizontalCenter
        anchors.top: listView.bottom
        anchors.topMargin: 7

        spacing: 20
        Repeater {
            model: listView.count
            Rectangle {
                width: 18; height: 18
                radius: 10
                color: listView.currentIndex == index ? "#00ffff" : "#ffffff"
            }
        }
    }

    Component{
        id:listDelegate;
        Item{
            id:listItem;
            width: listView.width;
            height: listView.height;
            Text {
                id:pageID;
                text:AppListPageIndex;
                font.family: fontFamily;
                font.pixelSize: 40;
                color: "#ffffff";
                visible: false;
            }
            MouseArea{
                anchors.fill: parent
                onCanceled: {
                    gridView.curSelectIndex = -1;
                }
                onReleased: {
                    gridView.curSelectIndex = -1;
                }
                onPressed: {
                    listPageID = pageID.text;
                    if(0 < mouse.x && mouse.x < 280)
                    {
                        if(0 < mouse.y && mouse.y < 280)
                            gridView.curSelectIndex = listPageID*8;
                        else if(292 < mouse.y && mouse.y < 572)
                            gridView.curSelectIndex = listPageID*8 + 1;
                    }
                    else if(292 < mouse.x && mouse.x < 572)
                    {
                        if(0 < mouse.y && mouse.y < 280)
                            gridView.curSelectIndex = listPageID*8 + 2;
                        else if(292 < mouse.y && mouse.y < 572)
                            gridView.curSelectIndex = listPageID*8 + 3;
                    }
                    else if(584 < mouse.x && mouse.x < 864)
                    {
                        if(0 < mouse.y && mouse.y < 280)
                            gridView.curSelectIndex = listPageID*8 + 4;
                        else if(292 < mouse.y && mouse.y < 572)
                            gridView.curSelectIndex = listPageID*8 + 5;
                    }
                    else if(876 < mouse.x && mouse.x < 1156)
                    {
                        if(0 < mouse.y && mouse.y < 280)
                            gridView.curSelectIndex = listPageID*8 + 6;
                        else if(292 < mouse.y && mouse.y < 572)
                            gridView.curSelectIndex = listPageID*8 + 7;
                    }
                }
                onClicked: {
                    gridView.curSelectIndex = -1;
                    onListClicked(mouse.x, mouse.y);
                }
            }
        }
    }

    ListModel{
        id:listModel;
        ListElement{
            AppListPageIndex : 0;
        }
        ListElement{
            AppListPageIndex : 1;
        }
    }

    Component{
        id:gridDelegate;
        Item{
            id:gridItem;
            width: 292;
            height: appCount <= 4 ? 584 : 292;
            anchors.rightMargin: 0;
            anchors.bottomMargin: 0;

            Image {
                id: pic;
                width: 280;
                height: appCount <= 4 ? 584 : 280;
                anchors.top: parent.top;
                anchors.left: parent.left;
                source: appCount <= 4 ? "../Assistantimages/bg_4.png" : "../Assistantimages/bg_app.png";
            }

            Image {
                id: appPic;
                width: 145;
                height: 145;
                y:appCount <= 4 ? 165 : 35;
                anchors.horizontalCenter: pic.horizontalCenter;
                source: AppListIconPath;
            }

            Text {
                id: id;
                text: AppListIndex;
                visible: false;
            }

            Text {
                id: name;
                text: AppListName;
                anchors.top: appPic.bottom;
                anchors.topMargin: 30;
                anchors.horizontalCenter: appPic.horizontalCenter;
                font.family: fontFamily;
                font.pixelSize: 40;
                color: "#ffffff";
            }
            Image {
                id: shade
                width: 280
                height: appCount <= 4 ? 584 : 280;
                anchors.top: parent.top;
                anchors.left: parent.left;
                source: "../Assistantimages/appList_shade.png"
                visible: (AppListName != "" && gridView.curSelectIndex == AppListIndex)? true:false
            }
        }
    }

    function onListClicked(x, y)
    {
        console.log("onListClicked x:",x);
	console.log("onListClicked y:",y);
        var index = gridView.indexAt(x, y);
        console.log("--------1-------onListClicked index:",index);
        console.log("onListClicked listPageID:", listPageID);

        if(0 < x && x < 280)
        {
            if(0 < y && y < 280)
                index = listPageID*8;
            else if(292 < y && y < 572)
                index = listPageID*8 + 1;
        }
        else if(292 < x && x < 572)
        {
            if(0 < y && y < 280)
                index = listPageID*8 + 2;
            else if(292 < y && y < 572)
                index = listPageID*8 + 3;
        }
        else if(584 < x && x < 864)
        {
            if(0 < y && y < 280)
                index = listPageID*8 + 4;
            else if(292 < y && y < 572)
                index = listPageID*8 + 5;
        }
        else if(876 < x && x < 1156)
        {
            if(0 < y && y < 280)
                index = listPageID*8 + 6;
            else if(292 < y && y < 572)
                index = listPageID*8 + 7;
        }

        console.log("----------2--------onListClicked index:", index);
        if(index != -1)
        {
            var appName = getItemName(index);
            if(appName != "")
            {
                wichAppClicked(index, appName);
            }
        }
    }


    function appListCount(value)
    {
        appCount = value;
    }

    function getItemName(index)
    {
        return AppList.get(index, "AppListName");
    }

    Connections{
        target: globalObject;
        onSigAppListCount:appListCount(value);
    }


    signal appListClicked();
    signal wichAppClicked(int index, string appName);

}

