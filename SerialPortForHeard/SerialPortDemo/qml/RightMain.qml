import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "./../js/images.js" as JsPng

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
           width: parent.width
           text: btnStation == false ? "打开串口":"关闭串口"
           property bool btnStation: false

           onClicked: {
               btnStation = !btnStation
               if( sp_obj.readIsMyPortOpen() ) {
                   emit: sendSettingInfoSignal(0)
                   timer.stop()
                   //customPlotTimer.stop()
               }
               else {
                   emit: sendSettingInfoSignal(1)
                   timer.start()
                   //customPlotTimer.start()
               }

           }
       }

       Basic.Button {
           id: repeateScanBtn
           width: parent.width
           text: "开始第1次探测"
           onClicked: {
               if (isStart) {
                   text = "结束第" + repeateScanLineNum + "次探测";
                   emit: sendrepeateScanLineNum( repeateScanLineNum - 1)
                   emit: sendSerPortStart( isStart )
               } else {
                   repeateScanLineNum += 1;
                   text = "开始第" + repeateScanLineNum + "次探测";
                   emit: sendSerPortStart( isStart)
               }
               isStart = !isStart;
           }

       }

       Basic.Button {
           id: dataSaveBtn
           width: parent.width
           text: "数据保存"
           onClicked: {

           }

       }

       Timer {
           id: timer
           interval: 50
           repeat: true
           onTriggered: {
               customColorMap.updatePlot( )

           }
       }
    }
 }



