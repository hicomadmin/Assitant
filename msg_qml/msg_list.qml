import QtQuick 2.0


Item {
    id: contentlist_page
    width: 597
    height: 552-19

    property string number:"";
    property string clickedNumber: "";
    signal listItemClicked(string name, string number);


    function showDetailMessage(name, number) {
        console.log("---> [ msg_list ] show detail messge name:", name,"number: ", number);
        listItemClicked(name, number);
    }
    function setTitleText(titleText)
    {
        console.log("---> [ msg_list.qml function setTitleText:]", titleText);

    }
    function setNumber(num)
    {
        number = num;
    }

    function onModelUpdated() {
        list.positionViewAtEnd();
        slider.visible = list.interactive = (list.contentHeight > list.height);
    }

    ListModel{
        id:listmodel
        ListElement{name:"Alen-阿丽";  icon:"../messageimages/persen.png";  time:"3月 24日";  unRead: false;  }
        ListElement{name:"JSON-老爸";  icon:"../messageimages/persen.png";  time:"3月 24日";  unRead: false;  }
        ListElement{name:"丫头骗子";  icon:"../messageimages/persen.png";  time:"3月 12日";  unRead: true;  }
        ListElement{name:"0769-7556237";  icon:"../messageimages/persen.png";  time:"3月 8日";  unRead: false;   }
        ListElement{name:"包子-下拉刷新和上拉分页逻辑";  icon:"../messageimages/persen.png";  time:"3月 12日";  unRead: true; }
        ListElement{name:"+8613588888888刷2145678998562478316";  icon:"../messageimages/persen.png";  time:"3月 8日";  unRead: false;   }
    }

    ListView {
        id: listView;
        objectName: "listView"
        anchors.fill: parent;
        anchors.topMargin: 19;
        anchors.left: parent.left
        anchors.leftMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        clip: true;
        currentIndex: -1;
        model: c_messageListModel;
        delegate: listModeDelegate;
    }

    Component {
        id: listModeDelegate;
        Rectangle {
            id: wrapper;
            width: listView.width;
            height: 108;
            focus: false;
            radius: 2;
            color: clickedNumber == number ? "#f14f5f":"transparent";
            MouseArea {
                id:listmouse;
                anchors.fill:parent;
                onClicked: {
                    showDetailMessage(name, number);
                    clickedNumber = number;
                    readState.visible = false;                  
                }
            }

            Image {
                anchors.bottom:  wrapper.top;
                anchors.left: wrapper.left;
                anchors.right: wrapper.right
                source: "../messageimages/List_line.png"
            }

            Image {
                id: idIcon;
                width: 84;
                height: 84;
                anchors.left: wrapper.left;
                anchors.leftMargin: 5;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../messageimages/persen.png";
            }
            Text {
                anchors.left: idIcon.right;
                anchors.leftMargin: 11;
                width: 335;         //用宽度来限制文本长度
                anchors.verticalCenter: wrapper.verticalCenter;
                text: name == ""? number: name;
                font.pixelSize: 36;
                font.family: fontFamily;
                elide: Text.ElideRight;
                color: "white";
                clip: true;
            }

            Text {
                anchors.right:wrapper.right;
                anchors.rightMargin: 5;
                anchors.verticalCenter: wrapper.verticalCenter
                text: time;
                font.pixelSize: 26
                font.family: fontFamily;
                color: "white";
                opacity: 0.5
            }

            Image {
                id: readState;
                anchors.right: parent.right;
                anchors.rightMargin: 10;
                anchors.top: parent.top;
                anchors.topMargin: 11;
                source: "../messageimages/new.png";
                visible: unRead;
            }

            Image {
                anchors.top: wrapper.bottom;
                anchors.left: wrapper.left;
                anchors.right: wrapper.right
                source: "../messageimages/List_line.png"
            }


        }
    }
}


