import QtQuick 2.0

Item {
    width: 520
    height: 369
    property string number;

    ListModel {
        id: phrasesListModel;
        ListElement { content: "您好，我正在开车，稍后与您联系！";}
        ListElement { content: "路上堵车，晚点到！";}
        ListElement { content: "我很快就到，请稍微等一会。";}
        ListElement { content: "你现在在哪里？";}
        ListElement { content: "当前正忙，请稍后联系我，谢谢！";}
    }

    Component {
        id: phrasesListDelegate;

        Item {
            id: item;
            width: 520;
            height: 73;
            focus: true;

            Component.onCompleted: {
                item.focus = false;
            }

            Text {
                id: phtasesText;
                anchors.verticalCenter: parent.verticalCenter;
                anchors.left: parent.left
                anchors.leftMargin: 30
                text: content;
                font.pixelSize: 24;
                font.family: fontFamily;
                color: item.focus ? "#00fffc" : "#ffffff";

            }

            Image {
                id: sp1
                source: "../messageimages/quickbar_list.png"
            }


            MouseArea {
                anchors.fill: parent;

                onPressed: {
                    item.focus = true;
                }

                onExited: {
                    item.focus = false;
                }
                onClicked: {
                    item.focus = false;
                    listItemClicked(phtasesText.text);
                    console.log("PhrasesList--item--onClicked", phtasesText.text);
                }
            }
        }
    }

    Image {
        id:quik_bg
        anchors.fill: parent;
        source: "../messageimages/quickbar_bg.png";
    }

    ListView {
        id: list;
        width: parent.width
        height: parent.height
        clip: true;
        interactive: false;
        currentIndex: -1;

        model: c_phraseListModel ;
        delegate: phrasesListDelegate;
    }

    signal listItemClicked(string text);
}

