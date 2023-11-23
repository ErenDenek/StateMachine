import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow
    width: 1280
    height: 640
    visible: true
    title: qsTr("STMDS")

    Flickable {
        id:flck
        anchors.fill: parent
        contentWidth: Math.max(lineGuide.width * lineGuide.scale, mainWindow.width)
        contentHeight: Math.max(lineGuide.height * lineGuide.scale, mainWindow.height)
        clip: true
        transformOrigin: Item.Center
        property real zoom: 0.0
        property real zoomStep: 0.1
        scale: Math.min(mainWindow.width / width, mainWindow.height / height, 1) + zoom

        LineGuide
        {
            id:lineGuide
        }

        WorkSpace
        {
            id:workspace
        }

    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.NoButton
        onWheel: {

            if (wheel.angleDelta.y > 0 ){
                flck.zoom = Number((flck.zoom + flck.zoomStep).toFixed(1));
            }
            else{
                if (flck.zoom > 0) flck.zoom = Number((flck.zoom - flck.zoomStep).toFixed(1));
            }

            wheel.accepted=true
        }
    }

    MenuBox
    {

    }
    ToolBox
    {
        visible:false
        id: toolbox
    }

}
