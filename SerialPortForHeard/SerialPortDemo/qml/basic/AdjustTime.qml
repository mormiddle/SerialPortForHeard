import QtQuick 2.12
import QtQuick.Controls 2.12

Item{
    signal signal_button_click();
    property bool is_enabled: true;
    property int  button_font_pixel_size: 36;
    property int  text_filed_font_pixel_size: 72;
    property string button_text:"button";
    property int button_width:300;
    property int button_height:200;
    property int t_minute: text_minute.text;
    property int t_second: text_second.text;

    function js_is_digital(val){
        var reg = /^\d{1,2}$/;
        if(reg.test(val)){ return true;} else { return false;}
    }

    id:root;
    width: button_width;
    height: button_height;

    Rectangle{
        id:rectangle;
        anchors.fill: parent;

        Button{   // 值确认操作
            id:button;
            enabled: is_enabled;
            width: button_width * 0.30;
            height: button_height;
            anchors.top: parent.top;
            anchors.topMargin: 1;
            anchors.left: parent.left;
            anchors.leftMargin:1;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 1;
            font.pixelSize: button_font_pixel_size;
            text: qsTr(button_text);
            onClicked: {root.signal_button_click();}
        }
        //////////////////////////////////////////////////////

        TextField{    // 分钟值显示
            id:text_minute
            width: button_width* 0.30;
            height: button.height/2-1;
            font.pixelSize: text_filed_font_pixel_size;
            anchors.top: parent.top;
            anchors.topMargin: 1;
            anchors.left: button.right;
            anchors.leftMargin:1;
            text:t_minute.toString();
            onTextChanged: {
                var val = text_minute.text;
                if(js_is_digital(val)){
                    t_minute = parseInt(val);
                    if(59<t_minute){t_minute=59;}
                    else if (0>t_minute){t_minute=0;}
                }else{ text_minute.text=t_minute.toString(); }
            }
        }

        Button{   // 分钟值增操作
            id:button_minute_up;
            enabled: is_enabled;
            width: button_width * 0.10;
            height: text_minute.height/2-1;
            anchors.top: parent.top;
            anchors.topMargin: 1;
            anchors.left: text_minute.right
            anchors.leftMargin: 1;
            text: qsTr("+");
            font.pixelSize: button_font_pixel_size;
            onClicked:{
                if(59<=t_minute){t_minute=0;}
                else{t_minute=t_minute+1;}
                text_minute.text=t_minute.toString();
            }
        }

        Button{   // 分钟值减操作
            id:button_minute_down;
            enabled: is_enabled;
            width: button_minute_up.width;
            height: button_minute_up.height;
            anchors.top: button_minute_up.bottom;
            anchors.topMargin: 1;
            anchors.left: text_minute.right
            anchors.leftMargin: 1;
            text: qsTr("-");
            font.pixelSize: button_font_pixel_size;
            onClicked:{
                if(0>=t_minute){t_minute=59;}
                else{t_minute=t_minute-1;}
                text_minute.text=t_minute.toString();
            }
        }

        Label{    // 分单位
            id:lable_minute;
            anchors.top: parent.top;
            anchors.topMargin: 1;
            anchors.left: button_minute_down.right
            anchors.leftMargin: 1;
            width: button_width-button.width-text_minute.width-button_minute_down.width;
            height: text_minute.height;
            text: qsTr("分")
            font.pixelSize: text_filed_font_pixel_size;
        }

        //////////////////////////////////////////////////////
        TextField{    // 秒钟值显示
            id:text_second
            width: text_minute.width;
            height: button.height/2-1;
            font.pixelSize: text_filed_font_pixel_size;
            anchors.top: text_minute.bottom;
            anchors.topMargin: 1;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 1
            anchors.left: button.right;
            anchors.leftMargin:1;
            text: t_second;
            onTextChanged: {
                var val = text_second.text;
                if(js_is_digital(val)){
                    t_second = parseInt(val);
                    if(59<t_second){t_second=59;}
                    else if (0>t_second){t_second=0;}
                }else{ text_second.text=t_second.toString(); }
            }
        }

        Button{   // 秒钟值增操作
            id:button_second_up;
            enabled: is_enabled;
            width: button_width * 0.10;
            height: text_second.height/2-1;
            anchors.top: button_minute_down.bottom;
            anchors.topMargin: 1;
            anchors.left: text_second.right
            anchors.leftMargin: 1;
            text: qsTr("+");
            font.pixelSize: button_font_pixel_size;
            onClicked:{
                if(59<=t_second){t_second=0;}
                else{t_second=t_second+1;}
                text_second.text=t_second.toString();
            }

        }

        Button{         // 秒钟值减操作
            id:button_second_down;
            enabled: is_enabled;
            width: button_minute_up.width;
            height: button_second_up.height;
            anchors.top: button_second_up.bottom;
            anchors.topMargin: 1;
            anchors.left: text_second.right
            anchors.leftMargin: 1;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 1;
            text: qsTr("-");
            font.pixelSize: button_font_pixel_size;
            onClicked:{
                if(0>=t_second){t_second=59;}
                else{t_second=t_second-1;}
                text_second.text=t_second.toString();
            }
        }

        Label{    // 秒单位
            id:lable_second;
            anchors.top: lable_minute.bottom;
            anchors.topMargin: 1;
            anchors.left: button_second_down.right
            anchors.leftMargin: 1;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin:1;
            width: lable_minute.width;
            height: text_second.height;
            text: qsTr("秒");
            font.pixelSize: text_filed_font_pixel_size;
        }

    }

}
