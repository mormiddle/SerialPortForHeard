#pragma once

#include <QObject>
#include "AppInfo.h"

class SwitchPage : public QObject
{
    Q_OBJECT
    Q_ENUMS( SWITCH_PAGE)

public:
    enum SWITCH_PAGE
    {
        PAGE_EMPTY,
        PAGE_ALERT_NULL,
        PAGE_ALERT_ERROR,
        PAGE_MAIN,
        PAGE_LEFT_MAIN,
        PAGE_TOP_MAIN,
        //PAGE_TOP_CONFIG,
        PAGE_RIGHT_MAIN,
        PAGE_MIDDLE_MAIN,
        PAGE_BOTTOM_MAIN,
    };

public:
    //获取qml文件路径
    Q_INVOKABLE static QString getPathQml( SWITCH_PAGE e)
    {
        QString path;
        switch ( e )
        {
        case PAGE_EMPTY:         path = "";                                   break;
        case PAGE_ALERT_NULL:    path = "qrc:/qml/alert/null.qml";            break;
        case PAGE_ALERT_ERROR:   path = "qrc:/qml/alert/error.qml";           break;
        case PAGE_MAIN:          path = "qrc:/qml/main.qml";                  break;
        case PAGE_LEFT_MAIN:     path = "qrc:/qml/LeftMain.qml";         break;
        case PAGE_TOP_MAIN:      path = "qrc:/qml/TopMain.qml";           break;
        case PAGE_RIGHT_MAIN:    path = "qrc:/qml/RightMain.qml";       break;
        case PAGE_MIDDLE_MAIN:   path = "qrc:/qml/MiddleMain.qml";     break;
        case PAGE_BOTTOM_MAIN:   path = "qrc:/qml/BottomMain.qml";     break;
        default:                 path = "qrc:/qml/alert/null.qml";            break;
        }

        return path;
    }
};

Q_DECLARE_METATYPE(SwitchPage::SWITCH_PAGE)
