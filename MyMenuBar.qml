import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    Button {
        id: fileButton
        text: "File"
        height: 20; width: 75
        onClicked: menu.open()

        Menu {
            id: menu
            y: fileButton.height
            width: parent.width

            MenuItem {
                width: parent.width;
                text: "Open"
                onClicked: {
                    projeSettings.load();
                }
            }
            MenuItem {
                text: "Save"
                width: parent.width;
                onClicked: {
                    projeSettings.save();
                }
            }
        }
    }
}
