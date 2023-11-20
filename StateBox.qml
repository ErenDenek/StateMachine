import QtQuick 2.0

Item {
    Connections{
        target: stateBoxProperties
        onNumberChanged : stateBoxRepeaterId.model = stateBoxProperties.getNumber();
    }

    Repeater
    {
        id: stateBoxRepeaterId;

        CustomStateBox{
            id:customStateBoxId
        }
    }
}
