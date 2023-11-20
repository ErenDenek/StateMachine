import QtQuick 2.0

Item {
    anchors.fill: parent
    property int circleR: 7
    property int stateBoxIndex : index;
    property int stateBoxX : parent.x
    property int stateBoxY : parent.y
    property bool marked : false

    function markedCircleShow(x, y)
    {
        marked = !marked;
        markedCircleId.x = x;
        markedCircleId.y = y;
        timer.running = marked;
    }

    Item{
        anchors.fill: parent

        Rectangle{
            anchors.fill: parent
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    allTerminalsId.visible = false;

                    if(marked == false){
                        allTerminalsId.visible = true;
                    }

                }
            }
        }
    }

    Item {
        id: activeTerminalId
        anchors.fill: parent
        Rectangle{
            id:markedCircleId
            width: circleR; height: circleR;
            radius: 15;
            color: "cyan";
        }

        Timer {
            id: timer
            interval: 333
            running: false
            repeat: true;
            onTriggered: {
                markedCircleId.visible = !markedCircleId.visible;
                console.log(markedCircleId.x);
                console.log(markedCircleId.y);
            }
        }
    }

    Item {
        id: allTerminalsId
        anchors.fill: parent
        visible: false;
        //Top Terminals
        Repeater{
            model : 3;

            Rectangle{
                width: circleR; height: circleR;
                radius: 15;
                x: (index * (parent.width / 4.1)) + (parent.width / 4.1)
                y: parent.y - 3;
                color: "cyan";
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        stateBoxConnLines.markTerminal(stateBoxIndex, index, 4);
                        allTerminalsId.visible = false;
                        markedCircleShow(parent.x, parent.y)
                    }
                }
            }
        }

        //Bottom Terminals
        Repeater{
            model : 3;

            Rectangle{
                width: circleR; height: circleR;
                radius: 15;
                x: (index * (parent.width / 4.1)) + (parent.width / 4.1)
                y: parent.height - 3
                color: "cyan";
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        stateBoxConnLines.markTerminal(stateBoxIndex, index, 3);
                        allTerminalsId.visible = false;
                        markedCircleShow(parent.x, parent.y)
                    }
                }
            }
        }

        //Right Terminals
        Repeater{
            model : 3;

            Rectangle{
                width: circleR; height: circleR;
                radius: 15;
                y: (index * (parent.height / 4.1)) + (parent.height / 4.1)
                x: parent.width - 3
                color: "cyan";
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        stateBoxConnLines.markTerminal(stateBoxIndex, index, 2);
                        allTerminalsId.visible = false;
                        markedCircleShow(parent.x, parent.y)
                    }
                }
            }
        }

        //Left Terminals
        Repeater{
            model : 3;

            Rectangle{
                width: circleR; height: circleR;
                radius: 15;
                y: (index * (parent.height / 4.1)) + (parent.height / 4.1)
                x : -2
                color: "cyan";
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        stateBoxConnLines.markTerminal(stateBoxIndex, index, 1);
                        allTerminalsId.visible = false;
                        markedCircleShow(parent.x, parent.y)
                    }
                }
            }
        }
    }




}
