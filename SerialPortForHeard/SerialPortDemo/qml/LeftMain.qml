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
    property var saveDataWindow: null

    ListView {
        id: listView
        anchors.fill: parent
        model: dataManager.fileNames
        delegate: Item {
            width: parent.width
            height: 40

            Rectangle {
                        anchors.fill: parent
                        border.width: 3;
                        color: "#80808080" // black with 50% transparency
                    }

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
//                    dataManager.loadData(modelData.fileName)
//                    var component = Qt.createComponent("SaveData.qml");
//                        if (component.status === Component.Ready) {
//                            var newWindow = component.createObject(listView);
//                            newWindow.show();
//                        }
                    dataManager.loadData(modelData.fileName)
                    if (root.saveDataWindow === null) {
                        var component = Qt.createComponent("SaveData.qml");
                        if (component.status === Component.Ready) {
                            root.saveDataWindow = component.createObject(listView, {"rootObject": root});
                        }
                    }
                    root.saveDataWindow.show();

                }
            }
        }
    }

}
