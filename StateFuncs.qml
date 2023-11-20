import QtQuick 2.0

Item {
    anchors.fill: parent
    anchors {
        horizontalCenter: parent.horizontalCenter
        left: parent.left
        topMargin: 22
    }

    Connections{
        target: stateBoxConnection
//        onParentNameChanged : parentNamedId.text = "Parent " + stateBoxConnection.getParentName(index);
//        onChildsNameChanged : childsNamedId.text = "Childs " + stateBoxConnection.getChildsNames(index);
    }

    Column{
        spacing: 1
        anchors.left: parent.left
        anchors.leftMargin: 3
        z:1
//        TextEdit{
//            id: entryFuncId
//            text: parent.x

//            //Keys.onEnterPressed: stateBoxProperties.setName(index, text);
//        }

//        TextEdit{
//            id: doFuncId
//            text: parent.y

//            //Keys.onEnterPressed: stateBoxProperties.setName(index, text);
//        }

//        TextEdit{
//            id: exitFuncId
//            text: "exit/"

//            //Keys.onEnterPressed: stateBoxProperties.setName(index, text);
//        }

//        Text{
//            id: parentNamedId;
//            text: stateBoxConnection.getParentName(index);

//        }

//        Text{
//            id: childsNamedId;
//            text: stateBoxConnection.getChildsNames(index);
//        }
    }
}
