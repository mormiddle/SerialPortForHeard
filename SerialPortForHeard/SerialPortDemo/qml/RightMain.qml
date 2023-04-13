import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "./../js/images.js" as JsPng

Item {
    id: root
    anchors.fill: parent

    property var choosedAisle: 0
    signal sendSettingInfoSignal(int state)
    //signal clearSignal()
    signal senChooseAisleSignal( var value)

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
                   customPlotTimer.stop()
               }
               else {
                   emit: sendSettingInfoSignal(1)
                   customPlotTimer.start()
               }

           }
       }

       Basic.ComboBox {
           id: aisleComBox
           textRole: "text"
           model: ListModel {
               id: aisleModel
               ListElement { text: "通道1"; value: 0 }
               ListElement { text: "通道2"; value: 1 }
               ListElement { text: "通道3"; value: 2 }
               ListElement { text: "通道4"; value: 3 }
               ListElement { text: "通道5"; value: 4 }
               ListElement { text: "通道6"; value: 5 }
               ListElement { text: "通道7"; value: 6 }
               ListElement { text: "通道8"; value: 7 }
               ListElement { text: "通道9"; value: 8 }
               ListElement { text: "通道10"; value: 9 }
           }

           onActivated: {
               choosedAisle = aisleComBox.model.get(aisleComBox.currentIndex).value
               senChooseAisleSignal( choosedAisle )
               console.log("Selected value: " + choosedAisle)
               // emit signal or do something with selected value
               customPlot.clearPlot()
            }
       }

       Basic.Button {
           id: saveBtn
           height: 30
           width: parent.width
           text: "保存当前通道"
           font.pointSize: 12
           font.family: "Helvetica"
           font.bold: true
           onClicked: {
                customPlot.saveData()
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
               customPlot.clearData()
           }
       }

    }




    Timer {
        id: customPlotTimer
        interval: 50
        repeat: true
        onTriggered: {
            customPlot.upAisleData()
        }
    }

 }



