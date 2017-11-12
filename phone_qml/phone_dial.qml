/*******************************************************
文  件  名: phone_dial.qml
描      述：拨号界面（包括拨号、文本区、打电话按钮）
*******************************************************/
import QtQuick 2.0


Item{
    id: softKeyBoard;
    signal keyPressed (string ch);
    signal pohneCallClicked(string contentNumber, string contentName);
    property string inputText: "";

    Image {
        id: bg_right
        anchors.left: parent.left;
        anchors.top:  parent.top;
        source: "../phoneimages/dial_bg.png"
    }

    Grid {
        anchors.left: bg_right.left;
        anchors.leftMargin: 38;
        anchors.top: bg_right.top;
        anchors.topMargin: 16;
        columns: 3;
        columnSpacing: 58;
        rowSpacing: 36;

        Loader {
            source: "KeybordButton.qml";
            id: btn_1;
            onLoaded: {
                item.text = "1";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_2;
            onLoaded: {
                item.text = "2";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_3;
            onLoaded: {
                item.text = "3";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_4;
            onLoaded: {
                item.text = "4";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_5;
            onLoaded: {
                item.text = "5";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_6;
            onLoaded: {
                item.text = "6";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_7;
            onLoaded: {
                item.text = "7";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_8;
            onLoaded: {
                item.text = "8";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_9;
            onLoaded: {
                item.text = "9";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "asteriskKeybordButton.qml";
            id: btn_asterisk;
            onLoaded: {
                item.text = "*";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_0;
            onLoaded: {
                item.text = "0";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
        Loader {
            source: "KeybordButton.qml";
            id: btn_end;
            onLoaded: {
                item.text = "#";
                item.btnClicked.connect(onSoftKeyBoardPressed);
            }
        }
    }

/******************拨号界面显示 begin********************/
    //编辑区
    Image {
        id: inputArea;
        width: 573;
        height: 103;
        anchors.right: bg_right.right;
        anchors.rightMargin: 20;
        anchors.top: bg_right.top;
        anchors.topMargin: 16;
        source: "../phoneimages/input_bg.png";
    }
    //省略号效果
    Text{
        id: inputAreaText;
        anchors.left: inputArea.left;
        anchors.leftMargin: 36;
        anchors.top: inputArea.top;
        anchors.topMargin: 20;
        anchors.right: deleteBtn.left;
        text: inputText;
        elide: Text.ElideLeft;
        font.pixelSize: 50;
        font.family: fontFamily;
        color: "#ffffff";
    }

    Loader {
        id:deleteBtn;
        source: "Button.qml";
        anchors.right:  inputArea.right;
        anchors.rightMargin: 30;
        anchors.verticalCenter: inputArea.verticalCenter
        width: 58;
        height: 44;
        onLoaded: {
            item.normalSource = "../phoneimages/delate_n.png";
            item.pressSource = "../phoneimages/delate.png";
            item.setEnabled(false);
            item.clicked.connect(onDeleteBtnPressed);
        }
    }

    //联想结果，最多3条
    Loader {
        id: list;
        objectName: "list";
        source: "./phone_thinkResult.qml";
        anchors.left: inputArea.left
        width: inputArea.width;
        anchors.top: inputArea.bottom
        anchors.topMargin: 40
        anchors.bottom: call_key.top;
        onLoaded: {
            item.contactItemClicked.connect(onContactItemClicked);
        }
    }

    //加载通话键
    Loader {
        id:call_key;
        anchors.horizontalCenter: inputArea.horizontalCenter;
        anchors.bottom: bg_right.bottom;
        anchors.bottomMargin:  36;
        width: 150;
        height: 150;
        visible: true;
        source: "../Assistantqml/Button.qml";
        onLoaded: {
            item.btnText = inputText;
            item.normalSource =  "../phoneimages/take_p.png"; //"../phoneimages/take.png"
            item.pressSource = "../phoneimages/take_p.png";
            item.clicked.connect(onDialNumberKeyClicked);
        }
    }

/****************** function ********************/

    function onSoftKeyBoardPressed(ch)
    {
        console.log("[phone_dial.qml] key pressed ", ch);
        if(inputText.length < 20) {
            inputText += ch.toLowerCase();
            globalObject.fillContactList(1, inputText);
        }
        if(inputText.length)
        {
            call_key.item.normalSource = "../phoneimages/take.png";
            deleteHighlight();
            deleteBtn.item.setEnabled(true);
        }
    }

    function onDeleteBtnPressed()
    {
        //inputAreaText.text.trim();
        inputText = inputText.slice(0, -1);
        if(inputText.length == 0) {
            deleteGrey();
            call_key.item.normalSource = "../phoneimages/take_p.png";
            c_thinkResultListModel.clear();
        }else{
            globalObject.fillContactList(1, inputText);
        }
    }

    function onContactItemClicked(number, name) {
        pohneCallClicked(number,name);
    }

    function onDialNumberKeyClicked()
    {
        if(inputText.length > 0)
        {
            pohneCallClicked(inputText, inputText)
        }
    }

    function deleteHighlight()
    {
        deleteBtn.item.normalSource = "../phoneimages/delate.png";
        deleteBtn.item.pressSource = "../phoneimages/delate_n.png";
    }
    function deleteGrey()
    {
        deleteBtn.item.normalSource = "../phoneimages/delate_n.png";
        deleteBtn.item.pressSource = "../phoneimages/delate.png";
        deleteBtn.item.setEnabled(false);
    }
}

