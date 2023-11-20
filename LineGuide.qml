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

    // Dikey kılavuz çizgileri
    Repeater {
        model: parent.width / gridSize  // 20 birim aralıklarla dikey çizgiler
        Rectangle {
            width: 1
            height: parent.height
            color: guideLinesVisible ? "lightgray" : "transparent"
            x: modelData * gridSize
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
        }
    }
}
