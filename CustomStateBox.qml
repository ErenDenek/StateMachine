import QtQuick 2.0

Item{
    anchors.fill: parent

    Rectangle{
        id: stateBoxId;
        radius: 10
        border.width: 2
        height: 100; width: 200
        color: "transparent"
        border.color: "black"
        focus: false

        Keys.onPressed: {
            if (event.key === Qt.Key_Delete) {
                stateBoxConnLines.remove(index);
                stateBoxProperties.remove(index);

            }
        }

        Connections{
            target: stateBoxProperties
            onXChanged : stateBoxId.x = stateBoxProperties.getX(index);
            onYChanged : stateBoxId.y = stateBoxProperties.getY(index);
            onWidthChanged : stateBoxId.width = stateBoxProperties.getWidth(index);
            onHeigthChanged : stateBoxId.height = stateBoxProperties.getHeigth(index);
            onNameChanged : stateNameId.text = stateBoxProperties.getName(index);

        }

        StateBoxTerminals{
            id : stateBoxTerminalsId;
            z : -1
        }

        StateFuncs{
            id: stateFuncsId;
            z:1
        }

        Rectangle{
            anchors {
                horizontalCenter: stateBoxId.horizontalCenter
                top: stateBoxId.top
                topMargin: 20
            }
            height: 2; width: stateBoxId.width
            color: "black";
        }


        TextEdit{
            id: stateNameId
            anchors.horizontalCenter: parent.horizontalCenter
            text: "no name!"
            z: 100;

            Keys.onEnterPressed: stateBoxProperties.setName(index, text);
        }

        onXChanged: {
            stateBoxProperties.setX(index, x);
            stateBoxConnLines.lineReCalculation(index);
        }

        onYChanged: {
            stateBoxProperties.setY(index, y);
            stateBoxConnLines.lineReCalculation(index);
        }


        MouseArea {
            property bool resizing: false
            property bool clicked: false;

            anchors.fill: parent
            hoverEnabled: true
            drag.target: parent

            onClicked: {

                clicked = !clicked;

                if(clicked){
                    stateBoxId.focus = true;
                    stateNameId.z = -1;
                    stateFuncsId.z = -1;
                    stateBoxTerminalsId.z = 1;
                }else{
                    stateBoxId.focus = false;
                    stateNameId.z = 1;
                    stateFuncsId.z = 1;
                    stateBoxTerminalsId.z = -1;
                }
            }

            onPressed: {
                if ((mouse.x > stateBoxId.width - 10) && (mouse.y > stateBoxId.height - 10)) {
                    drag.target = null;
                    resizing = true
                }
            }
            onReleased: {
                if(resizing == true){
                    stateBoxProperties.setWidth(index, stateBoxId.width);
                    stateBoxProperties.setHeigth(index, stateBoxId.height);
                }

                //stateBoxConnection.nestedControl(index);//!todo buradaki fonksiyonları düzelt.
                drag.target = parent;
                resizing = false


            }

            //Küçültme büyütme işlemi
            property real mouseX;
            property real mouseY;
            onPositionChanged: {

                if((mouse.x > stateBoxId.width - 10) && (mouse.y > stateBoxId.height - 10))
                    cursorShape = Qt.SizeFDiagCursor
                else
                    cursorShape = Qt.ArrowCursor

                if (resizing) {
                    stateBoxId.width = Math.max(50,  stateBoxId.width + mouse.x - mouseX)
                    stateBoxId.height = Math.max(50, stateBoxId.height + mouse.y - mouseY)
                }
                mouseX= mouse.x
                mouseY = mouse.y
            }
        }
    }
}



