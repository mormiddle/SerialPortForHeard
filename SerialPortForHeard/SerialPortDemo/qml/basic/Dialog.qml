import QtQuick 2.12
import QtQuick.Controls 2.12

Dialog {
    id: root
    title: qsTr("Dialog")
    implicitWidth: 400
    implicitHeight: 400
    parent: Overlay.overlay
    x: Math.round((parent.width - width) / 2)
    y: Math.round((parent.height - height) / 2)

    background: Rectangle {
        anchors.fill: parent
        radius: 3
        color: "#101010"
        border.color: "#3e3e3e"
    }

    header: Item {
        width: parent.width
        height: 34
        Rectangle {
            anchors.fill: parent
            anchors.margins: 5
            radius: 1
            color: "#3e3e3e"

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                font.pixelSize: 12
                color: "#f0f0f0"
                text: root.title
            }

            MouseArea {
                anchors.fill: parent
                property point clickPos: "0,0"
                onPressed: {
                    clickPos  = Qt.point(mouse.x, mouse.y)
                }
                onPositionChanged: {
                    var delta = Qt.point(mouse.x - clickPos.x, mouse.y - clickPos.y)
                    root.x = (root.x + delta.x)
                    root.y = (root.y + delta.y)
                }
            }

            MouseArea {
                anchors.right: parent.right
                width: parent.height
                height: parent.height
                onClicked: root.close()
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 12
                    color: "#f0f0f0"
                    text: qsTr("X")
                }
            }
        }
    }
}
