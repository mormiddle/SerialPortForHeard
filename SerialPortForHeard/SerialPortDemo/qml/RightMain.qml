import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "./../js/images.js" as JsPng
import DataManager 1.0

Item {
    id: root
    anchors.fill: parent

    property int repeateScanLineNum: 1
    property bool isStart: true
    signal sendSettingInfoSignal(int state)
    signal sendrepeateScanLineNum( int value)
    signal sendSerPortStart( bool value)

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

    property DataManager dataManager

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


//       Basic.Button {
//           id: openBtn
//           width: parent.width
//           text: btnStation == false ? "打开串口":"关闭串口"
//           property bool btnStation: false

//           onClicked: {
//               btnStation = !btnStation
//               if( sp_obj.readIsMyPortOpen() ) {
//                   emit: sendSettingInfoSignal(0)
//                   timer.stop()
//                   //customPlotTimer.stop()
//               }
//               else {
//                   emit: sendSettingInfoSignal(1)
//                   timer.start()
//                   //customPlotTimer.start()
//               }

//           }
//       }

       Basic.Button {
           id: repeateScanBtn
           width: parent.width
           text: "开始第1次探测"
           onClicked: {
               if (isStart) {
                   text = "结束第" + repeateScanLineNum + "次探测";
                   emit: sendrepeateScanLineNum( repeateScanLineNum - 1)
                   emit: sendSerPortStart( isStart )
                   emit: sendSettingInfoSignal(1)
                   timer.start()
               } else {
                   repeateScanLineNum += 1;
                   text = "开始第" + repeateScanLineNum + "次探测";
                   emit: sendSerPortStart( isStart)
                   emit: sendSettingInfoSignal(0)
                   dataManager.saveClos()
                   timer.stop()
               }
               isStart = !isStart;
           }

       }

       Basic.Button {
           id: dataSaveBtn
           width: parent.width
           text: "数据保存"
           onClicked: {
                dataManager.saveData()
                dataManager.saveDataToFile()
           }

       }

       Basic.Button {
           id: showDataWindowButton
           width: parent.width
           text: "硬点分布图显示"
           onClicked: {
               var component = Qt.createComponent("SaveData.qml");
                   if (component.status === Component.Ready) {
                       var newWindow = component.createObject(showDataWindowButton);
                       newWindow.show();
                   }
           }
       }

       Basic.Button {
           id: clearPlotButton
           width: parent.width
           text: "清除表格"
           onClicked: {
                customColorMap.clearPlot()
                repeateScanBtn.text = "开始第1次探测"
               emit: sendSerPortStart( isStart)
               emit: sendSettingInfoSignal(0)
               repeateScanLineNum = 1
               isStart = true
               timer.stop()
           }
       }

       Timer {
           id: timer
           interval: 20
           repeat: true
           onTriggered: {
               customColorMap.updatePlot( )

           }
       }
    }
 }



