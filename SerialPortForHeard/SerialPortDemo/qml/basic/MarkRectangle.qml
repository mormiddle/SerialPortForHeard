import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle{  //矩形标注组件
    property int rulers_size: 10;
    property int fixed: 30;

    id:rectangle_mark;
    border.width: 1;
    border.color: "red";
    opacity: 0.1;

    Rectangle {     //左侧托把,托动改变方框大小
        id: rectangle_left;
        width: rulers_size;
        height: rulers_size;
        color: "red";
        anchors.horizontalCenter: parent.left;
        anchors.horizontalCenterOffset: -rulers_size/2;
        anchors.verticalCenter: parent.verticalCenter;
        MouseArea {
            anchors.fill: parent
            drag{ target: parent; axis: Drag.XAxis }
            onMouseXChanged: {
                if(drag.active){
                    rectangle_mark.width = rectangle_mark.width - mouseX
                    rectangle_mark.x = rectangle_mark.x + mouseX
                    if(rectangle_mark.width < fixed){
                        rectangle_mark.width = fixed;
                    }
                }
            }
        }
    }

    Rectangle {     //右侧托把,托动改变方框大小
        id: rectangle_right;
        width: rulers_size;
        height: rulers_size;
        color: "red";
        anchors.horizontalCenter: parent.right;
        anchors.horizontalCenterOffset: rulers_size/2;
        anchors.verticalCenter: parent.verticalCenter;

        MouseArea {
            anchors.fill: parent
            drag{ target: parent; axis: Drag.XAxis }
            onMouseXChanged: {
                if(drag.active){
                    rectangle_mark.width = rectangle_mark.width + mouseX
                    if(rectangle_mark.width < fixed){
                        rectangle_mark.width = fixed;
                    }
                }
            }
        }
    }

    Rectangle {     //顶部托把,托动改变方框大小
        id: rectangle_top;
        width: rulers_size;
        height: rulers_size;
        color: "red";
        x: parent.x / 2;
        y: 0;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.top;
        anchors.verticalCenterOffset: -rulers_size/2;

        MouseArea {
            anchors.fill: parent
            drag{ target: parent; axis: Drag.YAxis }
            onMouseYChanged: {
                if(drag.active){
                    rectangle_mark.height = rectangle_mark.height - mouseY
                    rectangle_mark.y = rectangle_mark.y + mouseY
                    if(rectangle_mark.height < fixed){
                        rectangle_mark.height = fixed;
                    }
                }
            }
        }
    }

    Rectangle {     //底部托把,托动改变方框大小
        id: rectangle_bottom;
        width: rulers_size;
        height: rulers_size;
        color: "red";
        x: parent.x / 2;
        y: parent.y;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.bottom;
        anchors.verticalCenterOffset: rulers_size/2;

        MouseArea {
            anchors.fill: parent
            drag{ target: parent; axis: Drag.YAxis }
            onMouseYChanged: {
                if(drag.active){
                    rectangle_mark.height = rectangle_mark.height + mouseY
                    if(rectangle_mark.height < fixed){
                        rectangle_mark.height = fixed;
                    }
                }
            }
        }
    }

    MouseArea {     // drag mouse area
        anchors.fill: parent;
        drag{       //托动平移方框
            target: parent;
            minimumX: 0;
            minimumY: 0;
            maximumX: parent.parent.width - parent.width;
            maximumY: parent.parent.height - parent.height;
            smoothed: true
        }
        onDoubleClicked: {
            parent.destroy();       //双击销毁方框 destroy component
        }
    }
}
