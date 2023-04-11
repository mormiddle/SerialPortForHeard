import QtQuick 2.12
import QtQuick.Controls 2.12

CheckBox{
    id: control
    text: qsTr("")
    checked: false

    indicator: Rectangle {
        implicitWidth: 22
        implicitHeight: 22
        x: control.leftPadding
        y: parent.height / 2 - height / 2
        radius: 1
        color: "#3e3e3e"
        border.color: control.down ? "#17a81a" : "#515352"

        Rectangle {
            width: 10
            height: 10
            x: 6
            y: 6
            radius: 1
            color: control.down ? "#17a81a" : "#67ba2a"
            visible: control.checked
        }
    }

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#17a81a" : "#cdcdcd"
        verticalAlignment: Text.AlignVCenter
        leftPadding: control.indicator.width + control.spacing
    }

}
