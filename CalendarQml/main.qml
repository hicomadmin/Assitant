import QtQuick 2.0
import QtQuick.Window 2.0

Item {
    width: 1280
    height: 720
    visible: true

    Loader{
        id:calendarloadapge;
        anchors.fill: parent;
        source: "../CalendarQml/Calendar_month.qml";
        visible:true;

        onLoaded: {
            item.backClicked.connect(calendarBackClicked);
        }
    }

    function onClendarUpdateEvent()
    {
        calendarloadapge.item.calendar_on_updateEvent();
    }

    function onCalendarUpdateDateInfo()
    {
        calendarloadapge.item.calendar_on_updateDateInfo();
    }

    signal calendarBackClicked();
}
