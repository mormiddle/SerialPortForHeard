import QtQuick 2.12
import QtQuick.Controls 2.12

Item{
    signal signal_button_click();
    signal signal_up();
    signal signal_down();

    property bool is_enabled: true;
    property int  button_font_pixel_size: 36;
    property int  text_filed_font_pixel_size: 72;
    property string button_text:"button_text";
    property int button_width:300;
    property int button_height:200;
    property string text_field_value:text_field.text;

    id:root;
    width: button_width;
    height: button_height;

    MyRectangle{
        id:rectangle;
        anchors.fill: parent;

        MyButton{   /*值确认操作*/
            id:button;
            enabled: is_enabled;
            width: button_width * 0.45;
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

        MyTextField{    /*值显示*/
            id:text_field
            width: button.width;
            height: button.height;
            font.pixelSize: text_filed_font_pixel_size;
            anchors.top: parent.top;
            anchors.topMargin: 1;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 1
            anchors.left: button.right;
            anchors.leftMargin:1;
            text:text_field_value;
            enabled: false;
        }

        MyButton{   /*值增操作*/
            id:button_up;
            enabled: is_enabled;
            width: parent.width-button.width-text_field.width-2;
            height: button.height/2-2;
            anchors.top: parent.top;
            anchors.topMargin: 1;
            anchors.left: text_field.right
            anchors.leftMargin: 1;
            text: qsTr("+");
            font.pixelSize: button_font_pixel_size;
            onClicked: {root.signal_up();}
        }

        MyButton{   /*值减操作*/
            id:button_down;
            enabled: is_enabled;
            width: button_up.width;
            height: button_up.height;
            anchors.top: button_up.bottom;
            anchors.topMargin: 1;
            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 1
            anchors.left: text_field.right
            anchors.leftMargin: 1;
            text: qsTr("-");
            font.pixelSize: button_font_pixel_size;
            onClicked: {root.signal_down();}
        }
    }

}
