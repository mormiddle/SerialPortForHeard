import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import "./basic" as Basic
import "./../js/images.js" as JsPng

Item {
    id: root
    anchors.fill: parent

    Rectangle {
        id: rect
        visible: true
        anchors.fill: parent

        Basic.MenuRow {
            id: menu_top
            anchors.fill: parent

            Basic.MenuBlank {}
            Basic.MenuButton {
                id: btn_load
                source: JsPng.img_left_image_manager
                tooltip: qsTr("加载")
                onClicked: {
                    console.log("[trace] " + tooltip)
                    fileOpenDialog.open()
                }
            }
            Basic.MenuButton {
                source: JsPng.img_right_save
                tooltip: qsTr("保存")
                onClicked: {
                    console.log("[trace] " + tooltip)
                    pImageProvider.save()
                }
            }

            Basic.MenuBlank {}
            Basic.MenuButton {
                source: JsPng.img_right_reset
                tooltip: qsTr("重置")
                onClicked: {
                    console.log("[trace] " + tooltip)
                    pImageProvider.reset()
                }
            }
        }

        FileDialog {
            id: fileOpenDialog
            title: qsTr("Please choose an Dicom file")
            nameFilters: [
                "Dicom Files (*.dcm)",
                "*.*"
            ]
            onAccepted: {
                var file = String(fileUrl)

                // remove file:///
                if (file.indexOf("file:///") === 0)
                {
                    file = file.slice(8)
                }
                else if (file.indexOf("file://") === 0)
                {
                    file = file.slice(7)
                }

                pImageProvider.load(file)
            }
        }
    
    }
}
