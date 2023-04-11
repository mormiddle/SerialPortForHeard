/****************************************************************************
** Meta object code from reading C++ file 'SwitchPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SerialPortDemo/cpp/common/SwitchPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SwitchPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SwitchPage_t {
    QByteArrayData data[14];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwitchPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwitchPage_t qt_meta_stringdata_SwitchPage = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SwitchPage"
QT_MOC_LITERAL(1, 11, 10), // "getPathQml"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "SWITCH_PAGE"
QT_MOC_LITERAL(4, 35, 1), // "e"
QT_MOC_LITERAL(5, 37, 10), // "PAGE_EMPTY"
QT_MOC_LITERAL(6, 48, 15), // "PAGE_ALERT_NULL"
QT_MOC_LITERAL(7, 64, 16), // "PAGE_ALERT_ERROR"
QT_MOC_LITERAL(8, 81, 9), // "PAGE_MAIN"
QT_MOC_LITERAL(9, 91, 14), // "PAGE_LEFT_MAIN"
QT_MOC_LITERAL(10, 106, 13), // "PAGE_TOP_MAIN"
QT_MOC_LITERAL(11, 120, 15), // "PAGE_RIGHT_MAIN"
QT_MOC_LITERAL(12, 136, 16), // "PAGE_MIDDLE_MAIN"
QT_MOC_LITERAL(13, 153, 16) // "PAGE_BOTTOM_MAIN"

    },
    "SwitchPage\0getPathQml\0\0SWITCH_PAGE\0e\0"
    "PAGE_EMPTY\0PAGE_ALERT_NULL\0PAGE_ALERT_ERROR\0"
    "PAGE_MAIN\0PAGE_LEFT_MAIN\0PAGE_TOP_MAIN\0"
    "PAGE_RIGHT_MAIN\0PAGE_MIDDLE_MAIN\0"
    "PAGE_BOTTOM_MAIN"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwitchPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       1,   22, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString, 0x80000000 | 3,    4,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    9,   27,

 // enum data: key, value
       5, uint(SwitchPage::PAGE_EMPTY),
       6, uint(SwitchPage::PAGE_ALERT_NULL),
       7, uint(SwitchPage::PAGE_ALERT_ERROR),
       8, uint(SwitchPage::PAGE_MAIN),
       9, uint(SwitchPage::PAGE_LEFT_MAIN),
      10, uint(SwitchPage::PAGE_TOP_MAIN),
      11, uint(SwitchPage::PAGE_RIGHT_MAIN),
      12, uint(SwitchPage::PAGE_MIDDLE_MAIN),
      13, uint(SwitchPage::PAGE_BOTTOM_MAIN),

       0        // eod
};

void SwitchPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SwitchPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->getPathQml((*reinterpret_cast< SWITCH_PAGE(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SwitchPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SwitchPage.data,
    qt_meta_data_SwitchPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SwitchPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwitchPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SwitchPage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SwitchPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
