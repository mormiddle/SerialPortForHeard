import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../js/images.js" as JsPng

Button {
    id: control

    property url source: JsPng.img_menu_placeholder;
    property string tooltip: qsTr("This is a MenuBox")
    property bool fillWidth: false
    default property alias contentData: menu.contentData

    background: Rectangle {
        implicitWidth: 72
        implicitHeight: 48
        opacity: enabled ? 1 : 0.3
        color: "#3E3E3E"
        border.color: control.down ? "gray" : "#90A2A1"
        radius: 4
    }

    contentItem: Item {
        Image {
            anchors.verticalCenter: parent.verticalCenter
            source: control.source
        }
        Canvas {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 18
            implicitWidth: 1
            implicitHeight: parent.height - 2
            onPaint: {
                var ctx = getContext("2d")
                ctx.fillStyle = "#90A2A1"
                ctx.moveTo(0, 0)
                ctx.lineTo(width, 0)
                ctx.lineTo(width, height)
                ctx.lineTo(0, height)
                ctx.closePath()
                ctx.fill()
            }
        }
        Canvas {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            implicitWidth: 12
            implicitHeight: 12
            onPaint: {
                var ctx = getContext("2d")
                ctx.fillStyle = "#90A2A1"
                ctx.moveTo(0, 0)
                ctx.lineTo(width, 0)
                ctx.lineTo(width / 2, height)
                ctx.closePath()
                ctx.fill()
            }
        }
    }

    Layout.fillWidth: control.fillWidth
    ToolTip.delay: 1000
    ToolTip.timeout: 5000
    ToolTip.visible: hovered
    ToolTip.text: control.tooltip

    onClicked: menu.open()

    Menu {
        id: menu
        y: control.height + 1
        topPadding: 2
        bottomPadding: 2

        background: Rectangle {
            implicitWidth: 300
            implicitHeight: 60
            color: "#3E3E3E"
            border.color: "#90A2A1"
            radius: 4
        }
    }
}
