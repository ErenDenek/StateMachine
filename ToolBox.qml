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



    //    Image {
    //        id: switchImg
    //        width: 100; height: 100
    //        source: "qrc:/img/switch.png"
    //        x : 15; y : 0;

    //        onXChanged: {
    //            ghostSwitchImg.opacity = 1
    //        }

    //        MouseArea {
    //            anchors.fill: parent
    //            hoverEnabled: true
    //            drag.target: parent

    //            onReleased: {
    //                BoxGenerator.createNewBox(switchImg.x, switchImg.y)
    //                boxBinding.updateModel();

    //                switchImg.x = 15; switchImg.y = 0;
    //                ghostSwitchImg.opacity = 0
    //            }

    //            onEntered: switchOnGlow.visible = true;
    //            onExited:  switchOnGlow.visible = false;
    //        }
    //    }

    //    Image {
    //        id: ghostSwitchImg
    //        width: 100; height: 100
    //        source: "qrc:/img/switch.png"
    //        x: 15; y: 0
    //        opacity: 0
    //    }

    //    Glow {
    //        id: switchOnGlow
    //        anchors.fill: switchImg
    //        radius: 2
    //        samples: 3
    //        color: "cyan"
    //        source: switchImg
    //        visible: false
    //    }
}
