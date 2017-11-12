/*******************************************************
文  件  名：category.qml
描      述 ：类别选择: 包括拨号, 电话簿, 通话记录
*******************************************************/
import QtQuick 2.0


Item {
    id: category;
    width: 152;
    height: 174*3 + 28;
    property int itemHeight: 174;
    property int currIndex: -1;
    signal categoryChanged(int id);


    children: [
        Item {
            id: number;
            width: category.width;
            height: itemHeight;
            anchors.left: category.left;
            anchors.top: parent.top;

            Image {
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/left-gb.png";
                visible: !number.focus;
            }
            Image {
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/left-gb2.png";
                visible: number.focus;

            }
            Image {
                width: 77;
                height: 70;
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: "../phoneimages/icon.png";
            }

        },
        Item {
            id:  phonebook ;
            width: category.width;
            height: itemHeight;
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: category.left;
            Image {
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/left-gb.png";
                visible: !phonebook.focus;
            }
            Image {
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/left-gb2.png";
                visible: phonebook.focus;
            }
            Image {
                width: 77;
                height: 86;
                anchors.centerIn: phonebook
                source: "../phoneimages/icon2.png";
            }
        },
        Item {
            id:  history;
            width: category.width;
            height: itemHeight;
            anchors.left: category.left;
            anchors.bottom: parent.bottom;

            Image {
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/left-gb.png";
                visible: !history.focus;
            }
            Image {
                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                source: "../phoneimages/left-gb2.png";
                visible: history.focus;
            }
            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: "../phoneimages/icon3.png";
            }
        }
    ]

    MouseArea {
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 25;
        onPressed: {
            var id = (mouseY / itemHeight - 0.5).toFixed(0);
            if(id != currIndex) {
                categoryChanged(id);
            currIndex = id;
            setFocus(id);
            }
        }
    }

    function setFocus(id) {
        console.log("array in category.qml",id);
            for(var i = 0; i < category.children.length; i++) {
                if(id == i) {
                    category.children[i].focus = true;
                    if(currIndex != i)
                        categoryChanged(i);
                    currIndex = i;
                }
            }
        }

    function getCategory() {
        for(var i = 0; i < category.children.length; i++) {
            if(category.children[i].focus)
                return i;
        }
        return -1;
    }
    
}

