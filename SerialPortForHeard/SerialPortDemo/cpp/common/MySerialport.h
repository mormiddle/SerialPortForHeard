﻿#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QColor>
#include <vector>

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

public:

   int m_chanelPerScanLine;

   typedef QVector<double>          CHANEL_DATA;
   typedef QVector< CHANEL_DATA >   SCAN_LINE;

   QVector<SCAN_LINE>   m_scanLines;
   int                  m_idxCurrScanLine;
};

#endif // MYSERIALPORT_H
