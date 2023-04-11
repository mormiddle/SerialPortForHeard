import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

TextField {
    id: control
    color: "#E1E1E1"
    placeholderText: qsTr("Enter description")

    property bool fillWidth: false

    background: Rectangle {
        implicitWidth: 240
        implicitHeight: 48
        color: control.enabled ? "#3E3E3E" : "transparent"
        border.color: control.enabled ? "#90A2A1" : "transparent"
        radius: 4
    }

    Layout.fillWidth: control.fillWidth
    ToolTip.delay: 1000
    ToolTip.timeout: 5000
    ToolTip.visible: hovered
    ToolTip.text: control.placeholderText
}
