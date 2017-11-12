/*******************************************************
文  件  名：contacts.qml
描      述 ： 最近通话记录界面
*******************************************************/
import QtQuick 2.0


Item {
    id:record
    signal callRecordClick(string contentNumber,string contentName);

    Image {
        id: bg_right
        anchors.left: parent.left;
        anchors.top: parent.top;
        source: "../phoneimages/callRecords_bg.png"

    }

    ListModel{
        id:listmodel
        ListElement{name:"Alen-阿丽";  icon:"../phoneimages/icon4.png";  date:"2016-04-24  8:20:58"; }
        ListElement{name:"丫头骗子";  icon:"../phoneimages/icon4.png";  date:"2016-04-28  8:10:58"; }
        ListElement{name:"0769-7556237";  icon:"../phoneimages/icon5.png";  date:"2016-04-29  8:28:58";}
        ListElement{name:"+8613588888888刷2145678998562478316";  icon:"../phoneimages/icon6.png";  date:"2016-04-29  9:20:58"; }
    }
    ListView {
        id: listView;
        anchors.fill: bg_right;
        clip: true;
        currentIndex: -1;
        model:  c_recordListModel;    //listmodel
        delegate: listModeDelegate;
    }

    Component {
        id: listModeDelegate;
        Item {
            id: wrapper;
            width: listView.width;
            height: 97;

            Image {
                anchors.bottom:  wrapper.top;
                anchors.left: wrapper.left;
                anchors.leftMargin: 20
                anchors.right: wrapper.right
                anchors.rightMargin: 55;
                source: "../phoneimages/List_line.png"
            }

            Image {
                id: idIcon;
                width: 55;
                height: 43;
                anchors.left: wrapper.left;
                anchors.leftMargin: 48;
                anchors.verticalCenter: parent.verticalCenter;
                source: type == 1 ? "../phoneimages/icon5.png" :(type == 2 ? "../phoneimages/icon6.png" : "../phoneimages/icon4.png")
                //int type 1:已接来电、2:呼出电话、3:未接来电
            }

            Text {
                anchors.left: idIcon.right;
                anchors.leftMargin: 34;
                width: 600;         //用宽度来限制文本长度
                anchors.verticalCenter: wrapper.verticalCenter;
                elide: Text.ElideRight;
                text: name;
                font.pixelSize: 36;
                font.family: fontFamily;
                color: wrapper.focus ? "#6252ff" : "white";
                clip: true;
            }

            Text {
                anchors.right:wrapper.right;
                anchors.rightMargin: 70;
                anchors.verticalCenter: wrapper.verticalCenter
                text: date;
                font.pixelSize: 26
                font.family: fontFamily;
                color: wrapper.focus ? "#6252ff" : "white";
                opacity: 0.5
            }



            Image {
                anchors.top: wrapper.bottom;
                anchors.left: wrapper.left;
                anchors.leftMargin: 20;
                anchors.right: wrapper.right
                anchors.rightMargin: 55;
                source: "../phoneimages/List_line.png"
            }

            MouseArea {
                id:listmouse;
                anchors.fill: wrapper;
                onPressed: {
                    wrapper.focus = true;
                }
                onExited: {
                    wrapper.focus = false;
                }
                onClicked: {
                    console.log("[qml] CallRecord.qml onClicked name:", name, "number: ",  number);
                    callRecordClick(number, name);
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


}

