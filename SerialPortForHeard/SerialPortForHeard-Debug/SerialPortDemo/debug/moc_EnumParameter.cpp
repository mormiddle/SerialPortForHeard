/****************************************************************************
** Meta object code from reading C++ file 'EnumParameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SerialPortDemo/cpp/common/EnumParameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EnumParameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnumParameter_t {
    QByteArrayData data[97];
    char stringdata0[1903];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnumParameter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnumParameter_t qt_meta_stringdata_EnumParameter = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EnumParameter"
QT_MOC_LITERAL(1, 14, 6), // "ICM_KV"
QT_MOC_LITERAL(2, 21, 11), // "KV_NO_ERROR"
QT_MOC_LITERAL(3, 33, 25), // "KV_NO_GENERATOR_CONNECTED"
QT_MOC_LITERAL(4, 59, 32), // "KV_GENERATOR_RENTAL_DATA_IS_OVER"
QT_MOC_LITERAL(5, 92, 37), // "KV_REQUESTED_KV_VALUE_IS_BELO..."
QT_MOC_LITERAL(6, 130, 37), // "KV_REQUESTED_KV_VALUE_IS_ABOV..."
QT_MOC_LITERAL(7, 168, 31), // "KV_OK_BUT_MA_HAS_TO_BE_ADJUSTED"
QT_MOC_LITERAL(8, 200, 48), // "KV_PREHEAD_IS_REQUIRED_TO_SHO..."
QT_MOC_LITERAL(9, 249, 6), // "ICM_MA"
QT_MOC_LITERAL(10, 256, 11), // "MA_NO_ERROR"
QT_MOC_LITERAL(11, 268, 25), // "MA_NO_GENERATOR_CONNECTED"
QT_MOC_LITERAL(12, 294, 32), // "MA_GENERATOR_RENTAL_DATA_IS_OVER"
QT_MOC_LITERAL(13, 327, 37), // "MA_REQUESTED_MA_VALUE_IS_BELO..."
QT_MOC_LITERAL(14, 365, 37), // "MA_REQUESTED_MA_VALUE_IS_ABOV..."
QT_MOC_LITERAL(15, 403, 40), // "MA_PREHEAT_REQUIRED_MA_SET_AU..."
QT_MOC_LITERAL(16, 444, 6), // "ICM_TP"
QT_MOC_LITERAL(17, 451, 11), // "TP_NO_ERROR"
QT_MOC_LITERAL(18, 463, 25), // "TP_NO_GENERATOR_CONNECTED"
QT_MOC_LITERAL(19, 489, 32), // "TP_GENERATOR_RENTAL_DATA_IS_OVER"
QT_MOC_LITERAL(20, 522, 22), // "TP_SHOT_IS_IN_PROGRESS"
QT_MOC_LITERAL(21, 545, 40), // "TP_REQUESTED_VALUE_IS_BELOW_M..."
QT_MOC_LITERAL(22, 586, 40), // "TP_REQUESTED_VALUE_IS_ABOVE_M..."
QT_MOC_LITERAL(23, 627, 50), // "TP_REQUEST_TP_IS_BIGGER_THAN_..."
QT_MOC_LITERAL(24, 678, 46), // "TP_PREHEAT_IS_REQUIRED_TP_IS_..."
QT_MOC_LITERAL(25, 725, 6), // "ICM_TS"
QT_MOC_LITERAL(26, 732, 24), // "TS_NONE_NO_SHOT_ACTUALLY"
QT_MOC_LITERAL(27, 757, 13), // "TS_PREHEATING"
QT_MOC_LITERAL(28, 771, 14), // "TS_NORMAL_SHOT"
QT_MOC_LITERAL(29, 786, 9), // "TS_CYCLES"
QT_MOC_LITERAL(30, 796, 15), // "TS_CONDITIONING"
QT_MOC_LITERAL(31, 812, 6), // "ICM_ST"
QT_MOC_LITERAL(32, 819, 13), // "ST_CONNECTING"
QT_MOC_LITERAL(33, 833, 15), // "ST_NO_GENERATOR"
QT_MOC_LITERAL(34, 849, 17), // "ST_READY_TO_START"
QT_MOC_LITERAL(35, 867, 14), // "ST_ERROR_STATE"
QT_MOC_LITERAL(36, 882, 22), // "ST_PREHEATING_REQUIRED"
QT_MOC_LITERAL(37, 905, 26), // "ST_RESERVED_FOR_FUTURE_USE"
QT_MOC_LITERAL(38, 932, 25), // "ST_PREWARNING_IN_PROGRESS"
QT_MOC_LITERAL(39, 958, 19), // "ST_RAMP_IN_PROGRESS"
QT_MOC_LITERAL(40, 978, 19), // "ST_SHOT_IN_PROGRESS"
QT_MOC_LITERAL(41, 998, 14), // "ST_END_OF_SHOT"
QT_MOC_LITERAL(42, 1013, 19), // "ST_WAIT_IN_PROGRESS"
QT_MOC_LITERAL(43, 1033, 15), // "ST_SHOT_RESTART"
QT_MOC_LITERAL(44, 1049, 17), // "ST_PROMPT_MESSAGE"
QT_MOC_LITERAL(45, 1067, 7), // "ICM_CMD"
QT_MOC_LITERAL(46, 1075, 8), // "CMD_NULL"
QT_MOC_LITERAL(47, 1084, 6), // "CMD_SE"
QT_MOC_LITERAL(48, 1091, 6), // "CMD_KV"
QT_MOC_LITERAL(49, 1098, 6), // "CMD_MA"
QT_MOC_LITERAL(50, 1105, 6), // "CMD_TP"
QT_MOC_LITERAL(51, 1112, 6), // "CMD_ON"
QT_MOC_LITERAL(52, 1119, 6), // "CMD_OF"
QT_MOC_LITERAL(53, 1126, 6), // "CMD_XO"
QT_MOC_LITERAL(54, 1133, 6), // "CMD_TS"
QT_MOC_LITERAL(55, 1140, 6), // "CMD_SN"
QT_MOC_LITERAL(56, 1147, 6), // "CMD_MD"
QT_MOC_LITERAL(57, 1154, 6), // "CMD_ST"
QT_MOC_LITERAL(58, 1161, 6), // "CMD_RC"
QT_MOC_LITERAL(59, 1168, 8), // "ICM_TYPE"
QT_MOC_LITERAL(60, 1177, 13), // "ICM_TYPE_NULL"
QT_MOC_LITERAL(61, 1191, 15), // "ICM_TYPE_CP120B"
QT_MOC_LITERAL(62, 1207, 15), // "ICM_TYPE_CP160B"
QT_MOC_LITERAL(63, 1223, 15), // "ICM_TYPE_CP160D"
QT_MOC_LITERAL(64, 1239, 15), // "ICM_TYPE_CP200D"
QT_MOC_LITERAL(65, 1255, 16), // "ICM_TYPE_CP200DS"
QT_MOC_LITERAL(66, 1272, 15), // "ICM_TYPE_CP225D"
QT_MOC_LITERAL(67, 1288, 15), // "ICM_TYPE_CP300C"
QT_MOC_LITERAL(68, 1304, 12), // "LOGIN_RESULT"
QT_MOC_LITERAL(69, 1317, 17), // "LOGIN_RESULT_NULL"
QT_MOC_LITERAL(70, 1335, 20), // "LOGIN_RESULT_NO_USER"
QT_MOC_LITERAL(71, 1356, 24), // "LOGIN_RESULT_NO_PASSWORD"
QT_MOC_LITERAL(72, 1381, 35), // "LOGIN_RESULT_USER_OR_PASSWORD..."
QT_MOC_LITERAL(73, 1417, 22), // "LOGIN_RESULT_SUCCESSED"
QT_MOC_LITERAL(74, 1440, 18), // "XRAY_DETECTOR_TYPE"
QT_MOC_LITERAL(75, 1459, 25), // "XRAY_DETECTOR_TYPE_STATIC"
QT_MOC_LITERAL(76, 1485, 26), // "XRAY_DETECTOR_TYPE_DYNAMIC"
QT_MOC_LITERAL(77, 1512, 23), // "XRAY_DETECTOR_TYPE_NULL"
QT_MOC_LITERAL(78, 1536, 15), // "XRAY_CHECK_TYPE"
QT_MOC_LITERAL(79, 1552, 20), // "XRAY_CHECK_TYPE_NULL"
QT_MOC_LITERAL(80, 1573, 18), // "XRAY_CHECK_TYPE_DR"
QT_MOC_LITERAL(81, 1592, 18), // "XRAY_CHECK_TYPE_CR"
QT_MOC_LITERAL(82, 1611, 9), // "MARK_TYPE"
QT_MOC_LITERAL(83, 1621, 14), // "MARK_TYPE_NULL"
QT_MOC_LITERAL(84, 1636, 25), // "MARK_TYPE_AUTO_CACULATION"
QT_MOC_LITERAL(85, 1662, 14), // "MARK_TYPE_WORD"
QT_MOC_LITERAL(86, 1677, 17), // "MARK_TYPE_ELLIPSE"
QT_MOC_LITERAL(87, 1695, 17), // "MARK_TYPE_POLYGON"
QT_MOC_LITERAL(88, 1713, 19), // "MARK_TYPE_RECTANGLE"
QT_MOC_LITERAL(89, 1733, 15), // "MARK_TYPE_ARROW"
QT_MOC_LITERAL(90, 1749, 15), // "MARK_TYPE_ANGLE"
QT_MOC_LITERAL(91, 1765, 23), // "MARK_TYPE_STRAIGHT_LINE"
QT_MOC_LITERAL(92, 1789, 13), // "DICOM_VR_TYPE"
QT_MOC_LITERAL(93, 1803, 12), // "VR_TYPE_NULL"
QT_MOC_LITERAL(94, 1816, 28), // "VR_TYPE_EXPLICIT_TABLE_7_1_1"
QT_MOC_LITERAL(95, 1845, 28), // "VR_TYPE_EXPLICIT_TABLE_7_1_2"
QT_MOC_LITERAL(96, 1874, 28) // "VR_TYPE_IMPLICIT_TABLE_7_1_3"

    },
    "EnumParameter\0ICM_KV\0KV_NO_ERROR\0"
    "KV_NO_GENERATOR_CONNECTED\0"
    "KV_GENERATOR_RENTAL_DATA_IS_OVER\0"
    "KV_REQUESTED_KV_VALUE_IS_BELOW_MIN_KV\0"
    "KV_REQUESTED_KV_VALUE_IS_ABOVE_MIN_KV\0"
    "KV_OK_BUT_MA_HAS_TO_BE_ADJUSTED\0"
    "KV_PREHEAD_IS_REQUIRED_TO_SHOOT_AT_THIS_KV_VALUE\0"
    "ICM_MA\0MA_NO_ERROR\0MA_NO_GENERATOR_CONNECTED\0"
    "MA_GENERATOR_RENTAL_DATA_IS_OVER\0"
    "MA_REQUESTED_MA_VALUE_IS_BELOW_MIN_MA\0"
    "MA_REQUESTED_MA_VALUE_IS_ABOVE_MAX_MA\0"
    "MA_PREHEAT_REQUIRED_MA_SET_AUTOMATICALLY\0"
    "ICM_TP\0TP_NO_ERROR\0TP_NO_GENERATOR_CONNECTED\0"
    "TP_GENERATOR_RENTAL_DATA_IS_OVER\0"
    "TP_SHOT_IS_IN_PROGRESS\0"
    "TP_REQUESTED_VALUE_IS_BELOW_MIN_TP_VALUE\0"
    "TP_REQUESTED_VALUE_IS_ABOVE_MAX_TP_VALUE\0"
    "TP_REQUEST_TP_IS_BIGGER_THAN_REMAINING_RENTAL_TIME\0"
    "TP_PREHEAT_IS_REQUIRED_TP_IS_SET_AUTOMATICALLY\0"
    "ICM_TS\0TS_NONE_NO_SHOT_ACTUALLY\0"
    "TS_PREHEATING\0TS_NORMAL_SHOT\0TS_CYCLES\0"
    "TS_CONDITIONING\0ICM_ST\0ST_CONNECTING\0"
    "ST_NO_GENERATOR\0ST_READY_TO_START\0"
    "ST_ERROR_STATE\0ST_PREHEATING_REQUIRED\0"
    "ST_RESERVED_FOR_FUTURE_USE\0"
    "ST_PREWARNING_IN_PROGRESS\0ST_RAMP_IN_PROGRESS\0"
    "ST_SHOT_IN_PROGRESS\0ST_END_OF_SHOT\0"
    "ST_WAIT_IN_PROGRESS\0ST_SHOT_RESTART\0"
    "ST_PROMPT_MESSAGE\0ICM_CMD\0CMD_NULL\0"
    "CMD_SE\0CMD_KV\0CMD_MA\0CMD_TP\0CMD_ON\0"
    "CMD_OF\0CMD_XO\0CMD_TS\0CMD_SN\0CMD_MD\0"
    "CMD_ST\0CMD_RC\0ICM_TYPE\0ICM_TYPE_NULL\0"
    "ICM_TYPE_CP120B\0ICM_TYPE_CP160B\0"
    "ICM_TYPE_CP160D\0ICM_TYPE_CP200D\0"
    "ICM_TYPE_CP200DS\0ICM_TYPE_CP225D\0"
    "ICM_TYPE_CP300C\0LOGIN_RESULT\0"
    "LOGIN_RESULT_NULL\0LOGIN_RESULT_NO_USER\0"
    "LOGIN_RESULT_NO_PASSWORD\0"
    "LOGIN_RESULT_USER_OR_PASSWORD_ERROR\0"
    "LOGIN_RESULT_SUCCESSED\0XRAY_DETECTOR_TYPE\0"
    "XRAY_DETECTOR_TYPE_STATIC\0"
    "XRAY_DETECTOR_TYPE_DYNAMIC\0"
    "XRAY_DETECTOR_TYPE_NULL\0XRAY_CHECK_TYPE\0"
    "XRAY_CHECK_TYPE_NULL\0XRAY_CHECK_TYPE_DR\0"
    "XRAY_CHECK_TYPE_CR\0MARK_TYPE\0"
    "MARK_TYPE_NULL\0MARK_TYPE_AUTO_CACULATION\0"
    "MARK_TYPE_WORD\0MARK_TYPE_ELLIPSE\0"
    "MARK_TYPE_POLYGON\0MARK_TYPE_RECTANGLE\0"
    "MARK_TYPE_ARROW\0MARK_TYPE_ANGLE\0"
    "MARK_TYPE_STRAIGHT_LINE\0DICOM_VR_TYPE\0"
    "VR_TYPE_NULL\0VR_TYPE_EXPLICIT_TABLE_7_1_1\0"
    "VR_TYPE_EXPLICIT_TABLE_7_1_2\0"
    "VR_TYPE_IMPLICIT_TABLE_7_1_3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnumParameter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
      12,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    7,   74,
       9,    9, 0x0,    6,   88,
      16,   16, 0x0,    8,  100,
      25,   25, 0x0,    5,  116,
      31,   31, 0x0,   13,  126,
      45,   45, 0x0,   13,  152,
      59,   59, 0x0,    8,  178,
      68,   68, 0x0,    5,  194,
      74,   74, 0x0,    3,  204,
      78,   78, 0x0,    3,  210,
      82,   82, 0x0,    9,  216,
      92,   92, 0x0,    4,  234,

 // enum data: key, value
       2, uint(EnumParameter::KV_NO_ERROR),
       3, uint(EnumParameter::KV_NO_GENERATOR_CONNECTED),
       4, uint(EnumParameter::KV_GENERATOR_RENTAL_DATA_IS_OVER),
       5, uint(EnumParameter::KV_REQUESTED_KV_VALUE_IS_BELOW_MIN_KV),
       6, uint(EnumParameter::KV_REQUESTED_KV_VALUE_IS_ABOVE_MIN_KV),
       7, uint(EnumParameter::KV_OK_BUT_MA_HAS_TO_BE_ADJUSTED),
       8, uint(EnumParameter::KV_PREHEAD_IS_REQUIRED_TO_SHOOT_AT_THIS_KV_VALUE),
      10, uint(EnumParameter::MA_NO_ERROR),
      11, uint(EnumParameter::MA_NO_GENERATOR_CONNECTED),
      12, uint(EnumParameter::MA_GENERATOR_RENTAL_DATA_IS_OVER),
      13, uint(EnumParameter::MA_REQUESTED_MA_VALUE_IS_BELOW_MIN_MA),
      14, uint(EnumParameter::MA_REQUESTED_MA_VALUE_IS_ABOVE_MAX_MA),
      15, uint(EnumParameter::MA_PREHEAT_REQUIRED_MA_SET_AUTOMATICALLY),
      17, uint(EnumParameter::TP_NO_ERROR),
      18, uint(EnumParameter::TP_NO_GENERATOR_CONNECTED),
      19, uint(EnumParameter::TP_GENERATOR_RENTAL_DATA_IS_OVER),
      20, uint(EnumParameter::TP_SHOT_IS_IN_PROGRESS),
      21, uint(EnumParameter::TP_REQUESTED_VALUE_IS_BELOW_MIN_TP_VALUE),
      22, uint(EnumParameter::TP_REQUESTED_VALUE_IS_ABOVE_MAX_TP_VALUE),
      23, uint(EnumParameter::TP_REQUEST_TP_IS_BIGGER_THAN_REMAINING_RENTAL_TIME),
      24, uint(EnumParameter::TP_PREHEAT_IS_REQUIRED_TP_IS_SET_AUTOMATICALLY),
      26, uint(EnumParameter::TS_NONE_NO_SHOT_ACTUALLY),
      27, uint(EnumParameter::TS_PREHEATING),
      28, uint(EnumParameter::TS_NORMAL_SHOT),
      29, uint(EnumParameter::TS_CYCLES),
      30, uint(EnumParameter::TS_CONDITIONING),
      32, uint(EnumParameter::ST_CONNECTING),
      33, uint(EnumParameter::ST_NO_GENERATOR),
      34, uint(EnumParameter::ST_READY_TO_START),
      35, uint(EnumParameter::ST_ERROR_STATE),
      36, uint(EnumParameter::ST_PREHEATING_REQUIRED),
      37, uint(EnumParameter::ST_RESERVED_FOR_FUTURE_USE),
      38, uint(EnumParameter::ST_PREWARNING_IN_PROGRESS),
      39, uint(EnumParameter::ST_RAMP_IN_PROGRESS),
      40, uint(EnumParameter::ST_SHOT_IN_PROGRESS),
      41, uint(EnumParameter::ST_END_OF_SHOT),
      42, uint(EnumParameter::ST_WAIT_IN_PROGRESS),
      43, uint(EnumParameter::ST_SHOT_RESTART),
      44, uint(EnumParameter::ST_PROMPT_MESSAGE),
      46, uint(EnumParameter::CMD_NULL),
      47, uint(EnumParameter::CMD_SE),
      48, uint(EnumParameter::CMD_KV),
      49, uint(EnumParameter::CMD_MA),
      50, uint(EnumParameter::CMD_TP),
      51, uint(EnumParameter::CMD_ON),
      52, uint(EnumParameter::CMD_OF),
      53, uint(EnumParameter::CMD_XO),
      54, uint(EnumParameter::CMD_TS),
      55, uint(EnumParameter::CMD_SN),
      56, uint(EnumParameter::CMD_MD),
      57, uint(EnumParameter::CMD_ST),
      58, uint(EnumParameter::CMD_RC),
      60, uint(EnumParameter::ICM_TYPE_NULL),
      61, uint(EnumParameter::ICM_TYPE_CP120B),
      62, uint(EnumParameter::ICM_TYPE_CP160B),
      63, uint(EnumParameter::ICM_TYPE_CP160D),
      64, uint(EnumParameter::ICM_TYPE_CP200D),
      65, uint(EnumParameter::ICM_TYPE_CP200DS),
      66, uint(EnumParameter::ICM_TYPE_CP225D),
      67, uint(EnumParameter::ICM_TYPE_CP300C),
      69, uint(EnumParameter::LOGIN_RESULT_NULL),
      70, uint(EnumParameter::LOGIN_RESULT_NO_USER),
      71, uint(EnumParameter::LOGIN_RESULT_NO_PASSWORD),
      72, uint(EnumParameter::LOGIN_RESULT_USER_OR_PASSWORD_ERROR),
      73, uint(EnumParameter::LOGIN_RESULT_SUCCESSED),
      75, uint(EnumParameter::XRAY_DETECTOR_TYPE_STATIC),
      76, uint(EnumParameter::XRAY_DETECTOR_TYPE_DYNAMIC),
      77, uint(EnumParameter::XRAY_DETECTOR_TYPE_NULL),
      79, uint(EnumParameter::XRAY_CHECK_TYPE_NULL),
      80, uint(EnumParameter::XRAY_CHECK_TYPE_DR),
      81, uint(EnumParameter::XRAY_CHECK_TYPE_CR),
      83, uint(EnumParameter::MARK_TYPE_NULL),
      84, uint(EnumParameter::MARK_TYPE_AUTO_CACULATION),
      85, uint(EnumParameter::MARK_TYPE_WORD),
      86, uint(EnumParameter::MARK_TYPE_ELLIPSE),
      87, uint(EnumParameter::MARK_TYPE_POLYGON),
      88, uint(EnumParameter::MARK_TYPE_RECTANGLE),
      89, uint(EnumParameter::MARK_TYPE_ARROW),
      90, uint(EnumParameter::MARK_TYPE_ANGLE),
      91, uint(EnumParameter::MARK_TYPE_STRAIGHT_LINE),
      93, uint(EnumParameter::VR_TYPE_NULL),
      94, uint(EnumParameter::VR_TYPE_EXPLICIT_TABLE_7_1_1),
      95, uint(EnumParameter::VR_TYPE_EXPLICIT_TABLE_7_1_2),
      96, uint(EnumParameter::VR_TYPE_IMPLICIT_TABLE_7_1_3),

       0        // eod
};

void EnumParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject EnumParameter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EnumParameter.data,
    qt_meta_data_EnumParameter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EnumParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnumParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnumParameter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EnumParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
