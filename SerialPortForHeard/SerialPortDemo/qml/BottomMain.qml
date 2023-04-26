 import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "./../js/images.js" as JsPng

RowLayout {
    id: bottom_main
    anchors.fill: parent
    spacing: 2

    Rectangle {
        id: rect
        visible: true
        anchors.fill: parent
        color: "black"
        border.color: "gray"

        Basic.Label {
            text: qsTr(pAppInfo.title)
        }
    }
}
