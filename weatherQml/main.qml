import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    width: 1280
    height: 720
    visible: true


    Loader{
        id:splashpage;
        anchors.fill: parent;
        source: "../weatherQml/splashscreen.qml";
        visible:true;
        onLoaded: {
            item.sigsplashtimeout.connect(onsplashtimeout);
        }
    }

    Loader{
        id:weathermainapge;
        anchors.fill: parent;
        source: "../weatherQml/weather_main_dialog.qml";
        visible:false;
        onLoaded: {
            item.weatherBackCliceked.connect(weatherBackClicekedSignal);
        }
    }

    function onsplashtimeout()
    {
        weathermainapge.visible = true;
        globalObject.onWeatherInit();
    }

    function on_load_ok()
    {
        weathermainapge.visible = true;
        weathermainapge.item.onLoad_ok();
    }

    function on_load_fail()
    {
        weathermainapge.item.onLoad_fail();
    }

    Connections{
        target:assistant
        onSignal_load_ok:on_load_ok();
        onSignal_load_fail:on_load_fail();
    }

    signal weatherBackClicekedSignal();
}

