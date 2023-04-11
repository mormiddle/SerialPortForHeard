import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "../../js/images.js" as JsPng

Button{
    property url source: JsPng.img_menu_placeholder
    property string tooltip: qsTr("This is a StatusIcon")
    property bool fillWidth: false
    id: control;

    background: Item {
        implicitWidth: 32
        implicitHeight: 32
    }

    contentItem: Item {
        Image {
            sourceSize.width: 24
            sourceSize.height: 24
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
