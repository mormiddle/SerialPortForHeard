import QtQuick 2.12
import QtQuick.Controls 2.12

BusyIndicator {
    id: control

    contentItem: Rectangle {
        implicitWidth: 180
        implicitHeight: 16
        radius: 8
        border.width: 1
        border.color: "lightgray"
        color: "#0E0E0E"
        Rectangle {
            y: 2
            width: 12
            height: 12
            radius: 6
            color: "lightgray"
            XAnimator on x {
                loops: Animation.Infinite
                from: 2
                to: 180 - 14
                running: control.visible && control.running
                duration: 2000
            }
        }
    }
}
