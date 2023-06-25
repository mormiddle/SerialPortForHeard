import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../js/images.js" as JsPng

Button {
    property string source: JsPng.img_menu_placeholder
    property string tooltip: qsTr("This is a MenuButton")
    property bool fillWidth: false
    property color backgroundColor: "#3E3E3E"

    id: control

    background: Rectangle {
        implicitWidth: 48
        implicitHeight: 48
        opacity: enabled ? 1 : 0.3
//        color: control.checked ? "gray" : control.backgroundColor
        color: control.backgroundColor
        border.color: control.down ? "gray" : "#90A2A1"
        radius: 4
    }

    contentItem:Item {
        Image {
            anchors.centerIn: parent
            source: control.source
        }
    }

    Layout.fillWidth: control.fillWidth
    ToolTip.delay: 500
    ToolTip.timeout: 5000
    ToolTip.visible: hovered
    ToolTip.text: control.tooltip
}
