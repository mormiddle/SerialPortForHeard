import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import "./basic" as Basic
import "./../js/images.js" as JsPng
import DataManager 1.0

Item {
    id: root
    anchors.fill: parent

    property DataManager dataManager

    ListView {
        id: listView
        anchors.fill: parent
        model: dataManager.fileNames
        delegate: Item {
            width: parent.width
            height: 40

            Text {
                       id: fileNameText
                       text: modelData.fileName
                       anchors.centerIn: parent
                       font.pixelSize: 15
                       font.bold: true
                       color: "white"  // 设置文字颜色为白色
                   }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    dataManager.loadData(modelData.fileName)

                }
            }
        }
    }

}
