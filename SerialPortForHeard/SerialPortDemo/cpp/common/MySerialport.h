#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QColor>
#include <vector>
#include <QVector>
#include <QtMath>
#include <QFile>

#include "Globals.h"

#define ASIIC_TYPE true
#define HEX_TYPE false

class MySerialPort : public QObject
{
    Q_OBJECT

public:
    explicit MySerialPort(QObject *parent = nullptr);
    ~MySerialPort();
    QSerialPort *myPort;

public:
    QByteArray buffer;
    int start = 0;
    int framesReceived = 0;
    bool scanIsStart = false;
    int repeateScanLineNum = 0;
signals:
    void portNameSignal(QString portName);
    void displayRecDataSignal( QString );
    void autorChanged();
    void returnOpenResultSignal( bool );

public slots:
    void setPort();
    void initPort();
    void openPort( QString value );
    void readData_slot();
    bool readIsMyPortOpen();
    quint8 CRC8(QByteArray buffer, int start, int length);
    //void showData(QVector<QVector<double>>&);
    int toIntData(quint8 lowByte, quint8 highByte);
    Q_INVOKABLE void setScanIsStart(bool start);
    Q_INVOKABLE void setRepeateScanLineNum(int value);

private:
    std::array<double, 10> m_01KhzReal;
    std::array<double, 10> m_01KhzImag;
    std::array<double, 10> m_2_5KhzReal;
    std::array<double, 10> m_2_5KhzImag;
    std::array<double, 10> m_04KhzReal;
    std::array<double, 10> m_04KhzImag;
    std::array<double, 10> m_5_5KhzReal;
    std::array<double, 10> m_5_5KhzImag;
    std::array<double, 10> m_dhardValue;

    bool m_b01KhzIsReady = false;
    bool m_b2_5KhzIsReady = false;
    bool m_b04KhzIsReady = false;
    bool m_b5_5KhzIsReady = false;
    bool m_bchannelPerameterIsReady = false;

    QVector< QVector<double>> m_channelParameter;

    double CalculateHardnessValue(std::array<double, 25> channel,
                                double x1, double x2, double x3, double x4,
                                double x5, double x6, double x7, double x8  );
    void readFileTo2DArray(QVector< QVector<double> >& array, const QString& filePath);


};

#endif // MYSERIALPORT_H
