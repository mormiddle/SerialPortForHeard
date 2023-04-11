import QtQuick 2.12
import QtQuick.Controls 2.2


ApplicationWindow {
    id: root
    visible: true
    width: 1366
    height: 892
    minimumWidth: 320
    minimumHeight: 240
    title: qsTr(pAppInfo.title)
    color: "black"

    onActiveChanged: {
        console.log("[trace]" + "active" + this.active)
    }

    onClosing: {
        console.log("[trace]")
    }

    MainPage {
        visible: true
        anchors.fill: parent
    }



}


