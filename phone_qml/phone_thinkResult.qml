/*******************************************************
文  件  phone_thinkResult.qml
描      述 ：拨号联想结果列表
*******************************************************/
import QtQuick 2.0

Item {
    id: thinkResult
    anchors.fill: parent;
    signal contactItemClicked(string number, string name);

    ListView {
        id: listView;
        anchors.fill: parent;
        model: c_thinkResultListModel ; //contactModel;
        delegate: contactsDelegate;
        clip: true;
        currentIndex: -1;
    }

    //just for UI demo
    ListModel {
        id: contactModel;
        ListElement {name: "拨号联想结果"; number: "13570886588";}
        ListElement {name: "包子";        number: "13745623589"}
    }

    Component {
        id: contactsDelegate
        Item {
            id: wrapper;
            width: thinkResult.width;
            height: 60;

            Text {
                id: idName;
                anchors.left: parent.left;
                anchors.leftMargin: 5;
                anchors.right: idNumber.left;
                anchors.rightMargin: 10;
                anchors.verticalCenter: parent.verticalCenter;
                elide: Text.ElideRight;
                text: name;
                font.pixelSize: 36;
                font.family: fontFamily;
                color: wrapper.focus ? "#6252ff" : "white";
            }
            Text {
                id: idNumber;
                anchors.right: parent.right;
                anchors.rightMargin: 5;
                anchors.verticalCenter: parent.verticalCenter;
                text: number
                font.pixelSize: 36;
                font.family: fontFamily;
                color: wrapper.focus ? "#6252ff" : "white";
                opacity: wrapper.focus ? 1: 0.4;
            }
            MouseArea {
                anchors.fill: parent;
                onPressed: {
                    wrapper.focus = true;
                }
                onExited: {
                    wrapper.focus = false;
                }
                onPositionChanged: {
                    wrapper.focus = false;
                }
                onClicked: {
                    console.log("contactsDelegate onClicked", name, number);
                    wrapper.focus = false;
                    if(number != "") {
                        contactItemClicked(number, name);
                    }
                }
            }
        }
    }

}

