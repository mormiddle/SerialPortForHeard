import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id: control
    padding: 4

    property bool leftToRight: true
    default property alias children: rowLayout.children

    background: Rectangle {
        color: "black"
        border.color: "gray"
    }

    RowLayout {
        id: rowLayout
        anchors.left: parent.left
        //anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        layoutDirection: control.leftToRight ? Qt.LeftToRight : Qt.RightToLeft
        spacing: 4
    }
}
