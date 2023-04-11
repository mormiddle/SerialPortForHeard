import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ComboBox{
    property int combobox_implicit_width: 100

    id: combobox
    implicitWidth: combobox_implicit_width;
    Layout.fillWidth: true

}
