import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    id: item1
    width: 1280
    height: 720
    visible: true

    property int weatherMouth: 0;
    property int weatherDay: 0;

    onVisibleChanged: {
        if(visible){
            loadstatus.text = "正在刷新天气...";
            loadstatus.visible = true;
            loading_icon.visible = true;
            reloading.visible = false;
            globalObject.onWeatherInit();
        }
    }

    Image {
        id: weatherBG
        anchors.fill: parent;
        width: 1280;
        height: 720;
        source: "../Assistantimages/bg.png";
    }
    
    MouseArea{
        anchors.fill: parent;
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
            item.clicked.connect(weatherBackCliceked);
        }
    }

    Text {
        text: qsTr("天气");
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 27;
        font.pixelSize: 42;
        font.family: fontFamily;
        color: "#ffffff";
        wrapMode: Text.Wrap;
    }

    Image {
        id: firstDayPlane
        x: 34
        y: 113
        width: 402;
        height: 177;
        source: "../weatherImages/bg/left_plane.png"

        Text {
            id: firstDayWeek
            anchors.left: parent.left
            anchors.leftMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 44
            color: "#ffffff"
            text: qsTr("周--")
            font.pixelSize: 35
            font.family: fontFamily;
        }

        Text {
            id: firstDayWeather
            anchors.left: parent.left
            anchors.leftMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 112
            color: "#ffffff"
            text: qsTr("--")
            font.pixelSize: 27
            font.family: fontFamily;
        }

        Text {
            id: firstDayTempture
            anchors.right: parent.right
            anchors.rightMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 44
            color: "#ffffff"
            text: qsTr("--/--")
            font.pixelSize: 35
            font.family: fontFamily;
        }

        Image {
            id: firstDayWeatherIcon
            anchors.right: parent.right
            anchors.rightMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 100
            width: 60
            height: 60
            source: "../weatherImages/weather_icon_small/weather_icon_0.png"
        }
    }

    //week2
    Image {
        id: secondDayPlane
        x: 35
        anchors.top: firstDayPlane.bottom;
        anchors.topMargin: 13;
        width: 402;
        height: 177;
        source: "../weatherImages/bg/left_plane.png"
        Text {
            id: firstDayWeek1
            anchors.left: parent.left
            anchors.leftMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 44
            color: "#ffffff"
            text: qsTr("周--")
            font.pixelSize: 35
            font.family: fontFamily;
        }

        Text {
            id: firstDayWeather1
            anchors.left: parent.left
            anchors.leftMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 112
            color: "#ffffff"
            text: qsTr("--")
            font.pixelSize: 27
            font.family: fontFamily;
        }

        Text {
            id: firstDayTempture1
            anchors.right: parent.right
            anchors.rightMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 44
            color: "#ffffff"
            text: qsTr("--/--")
            font.pixelSize: 35
            font.family: fontFamily;
        }

        Image {
            id: firstDayWeatherIcon1
            anchors.right: parent.right
            anchors.rightMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 100
            width: 60
            height: 60
            source: "../weatherImages/weather_icon_small/weather_icon_0.png"
        }
    }

    //week3
    Image {
        id: thirdDayPlane
        x: 35
        anchors.top: secondDayPlane.bottom;
        anchors.topMargin: 13;
        width: 402;
        height: 177;
        source: "../weatherImages/bg/left_plane.png"
        Text {
            id: firstDayWeek2
            anchors.left: parent.left
            anchors.leftMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 44
            color: "#ffffff"
            text: qsTr("周--")
            font.pixelSize: 35
            font.family: fontFamily;
        }

        Text {
            id: firstDayWeather2
            anchors.left: parent.left
            anchors.leftMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 112
            color: "#ffffff"
            text: qsTr("--")
            font.pixelSize: 27
            font.family: fontFamily;
        }

        Text {
            id: firstDayTempture2
            anchors.right: parent.right
            anchors.rightMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 44
            color: "#ffffff"
            text: qsTr("--/--")
            font.pixelSize: 35
            font.family: fontFamily;
        }

        Image {
            id: firstDayWeatherIcon2
            anchors.right: parent.right
            anchors.rightMargin: 36
            anchors.top: parent.top
            anchors.topMargin: 100
            width: 60
            height: 60
            source: "../weatherImages/weather_icon_small/weather_icon_0.png"
        }
    }

    //righ
    Image {
        id: rightPlane
        x: 448
        y: 113
        width: 795
        height: 557
        source: "../weatherImages/bg/right_plane.png"
    }

    Text {
        id: loadstatus
        x: 630
        y: 162
        color: "#ffffff"
        text: qsTr("正在刷新天气...")
        font.pixelSize: 35
        font.family: fontFamily;
    }

    Image {
        id: loading_icon
        objectName: "weatherLoadingIcon"
        y: 162
        anchors.left: loadstatus.right;
        width: 28
        height: 30
        clip: false
        visible: loadstatus.text.length == 9 ? true : false; //正在刷新天气...
        opacity: 1
        source: "../weatherImages/loading.png"

        NumberAnimation {
            running: loading_icon.visible
            loops: Animation.Infinite
            target: loading_icon
            from: 0
            to: -360
            property: "rotation"
            duration: 1000
        }
    }

    //Icon right
    Image {
        id: weathericon
        x: 630
        y: 294
        width: 120
        height: 120
        source: "../weatherImages/weather_icon_big/weather_icon_0.png"
    }

    //temp right
    Text {
        id: weathertemp
        y: 312 -25
        anchors.right: parent.right
        anchors.rightMargin: 296
        color: "#ffffff"
        text: qsTr("--")
        font.pixelSize: 120
        font.family: fontFamily;
    }

    Image {
        id: logo
        y: 675
        anchors.right: rightPlane.right;
        width: 99
        height: 31
        source: "../weatherImages/logo.png"
    }

    //city
    Text {
        id: weathercityinfo
        x: 630
        y: 218
        color: "#ffffff"
        text: qsTr("")
        font.pixelSize: 35
        font.family: fontFamily;
    }

    //week right
    Text {
        id: weathercityweekinfo
        anchors.left: weathercityinfo.right;
        anchors.bottom: weathercityinfo.bottom
        color: "#ffffff"
        font.pixelSize: 35
        font.family: fontFamily;
    }

    //date
    Text {
        id: weathercitydateinfo
        anchors.left: weathercityweekinfo.right;
        y: 218
        color: "#ffffff"
        font.pixelSize: 35
        font.family: fontFamily;
    }

    Text {
        id: weatherreleasetime
        color: "#ffffff"
        text: qsTr("")
        anchors.left: weathercitydateinfo.right
        anchors.leftMargin: 6
        anchors.bottom: weathercityinfo.bottom
        anchors.bottomMargin: 5
        font.pixelSize: 23
        visible:true
        font.family: fontFamily;
    }

    Text {
        id: weatherchangestatus
        x: 604
        y: 452
        color: "#ffffff"
        text: qsTr("")
        font.pixelSize: 32
        font.family: fontFamily;
    }

    Text {
        id: weatherwind
        //x: 900
        y: 452
        anchors.right: parent.right
        anchors.rightMargin: 188
        color: "#ffffff"
        text: qsTr("")
        font.pixelSize: 32
        font.family: fontFamily;
    }

    Text {
        id: highTemp
        y:318 -2
        anchors.right: parent.right
        anchors.rightMargin: 188
        color: "#ed4f5f";
        text: qsTr("--")
        font.family: fontFamily
        font.pixelSize: 25
    }

    Text {
        id: lowTemp
        y: 378 -2
        anchors.right: parent.right
        anchors.rightMargin: 188
        color: "#18f5f9"
        text: qsTr("--")
        font.family: fontFamily
        font.pixelSize: 25
    }

    Image{
        id: highTmpIcon
        x:1002;
        y: 318;
        width: 13;
        height: 23;
        source: "../weatherImages/hight.png"
    }

    Image{
        id:lowTmpIcon
        x: 1002
        y: 378
        width: 13;
        height: 23;
        source: "../weatherImages/lower.png"
    }

    Button {
        id: btnwash
        x: 607
        y: 544
        width: 238;
        height: 87;
        normalSource: "../weatherImages/bg/bg_6.png"
        pressSource: "../weatherImages/bg/bg_6.png"

        Image {
            id: image3
            x: 50;
            anchors.verticalCenter: parent.verticalCenter;
            width: 30
            height: 30
            source: "../weatherImages/icon_wash.png"
        }

        Text {
            id: washIndex
            objectName: "washIndexObj";
            x: 100;
            anchors.verticalCenter: parent.verticalCenter;
            color: "#ffffff"
            text: qsTr("--")
            font.pixelSize: 25
            font.family: fontFamily;
        }
    }

    Button {
        id: btnairIndex
        x: 849
        y: 544
        width: 238;
        height: 87;
        pressSource: "../weatherImages/bg/bg_1.png"
        normalSource: "../weatherImages/bg/bg_1.png"

        Image {
            id: image4
            x: 50;
            anchors.verticalCenter: parent.verticalCenter;
            width: 30
            height: 30
            source: "../weatherImages/1.png"

            Text {
                id: airIndex
                anchors.centerIn: parent;
                text: qsTr("-")
                font.pixelSize: 22
                font.family: fontFamily;
            }
        }

        Text {
            id: airlevel
            x: 120
            anchors.verticalCenter: parent.verticalCenter;
            color: "#ffffff"
            text: qsTr("--")
            font.pixelSize: 25
            font.family: fontFamily;
        }
    }

    Loader{
        id: reloading;
        x: 968;
        y: 152;
        width: 150;
        height: 55;
        source: "../Assistantqml/Button.qml"
        visible: !loading_icon.visible && loadstatus.text.length == 10;
        onLoaded: {
            item.btnText = "重新加载";
            item.textsize = 23;
            item.pressSource = "../weatherImages/bg/more_p.png";
            item.normalSource = "../weatherImages/bg/more_n.png";
            item.clicked.connect(onBtnLoadingClicked);
        }
    }

    function on_updateEveryDayWeather()
    {
        weathercityweekinfo.text = globalObject.getCurrentWeekWeaeher() + " ";
        var weatherinfolist = globalObject.getFirstDayWeatherInfo();
        for(var i in weatherinfolist)
        {
            firstDayWeek.text = weatherinfolist[1];
            firstDayWeather.text = String(weatherinfolist[4]);
            firstDayTempture.text = String(weatherinfolist[2])+ "°" + "/" + String(weatherinfolist[3]) + "°";
            firstDayWeatherIcon.source = weatherinfolist[8];
            break;
        }

        weatherinfolist = globalObject.getSecondDayWeatherInfo();
        for(var i in weatherinfolist)
        {
            firstDayWeek1.text = weatherinfolist[1];
            firstDayWeather1.text = String(weatherinfolist[4]);
            firstDayTempture1.text = String(weatherinfolist[2]) + "°"+ "/" + String(weatherinfolist[3]) + "°";
            firstDayWeatherIcon1.source = weatherinfolist[8];

            break;
        }

        weatherinfolist = globalObject.getThirdDayWeatherInfo();
        for(var i in weatherinfolist)
        {
            firstDayWeek2.text = weatherinfolist[1];
            firstDayWeather2.text = String(weatherinfolist[4]);
            firstDayTempture2.text = String(weatherinfolist[2]) + "°"+ "/" + String(weatherinfolist[3]) + "°";
            firstDayWeatherIcon2.source = weatherinfolist[8];

            break;
        }
    }

    function on_updateCurrentDayWeather()
    {
        var weatherinfolist = globalObject.getCurrentDayWeatherInfo();
        weatherMouth = String(weatherinfolist[2]).substring(0, 2); //类型转换去掉08前面的0
        weatherDay  = String(weatherinfolist[2]).substring(3, 5);  //类型转换去掉08前面的0
        for(var i in weatherinfolist)
        {
            console.log("############# weatherMouth = ", weatherMouth);
            console.log("############# weatherDay = ", weatherDay);
            weathercityinfo.text = String(weatherinfolist[7]) + " ";
            weathercitydateinfo.text = weatherMouth + "月" + weatherDay + "日";
            weatherreleasetime.text = "(" + String(weatherinfolist[2]).substring(6, 12) + "发布)";
            weathertemp.text = weatherinfolist[5] + "°";
            weatherchangestatus.text = String(weatherinfolist[4]);
            weatherwind.text = weatherinfolist[12];
            weathericon.source = weatherinfolist[15];

            airIndex.text = weatherinfolist[13]; //140
            setIconPath(airIndex.text);
            airlevel.text =  weatherinfolist[14]; //轻度污染

            lowTemp.text = weatherinfolist[9] + "°";
            highTemp.text = weatherinfolist[10] + "°";

            return;
        }
    }

    function setIconPath(aqi)
    {
        if(aqi == 60)
            image4.source = "../weatherImages/icon_pollution2.png";
        else if(aqi == 140)
        {
            image4.width = 50;
            image4.height = 50;
            image4.source = "../weatherImages/icon_pollution3.png";
        }
        else if(aqi == 170)
        {
            image4.width = 50;
            image4.height = 50;
            image4.source = "../weatherImages/icon_pollution4.png";
        }
        else if(aqi == 170)
        {
            image4.width = 50;
            image4.height = 50;
            image4.source = "../weatherImages/icon_pollution5.png";
        }
        else if(aqi == 170)
        {
            image4.width = 50;
            image4.height = 50;
            image4.source = "../weatherImages/icon_pollution6.png";
        }
        else //48
            image4.source = "../weatherImages/1.png";
    }

    function onBtnLoadingClicked(){
        console.log("############## onBtnLoadingClicked 222")
        loadstatus.visible = true;
        loadstatus.text = "正在刷新天气...";
        loading_icon.visible = true;
        reloading.visible = false;
        globalObject.onWeatherInit();
    }

    function onLoad_ok()
    {
        reloading.visible = false;
        loading_icon.visible = false;
        loadstatus.visible = false;
        console.log("\n==== 11 ==== on_load_ok");
    }

    function onLoad_fail()
    {
        loadstatus.visible = true;
        loadstatus.text = "加载失败，点击重试!";
        reloading.visible = true;
        loading_icon.visible = false;
        console.log("################### loadstatus.text", loadstatus.text);
    }

    function setLoadongIconStop()
    {
        loading_icon.visible = false;
    }

    Connections{
        target: globalObject;
        onSetLoadingWeatherStop:setLoadongIconStop();
    }

    Connections{
        target:assistant
        onSignal_updateEveryDayWeather:on_updateEveryDayWeather();
        onSignal_updateCurrentDayWeather:on_updateCurrentDayWeather();
    }

    signal weatherBackCliceked();
}
