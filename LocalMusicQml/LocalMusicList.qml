import QtQuick 2.0
import "../Assistantqml"

Item {
    id: musicListPage
    width: 1280
    height:720

    property string    musicName:          "";
    property string    musicSinger:        "";
    property string    singerPicture:      "../LocalMusicImages/CD_small.png";
    property string    currentSelectMusicId:  "";
    property bool      playStatus:          true;

    Image {
        id: mainBackground;
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
        visible:true;
    }

    Loader {
        width: 67;
        height: 67;
        source: "Button.qml"
        anchors.left: parent.left;
        anchors.leftMargin: 66;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        onLoaded: {
            item.normalSource = "../Assistantimages/back_icon_n.png";
            item.pressSource = "../Assistantimages/back_icon_p.png";
            item.clicked.connect(musicListPage.listPageBtnClicked);
        }
    }

    Text {
        text:"音乐"
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 27;
        font.pixelSize: 42;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
    }

    Image {
        id: listbkg
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 104;
        width: 1234;
        height: 483;
        source: "../LocalMusicImages/up_bg.png"
    }
    //for demo
    ListModel{
        id:musicListModel;
        ListElement{
            musicPlayingPic: "../LocalMusicImages/music.png";
            localMusicName:"飞车勿扰--汽车保养123456789012345567890";
            localMusicSinger:"车友讲堂";
            duration:"03 : 45";
            localMusicSingerPath:"" ;
        }
        ListElement{
            musicPlayingPic: "../LocalMusicImages/music.png";
            localMusicName:"超好听的欧美音乐";
            localMusicSinger:"匿名";
            duration:"05 : 04";
            localMusicSingerPath:"" ;
        }
        ListElement{
            musicPlayingPic: "../LocalMusicImages/music.png";
            localMusicName:"Nothing's Gonna Change";
            localMusicSinger:"George Benson";
            duration:"02 : 55"
            localMusicSingerPath:"" ;
        }
        ListElement{
            musicPlayingPic: "../LocalMusicImages/music.png";
            localMusicName:"十万个冷笑话";
            localMusicSinger:"哔哩哔哩";
            duration:"03 : 12";
            localMusicSingerPath:"" ;
        }
    }

    ListView{
        id:musicInfoListView;
        anchors.left: listbkg.left;
        anchors.right: listbkg.right;
        anchors.top: listbkg.top;
        anchors.topMargin: 12;
        anchors.bottom: listbkg.bottom;
        orientation:ListView.Vertical;
        model: localmusic;
        delegate: listModeDelegate;
        clip: true;
        visible: true;
    }

    Component{
        id:listModeDelegate;
        Item{
            id:musicInfo;
            width:musicInfoListView.width;
            height: 116;
            focus: false;

            Rectangle{
                id:hightlight;
                width: 1120;
                height: 105;
                anchors.top:underLine.top;
                anchors.topMargin: 6;
                anchors.left: parent.left;
                anchors.leftMargin: 57;
                focus: false;
                radius: 2;
                color: musicInfo.focus == false ? "transparent" : "#f14f5f";
            }

            Image{
                id:underLine;
                anchors.bottom: musicInfo.top;
                anchors.left: musicInfo.left;
                anchors.leftMargin: 53;
                anchors.right: musicInfo.right
                anchors.rightMargin: 53
                source:"../LocalMusicImages/box_list_line.png"
            }

            Image{
                id:musicIcon;
                width: 48;
                height: 52;
                anchors.left: parent.left;
                anchors.leftMargin: 130;
                anchors.verticalCenter: parent.verticalCenter;
                source: musicId.text == currentSelectMusicId ? "../LocalMusicImages/playing.png" : "../LocalMusicImages/music.png";
            }

            Text{
                id:musicId;
                anchors.top: parent.top;
                anchors.topMargin: 40;
                anchors.left: parent.left;
                anchors.leftMargin: 400;
                text: songId;
                visible: false;
            }

            Text {
                id: musicListSongName;
                width: 744;
                anchors.top: parent.top;
                anchors.topMargin: 25;
                anchors.left: parent.left;
                anchors.leftMargin: 260;
                text: localMusicName;
                font.pixelSize: 31;
                font.family: fontFamily;
                color: musicId.text == currentSelectMusicId ? "#78e012" : "#ffffff";
                clip: true;
            }

            Text{  //(29 characters 640px)
                id:singer;
                width: 730;
                anchors.top: underLine.bottom;
                anchors.topMargin: 72;
                anchors.left: parent.left;
                anchors.leftMargin: 260;
                text: localMusicSinger;
                font.pixelSize: 24;
                font.family: fontFamily;
                color:  musicId.text == currentSelectMusicId ? "#78e012": (musicInfo.focus == true ? "#ffffff": "#ff5e00");
                elide: Text.ElideRight;
                clip: true;
            }

//            Text{
//                id:time;
//                anchors.top: parent.top;
//                anchors.topMargin: 73;
//                anchors.right: parent.right;
//                anchors.rightMargin: 160;
//                text: duration;
//                font.pixelSize: 24;
//                font.family: fontFamily;
//                color: musicInfo.focus == false ? "#ff5e00" : "#78e012";
//                clip: true;
//            }

            Image{
                id:bottomUnderLine;
                anchors.top: musicInfo.bottom;
                anchors.left: musicInfo.left;
                anchors.leftMargin: 53;
                anchors.right: musicInfo.right
                anchors.rightMargin: 53
                source:"../LocalMusicImages/box_list_line.png"
            }

            MouseArea{
                id:listMousArea;
                anchors.fill:musicInfo;
                onPressed: musicInfo.focus = true;
                onExited: musicInfo.focus = false;
                onReleased: musicInfo.focus = false;
                onClicked: {
                    globalObject.localMusic_do_PlayLocalSong(songId);
                }
            }

        }
    }

    Image {
        id: bottomPlayBtnBg
        anchors.horizontalCenter: parent.horizontalCenter;
        y:610;
        width: 1236;
        height: 95;
        source: "../LocalMusicImages/down_bg.png"
        MouseArea{
            width: 650;
            height: parent.height;
            anchors.left: parent.left;
            anchors.leftMargin: 32;
            anchors.top: parent.top;
            onClicked: backToPlayPage();
        }
    }

    Image {
        id: musicPic
        width: 86;
        height: 86;
        anchors.left: bottomPlayBtnBg.left;
        anchors.leftMargin: 32;
        anchors.top:bottomPlayBtnBg.top;
        anchors.topMargin: 6;
        anchors.bottom: bottomPlayBtnBg.bottom;
        anchors.bottomMargin: 5;
        source: singerPicture;
    }

    Text {
        id: bottomName;
        text:musicName;
        width: 520;
        anchors.left: bottomPlayBtnBg.left;
        anchors.leftMargin: 150;
        anchors.top: bottomPlayBtnBg.top;
        anchors.topMargin: 20;
        color:"#ffffff";
        font.pixelSize: 26;
        font.family: fontFamily;
        clip: true;
    }

    Text {
        text: musicSinger;
        width: 610;
        anchors.left: bottomPlayBtnBg.left;
        anchors.leftMargin: 150;
        anchors.bottom: bottomPlayBtnBg.bottom;
        anchors.bottomMargin: 12;
        font.pixelSize: 24
        font.family: fontFamily;
        color: "#ffffff";
        elide: Text.ElideRight;
        clip: true;
    }

    Loader {
        id:musicPrev;
        width: 56;
        height: 46;
        source: "Button.qml"
        anchors.right: musicPlay.left;
        anchors.rightMargin: 102;
        anchors.verticalCenter: bottomPlayBtnBg.verticalCenter;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/Prev_n.png";
            item.pressSource = "../LocalMusicImages/Prev_p.png";
            item.clicked.connect(musicListPage.prevClicked);
        }
    }

    Loader {
        id:musicPlay;
        width: 84;
        height: 48;
        source: "Button.qml"
        anchors.right: musicNext.left;
        anchors.rightMargin: 102;
        anchors.verticalCenter: bottomPlayBtnBg.verticalCenter;
        visible: playStatus;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/playAndStop_n.png";
            item.pressSource = "../LocalMusicImages/playAndStop_p.png";
            item.clicked.connect(musicListPage.playClicked);
        }
    }

    Loader {
        id:musicPause;
        width: 84;
        height: 48;
        source: "Button.qml"
        anchors.right: musicNext.left;
        anchors.rightMargin: 102;
        anchors.verticalCenter: bottomPlayBtnBg.verticalCenter;
        visible: !playStatus;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/playAndStop_n.png";
            item.pressSource = "../LocalMusicImages/playAndStop_p.png";
            item.clicked.connect(musicListPage.pauseClicked);
        }
    }

    Loader {
        id:musicNext;
        width: 56;
        height: 46;
        source: "Button.qml"
        anchors.right: bottomPlayBtnBg.right;
        anchors.rightMargin: 56;
        anchors.verticalCenter: bottomPlayBtnBg.verticalCenter;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/nextSong_n.png";
            item.pressSource = "../LocalMusicImages/nextSong_p.png";
            item.clicked.connect(musicListPage.nextClicked);
        }
    }

    Text {
        id:noMusic;
        text:"暂无音乐,请到手机端下载";
        anchors.centerIn: listbkg;
        font.pixelSize: 36;
        font.family: fontFamily;
        color: "#ffffff";
        visible: false;
    }

    function setShowMusicListNoMusicText(flag)
    {
        if(flag == 1)
        {
            musicInfoListView.visible = false;
            noMusic.visible = true;
        }else{
            musicInfoListView.visible = true;
            noMusic.visible = false;
        }
    }

    signal prevClicked();
    signal playClicked();
    signal pauseClicked();
    signal nextClicked();
    signal backToPlayPage();
    signal listPageBtnClicked();

}
