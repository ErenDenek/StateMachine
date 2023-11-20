import QtQuick 2.12

Item {
    anchors.fill: parent;



    Item{
        anchors.fill: parent

        Repeater
        {
            id: line1RepId;
            Rectangle{
                id:line1
                x: stateBoxConnLines.getX(index, 0); y: stateBoxConnLines.getY(index, 0)
                width: stateBoxConnLines.getWidth(index, 0); height: stateBoxConnLines.getHeight(index, 0)
                color: "cyan"

                Keys.onPressed: {
                    if (event.key === Qt.Key_Delete) {
                        stateBoxConnLines.removeLines(index);
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    z: 1

                    onClicked: {
                        clickedLine(index);
                    }

                    onEntered: cursorShape = Qt.PointingHandCursor
                    onExited: cursorShape = Qt.ArrowCursor
                }
            }
        }
    }

    Item{
        anchors.fill: parent

        Repeater
        {
            id: line2RepId;

            Rectangle{
                id:line2
                x: stateBoxConnLines.getX(index, 1); y: stateBoxConnLines.getY(index, 1)
                width: stateBoxConnLines.getWidth(index, 1); height: stateBoxConnLines.getHeight(index, 1)
                color: "black"

                Keys.onPressed: {
                    if (event.key === Qt.Key_Delete) {
                        stateBoxConnLines.removeLines(index);
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    z: 1

                    onClicked: {
                        clickedLine(index);
                    }

                    onEntered: cursorShape = Qt.PointingHandCursor
                    onExited: cursorShape = Qt.ArrowCursor
                }
            }
        }
    }

    Item{
        anchors.fill: parent

        Repeater
        {
            id: line3RepId;

            Rectangle{
                id:line3
                x: stateBoxConnLines.getX(index, 2); y: stateBoxConnLines.getY(index, 2)
                width: stateBoxConnLines.getWidth(index, 2); height: stateBoxConnLines.getHeight(index, 2)
                color: "red"

                Keys.onPressed: {
                    if (event.key === Qt.Key_Delete) {
                        stateBoxConnLines.removeLines(index);
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    hoverEnabled: true
                    z: 1

                    onClicked: {
                        clickedLine(index);
                    }

                    onEntered: cursorShape = Qt.PointingHandCursor
                    onExited: cursorShape = Qt.ArrowCursor
                }
            }
        }
    }

    property bool clicked: false

    function clickedLine(index){
        clicked = !clicked;
        if(clicked){
            line1RepId.itemAt(index).color = "yellow"
            line2RepId.itemAt(index).color = "yellow"
            line3RepId.itemAt(index).color = "yellow"
            line1RepId.itemAt(index).focus = true;
            line2RepId.itemAt(index).focus = true;
            line3RepId.itemAt(index).focus = true;
        }else{
            line1RepId.itemAt(index).color = "cyan"
            line2RepId.itemAt(index).color = "black"
            line3RepId.itemAt(index).color = "red"
            line1RepId.itemAt(index).focus = false;
            line2RepId.itemAt(index).focus = false;
            line3RepId.itemAt(index).focus = false;
        }
    }

    Connections{
        target: stateBoxConnLines;
        onConnectionNumberChanged : {
            line1RepId.model = stateBoxConnLines.getConnectionNumber();
            line2RepId.model = stateBoxConnLines.getConnectionNumber();
            line3RepId.model = stateBoxConnLines.getConnectionNumber();
        }
        onLineUpdated :{

            //!Değişen çizgi grubunun indexi getChangedConnLineIndex()
            var connLineIndex = stateBoxConnLines.getChangedConnLineIndex();
            var line1Item = line1RepId.itemAt(connLineIndex);
            if (line1Item) {
                line1Item.x = stateBoxConnLines.getX(connLineIndex, 0);
                line1Item.y = stateBoxConnLines.getY(connLineIndex, 0);
                line1Item.width = stateBoxConnLines.getWidth(connLineIndex, 0);
                line1Item.height = stateBoxConnLines.getHeight(connLineIndex, 0);
            }
            var line2Item = line2RepId.itemAt(connLineIndex);
            if (line2Item) {
                line2Item.x = stateBoxConnLines.getX(connLineIndex, 1);
                line2Item.y = stateBoxConnLines.getY(connLineIndex, 1);
                line2Item.width = stateBoxConnLines.getWidth(connLineIndex, 1);
                line2Item.height = stateBoxConnLines.getHeight(connLineIndex, 1);
            }
            var line3Item = line3RepId.itemAt(connLineIndex);
            if (line3Item) {
                line3Item.x = stateBoxConnLines.getX(connLineIndex, 2);
                line3Item.y = stateBoxConnLines.getY(connLineIndex, 2);
                line3Item.width = stateBoxConnLines.getWidth(connLineIndex, 2);
                line3Item.height = stateBoxConnLines.getHeight(connLineIndex, 2);
            }
        }
    }
}
