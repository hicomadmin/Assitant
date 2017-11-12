import QtQuick 2.0


Item {
    id: button;
    width: 101;
    height: 101;
    property string text: "";
    signal btnClicked(string name);

    Image {
        id: btn_n;
        source: "../phoneimages/dial_bg_n.png";
        anchors.fill: parent;
        visible: true;
    }
    Image {
        id: btn_p;
        source: "../phoneimages/dial_bg_p.png";
        anchors.fill: parent;
        visible: false;
    }
    Image {
        id: btn_d;
        source: "../phoneimages/dial_bg_n.png"; //default disable state the same as normal
        anchors.fill: parent;
        visible: false;
    }
    function setBtnBgN(src)
    {
        btn_n.source = src;
    }
    function setBtnBgP(src)
    {
        btn_p.source = src;
    }
    function setBtnBgD(src)
    {
        btn_d.source = src;
    }
    function setEnabled(enabled)
    {
        button.enabled = enabled;
    }

    Text {
        id: numKey;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 32;
        text: button.text;
        color: button.focus ? "#00fffc":"#ffffff";
        font.pixelSize: 48;
        font.family: fontFamily;
        elide: Text.ElideRight;
    }
    onEnabledChanged: {
        if(enabled) {
            btn_d.visible = false;
            btn_p.visible = false;
            btn_n.visible = true;
        }else{
            btn_p.visible = false;
            btn_n.visible = false;
            btn_d.visible = true;
        }
    }

    MouseArea {
        anchors.fill: parent;
        enabled: button.enabled;
        onPressed: {
            button.focus = true;
            btn_p.visible = true;
            btn_n.visible = false;
        }
        onExited: {
            button.focus = false;
            if(button.enabled) {
                btn_p.visible = false;
                btn_n.visible = true;
            }
        }
        onReleased: {
            if(button.enabled) {
                btn_p.visible = false;
                btn_n.visible = true;
            }
        }
        onClicked: {
            btnClicked(button.text);
        }
    }
}
