import QtQuick 2.0
import "../Assistantqml"

Item {
    id: localMusicPlayPage;
    width: 1280;
    height: 720;

    property string  musicName:     "";
    property string  musicSinger:   "";
    property string  singerPicture: "../LocalMusicImages/CD.png";
    property int     playMode:         0;
    property bool    isMusicPictureRotation: false;
    property bool    playStatus:          true;

    Image {
        id: mainBackground
        anchors.fill: parent;
        source: "../Assistantimages/bg.png"
        visible:true;
    }

    Loader {
        id: returnBtn
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
            item.clicked.connect(localMusicPlayPage.localMusicBackClicked);
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
        id:playBackground;
        width: 1234;
        height: 592;
        anchors.horizontalCenter: parent.horizontalCenter;
        y:104
        source: "../LocalMusicImages/big_bg.png"
    }

    Image {
        id:singerPic;
        width: 330;
        height: 330;
        anchors.left: playBackground.left;
        anchors.leftMargin: 122;
        anchors.top:playBackground.top;
        anchors.topMargin: 55;
        source: singerPicture;
        RotationAnimation on rotation {
            id:picRotaton;
            loops: Animation.Infinite;
            from: 0;
            to: 360;
            duration: 10000;
            paused: !isMusicPictureRotation;
        }
    }

    Marquee {
        id: playPageSongName;
        maxWidth: 535;
        interval: 40;
        anchors.left: singerPic.right;
        anchors.leftMargin: 69;
        anchors.top:playBackground.top;
        anchors.topMargin: 171;
        Text {
            color:"#ffffff";
            text:musicName;
            font.pixelSize: 44
            font.family: fontFamily;
        }
    }

    Text {
        id: singer;
        width: 535;
        anchors.left: singerPic.right;
        anchors.leftMargin: 69;
        anchors.bottom: playBackground.bottom;
        anchors.bottomMargin: 285;
        color:"#ffffff";
        text:musicSinger;
        font.pixelSize: 44
        font.family: fontFamily;
        elide: Text.ElideRight;
        clip: true;
    }

    Loader {
        id:musicList;
        width: 56;
        height: 56;
        source: "Button.qml"
        x:175;
        y:595;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/list_n.png";
            item.pressSource = "../LocalMusicImages/list_p.png";
            item.clicked.connect(localMusicPlayPage.musicListClicked);
        }
    }

    Loader {
        id:musicPrev;
        width: 56;
        height: 46;
        source: "Button.qml"
        x:400;
        y:599;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/Prev_n.png";
            item.pressSource = "../LocalMusicImages/Prev_p.png";
            item.clicked.connect(localMusicPlayPage.prevClicked);
        }
    }

    Loader {
        id:musicPlay;
        width: 84;
        height: 48;
        source: "Button.qml"
        x:625;
        y: 599;
        visible: playStatus;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/playAndStop_n.png";
            item.pressSource = "../LocalMusicImages/playAndStop_p.png";
            item.clicked.connect(localMusicPlayPage.playClicked);
        }
    }

    Loader {
        id:musicPause;
        width: 84;
        height: 48;
        source: "Button.qml"
        x:625;
        y: 599;
        visible: !playStatus;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/playAndStop_n.png";
            item.pressSource = "../LocalMusicImages/playAndStop_p.png";
            item.clicked.connect(localMusicPlayPage.pauseClicked);
        }
    }

    Loader {
        id:musicNext;
        width: 56;
        height: 46;
        source: "Button.qml"
        x:850;
        y:599;
        visible: true;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/nextSong_n.png";
            item.pressSource = "../LocalMusicImages/nextSong_p.png";
            item.clicked.connect(localMusicPlayPage.nextClicked);
        }
    }

    Loader {
        id:musicPlayCycle;
        width: 71;
        height: 53;
        source: "Button.qml"
        x:1075;
        y:599;
        visible: playMode == 2 ? true:false;
        onLoaded: {            
            item.normalSource = "../LocalMusicImages/single_n.png";
            item.pressSource = "../LocalMusicImages/single_p.png";
            item.clicked.connect(localMusicPlayPage.cycleClicked);
        }
    }

    Loader {
        id:musicPlayLoop;
        width: 71;
        height: 53;
        source: "Button.qml"
        x:1075;
        y:599;
        visible: playMode == 0 ? true:false;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/loop_n.png";
            item.pressSource = "../LocalMusicImages/loop_p.png";
            item.clicked.connect(localMusicPlayPage.loopClicked);
        }
    }

    Loader {
        id:musicPlayRandom;
        width: 71;
        height: 53;
        source: "Button.qml"
        x:1075;
        y:599;
        visible: playMode == 1 ? true:false;
        onLoaded: {
            item.normalSource = "../LocalMusicImages/random_n.png";
            item.pressSource = "../LocalMusicImages/random_p.png";
            item.clicked.connect(localMusicPlayPage.randomClicked);
        }
    }

    signal randomClicked();
    signal loopClicked();
    signal cycleClicked();
    signal nextClicked();
    signal pauseClicked();
    signal playClicked();
    signal prevClicked();
    signal musicListClicked();
    signal localMusicBackClicked();

}
