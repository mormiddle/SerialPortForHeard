#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QColor>
#include <vector>
#include <QVector>
#include <QtMath>

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
    std::array<double, 10> m_10MhzReal;
    std::array<double, 10> m_10MhzImag;
    std::array<double, 10> m_25MhzReal;
    std::array<double, 10> m_25MhzImag;
    std::array<double, 10> m_dhardValue;
    bool m_b10MhzIsReady = false;
    bool m_b25MhzIsReady = false;
    double CalculateHardnessValue(double b0, double b1, double b2, double b3, double b4, double b5,
                                double b6, double b7, double b8, double b9, double b10, double b11, double b12,
                                double x1, double x2, double x3, double x4);
};

#endif // MYSERIALPORT_H
