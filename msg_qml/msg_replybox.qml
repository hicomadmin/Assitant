import QtQuick 2.0
import QtQuick.Window 2.0



Item {
    id: right_detailWindow           //短信右边聊天记录数据
    width: 520;
    height: 552;
    property string number;
    property string msgFlag: ""
    property int mouseFlag: 1;
    signal sigEditBoxClicked();


    onVisibleChanged: {
        if(visible){
            if(list.count == 0)
                onSetSendMessageUnusered();
        }
    }

    ListModel {
        id: messageDialogModel;
        ListElement {
            content: "亲：明天9点开会记得哟！";
            time: "7月20日 08:35";
            isSend: true;
            sendFlag: 3;
        }
        ListElement {
            content: "好的，记得发邮件给我。";
            time: "7月24日 11:49";
            isSend: false;
            sendFlag: 2;
        }
    }

    //消息项代理
    Component {
        id: messageItemDelegate;
        Item {
            id: listItem;
            width: 520;

            Text {
                id: testWidth;
                text: content;
                font.pixelSize: test.font.pixelSize;
                font.family: fontFamily;
                visible: false
            }
            Text {
                id: test;
                text: content;
                width: parent.width-30;
                font.pixelSize: leftContent.font.pixelSize;
                font.family: fontFamily;
                wrapMode: Text.WrapAnywhere;
                lineHeight: 1.2;              //设置文本的行高
                z: 2;

                visible: false;
                property int lineCount: 0;
                property int itemHeight: 0;
                property int itemWidth: 0;
                property bool isLayout: false;

                onLineLaidOut: {
                    if(isLayout == true) {
                        return;
                    }
                    itemHeight += line.height;
                    lineCount++;
                }
                Component.onCompleted: {
                    isLayout = true;
                    if(lineCount == 1) {
                        itemWidth = testWidth.width;
                    }
                    else {
                        itemWidth = width;
                    }
                }
            }

            Item {
                id: left;
                anchors.left: parent.left;
                anchors.right: parent.right;
                visible: !isSend;

                Item {
                    id: leftBg;
                    width: test.itemWidth + 30;
                    height: test.itemHeight + 40 //20
                    anchors.left: parent.left;
                    anchors.top: parent.top;
                    z: 1;


                    Image {
                        id: leftLT;
                        anchors.left: parent.left;
                        anchors.top: parent.top;
                        width: 6;
                        height: 6;
                        source: "../messageimages/dialog_left_lt.png";
                    }
                    Image {
                        id: leftCT;
                        anchors.left: leftLT.right;
                        anchors.top: leftLT.top;
                        anchors.right: leftRT.left;
                        height: leftLT.height;
                        source: "../messageimages/dialog_left_ct.png";
                    }
                    Image {
                        id: leftRT;
                        anchors.right: parent.right;
                        anchors.top: parent.top;
                        width: 6;
                        height: leftLT.height;
                        source: "../messageimages/dialog_left_rt.png";
                    }

                    Image {
                        id: leftLC;
                        anchors.left: parent.left;
                        anchors.top: leftLT.bottom;
                        anchors.bottom: leftLB.top;
                        width: leftLT.width;
                        source: "../messageimages/dialog_left_lc.png";
                    }
                    Image {
                        id: leftCC;
                        anchors.left: leftLC.right;
                        anchors.top: leftCT.bottom;
                        anchors.right: leftRC.left;
                        anchors.bottom: leftCB.top;
                        source: "../messageimages/dialog_left_cc.png";
                    }
                    Image {
                        id: leftRC;
                        anchors.right: parent.right;
                        anchors.top: leftRT.bottom;
                        anchors.bottom: leftRB.top;
                        width: leftRT.width;
                        source: "../messageimages/dialog_left_rc.png";
                    }

                    Image {
                        id: leftLB;
                        anchors.left: parent.left;
                        anchors.bottom: parent.bottom;
                        width: leftLT.width;
                        height: 6;
                        source: "../messageimages/dialog_left_lb.png";
                    }
                    Image {
                        id: leftCB;
                        anchors.left: leftLB.right;
                        anchors.bottom: leftLB.bottom;
                        anchors.right: leftRB.left;
                        height: leftLB.height;
                        source: "../messageimages/dialog_left_cb.png";
                    }
                    Image {
                        id: leftRB;
                        anchors.right: parent.right;
                        anchors.bottom: parent.bottom;
                        width: leftRT.width;
                        height: leftLB.height;
                        source: "../messageimages/dialog_left_rb.png";
                    }


                }

                Text {
                    id: leftContent;
                    text: content;
                    font.pixelSize: 24;
                    font.family: fontFamily;
                    color: "#ffffff";
                    wrapMode: Text.WrapAnywhere;
                    verticalAlignment: Text.AlignVCenter;
                    lineHeight: 1.2;
                    z: 2;

                    anchors.left: leftBg.left;
                    anchors.leftMargin: 15;
                    anchors.right: leftBg.right;
                    anchors.rightMargin: 10;
                    anchors.top: leftBg.top;
                    anchors.topMargin: 25; //to fix the vertical center problem while counting lineHeight
                    anchors.bottom: leftBg.bottom;
                    anchors.bottomMargin: 15 //10;
                }
                Text {
                    id: leftTime;
                    text: time;
                    height: 24;
                    anchors.left: leftBg.left;
                    anchors.leftMargin: 6
                    anchors.top: leftBg.bottom;
                    anchors.topMargin: 15;
                    horizontalAlignment: Text.AlignLeft;
                    verticalAlignment: Text.AlignVCenter;
                    font.pixelSize: 20;
                    font.family: fontFamily;
                    color: "#ffffff";
                    opacity: 0.4;
                }
                Component.onCompleted: {
                    left.height = leftBg.height + leftTime.height;
                    listItem.height = left.height + 30;
                    //console.log("listItem----onCompleted-----listItem.width", listItem.width, "listItem.height", listItem.height);
                }
            }

            Item {
                id: right;
                anchors.left: parent.right;
                anchors.right: parent.right;
                visible: isSend;

                Item {
                    id: rightBg;
                    width: test.itemWidth + 30 > 480 ? 480 : test.itemWidth + 30;
                    height: test.itemHeight + 40 //20;
                    anchors.right: parent.right;
                    anchors.top: parent.top;
                    z: 1;

                    Image {
                        id: rightLT;
                        anchors.left: parent.left;
                        anchors.top: parent.top;
                        width: 6;
                        height: 6;
                        source: "../messageimages/dialog_right_lt.png";
                    }
                    Image {
                        id: rightCT;
                        anchors.left: rightLT.right;
                        anchors.top: rightLT.top;
                        anchors.right: rightRT.left;
                        height: rightLT.height;
                        source: "../messageimages/dialog_right_ct.png";
                    }
                    Image {
                        id: rightRT;
                        anchors.right: parent.right;
                        anchors.top: parent.top;
                        width: 6;
                        height: rightLT.height;
                        source: "../messageimages/dialog_right_rt.png";
                    }

                    Image {
                        id: rightLC;
                        anchors.left: parent.left;
                        anchors.top: rightLT.bottom;
                        anchors.bottom: rightLB.top;
                        width: rightLT.width;
                        source: "../messageimages/dialog_right_lc.png";
                    }
                    Image {
                        id: rightCC;
                        anchors.left: rightLC.right;
                        anchors.top: rightCT.bottom;
                        anchors.right: rightRC.left;
                        anchors.bottom: rightCB.top;
                        source: "../messageimages/dialog_right_cc.png";
                    }
                    Image {
                        id: rightRC;
                        anchors.right: parent.right;
                        anchors.top: rightRT.bottom;
                        anchors.bottom: rightRB.top;
                        width: rightRT.width;
                        source: "../messageimages/dialog_right_rc.png";
                    }

                    Image {
                        id: rightLB;
                        anchors.left: parent.left;
                        anchors.bottom: parent.bottom;
                        width: rightLT.width;
                        height: 6;
                        source: "../messageimages/dialog_right_lb.png";
                    }
                    Image {
                        id: rightCB;
                        anchors.left: rightLB.right;
                        anchors.bottom: rightLB.bottom;
                        anchors.right: rightRB.left;
                        height: rightLB.height;
                        source: "../messageimages/dialog_right_cb.png";
                    }
                    Image {
                        id: rightRB;
                        anchors.right: parent.right;
                        anchors.bottom: parent.bottom;
                        width: rightRT.width;
                        height: rightLB.height;
                        source: "../messageimages/dialog_right_rb.png";
                    }
                }

                Text {
                    id: rightContent;
                    text: content;
                    font.pixelSize:24;             //发送消息文字大小
                    font.family: fontFamily;
                    color: "#ffffff";
                    wrapMode: Text.WrapAnywhere;
                    verticalAlignment: Text.AlignVCenter;
                    lineHeight: 1.2;
                    z: 2;

                    anchors.left: rightBg.left;
                    anchors.leftMargin: 10;
                    anchors.right: rightBg.right;
                    anchors.rightMargin: 15;
                    anchors.top: rightBg.top;
                    anchors.topMargin: 25; //to fix the vertical center problem while counting lineHeight
                    anchors.bottom: rightBg.bottom;
                    anchors.bottomMargin: 15//10;
                }
                Text {
                    id: rightTime;
                    text: time;
                    height: 24;
                    anchors.right: rightBg.right;
                    anchors.rightMargin: 6;
                    anchors.top: rightBg.bottom;
                    anchors.topMargin: 15
                    horizontalAlignment: Text.AlignRight;
                    verticalAlignment: Text.AlignVCenter;
                    font.pixelSize: 20;
                    font.family: fontFamily;
                    color: "#ffffff";
                    opacity: 0.4;
                }
                Item{
                    id: sendStatus;
                    anchors.right: rightBg.left;
                    anchors.rightMargin: 16;
                    height: rightBg.height;
                    Image {
                        id: sendingIndct;
                        objectName: "sendingIndct"
                        width: 24;
                        height: 24;
                        anchors.centerIn: parent;
                        visible: sendFlag == 2  ?  true : false;
                        source: "../messageimages/download_send1.png"
                        NumberAnimation {
                            running: sendingIndct.visible
                            loops: Animation.Infinite
                            target: sendingIndct
                            from: 0
                            to: 360
                            property: "rotation"
                            duration: 1000
                        }                       
                    }

                    Loader {
                        id: sendFail;
                        width: 24;
                        height: 24;
                        anchors.centerIn: parent;
                        source: "../msg_qml/senMsg.qml"
                        visible: sendFlag == 1 ? true : false;

                        onLoaded: {
                            item.normalSource = "../messageimages/btn_send_fail_n.png";
                            item.pressSource = "../messageimages/btn_send_fail_p.png";
                            item.clicked.connect(reSendClicked);
                        }
                        function reSendClicked() {
                            sendingIndct.visible = true;
                            sendFail.visible = false;
                            onSetSendMessageUnusered();
                            globalObject.reSendMessage(number, content, rank);
                        }
                    }

                }

                Connections {
                    target: list;
                    onMovingChanged: {
                        sendFail.item.focus = false;
                    }
                }
                MouseArea {

                    onPressed: {
                    }

                    onReleased: {
                        var upSelectIndex = list.indexAt(parent.x + mouse.x, parent.y + mouse.y);
                    }
                }
                Component.onCompleted: {
                    right.height = rightBg.height + rightTime.height;
                    listItem.height = right.height + 30;
                }
            }
        }
    }

    property int stepSize;
    property int offset;

    ListView {
        id: list;
        anchors.left: editBox.left;
        anchors.bottom: editBox.top;
        anchors.top: parent.top
        anchors.topMargin: 19
        width: 552;
        clip: true;
        keyNavigationWraps:true;

        model: c_detailListModel;
        delegate: messageItemDelegate;

        //滑块
//                onContentYChanged: {
//                    var total = (list.contentHeight > list.height)?(list.contentHeight - list.height): list.height;
//                    var percent = 100 * contentY / total;
//                    if(percent < 0)
//                        percent = 0;
//                    if(percent > 100)
//                        percent = 100;
//                  //  offset = percent * (slider.height - stepSize) / 100;
//                   // console.log("onContentYChanged contentY:", contentY, " offset", offset, "total:", total, "stepSize:", stepSize);
//                }
//                onContentHeightChanged: {
//                    stepSize = slider.height * list.height / list.contentHeight;
//                    if(stepSize > slider.height)
//                        stepSize = slider.height;
//                }

    }

    //滑块
//        Rectangle {
//            id: slider;
//            width: 5;
//            anchors.top: list.top;
//            anchors.topMargin: 9;
//            anchors.bottom: list.bottom;
//            anchors.bottomMargin: 9;
//            anchors.right: list.right;
//            anchors.rightMargin: 15;
//            color: "transparent";

//            Rectangle {
//                id: control;
//                color: "gray";
//                opacity: 0.4;
//                width: slider.width;
//                height: stepSize;
//                y: offset;
//                radius: 8;
//            }
//        }

    Item {
        id: editBox;
        anchors.left: parent.left;
        anchors.leftMargin:15;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 30
        width: 520 ;
        height: 75;

        MouseArea {
            id: mouseid;
            anchors.fill: parent;
            onPressed: {
                phraseBtn.source = "../messageimages/pic4.png"
                phraseHint.color = "#00fffc";
            }
            onClicked: {
                phraseBtn.source = "../messageimages/pic4.png"
                phraseHint.color = "#00fffc";
                onEditBoxClicked();
            }
        }
    }

    Image {
        id: editBg                                          // 短语矩形框
        anchors.left: editBox.left;
        anchors.bottom:  editBox.bottom;
        source:"../messageimages/shurulan bg.png";
    }

    Image {
        id: phraseBtn;                                       // 短语按钮图标
        anchors.left: editBg.left;
        anchors.leftMargin: 16;
        anchors.verticalCenter: editBg.verticalCenter;
        source: "../messageimages/pic3.png";
    }
    Text {
        id: phraseHint;                                         // 提示短语
        anchors.left: phraseBtn.right;
        anchors.leftMargin: 23;
        anchors.verticalCenter: editBg.verticalCenter;
        text: "点击选择快捷短语";
        font.family: fontFamily;
        color: "#ffffff";
        font.pixelSize: 32;
    }

    function onSetSendMessageUnusered()
    {
        console.log("################# 888 onSetSendMessageUnusered");
        phraseBtn.source = "../messageimages/hinitIcon_w.png";
        phraseHint.color = "#959595";
        mouseid.enabled = false;
    }
    function onSetSendMessageUsered()
    {
        console.log("################# 999 onSetSendMessageUsered");
        mouseid.enabled = true;
        phraseBtn.source = "../messageimages/pic3.png";
        phraseHint.color = "#ffffff";
    }

    function setPhraseHintColor_n()
    {
        phraseBtn.source = "../messageimages/pic3.png"
        phraseHint.color = "#ffffff";
    }
    function setPhraseHintColor_p()
    {
         phraseBtn.source = "../messageimages/pic4.png"
         phraseHint.color = "#00fffc";
    }
    function onEditBoxClicked() {
        setPhraseHintColor_p();
        sigEditBoxClicked();
    }
    
    function onModelUpdated() {
        list.positionViewAtEnd();
    }
}



