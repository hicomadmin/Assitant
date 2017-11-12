import QtQuick 2.0

Item {
    id: root
    clip: true

    width: Math.min(contentItem.width, maxWidth)
    height: contentItem.height

    property real maxWidth: 0
    property bool interactive: true
    default property Item contentItem
    property alias interval: marqueeAnim.interval

    onContentItemChanged: {
        contentItem.parent = internel;
    }

    Text {
        text: contentItem.width
    }

    function stopAnimation()
    {
        marqueeAnim.stop();
    }

    function startAnimation()
    {
        marqueeAnim.start();
    }

    children:  Item {
        id: internel
        width: contentItem.width
        height: contentItem.height
        states: [State {
            when: root.width < internel.width && interactive
            StateChangeScript { script: marqueeAnim.restart() }
        },State {
                when: root.width >= internel.width || !interactive
                StateChangeScript {
                    script: {
                        marqueeAnim.stop()
                    }
                }
            }]
        Timer {
            id: marqueeAnim
            interval: 10
            repeat: true
            onTriggered: {
                if(internel.x < -internel.width)
                    internel.x = root.width
                internel.x--
            }
            onRunningChanged: {
                if(!running)
                    internel.x = 0
            }
        }
    }
}

