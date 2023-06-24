﻿#include "MySerialport.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QTime>

int count = 0;
MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    myPort = new QSerialPort;
    m_repeateScanLineNum = 0;
    m_repeateScanLines.repeateTimes.push_back(0);
    readFileTo2DArray(m_channelParameter,"D:/Sacar/参数.txt");
}

MySerialPort::~MySerialPort()
{
    delete myPort;
}


void MySerialPort::setPort()
{

}


void MySerialPort::initPort()
{
    foreach( const QSerialPortInfo &info, QSerialPortInfo::availablePorts() )
    {
        //qDebug() << "Name : " << info.portName();
        emit portNameSignal( info.portName() );
    }
    myPort->setBaudRate(115200);
    myPort->setDataBits(QSerialPort::Data8);
    myPort->setParity(QSerialPort::NoParity);
    myPort->setStopBits(QSerialPort::OneStop);
}

void MySerialPort::openPort( QString value)
{
    qDebug() << " openPort is working ";
    QStringList list = value.split('/');
    int btnState = list[0].toInt();
    QString port = list[1];

    if( btnState == 1 )     //1 串口打开标志
    {
        //设置串口名字
        myPort->setPortName( port );
        if( myPort->open( QIODevice::ReadWrite ) ) {
            connect( myPort, &QSerialPort::readyRead, this, &MySerialPort::readData_slot );
            qDebug() << myPort->portName() << myPort->baudRate() << myPort->dataBits()
                     << myPort->parity() << myPort->stopBits();
        }
        else {

        }
    }
    else
    {
        if( btnState == 0 )
        {
            myPort->close();
        }
        emit returnOpenResultSignal( myPort->isOpen() );
    }
}

void MySerialPort::readData_slot()
{
    int num = myPort->bytesAvailable();
    if( num == 0) {
        return;
    }

    if( scanIsStart )
    {
       m_repeateScanLineNum = repeateScanLineNum;
//       qDebug() << "sacnIsStart: " << scanIsStart;
//       qDebug() << "m_repeateScanLineNum: " << m_repeateScanLineNum;
    }
    else {
//        qDebug() << "sacnIsStart: " << scanIsStart;
        return;
    }


    QByteArray buff;
    buff = myPort->readAll();

    buffer.append(buff);//缓存数据


    int count = buffer.count();
    int bytesIgnored = 0;

    while ( start + 45 <= count ) {

        if( buffer[start] != static_cast<char>(0xaa) || buffer[start + 1] != static_cast<char>(0x29) || buffer[start + 44] != static_cast<char>(0x80)) {
            ++start;
            ++bytesIgnored;
            continue;
        }

        if( CRC8(buffer, start + 2, 40) !=static_cast<unsigned char>(buffer[start + 42]) ){
            ++start;
            ++bytesIgnored;
            continue;

        }

        //appen data
        {
            if ( m_repeateScanLines.ChanelData.size() == 0)
            {
                for ( int i = 0; i < m_chanelPerScanLine; ++i){
                    m_repeateScanLines.ChanelData.push_back(SINGAL_CHANEL_DATA());

                }

            }

            //双频率数据处理
            if ( buffer[start + 43] == static_cast<char>(0x01)) {
                int value = 0;           
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    //10Mhz的实部
                    value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
                    m_01KhzReal[i] = value - m_01KhzRealDemarcate[i];
                    //10Mhz的虚部
                    value = toIntData(buffer[start + 4 + i * 4], buffer[start + 5 + i * 4]);
                    m_01KhzImag[i] = value - m_01KhzImagDemarcate[i];
                }                
                m_b01KhzIsReady = true;

            }

            if ( buffer[start + 43] == static_cast<char>(0x02)) {
                int value = 0;              
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    //25Mhz的实部
                    value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
                    m_2_5KhzReal[i] = value - m_2_5KhzRealDemarcate[i];
                    //25Mhz的虚部
                    value = toIntData(buffer[start + 4 + i * 4], buffer[start + 5 + i * 4]);
                    m_2_5KhzImag[i] = value - m_2_5KhzImagDemarcate[i];
                }               
                m_b2_5KhzIsReady = true;

            }

            if ( buffer[start + 43] == static_cast<char>(0x03)) {
                int value = 0;                
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    //25Mhz的实部
                    value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
                    m_04KhzReal[i] = value - m_04KhzRealDemarcate[i];
                    //25Mhz的虚部
                    value = toIntData(buffer[start + 4 + i * 4], buffer[start + 5 + i * 4]);
                    m_04KhzImag[i] = value - m_04KhzImagDemarcate[i];
                }             
                m_b04KhzIsReady = true;

            }

            if ( buffer[start + 43] == static_cast<char>(0x04)) {
                int value = 0;                
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    //25Mhz的实部
                    value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
                    m_5_5KhzReal[i] = value - m_5_5KhzRealDemarcate[i];
                    //25Mhz的虚部
                    value = toIntData(buffer[start + 4 + i * 4], buffer[start + 5 + i * 4]);
                    m_5_5KhzImag[i] = value - m_5_5KhzImagDemarcate[i];
                }                
                m_b5_5KhzIsReady = true;

            }

            if ( m_b01KhzIsReady && m_b2_5KhzIsReady && m_b04KhzIsReady && m_b5_5KhzIsReady && m_bchannelPerameterIsReady && m_bdemarcateIsReady) {

                for( int i = 0; i < m_chanelPerScanLine; ++i) {
                    std::array<double, 25> tmpParam{};
                    for( int j = 0; j < 19; ++j) {
                        tmpParam[j] = m_channelParameter[i][j];
                    }
                    m_dhardValue[i] = CalculateHardnessValue(tmpParam, m_01KhzReal[i], m_01KhzImag[i], m_2_5KhzReal[i], m_2_5KhzImag[i], m_04KhzReal[i], m_04KhzImag[i], m_5_5KhzReal[i], m_5_5KhzImag[i]);
                }

                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    m_repeateScanLines.ChanelData[i].push_back(m_dhardValue[i]);
                }

                m_b01KhzIsReady = false;
                m_b2_5KhzIsReady = false;
                m_b04KhzIsReady = false;
                m_b5_5KhzIsReady = false;

            }

//            // 然后像以前一样处理数据
//            int value = 0;
//            for (int i = 0; i < m_chanelPerScanLine; ++i) {
//                value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
//                m_repeateScanLines.ChanelData[i].push_back(value);
//            }


        }

        start += 44;
        ++framesReceived;

    }

    if( bytesIgnored > 0) {
        QDateTime dt = QDateTime::currentDateTime();
        qDebug() << QString("%1:%2:%3.%4 %5 frames received, %6 bytes ignored")
                            .arg(dt.time().hour()).arg(dt.time().minute())
                            .arg(dt.time().second()).arg(dt.time().msec())
                            .arg(framesReceived).arg(bytesIgnored);
        framesReceived = 0;
    }

    if( start < count ) {
        buffer = buffer.mid(start, count - start);
    }
    else {
        buffer.clear();
    }
    start = 0;


}

bool MySerialPort::readIsMyPortOpen()
{
    qDebug() << myPort->isOpen();
    return myPort->isOpen();
}

quint8 MySerialPort::CRC8(QByteArray buffer, int start, int length)
{
    quint8 crc = 0; // Initial value

    for (int j = start; j < start + length; j++)
    {
       crc ^= buffer[j];
       for (int i = 0; i < 8; i++)
       {
           if ((crc & 0x80) != 0)
           {
               crc <<= 1;
               crc ^= 0x07;
           }
           else
           {
               crc <<= 1;
           }
       }
    }
    return crc;
}

int MySerialPort::toIntData(quint8 lowByte, quint8 highByte)
{
    qint16 rawValue = (qint16)((highByte << 8) | lowByte); // convert to signed short
    int signedValue = static_cast<int>(rawValue); // convert to signed int
    return signedValue;
}

void MySerialPort::setScanIsStart(bool start)
{
    scanIsStart = start;
}

void MySerialPort::setRepeateScanLineNum(int value)
{
    repeateScanLineNum = value;
}

void MySerialPort::setDemarcate()
{
    for (int i = 0; i < m_chanelPerScanLine; ++i)
    {
        m_01KhzRealDemarcate[i] = m_01KhzReal[i];
        m_01KhzImagDemarcate[i] = m_01KhzImag[i];
        m_2_5KhzRealDemarcate[i] = m_2_5KhzReal[i];
        m_2_5KhzImagDemarcate[i] = m_2_5KhzImag[i];
        m_04KhzRealDemarcate[i] = m_04KhzReal[i];
        m_04KhzImagDemarcate[i] = m_04KhzImag[i];
        m_5_5KhzRealDemarcate[i] = m_5_5KhzReal[i];
        m_5_5KhzImagDemarcate[i] = m_5_5KhzImag[i];
        m_dhardValueDemarcate[i] = m_dhardValue[i];
    }

    m_b01KhzIsReady = false;
    m_b2_5KhzIsReady = false;
    m_b04KhzIsReady = false;
    m_b5_5KhzIsReady = false;
    m_bdemarcateIsReady = true;

    buffer.clear();
    start = 0;
    framesReceived = 0;
    scanIsStart = false;
    repeateScanLineNum = 0;

}

double MySerialPort::CalculateHardnessValue(std::array<double, 25> channel, double x1, double x2, double x3, double x4, double x5, double x6, double x7, double x8)
{
    double HardnessValue = channel[0]
                         + (channel[1] * qPow(x1, 3)) + (channel[2] * qPow(x1, 2)) + (channel[3] * x1)
                         + (channel[4] * qPow(x2, 3)) + (channel[5] * qPow(x2, 2)) + (channel[6] * x2)
                         + (channel[7] * qPow(x3, 3)) + (channel[8] * qPow(x3, 2)) + (channel[9] * x3)
                         + (channel[10] * qPow(x4, 3)) + (channel[11] * qPow(x4, 2)) + (channel[12] * x4)
                         + (channel[13] * qPow(x5, 3)) + (channel[14] * qPow(x5, 2)) + (channel[15] * x5)
                         + (channel[16] * qPow(x6, 3)) + (channel[17] * qPow(x6, 2)) + (channel[18] * x6)
                         + (channel[19] * qPow(x7, 3)) + (channel[20] * qPow(x7, 2)) + (channel[21] * x7)
                         + (channel[22] * qPow(x8, 3)) + (channel[23] * qPow(x8, 2)) + (channel[24] * x8);
    return HardnessValue;
}

void MySerialPort::readFileTo2DArray(QVector<QVector<double> > &array, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading: " << qPrintable(file.errorString());
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split('\t');

        QVector<double> row;
        for(int j = 0; j < fields.size(); ++j) {
            row.append(fields[j].toDouble());
        }
        array.append(row);
    }
    file.close();

    m_bchannelPerameterIsReady = true;
}


