import QtQuick 2.0

Item {
    id: eventItem;

    width: 484
    height: 117

    Image {
        id: itemBg;
        x: 0
        y: 0
        source: "../CalendarImages/notice_bg2.png"
    }

    Text {
        id: startTime
        x: 28
        y: 20
        color: "#ffffff"
        text: start_time
        font.pixelSize: 32
        elide: Text.ElideRight;
    }

    Text {
        id: endTime
        x: 28
        y: 63
        color: "#ffffff"
        text: end_time
        font.pixelSize: 32
        font.family: fontFamily;
        clip: true;
    }

    Text {
        id: eventLocal
        x: 154
        y: 20
        width: 330;
        color: "#ffffff"
        text: event_local
        font.pixelSize: 32
        font.family: fontFamily;
        elide: Text.ElideRight;
    }

    Text {
        id: eventTitle
        x: 152
        y: 63
        width: 293;
        color: "#ffffff"
        text: event_title
        font.pixelSize: 32
        font.family: fontFamily;
        clip: true;
        elide: Text.ElideRight;
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent

        onClicked: {
            parent.parent.ListView.view.parent.onclickitem(event_id,index);
        }
    }

}

