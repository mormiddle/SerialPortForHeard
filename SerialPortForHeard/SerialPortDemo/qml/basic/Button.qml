import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Button{
    id: control;
    text: qsTr("Button")
    font.pixelSize: 12
//    implicitWidth: 150
//    implicitHeight: 30
    Layout.fillWidth: true
    Layout.fillHeight: true


    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#17a81a" : "#d8d8d8"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        anchors.fill: parent
        opacity: enabled ? 1 : 0.3
        color: "#3e3e3e"
        border.color: control.down ? "#17a81a" : "#8e9a97"
        border.width: 1
        radius: 2
    }
}
