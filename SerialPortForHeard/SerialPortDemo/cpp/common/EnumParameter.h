#pragma once

#include <QObject>


class EnumParameter : public QObject
{
    Q_OBJECT
    Q_ENUMS(ICM_KV)
    Q_ENUMS(ICM_MA)
    Q_ENUMS(ICM_TP)
    Q_ENUMS(ICM_TS)
    Q_ENUMS(ICM_ST)
    Q_ENUMS(ICM_CMD)
    Q_ENUMS(ICM_TYPE)
    Q_ENUMS(LOGIN_RESULT)

    Q_ENUMS(XRAY_DETECTOR_TYPE)
    Q_ENUMS(XRAY_CHECK_TYPE)

    Q_ENUMS(MARK_TYPE)

    Q_ENUMS(DICOM_VR_TYPE)

public:
    /**
     * @brief Program new kV value
     */
    enum ICM_KV
    {
        KV_NO_ERROR = 0,
        KV_NO_GENERATOR_CONNECTED,                          //发生器没有连接
        KV_GENERATOR_RENTAL_DATA_IS_OVER,                   //发生器租赁期限已过
        KV_REQUESTED_KV_VALUE_IS_BELOW_MIN_KV,              //要求的电压值小于最小电压值
        KV_REQUESTED_KV_VALUE_IS_ABOVE_MIN_KV,              //要求的电压值大于最大电压值
        KV_OK_BUT_MA_HAS_TO_BE_ADJUSTED,                    //电压值正常但是电流值需要调整
        KV_PREHEAD_IS_REQUIRED_TO_SHOOT_AT_THIS_KV_VALUE    //在此电压值下开启射线需要预热
    };

    /**
     * @brief Program new mA value
     */
    enum ICM_MA
    {
        MA_NO_ERROR = 0,
        MA_NO_GENERATOR_CONNECTED,                          //发生器没有连接
        MA_GENERATOR_RENTAL_DATA_IS_OVER,                   //发生器租赁期限已过
        MA_REQUESTED_MA_VALUE_IS_BELOW_MIN_MA,              //要求的电流值小于最小电流值
        MA_REQUESTED_MA_VALUE_IS_ABOVE_MAX_MA,              //要求的电流值大于最大电流值
        MA_PREHEAT_REQUIRED_MA_SET_AUTOMATICALLY            //需要预热_电流自动设定
    };

    /// <summary>
    /// Program new exposure time value
    /// </summary>
    enum ICM_TP
    {
        TP_NO_ERROR,
        TP_NO_GENERATOR_CONNECTED,                          //发生器没有连接
        TP_GENERATOR_RENTAL_DATA_IS_OVER,                   //发电机租赁期限已过
        TP_SHOT_IS_IN_PROGRESS,                             //正在拍摄中
        TP_REQUESTED_VALUE_IS_BELOW_MIN_TP_VALUE,           //请求值低于最小TP值
        TP_REQUESTED_VALUE_IS_ABOVE_MAX_TP_VALUE,           //请求值高于最大TP值
        TP_REQUEST_TP_IS_BIGGER_THAN_REMAINING_RENTAL_TIME, //请求的TP大于剩余的租赁时间
        TP_PREHEAT_IS_REQUIRED_TP_IS_SET_AUTOMATICALLY      //需要预热-TP自动设置
    };

    /**
     * @brief Ask for the shot type
     */
    enum ICM_TS
    {
        TS_NONE_NO_SHOT_ACTUALLY = 0,                       //射线机关闭
        TS_PREHEATING,                                      //预热
        TS_NORMAL_SHOT,                                     //正常拍摄
        TS_CYCLES,                                          //循环拍摄
        TS_CONDITIONING                                     //有条件的拍摄
    };

    /**
     * @brief Retrieve current status of PowerBox/Generator
     */
    enum ICM_ST
    {
        ST_CONNECTING = 0,                                  //连接中
        ST_NO_GENERATOR,                                    //无发声器
        ST_READY_TO_START,                                  //准备启动
        ST_ERROR_STATE,                                     //错误状态
        ST_PREHEATING_REQUIRED,                             //预热请求
        ST_RESERVED_FOR_FUTURE_USE,                         //保留字段
        ST_PREWARNING_IN_PROGRESS,                          //预警中
        ST_RAMP_IN_PROGRESS,                                //上升过程中
        ST_SHOT_IN_PROGRESS,                                //拍摄中
        ST_END_OF_SHOT,                                     //拍摄结束
        ST_WAIT_IN_PROGRESS,                                //拍摄过程中,请等待
        ST_SHOT_RESTART,                                    //拍摄重新开始
        ST_PROMPT_MESSAGE                                   //提示消息
    };

    /**
     * @brief ICM协议命令类型
     */
    enum ICM_CMD
    {
        CMD_NULL,
        CMD_SE,                                             //Ask for actual shot values
        CMD_KV,                                             //Program new KV value
        CMD_MA,                                             //Program new MA value
        CMD_TP,                                             //Program new exposure time value
        CMD_ON,                                             //Start shot
        CMD_OF,                                             //Stop shot
        CMD_XO,                                             //Watchdog
        CMD_TS,                                             //Ask for the shot type
        CMD_SN,                                             //Ask for the serial numbers of generator and PowerBox
        CMD_MD,                                             //Ask for the generator model
        CMD_ST,                                             //Retrieve current status of PowerBox/Generator
        CMD_RC                                              //Ask the rating chart
    };

    /**
     * @brief 不同的设备类型
     */
    enum ICM_TYPE
    {
        ICM_TYPE_NULL,
        /////////////////////////////////////////////////////////
        ICM_TYPE_CP120B,        //此区间设备共同一套协议
        ICM_TYPE_CP160B,
        /////////////////////////////////////////////////////////
        ICM_TYPE_CP160D,        //此区间设备共同一套协议
        ICM_TYPE_CP200D,
        ICM_TYPE_CP200DS,
        ICM_TYPE_CP225D,
        ICM_TYPE_CP300C
        /////////////////////////////////////////////////////////
    };

    /**
     * @brief 用户登录结果提示
     */
    enum LOGIN_RESULT {
        LOGIN_RESULT_NULL,
        LOGIN_RESULT_NO_USER,
        LOGIN_RESULT_NO_PASSWORD,
        LOGIN_RESULT_USER_OR_PASSWORD_ERROR,
        LOGIN_RESULT_SUCCESSED
    };


    /**
     * @brief 检测器类型
     */
    enum XRAY_DETECTOR_TYPE
    {
        /// <summary>
        /// 静态
        /// </summary>
        XRAY_DETECTOR_TYPE_STATIC,
        /// <summary>
        /// 动态
        /// </summary>
        XRAY_DETECTOR_TYPE_DYNAMIC,
        /// <summary>
        /// NULL
        /// </summary>
        XRAY_DETECTOR_TYPE_NULL=99
    };

    /**
     * @brief 检测类别
     */
    enum XRAY_CHECK_TYPE
    {
        XRAY_CHECK_TYPE_NULL,
        XRAY_CHECK_TYPE_DR,
        XRAY_CHECK_TYPE_CR
    };

    /**
     * @brief 标注类型
     */
    enum MARK_TYPE
    {
        MARK_TYPE_NULL,
        MARK_TYPE_AUTO_CACULATION,                      //自动计算合适的窗宽宽窗位
        MARK_TYPE_WORD,                                 //标注文字
        MARK_TYPE_ELLIPSE,                              //标注椭圆
        MARK_TYPE_POLYGON,                              //标注多边形
        MARK_TYPE_RECTANGLE,                            //标注矩形
        MARK_TYPE_ARROW,                                //标注箭头
        MARK_TYPE_ANGLE,                                //标主角度
        MARK_TYPE_STRAIGHT_LINE                         //标注直线
    };

    /**
     * @brief DICOM数据元素VR类型
     * <<DICOM Part 5 Data Structures and Encoding.pdf>> section 7 The Data Set
     */
    enum DICOM_VR_TYPE
    {
        VR_TYPE_NULL,
        VR_TYPE_EXPLICIT_TABLE_7_1_1,
        VR_TYPE_EXPLICIT_TABLE_7_1_2,
        VR_TYPE_IMPLICIT_TABLE_7_1_3
    };
};

//Q_DECLARE_METATYPE(EnumParamter::ICM_KV)
//Q_DECLARE_METATYPE(EnumParamter::ICM_MA)
//Q_DECLARE_METATYPE(EnumParamter::ICM_TP)
//Q_DECLARE_METATYPE(EnumParamter::ICM_TS)
//Q_DECLARE_METATYPE(EnumParamter::ICM_ST)
//Q_DECLARE_METATYPE(EnumParamter::ICM_CMD)
//Q_DECLARE_METATYPE(EnumParamter::ICM_TYPE)
//Q_DECLARE_METATYPE(EnumParamter::LOGIN_RESULT)

//Q_DECLARE_METATYPE(EnumParamter::XRAY_DETECTOR_TYPE)
//Q_DECLARE_METATYPE(EnumParamter::XRAY_CHECK_TYPE)
//Q_DECLARE_METATYPE(EnumParamter::MARK_TYPE)

//Q_DECLARE_METATYPE(EnumParamter::DICOM_VR_TYPE)

