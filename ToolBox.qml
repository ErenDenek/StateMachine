import QtQuick 2.0
import QtGraphicalEffects 1.12

Item {
    property bool glowVisible: false
    anchors.fill: parent

    Rectangle{
        id: ghostStateBoxId;
        radius: 3
        border.width: 2
        height: 25; width: 50
        opacity: 0
        color: "transparent"
        border.color: "black"

        Rectangle{
            anchors {
                horizontalCenter: ghostStateBoxId.horizontalCenter
                top: ghostStateBoxId.top
                topMargin: 5
            }
            height: 2; width: ghostStateBoxId.width
            color: "black";
        }
    }

    Rectangle{
        id: stateBoxId;
        radius: 3
        border.width: 2
        height: 25; width: 50
        color: "transparent"
        border.color: "black"

        Rectangle{
            anchors {
                horizontalCenter: stateBoxId.horizontalCenter
                top: stateBoxId.top
                topMargin: 5
            }
            height: 2; width: stateBoxId.width
            color: "black";
        }

        onXChanged: ghostStateBoxId.opacity = 1;

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            drag.target: parent

            onReleased: {
                stateBoxProperties.newStateBox(stateBoxId.x, stateBoxId.y);

                stateBoxId.x = 0; stateBoxId.y = 0;
                ghostStateBoxId.opacity = 0
            }

            //            onEntered: switchOnGlow.visible = true;
            //            onExited:  switchOnGlow.visible = false;
        }


    }
}
