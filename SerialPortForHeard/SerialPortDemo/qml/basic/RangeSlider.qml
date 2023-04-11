import QtQuick 2.12
import QtQuick.Controls 2.12

RangeSlider {
    id: control
    first.value: 0.25
    second.value: 0.75

    background: Rectangle {
        x: control.leftPadding
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 200
        implicitHeight: 4
        width: control.availableWidth
        height: implicitHeight
        radius: 2
        color: "#3E3E3E"

        Rectangle {
            x: control.first.visualPosition * parent.width
            width: control.second.visualPosition * parent.width - x
            height: parent.height
            color: "#BDBEBF"
            radius: 2
        }
    }

    first.handle: Rectangle {
        x: control.leftPadding + first.visualPosition * (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 8
        implicitHeight: 16
        radius: 2
        color: first.pressed ? "#3E3E3E" : "#3E3E3E"
        border.color: "#BDBEBF"
    }

    second.handle: Rectangle {
        x: control.leftPadding + second.visualPosition * (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 8
        implicitHeight: 16
        radius: 2
        color: second.pressed ?"#3E3E3E" : "#3E3E3E"
        border.color: "#BDBEBF"
    }
}
