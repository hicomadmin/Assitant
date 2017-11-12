import QtQuick 2.0

Item {
    width: 1280
    height: 720
    visible: true
    property int categoryIndex: 0;
    signal phoneCallBtnCliked(string number, string contentName);
    signal phoneBackButtonCliked();

    Image {
        id:bk
        anchors.fill: parent
        source: "../Assistantimages/bg.png"
    }

    MouseArea{
        anchors.fill: parent
    }

    Item {
        id: title;
        width: 1280;
        height: 105;
        anchors.right: parent.right;
        anchors.top: parent.top;
        Image {
            anchors.left: parent.left;
            anchors.top: parent.top;
            source: "../phoneimages/title.png";
        }
        Text {
            text: qsTr("电话");
            font.pixelSize: 42;
            font.family: fontFamily;
            color: "#ffffff";
            anchors.centerIn: parent;
        }
    }

    Loader {
        width: 67;
        height: 67;
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        source: "../Assistantqml/Button.qml";
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(phoneBackButtonCliked);
        }
    }

    //拨号 电话簿 通话
    Loader {
        id: categoryid;
        anchors.left: parent.left;
        anchors.leftMargin: 22;
        anchors.top: title.bottom;
        source: "category.qml";
        onLoaded: {
            item.categoryChanged.connect(onCategoryChanged);
            item.setFocus(categoryIndex);
        }
    }

    Loader{
        id:dialView
        anchors.left: categoryid.right;
        anchors.top: categoryid.top;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        source: "phone_dial.qml";
        onLoaded: {
            item.pohneCallClicked.connect(onpohneCallClicked);
        }
    }

    Loader{
        id:contactsView;
        anchors.left: categoryid.right;
        anchors.top: categoryid.top;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        visible: false;
        source: "Contacts.qml";
        onLoaded: {
            item.contactItemClicked.connect(onContactItemClicked);
        }
    }
    Loader{
        id:callRecordView;
        anchors.left: categoryid.right;
        anchors.top: categoryid.top;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        visible: false;
        source:  "CallRecord.qml";
        onLoaded: {
            item.callRecordClick.connect(onContactItemClicked);
        }
    }
    Image {
        id: phoneBookloadingIcon;
        objectName: "phoneBookloadingIcon"
        width: 120;
        height: 120;
        anchors.centerIn: contactsView;
        visible: false;
        source: "../phoneimages/downloading_icon.png"
        NumberAnimation {
            running: phoneBookloadingIcon.visible
            loops: Animation.Infinite
            target: phoneBookloadingIcon
            from: 0
            to: 360
            property: "rotation"
            duration: 1000
        }
    }

    function onpohneCallClicked(contentNumber,contentName)
    {
        phoneCallBtnCliked(contentNumber, contentName);
    }

    function onContactItemClicked(contentNumber, contentName)
    {
        phoneCallBtnCliked(contentNumber, contentName);
    }

    function setCategoryFocus(category)
    {
        categoryid.item.setFocus(category);
    }

    function onCategoryChanged(category) {
        console.log("onCategoryChanged id:", category);
        categoryIndex = category;
        activeCategory(categoryIndex);
    }

    function activeCategory(categoryIndex)
    {
        console.log("activeCategory categoryIndex :%d ======", categoryIndex);
        if(categoryIndex == 0){
            dialView.visible = true;
            phoneBookloadingIcon.visible = false;
            contactsView.visible = false;
            callRecordView.visible = false;
            phoneCallAnswer.visible = false;
        }
        else if(categoryIndex == 1){
            dialView.visible = false;
            callRecordView.visible = false;
            phoneCallAnswer.visible = false;
            contactsView.visible = true;
            globalObject.readContactList();
        }
        else{
            dialView.visible = false;
            contactsView.visible = false;
            phoneCallAnswer.visible = false;
            callRecordView.visible = true;
            phoneBookloadingIcon.visible = true;
            globalObject.getCallLogs();
        }
    }

    function setPhoneDialTextNull()
    {
        dialView.item.inputText = "";
        dialView.item.deleteGrey();
    }

}

