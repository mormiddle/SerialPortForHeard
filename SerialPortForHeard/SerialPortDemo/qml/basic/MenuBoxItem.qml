import QtQuick 2.12
import QtQuick.Controls 2.12
import "../../js/images.js" as JsPng

MenuItem {
    id: control
    implicitWidth: 300
    implicitHeight: 60
    property url source:JsPng.img_menu_placeholder;

    indicator: Item {
        implicitWidth: 60
        implicitHeight: 60
        Rectangle {
            implicitWidth: 48
            implicitHeight: 48
            anchors.centerIn: parent
            opacity: enabled ? 1 : 0.3
            color: "#3E3E3E"
            border.color: "#90A2A1"
            radius: 4
            Image {
                anchors.centerIn: parent
                source: control.source
            }
        }
    }

    contentItem: Text {
        leftPadding: control.indicator.width
        rightPadding: control.arrow.width
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.highlighted ? "#ffffff" : "#B6B5B6"
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 300
        implicitHeight: 60
        opacity: enabled ? 1 : 0.3
        color: control.highlighted ? "#6E6E6E" : "transparent"
    }
}
