import QtQuick 2.0

Item {
    id: localMusicWindow;
    width: 1280
    height:720

    MouseArea {
        anchors.fill: parent;
    }

    Loader{
        id:localMusicPlayPage;
        anchors.fill: parent;
        source: "../LocalMusicQml/LocalMusicPlayPage.qml";
        visible: true;
        onLoaded: {
            item.musicListClicked.connect(onMusicListClicked);
            item.prevClicked.connect(sigPrevClicked);
            item.playClicked.connect(sigPlayClicked);
            item.pauseClicked.connect(sigPauseClicked);
            item.nextClicked.connect(sigNextClicked);
            item.cycleClicked.connect(onCycleClicked);
            item.loopClicked.connect(onLoopClicked);
            item.randomClicked.connect(onRandomClicked);
            item.localMusicBackClicked.connect(mBackBtnClicked);
        }
    }

    Loader{
        id:localMusicListPage;
        source: "../LocalMusicQml/LocalMusicList.qml";
        visible: false;
        onLoaded: {
            item.prevClicked.connect(sigPrevClicked);
            item.playClicked.connect(sigPlayClicked);
            item.pauseClicked.connect(sigPauseClicked);
            item.nextClicked.connect(sigNextClicked);
            item.backToPlayPage.connect(onBackToPlayPage);
            item.listPageBtnClicked.connect(onListPageBackBtnClicked);
        }
    }
    function onBackToPlayPage()
    {
        console.log("################## onBackToPlayPage \n");
        localMusicPlayPage.visible = true;
        localMusicListPage.visible = false;
    }

    function onCycleClicked()
    {
        console.log("################## onCycleClicked \n");
        globalObject.localMusic_do_SetPlayMode(2);
    }

    function onLoopClicked()
    {
        console.log("################## onLoopClicked \n");
        globalObject.localMusic_do_SetPlayMode(0);
    }

    function onRandomClicked()
    {
        console.log("################## onRandomClicked \n");
        globalObject.localMusic_do_SetPlayMode(1);
    }

    function onListPageBackBtnClicked()
    {
        if(localMusicListPage.visible == true)
        {
            localMusicListPage.visible = false;
            localMusicPlayPage.visible = true;
        }
    }

    function onMusicListClicked()
    {
        console.log("################## onMusicListClicked \n");
        localMusicPlayPage.visible = false;
        localMusicListPage.visible = true;
    }

    function setMusicPlayingOrStop(playStatus)
    {
        if(playStatus == 0)
        {
            localMusicPlayPage.item.playStatus = 0;
            localMusicListPage.item.playStatus = 0;
        }
        else if(playStatus == 1)
        {
            localMusicPlayPage.item.playStatus = 1;
            localMusicListPage.item.playStatus = 1;
        }
    }

    function setLocalMusicName(musicName)
    {
        if(musicName == "1")
        {
            localMusicPlayPage.item.musicName = "暂无音乐";
            localMusicListPage.item.musicName = "暂无正在播放音乐";
        }else{
            console.log("\n################# musicName = ",musicName);
            localMusicPlayPage.item.musicName = musicName;
            localMusicListPage.item.musicName = musicName;
        }
    }

    function setLocalMusicSinger(musicSinger)
    {
        localMusicPlayPage.item.musicSinger = musicSinger;
        localMusicListPage.item.musicSinger = musicSinger;
    }
	
    function setLocalMusicSingerPicture(picPath)
    {
        console.log("################## setLocalMusicSingerPicture   picPath: ",picPath);
        if(picPath == "1")
        {
            console.log("################## setLocalMusicSingerPicture \n");
            localMusicPlayPage.item.singerPicture = "../LocalMusicImages/CD.png";
            localMusicListPage.item.singerPicture = "../LocalMusicImages/CD_small.png";
        }else{
            localMusicPlayPage.item.singerPicture = "file://"+picPath;
            localMusicListPage.item.singerPicture = "file://"+picPath;
        }
    }

    function setMusicPlayStatus(playStatus)
    {
        console.log("\n################# setMusicPlayStatus: ",playStatus);
        if(playStatus == 0)
        {
            localMusicPlayPage.item.playStatus = false;
            localMusicListPage.item.playStatus = false;
        }else{
            localMusicPlayPage.item.playStatus = true;
            localMusicListPage.item.playStatus = true;
        }
    }

    function getPlayModeFromPhone(playmode)
    {
        if(playmode == 0) //loop
            localMusicPlayPage.item.playMode = 0;
        else if(playmode == 1)  //Random
            localMusicPlayPage.item.playMode = 1;
        else   //cycle
            localMusicPlayPage.item.playMode = 2;
    }

    function setMusicPageAndListAnimation(isRotation)
    {
        console.log("\n################# setMusicPageAndListAnimation: ",isRotation);
        if(isRotation == 0)
        {
            localMusicPlayPage.item.isMusicPictureRotation = true;
        }else{
            localMusicPlayPage.item.isMusicPictureRotation = false;
        }
    }

    function setMusicListMusicId(songId)
    {
        console.log("\n################# songID = ",songId);
        localMusicListPage.item.currentSelectMusicId = songId;
    }

    function setShowNoMusicText(flag)
    {
        localMusicListPage.item.setShowMusicListNoMusicText(flag);
    }

    function resetMusicNAmeAndSinger()
    {
        localMusicPlayPage.item.musicName = "暂无音乐";
        localMusicPlayPage.item.musicSinger = "";
        localMusicPlayPage.item.isMusicPictureRotation = false;
        localMusicListPage.item.musicName = "暂无正在播放音乐";
        localMusicListPage.item.musicSinger = "";
    }

    signal sigPrevClicked();
    signal sigPlayClicked();
    signal sigPauseClicked();
    signal sigNextClicked();
    signal mBackBtnClicked();

    Connections{
        target: globalObject;
        onSigGetPlayModeFromPhone:getPlayModeFromPhone(playmode);
    }

}
