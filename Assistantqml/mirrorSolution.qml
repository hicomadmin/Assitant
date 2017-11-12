import QtQuick 2.0

Item {
    width: 1280
    height: 720

    Image {
        id: main_bkg
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
        visible:true;
    }

    MouseArea{
        anchors.fill: parent
    }

    Title{
        id:title;
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: parent.width;
        titleText: qsTr("解决方案", I108n.lang);
        onBackClicked: {
            onSolutionBackBtnClicked();
        }
    }

    Image {
        id: centerPic;
        width: 1199;
        height: 579;
        anchors.top: parent.top;
        anchors.topMargin: 106;
        anchors.horizontalCenter:main_bkg.horizontalCenter;
        source: "../Assistantimages/center.png"

        Text {
            id: text1;
            anchors.top: parent.top;
            anchors.topMargin: 65
            anchors.left: parent.left;
            anchors.leftMargin: 108
            color: "#ffffff";
            font.pixelSize: 34;
            font.family: fontFamily;
            text: qsTr("①开启开发者选项", I108n.lang);
        }

        Text {
            id:text2
            anchors.left: text1.left;
            anchors.top: text1.bottom
            anchors.topMargin: 10;
            color: "#ffffff";
            font.pixelSize: 34;
            font.family: fontFamily;
            text: qsTr("勾选默认<font color=\"#ff3057\">USB配件</font>并确认", I108n.lang);
        }

        Text {
            id: text3;
            anchors.top: parent.top;
            anchors.topMargin: 65
            anchors.left: text2.right;
            anchors.leftMargin: 200;
            color: "#ffffff";
            font.pixelSize: 34;
            font.family: fontFamily;
            text: qsTr("②首次连接勾选<font color=\"#ff3057\">始终</font>", I108n.lang);
        }

        Text {
            id: text4;
            anchors.left: text3.left;
            anchors.top: text3.bottom;
            anchors.topMargin: 10;
            color: "#ffffff";
            font.pixelSize: 34;
            font.family: fontFamily;
            text: qsTr("<font color=\"#ff3057\">允许该PC</font>并确认", I108n.lang);
        }

        Image {
            id: pic3;
            anchors.top: text2.bottom;
            anchors.topMargin: 54;
            anchors.left: text2.left;
            width: 318;
            height: 321;
            source: "../Assistantimages/barcode/pic3.png";
        }

        Image {
            id: pic8;
            anchors.top: text4.bottom;
            anchors.topMargin: 100;
            anchors.left: text4.left;
            width: 428;
            height: 246;
            source: "../Assistantimages/barcode/pic8.png";
        }
    }


    function onSolutionBackBtnClicked()
    {
        solutionbackBtnClicked();
    }

    signal solutionbackBtnClicked();
}
