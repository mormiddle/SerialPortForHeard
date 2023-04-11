import QtQuick 2.12
import QtQuick.Controls 2.12

Slider {
    id: root

    value: 0.25

    background: Rectangle {
        x: root.leftPadding
        y: root.topPadding + root.availableHeight / 2 - height / 2
        implicitWidth: 100
        implicitHeight: 14
        width: root.availableWidth
        height: implicitHeight
        radius: height / 2
        color: "#3E3E3E"

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            color: "#BDBEBF"
            radius: 2
        }
    }

    handle: Rectangle {
        x: root.leftPadding + root.visualPosition * (root.availableWidth - width)
        y: root.topPadding + root.availableHeight / 2 - height / 2
        implicitWidth: root.background.implicitHeight * 2 / 3
        implicitHeight: root.implicitHeight * 2
        radius: implicitWidth / 2
        color: pressed ? "#3498DB" : "#EBEDEF"
        border.color: "#BDBEBF"
    }
}
