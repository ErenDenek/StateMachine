import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: parent.width
    Rectangle {
        width: parent.width
        height: 40
        //color: "#343058"
        gradient: Gradient {
            id: gradient
            GradientStop { position: 0.0; color: "#1e1a39" }
            GradientStop { position: 1.0; color: "#012d45" }
        }
        Row {
            spacing: 10
            Button {
                id:toolButton
                height: 40
                width: 40
                flat:true
                Image {
                    source: "qrc:/assets/menu_black_24dp.svg"
                    width: 24
                    height: 24
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit
                }

                // Butonun arkaplan rengi
                background: Rectangle {
                    color: toolButton.hovered ? "#8dbab5" : "transparent"
                    radius: 5
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: toolbox.visible = !toolbox.visible
                }

            }
            Button {
                id:fileButton
                width: 40
                height: 40
                flat:true
                Image {
                    source: "qrc:/assets/folder_open_black_24dp.svg"
                    width: 24
                    height: 24
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit

                }

                // Butonun arkaplan rengi
                background: Rectangle {
                    color: fileButton.hovered ? "#766898" : "transparent"
                    radius: 5
                }

                // Tıklama olayı
                //onClicked: fileMenu.open()

            }
            Button {
                id:saveFileButton
                width: 40
                height: 40
                flat:true
                Image {
                    source: "qrc:/assets/save_black_24dp.svg"
                    width: 24
                    height: 24
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit

                }

                // Butonun arkaplan rengi
                background: Rectangle {
                    color: saveFileButton.hovered ? "#766898" : "transparent"
                    radius: 5
                }

                // Tıklama olayı
               // onClicked: fileMenu.open()

            }

        }
    }
}
