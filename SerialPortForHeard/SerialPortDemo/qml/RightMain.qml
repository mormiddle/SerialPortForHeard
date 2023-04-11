import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "./../js/images.js" as JsPng

Item {
    id: root
    anchors.fill: parent

    signal sendSettingInfoSignal(int state)
    signal clearSignal()

    function setModel(s){
        myModel.append({s})
    }
    function getSetting(state){
        var value=portComBox.currentText+'/'
        return value
    }
    function setOpenBtnText(station){
        openBtn.btnStation=station
        console.log("get result:"+openBtn.btnStation)
    }

    Component.onCompleted: {
        sp_obj.returnOpenResultSignal.connect(setOpenBtnText)
        sp_obj.portNameSignal.connect(setPortName)
    }



    ColumnLayout {
        width: root.width



       Basic.ComboBox {
           id: portComBox
           model: ListModel {
               id: myModel
           }

           delegate: ItemDelegate {
               id: itmdlg
               height: 30
               width: parent.width
               text: modelData
               background: Rectangle {
                   id: backRect
                   anchors.fill: parent
                   color: itmdlg.hovered ? "#507BF6":"white"
               }
           }
       }


       Basic.Button {
           id: openBtn
           height: 30
           width: parent.width
           text: btnStation == false ? "打开串口":"关闭串口"
           property bool btnStation: false
           font.pointSize: 12
           font.family: "Helvetica"
           font.bold: true
           onClicked: {
               btnStation = !btnStation
               if( sp_obj.readIsMyPortOpen() ) {
                   emit: sendSettingInfoSignal(0)
               }
               else {
                   emit: sendSettingInfoSignal(1)
               }

           }
       }

       Basic.Button {
           id: cleanBtn
           height: 30
           width: parent.width
           text: "清除数据"
           font.pointSize: 12
           font.family: "Helvetica"
           font.bold: true
           onClicked: {
               clearSignal()
           }
       }




   }

}

