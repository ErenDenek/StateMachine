import QtQuick 2.12
import QtQuick.Controls 2.12


ApplicationWindow {
    visible: true
    width: 1920
    height: 1280

    LineGuide
    {
        id:lineGuide
    }
    MenuBox
    {

    }
    ToolBox
    {
        visible:false
        id: toolbox
    }
    WorkSpace
    {

    }
}
