import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "./basic" as Basic
import "../js/images.js" as JsPng
//import diye.xray.enumparamter 1.0

Page{
    id: root;
    signal signal_login_successed;
    signal signal_login_failed;

    Component.onCompleted: {
        txt_user_name.text = pUserLogin.user_name;
        txt_password.text = pUserLogin.password;
        chk_auto_login.checked = pUserLogin.auto_login;
    }
    Connections{
        target: pUserLogin;
        onSignal_login_result:{          
            switch(pUserLogin.login_result) {
            case TypeEnum.LOGIN_RESULT_SUCCESSED:
                root.signal_login_successed();
                break;
            default:
                lable_login_result.visible = true;
                root.signal_login_failed();
                break;
            }
        }
    }

    background: Basic.Rectangle {}

    GridLayout{
        id:grid;
        anchors.centerIn: parent
        rowSpacing: 16
        columns: 2

        Item { height: 8 }
        Basic.Label{
            text: root.title
            color: "black"
            Layout.alignment: Qt.AlignCenter
        }

        Basic.Image {
            source: JsPng.img_login_user;
        }
        Basic.TextField{
            id: txt_user_name
            placeholderText: qsTr("请输入用户名")
            onTextChanged: { pUserLogin.invoke_user_name(txt_user_name.text);}
        }


        Basic.Image {
            source: JsPng.img_login_password;
        }
        Basic.TextField {
            id: txt_password
            echoMode: TextField.Password
            placeholderText: qsTr("********")
            onTextChanged:{ pUserLogin.invoke_password(txt_password.text); }
        }

        Item { height: 8 }
        Basic.CheckBox {
            id: chk_auto_login
            text: qsTr("自动登陆")
            onCheckedChanged: {pUserLogin.invoke_auto_login(chk_auto_login.checked);}
        }

        Item { height: 8 }
        Basic.Button {
            height: 36
            text: qsTr("登陆")
            Layout.fillWidth: true
            onClicked: { pUserLogin.invoke_try_login();}
        }
    }

    Basic.Label {
        id: lable_login_result
        width: 200
        visible: false;
        font.pixelSize: 18
        anchors.top: grid.bottom
        anchors.topMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#ff0000"
        states: [
            State {
                when: TypeEnum.LOGIN_RESULT_NO_USER === pUserLogin.login_result
                PropertyChanges {
                    target: lable_login_result;
                    text: qsTr("用户名不能为空！");
                }
            },
            State {
                when: TypeEnum.LOGIN_RESULT_NO_PASSWORD === pUserLogin.login_result
                PropertyChanges {
                    target: lable_login_result;
                    text: qsTr("密码不能为空！");
                }
            },
            State {
                when: TypeEnum.LOGIN_RESULT_USER_OR_PASSWORD_ERROR === pUserLogin.login_result
                PropertyChanges {
                    target: lable_login_result;
                    text: qsTr("用户名或密码错误！");
                }
            },
            State {
                when: TypeEnum.LOGIN_RESULT_SUCCESSED === pUserLogin.login_result
                PropertyChanges {
                    target: lable_login_result;
                    text: qsTr("登录成功");
                }
            }
        ]
    }

}
