/****************************************************************************
** Meta object code from reading C++ file 'MySerialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SerialPortDemo/cpp/common/MySerialport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MySerialport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MySerialPort_t {
    QByteArrayData data[22];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySerialPort_t qt_meta_stringdata_MySerialPort = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MySerialPort"
QT_MOC_LITERAL(1, 13, 14), // "portNameSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "portName"
QT_MOC_LITERAL(4, 38, 20), // "displayRecDataSignal"
QT_MOC_LITERAL(5, 59, 12), // "autorChanged"
QT_MOC_LITERAL(6, 72, 22), // "returnOpenResultSignal"
QT_MOC_LITERAL(7, 95, 7), // "setPort"
QT_MOC_LITERAL(8, 103, 8), // "initPort"
QT_MOC_LITERAL(9, 112, 8), // "openPort"
QT_MOC_LITERAL(10, 121, 5), // "value"
QT_MOC_LITERAL(11, 127, 13), // "readData_slot"
QT_MOC_LITERAL(12, 141, 16), // "readIsMyPortOpen"
QT_MOC_LITERAL(13, 158, 4), // "CRC8"
QT_MOC_LITERAL(14, 163, 6), // "buffer"
QT_MOC_LITERAL(15, 170, 5), // "start"
QT_MOC_LITERAL(16, 176, 6), // "length"
QT_MOC_LITERAL(17, 183, 9), // "toIntData"
QT_MOC_LITERAL(18, 193, 7), // "lowByte"
QT_MOC_LITERAL(19, 201, 8), // "highByte"
QT_MOC_LITERAL(20, 210, 14), // "setScanIsStart"
QT_MOC_LITERAL(21, 225, 21) // "setRepeateScanLineNum"

    },
    "MySerialPort\0portNameSignal\0\0portName\0"
    "displayRecDataSignal\0autorChanged\0"
    "returnOpenResultSignal\0setPort\0initPort\0"
    "openPort\0value\0readData_slot\0"
    "readIsMyPortOpen\0CRC8\0buffer\0start\0"
    "length\0toIntData\0lowByte\0highByte\0"
    "setScanIsStart\0setRepeateScanLineNum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySerialPort[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,
       6,    1,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    1,   91,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    3,   96,    2, 0x0a /* Public */,
      17,    2,  103,    2, 0x0a /* Public */,
      20,    1,  108,    2, 0x0a /* Public */,
      21,    1,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::UChar, QMetaType::QByteArray, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Int, QMetaType::UChar, QMetaType::UChar,   18,   19,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void MySerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MySerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portNameSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->displayRecDataSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->autorChanged(); break;
        case 3: _t->returnOpenResultSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setPort(); break;
        case 5: _t->initPort(); break;
        case 6: _t->openPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->readData_slot(); break;
        case 8: { bool _r = _t->readIsMyPortOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { quint8 _r = _t->CRC8((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< quint8*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->toIntData((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setScanIsStart((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setRepeateScanLineNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MySerialPort::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySerialPort::portNameSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MySerialPort::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySerialPort::displayRecDataSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MySerialPort::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySerialPort::autorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MySerialPort::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MySerialPort::returnOpenResultSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MySerialPort::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MySerialPort.data,
    qt_meta_data_MySerialPort,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MySerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MySerialPort.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MySerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MySerialPort::portNameSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MySerialPort::displayRecDataSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MySerialPort::autorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MySerialPort::returnOpenResultSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
