import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    width: parent.width
    height: parent.height

    property int gridSize: 20  // Grid arası mesafe
    property bool guideLinesVisible: true

    function showGuideLines()
    {
        guideLinesVisible = true;
    }

    function hideGuideLines()
    {
        guideLinesVisible = false;
    }

    Rectangle{
        height: parent.height
        width: parent.width
        color:"#1B1B1B"
    // Dikey kılavuz çizgileri
    Repeater {
        model: parent.width / gridSize  // 20 birim aralıklarla dikey çizgiler
        Rectangle {
            width: 1
            height: parent.height
            color: guideLinesVisible ? "lightgray" : "transparent"
            x: modelData * gridSize
            opacity: 0.2
        }
    }
    // Yatay kılavuz çizgileri
    Repeater {
        model: parent.height / gridSize  // 20 birim aralıklarla yatay çizgiler
        Rectangle {
            width: parent.width
            height: 1
            color: guideLinesVisible ? "lightgray" : "transparent"
            y: modelData * gridSize
            opacity:0.2
        }
    }
    }
}
