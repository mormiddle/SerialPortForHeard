import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import "./basic" as Basic
import "./../js/images.js" as JsPng

Item {
    id: root
    anchors.fill: parent

    function clearDisplayText(){
        displaText.clear()
    }
    function setDisplyText(data){
        displaText.insert(displaText.length,data)
    }
//        Layout.fillWidth: true
//        Layout.fillHeight: true
//        Layout.columnSpan:2
//        border.width: 1
//        border.color: "gray"
//        height: 4

        ScrollView {
            width: parent.width
            height: 300
            clip: true
            background: Rectangle {
                anchors.fill: parent
                border.color: "gray"
                radius: 5
            }

            TextArea {
                id: displaText
                wrapMode:TextArea.Wrap
                font.family: "Courier New"
                font.pointSize: 14

            }
        }




}
