/*******************************************************
文  件  名：contacts.qml
描      述 ：电话簿界面
*******************************************************/
import QtQuick 2.0

Item {
    id:phoneBook
    signal contactItemClicked(string contentNumber, string contentName);

    function onModelUpdated(index)
    {
        listView.positionViewAtIndex(index,ListView.Beginning);
    }

    Image {
        id: bg_right
        anchors.left: parent.left;
        anchors.top: parent.top;
        source: "../phoneimages/contacts_bg.png"

    }

    ListModel{
        id:listmodel
        ListElement{ type: "icon";  name: "A";  number: "";}
        ListElement{type: "text";   name:"Alen-阿丽";   number:"13570896500";   }
        ListElement{ type: "icon";  name: "Y";  number: "";}
        ListElement{type: "text";   name:"丫头骗子";    number:"13894585652";   }
        ListElement{ type: "icon";  name: "#";  number: "";}
        ListElement{type: "text";   name:"0769-7556237";   number:"13132971828";    }
        ListElement{type: "text";   name:"+8613588888888刷2145678998562478316";    number:"13477885657";   }
    }

    ListView {
        id: listView;
        anchors.top: bg_right.top;
        anchors.topMargin: 19;
        anchors.left: bg_right.left;
        anchors.leftMargin: 20;
        anchors.right: parent.right;
        anchors.rightMargin: 85;
        anchors.bottom: bg_right.bottom;
        clip: true;
        currentIndex: -1;

        model:  c_bookListModel;    //listmodel
        delegate: listModeDelegate;
    }

    Component {
        id: listModeDelegate;

        Rectangle {
            id: wrapper;
            width: listView.width;
            height: 108;
            //color: wrapper.ListView.isCurrentItem?"#f14f5f":"transparent";
             color: wrapper.focus?"#f14f5f":"transparent";

            Image {
                anchors.left: parent.left;
                anchors.right: parent.right;
                height: 1;
                anchors.top: parent.top;
                source: "../phoneimages/List_line.png";
            }

            Loader {
                id: idIconChar;
                visible: (type == "icon");
                anchors.left: parent.left;
                anchors.leftMargin: 20;
                width: 64;
                height: 64;
                anchors.verticalCenter: parent.verticalCenter;
                source: "KeybordButton.qml";
                onLoaded: {
                    item.text = name;
                }
            }
            Image {
                id: idIcon;
                visible: (type == "text");
                width: 84;
                height: 84;
                anchors.left: wrapper.left;
                anchors.leftMargin: 20;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/photo.png";
            }

            Text {
                id: idName;
                visible: (type == "text");
                anchors.left: idIcon.right;
                anchors.leftMargin: 10;
                anchors.verticalCenter: parent.verticalCenter;
                width: 600;
                elide: Text.ElideRight;
                text: name;
                font.pixelSize: 36;
                font.family: fontFamily;
                color: "#ffffff";
            }
            Text {
                id: idNumber;
                visible: (type == "text");
                anchors.right: parent.right;
                anchors.rightMargin: 104;
                anchors.verticalCenter: parent.verticalCenter;
                text: number
                font.pixelSize: 26;
                font.family: fontFamily;
                color: "#ffffff";
            }


            MouseArea {
                anchors.fill: wrapper;
                onPressed: {
                    wrapper.focus = true;
                }
                onExited: {
                    wrapper.focus = false;
                }
                onClicked: {
                    //wrapper.ListView.view.currentIndex = index ;
                    if(number != "") {
                        contactItemClicked(idNumber.text, idName.text);
                        console.log("[qml] contacts.qml onClicked 2 name:", idNumber.text,"number: ",  idName.text);
                    }
                }
            }

            Connections {
                target: listView;
                onMovingChanged: {
                    wrapper.focus = false;
                }
            }
        }
    }

//==============

    Rectangle{
        id: hintWind
        width: 108;
        height: 108;
        anchors.horizontalCenter: listView.horizontalCenter;
        anchors.top: listView.top;
        anchors.topMargin: 216;
        color: "#13c5c8";
        visible: false;
        opacity: 0.4;
        radius: 20;
        Text {
            id: hintCH;
            anchors.centerIn: parent;
            font.pixelSize: 50;
            color: "#ffffff";
            text: "";
        }
    }

    Timer{
        interval: 1000;
        onTriggered: {
            hintWind.visible = false;
        }
        running: hintWind.visible;
    }

    //=============================

    /*
    BT.CharSlider{
        id: charSlider
        x:27
        y:107
        visible: list.count !== 0
        onCharTextChanged:{
            if(!list.flicking)
            list.positionViewAtldex(btHMI.getFirstLetterlndex(this.charText),ListView.Beginning);
        }
    }

    */

    property string charText //快速搜索首字母
    Item{
        id: quickSearch
        anchors.right: bg_right.right;
        implicitWidth: 60 //50
        implicitHeight: 506
        visible: listView.count > 0 ? true : false;


        QtObject {
            id: self
            property int value: 0
            property int maxValue: 26
            property variant charArray: ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','#']
        }

        Binding {
            target: phoneBook;
            property: "charText";
            value: self.charArray[self.value]
        }

        Connections {
            target: phoneBook //quickSearch
            onCharTextChanged: {
                if(charText.length == 1 && !moveArea.pressed) {
                    self.value = charText.charCodeAt(0)  - 'A'.charCodeAt(0);
                    point.y = ((self.value>=0&&self.value<=self.maxValue)?self.value:self.maxValue) *((sliderBar.height - point.height + 10)/self.maxValue) + aTxt.height;
                }
                if(listView.count > 0)
                    if(self.value>=0&&self.value<=self.maxValue)
                    {
                        listView.positionViewAtIndex(globalObject.getFirstIndex(self.charArray[self.value]), ListView.Beginning);
                        hintCH.text = self.charArray[self.value];
                        hintWind.visible = true;
                    }
            }
        }

        Rectangle{
            id: sliderBar
            width:2;height: 506
            color: "#3d7296"
            visible: false;
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            onPressed: {
                if(mouse.y < aTxt.height + (point.height / 2)){
                    self.value = 0;
                }else if(mouse.y > (aTxt.height + sliderBar.height - point.height / 2)){
                    self.value = self.maxValue;
                }else{
                    self.value = Math.round((mouse.y - aTxt.height - point.height/2)/(sliderBar.height - point.height + 10)*self.maxValue);
                }
                point.y = self.value *((sliderBar.height - point.height + 10)/self.maxValue) + aTxt.height;
            }
        }

        Text{// a text
            id: aTxt
            font.pixelSize: 20
            text: "A"
            color: "#349adf"
            visible: false
            anchors{top: parent.top;horizontalCenter: parent.horizontalCenter}

        }
        Image { //a Icon
            id:aIcon
            height: 30;
            source: "../phoneimages/qselect/a1.png";
            anchors{top: parent.top; topMargin: 23; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point1
            height: 6;
            source: "../phoneimages/pic.png";
            anchors{top: aIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //d Icon
            id:dIcon
            height: 30;
            source: "../phoneimages/qselect/d1.png";
            anchors{top: aIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point2
            height: 6;
            source: "../phoneimages/pic.png";
            anchors{top: dIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //g Icon
            id:gIcon
            source: "../phoneimages/qselect/g1.png";
            anchors{top: dIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point3
            source: "../phoneimages/pic.png";
            anchors{top: gIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //o Icon
            id:oIcon
            height: 30;
            source: "../phoneimages/qselect/o1.png";
            anchors{top: gIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point4
            height: 6;
            source: "../phoneimages/pic.png";
            anchors{top: oIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //r Icon
            id:rIcon
            height: 30;
            source: "../phoneimages/qselect/r1.png";
            anchors{top: oIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point5
            height: 6;
            source: "../phoneimages/pic.png";
            anchors{top: rIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //w Icon
            id:wIcon
            height: 30;
            width: 30;
            source: "../phoneimages/qselect/w1.png";
            anchors{top: rIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point6
            height: 6
            source: "../phoneimages/pic.png";
            anchors{top: wIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //x Icon
            id:xIcon
            height: 30;
            source: "../phoneimages/qselect/x1.png";
            anchors{top: wIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point7
            height: 6;
            source: "../phoneimages/pic.png";
            anchors{top: xIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //z Icon
            id:zIcon
            height: 30
            source: "../phoneimages/qselect/z1.png";
            anchors{top: xIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Image { //point Icon
            id: point8
            source: "../phoneimages/pic.png";
            anchors{top: zIcon.bottom; topMargin: 12; horizontalCenter: parent.horizontalCenter}
        }

        Image { //# Icon
            id: endIcon
            height: 30;
            source: "../phoneimages/qselect/123.png";
            anchors{top: zIcon.bottom; topMargin: 30; horizontalCenter: parent.horizontalCenter}
        }

        Text{ // # text
            font.pixelSize: 20
            text: "#"
            color: "#349adf"
            visible: false;
            anchors{bottom: parent.bottom;horizontalCenter: parent.horizontalCenter}
        }

        //滑动小球
        Rectangle{
            id: point
            width: quickSearch.width
            height: quickSearch.width
            radius: quickSearch.width / 2
            color:  "transparent"; //"#05acd4"
            opacity: 0.1
            //y: self.value *((sliderBar.height - point.height + 10)/self.maxValue) + aTxt.height
            y: aTxt.height

            Text{ //显示要搜索的首字母
               anchors.centerIn: parent
                font.pixelSize: 18 //25
                color:  "transparent";
                text: (self.value>=0&&self.value<=self.maxValue)?self.charArray[self.value]:"*"
            }

            MouseArea{//触控区域
                id: moveArea
                anchors.fill: parent
                drag{
                    target: point
                    minimumY: aTxt.height
                    maximumY: sliderBar.height - point.height + 10 + aTxt.height
                    axis: Drag.YAxis
                }
                onReleased: {
                    self.value = Math.round((point.y - aTxt.height)/(sliderBar.height - point.height + 10)*self.maxValue);
                }
                onPositionChanged: {
                    self.value = Math.round((point.y - aTxt.height)/(sliderBar.height - point.height + 10)*self.maxValue);
                }
                onPressed: { // new add
                    self.value = Math.round((point.y - aTxt.height)/(sliderBar.height - point.height + 10)*self.maxValue);
                }
            }
        }
    }

    Text {
        id: noContact;
        //objectName: "noContact";
        anchors.centerIn: bg_right;
        font.pixelSize: 36;
        font.family: fontFamily;
        color: "#ffffff";
        visible: listView.count > 0 ? false : true;
        text: qsTr("通讯录获取失败");
    }

}





