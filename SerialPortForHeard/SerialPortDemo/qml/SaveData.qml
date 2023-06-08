import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "./../js/zbase.js" as JsZBase
import "./../js/images.js" as JsPng
import CustomPlot 1.0


ApplicationWindow {
    id: savedateWindo
    visible: true
    width: 640
    height: 480
    title: "硬点分布图"


    CustomColorMap {
        id: customColorMap
        anchors.fill: parent
        Component.onCompleted: {
            customColorMap.initSaveCustomPlot()
            customColorMap.updateSavePlot()
        }
    }
}
