import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.14
import QtQuick.XmlListModel 2.0
import "./basic" as Basic
import "./../js/zbase.js" as JsZBase
import "./../js/images.js" as JsPng

Item {
    id: root
    anchors.fill: parent

    Rectangle {
        id: rect
        visible: true
        anchors.fill: parent
        color: "black"
        border.color: "gray"
        clip: true



        Basic.Label {
            id: lblInfo
            visible: true
            horizontalAlignment: Text.AlignLeft
            text: "Company: xxxxxx\r\nOperator:xxx"
        }

        ColorMap {
            anchors.fill: parent
            visible: true
        }


//        property string mouseAction: ""             // box, drag
//        property point lastMousePos: []

//        function onMouseDown(item, mouse) {
//            if (mouseAction != "") {
//                return
//            }

//            if (mouse.button === Qt.LeftButton) {
//                mouseAction = "box"
//            }
//            else if (mouse.button === Qt.RightButton) {
//                mouseAction = "drag"
//            }

//            lastMousePos.x = mouse.x
//            lastMousePos.y = mouse.y
//        }

//        function getImgActualPos(img, x, y) {
//            if (img.width === img.sourceSize.width && img.height == img.sourceSize.height) {
//                return {x, y}
//            }

//            x *= img.sourceSize.width / img.width
//            y *= img.sourceSize.height / img.height

//            return {x, y}
//        }

//        function onMouseMove(obj, mouse, bMouseUp) {
//            if (mouseAction == "") {
//                return
//            }
            
//            if (mouseAction == "box") {
//                if (pImageProvider.getOperateMode() === "") {
//                    var box = JsZBase.getQmlChild(obj, "box")
//                    if (bMouseUp) {
//                        box.visible = false
//                        if (box.grayMin >= 0) {
//                            pImageProvider.setHistoRange(box.grayMin, box.grayMax)
//                        }
//                    }
//                    else {
//                        // frame
//                        box.x = Math.min(lastMousePos.x, mouse.x)
//                        box.y = Math.min(lastMousePos.y, mouse.y)
//                        box.width = Math.abs(mouse.x - lastMousePos.x)
//                        box.height = Math.abs(mouse.y - lastMousePos.y)

//                        // string
//                        var pt1 = getImgActualPos(obj, box.x, box.y)
//                        var pt2 = getImgActualPos(obj, box.x + box.width, box.y + box.height)
//                        var str = pImageProvider.getRegionMinMaxAveString( pt1.x, pt1.y, pt2.x, pt2.y)
//                        //console.debug(pt1.x, pt1.y, pt2.x, pt2.y, str)
//                        box.grayMin = -1
//                        if (str.length > 0) {
//                            var arr = str.split(",")
//                            box.grayMin = parseInt(arr[0])
//                            box.grayMax = parseInt(arr[1])
//                            box.grayAve = parseInt(arr[2])
//                            str = JsZBase.format("max: %s\r\nmin: %s\r\nave: %s",
//                                JsZBase.expandStrLeft(box.grayMax, 5),
//                                JsZBase.expandStrLeft(box.grayMin, 5),
//                                JsZBase.expandStrLeft(box.grayAve, 5))
//                        }
//                        var lbl = JsZBase.getQmlChild(box, "lblBox")
//                        lbl.text = str;

//                        box.visible = true
//                    }
//                }
//                else if (pImageProvider.getOperateMode() === "doubleWireMeasurement") {
//                    var box = JsZBase.getQmlChild(obj, "arrow")
//                    if (bMouseUp) {
//                        box.visible = false
//                    }
//                    else {
//                        // frame
//                        box.x = Math.min(lastMousePos.x, mouse.x)
//                        box.y = Math.min(lastMousePos.y, mouse.y)
//                        box.width = Math.abs(mouse.x - lastMousePos.x)
//                        box.height = Math.abs(mouse.y - lastMousePos.y)

//                        // string
//                        var offsetX = box.margin - box.x
//                        var offsetY = box.margin - box.y
//                        box.ptBegin.x = offsetX + lastMousePos.x
//                        box.ptBegin.y = offsetY + lastMousePos.y
//                        box.ptEnd.x = offsetX + mouse.x
//                        box.ptEnd.y = offsetY + mouse.y

//                        var angle = JsZBase.calcAngle_2Points(box.ptBegin, box.ptEnd)
//                        var rad = (angle + 90) / 180 * Math.PI
//                        var dx = box.margin * Math.cos(rad)
//                        var dy = box.margin * Math.sin(rad)
//                        box.ptTail1.x = offsetX + lastMousePos.x + dx
//                        box.ptTail1.y = offsetY + lastMousePos.y + dy
//                        box.ptTail2.x = offsetX + lastMousePos.x - dx
//                        box.ptTail2.y = offsetY + lastMousePos.y - dy

//                        rad = angle / 180 * Math.PI
//                        var x = mouse.x - box.margin * 3 * Math.cos(rad)
//                        var y = mouse.y - box.margin * 3 * Math.sin(rad)
//                        box.ptArrow1.x = offsetX + x + dx
//                        box.ptArrow1.y = offsetY + y + dy
//                        box.ptArrow2.x = offsetX + x - dx
//                        box.ptArrow2.y = offsetY + y - dy

//                        box.visible = true
//                    }
//                }
//            }
//            else if (mouseAction == "drag") {
//                obj.x += mouse.x - lastMousePos.x
//                obj.y += mouse.y - lastMousePos.y
//                JsZBase.autoAdjustView(obj)
//            }
//        }

//        function onMouseUp(obj, mouse) {
//            if (mouseAction == "") {
//                return
//            }

//            if (mouseAction == "box" && mouse.button === Qt.LeftButton) {
//                onMouseMove(obj, mouse, true)
//                mouseAction = ""
//            }
//            else if (mouseAction == "drag" && mouse.button === Qt.RightButton) {
//                onMouseMove(obj, mouse, true)
//                mouseAction = ""
//            }
//        }

//        function onMouseWheel(obj, wheel) {
//            if ( wheel.buttons !== 0 && mouseAction != "drag" ) {
//                return
//            }
            
//            var scaleRatio = 1.4142135623731
//            if (wheel.angleDelta.y > 0 && img.width < img.sourceSize.width * 8) {
//                var ratio = scaleRatio
//                obj.width *= ratio
//                obj.height *= ratio
//                obj.x += wheel.x * (1 - ratio)
//                obj.y += wheel.y * (1 - ratio)
//                JsZBase.autoAdjustView(obj)

//                if (mouseAction !== 0) {
//                    lastMousePos.x = wheel.x * ratio
//                    lastMousePos.y = wheel.y * ratio
//                }
//            }
//            else if (wheel.angleDelta.y < 0 && img.width > img.sourceSize.width * 0.125) {
//                var ratio = 1 / scaleRatio
//                obj.width *= ratio
//                obj.height *= ratio
//                obj.x += wheel.x * (1 - ratio)
//                obj.y += wheel.y * (1 - ratio)
//                JsZBase.autoAdjustView(obj)

//                if (mouseAction !== 0) {
//                    lastMousePos.x = wheel.x * ratio
//                    lastMousePos.y = wheel.y * ratio
//                }
//            }
//        }




    }

}
