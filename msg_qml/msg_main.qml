import QtQuick 2.0

Item {
    id: main_item
    width: 1280;
    height: 720;
    visible: true
    signal msgBackButtonClicked();
    property string hintTxt : "暂无选中项";
    property string selectMessageContactName: "";
    property string selectMessageContactNumber: "";

    onVisibleChanged: {
        if(visible)
        {
            title.item.titleText = "短信";
            hint.text = "未选择项目";
            hint.visible = true
        }
    }

    //背景图片
    Image {
        id: main_bkg
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
        MouseArea {
            anchors.fill: parent;
        }
    }
    Image {
        id: left_bkg
        anchors.left: main_bkg.left;
        anchors.leftMargin: 59;
        anchors.top:title.bottom;
        source: "../messageimages/left-bg.png"
    }
    Image {
        id: right_bkg
        anchors.left: left_bkg.right;
        anchors.leftMargin: 15;
        anchors.top:title.bottom;
        source: "../messageimages/right-bg.png"
    }

    Text {
        id: hint;
        objectName: "hintUnchose";
        text: hintTxt;
        anchors.centerIn: right_bkg;
        font.pixelSize: 36;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Loader{
        id:title;
        objectName: "title";
        anchors.left: parent.left;
        anchors.top: parent.top;
        source: "title.qml";

        onLoaded: {
            item.titleText = "短信";
            item.backClicked.connect(onBackButtonClicked);
        }
    }

    //message list
    Loader {
        id:conentlist_ldr;
        anchors.fill: left_bkg
        source: "../msg_qml/msg_list.qml";
        onLoaded: {
            if(item) {
                item.listItemClicked.connect(onListItemClicked);
            }
        }
        function show(){
            title.item.titleText = selectMessageContactName;
            item.setNumber(selectMessageContactNumber);
        }
    }

    //快捷回复
    Loader {
        id: mesgDetailList;
        objectName: "mesgDetailList"
        anchors.left: right_bkg.left;
        anchors.bottom: right_bkg.bottom;
        source: "../msg_qml/msg_replybox.qml"
        onLoaded: {
            console.log("===== <msg_main.qml> loaded mesgDetailLIst! ...................")
            item.sigEditBoxClicked.connect(onSigEditBoxClicked);
        }
    }

    MouseArea {
        anchors.fill: parent;
        enabled: phrases.visible;
        onPressed: {
            if(!(mouseX > phrases.x
                 && mouseX < (phrases.x + phrases.width)
                 && mouseY > phrases.y
                 && mouseY < (phrases.y + phrases.height))) {
                phrases.visible = false;
                mesgDetailList.item.setPhraseHintColor_n();
            }
        }
    }

    Loader {
        id: phrases;
        anchors.left: mesgDetailList.left
        anchors.leftMargin: 15;
        anchors.bottom: mesgDetailList.bottom
        anchors.bottomMargin: 105;
        visible: false;
        source: "../msg_qml/PhrasesList.qml";
        onLoaded: {
            item.listItemClicked.connect(onPhrasesListReturn);       //隐藏数据窗口
        }
    }

    Image {
        id: noHistory
        objectName: "hintUncontacts"
        anchors.left: parent.left
        anchors.leftMargin: 32;
        anchors.top: parent.top;
        anchors.topMargin: 104;
        anchors.right: parent.right
        anchors.rightMargin: 32;
        visible: false;
        source: "../phoneimages/callAnswer_bg.png"
        Text {
            anchors.centerIn: parent;
            font.pixelSize: 36;
            font.family: fontFamily;
            color: "#ffffff";
            text: qsTr("未获取到历史信息");
        }
        MouseArea{
            onClicked: {}
            onReleased: {}
        }
    }

    function onPhrasesListReturn(text) {
        phrases.visible = false;
        mesgDetailList.item.setPhraseHintColor_n();
        if(selectMessageContactNumber)
        {
            if(title.item.titleText != "短信"){
                 mesgDetailList.item.onSetSendMessageUnusered();
                 globalObject.sendMessage(selectMessageContactNumber, text);
            }
        }
    }

    function onListItemClicked(name, number) {
        selectMessageContactName = name;
        selectMessageContactNumber = number;
        hint.visible = false;       //隐藏"未选择项目"
        phrases.visible = false;    //点击隐藏短语框
        conentlist_ldr.show();
        mesgDetailList.item.onSetSendMessageUsered();
        c_detailListModel.clear();
        globalObject.getOnePersonMessages(number);                     //详细短信内容
        globalObject.updateReadedStatus(selectMessageContactNumber);  //根据Number更新已读未读状态
    }

    function onSigEditBoxClicked(){
        phrases.visible = true;
        //mesgDetailList.item.setPhraseHintColor_p();
    }

    function onBackButtonClicked(){
        msgBackButtonClicked();
        hint.visible = true;
        conentlist_ldr.item.clickedNumber = "";
        mesgDetailList.item.onSetSendMessageUnusered();
    }


    Connections {
        target: globalObject;
        onDetailContentUpdated: {
            mesgDetailList.item.onModelUpdated();
        }
        onSendMessageCallback:{
            mesgDetailList.item.onSetSendMessageUsered();
        }
        onSendMessageBtnUnused:{
            mesgDetailList.item.onSetSendMessageUnusered();
        }
    }
}
