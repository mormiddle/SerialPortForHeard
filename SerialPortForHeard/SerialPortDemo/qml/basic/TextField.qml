import QtQuick 2.12
import QtQuick.Controls 2.12

TextField {
    id: control
    placeholderText: qsTr("Enter description")
    implicitWidth: 200
    implicitHeight: 25
    font.pixelSize: 12
    color: "#dcdcdc"

    background: Rectangle {
        anchors.fill: parent
        radius: 2
        color: control.enabled ? "#3e3e3e" : "#353637"
        border.color: control.enabled ? "#9c9c9c" : "transparent"
    }
}

