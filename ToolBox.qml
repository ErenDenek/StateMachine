import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    height: parent.height-100
    anchors.verticalCenter: parent.verticalCenter
    Rectangle {
        width: 40
        height: parent.height-100
        color: "#343058"
        radius:5

        Column {
            spacing: 10
            Button{

                id: stateBoxId;
                height: 40; width: 40
                flat:true
                Image {
                    source: "qrc:/assets/add_circle_black_24dp.svg"
                    width: 24
                    height: 24
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit

                }
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    drag.target: parent

                    onReleased: {
                        stateBoxProperties.newStateBox(stateBoxId.x, stateBoxId.y);
                        stateBoxId.x = 0; stateBoxId.y = 0;
                    }
                }
                background: Rectangle {
                    color: stateBoxId.hovered ? "#766898" : "transparent"
                    radius: 5
                }

            }
            Button {
                id:gridButton
                width: 40
                height: 40
                flat:true
                Image {
                    source: lineGuide.guideLinesVisible ? "qrc:/assets/grid_off_FILL0_wght400_GRAD0_opsz24.svg":"qrc:/assets/grid_on_FILL0_wght400_GRAD0_opsz24.svg"
                    width: 24
                    height: 24
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit

                }
                onClicked: {
                    if (lineGuide.guideLinesVisible) {
                        lineGuide.hideGuideLines();
                    } else {
                        lineGuide.showGuideLines();
                    }
                }
                background: Rectangle {
                    color: gridButton.hovered ? "#766898" : "transparent"
                    radius: 5
                }
            }
            anchors.verticalCenter: parent.verticalCenter  // Yatay ortalamak için
            anchors.horizontalCenter: parent.horizontalCenter // İsteğe bağlı olarak aşağı kaydırmak için
        }
    }
}
