import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import SerialPortDemo.SWitchpage 1.0
import MySerialPort 1.0
import CustomPlot 1.0
//import CustomPlot 1.0

Page{
    id: root

    function setPortName( str){
        right_main.setModel(str)
    }
    function sendSetting(state){
        var value=state+'/'+right_main.getSetting()
        sp_obj.openPort(value)
    }

    Component.onCompleted: {
        sp_obj.portNameSignal.connect(setPortName)
        sp_obj.initPort()
        right_main.sendSettingInfoSignal.connect(sendSetting)

    }

    SerialPort {
        id: sp_obj
    }
    Basic.Rectangle {
        id: rect_top
        radius: 0
        height: 60
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        color: "black"
        border.color: "gray"

        TopMain{
            id: top_main
            anchors.fill: parent
        }

    }

    Basic.Rectangle {
        id: rect_left
        width: 256 + 12
        radius: 0
        anchors.left: parent.left
        anchors.top: rect_top.bottom
        anchors.bottom: rect_bottom.top
        color: "black"
        border.color: "gray"


        LeftMain{
            id: left_main
            anchors.fill: parent
        }

    }

    Basic.Rectangle {
        id: rect_middle
        radius: 0
        anchors.left: rect_left.right
        anchors.top: rect_top.bottom
        anchors.right: rect_right.left
        anchors.bottom: rect_bottom.top
        color: "black"
        border.color: "gray"


        MiddleMain {
            id: middle_main
            anchors.fill: parent

            CustomColorMap {
                id: customColorMap
                anchors.fill: parent
                Component.onCompleted: customColorMap.initCustomPlot()
            }

        }

    }

    Basic.Rectangle {
        id: rect_right
        width: 200
        radius: 0
        anchors.top: rect_top.bottom
        anchors.right: parent.right
        anchors.bottom: rect_bottom.top
        color: "black"
        border.color: "gray"


        RightMain {
            id: right_main
            anchors.fill: parent

            onSenChooseAisleSignal: {
                customPlot.setAisleValue( choosedAisle )
            }
        }

    }

    Basic.Rectangle {
        id: rect_bottom
        width: parent.width
        height: 20
        radius:0
        anchors.bottom: parent.bottom
        color: "black"
        border.color: "gray"

        BottomMain {
            id: bottom_main
            anchors.fill: parent
        }
    }

}
