#include "MySerialport.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QTime>

int count = 0;
MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    myPort = new QSerialPort;
    m_currScanLine = 0;

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
        qDebug() << "Name : " << info.portName();
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
        if( myPort->open( QIODevice::ReadWrite ) )
        {
            connect( myPort, &QSerialPort::readyRead, this, &MySerialPort::readData_slot );
            qDebug() << myPort->portName() << myPort->baudRate() << myPort->dataBits()
                     << myPort->parity() << myPort->stopBits();
        }
        else
        {

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

    QByteArray buff;
    buff = myPort->readAll();

    buffer.append(buff);//缓存数据

    int count = buffer.count();
    int bytesIgnored = 0;

    while ( start + 44 <= count ) {

        if( buffer[start] != static_cast<char>(0xaa) || buffer[start + 1] != static_cast<char>(0x29) || buffer[start + 43] != static_cast<char>(0x80)) {
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
            if( m_repeateScanLines.size() == 0)
            {
                m_repeateScanLines = QVector<SINGAL_SCAN_LINE>(1);
                QVector<SINGAL_CHANEL_DATA>& firstScanData = m_repeateScanLines[m_currScanLine].tenChanelData;
                for (int i = 0; i < m_chanelPerScanLine; i++) {
                    firstScanData.push_back(SINGAL_CHANEL_DATA());
                }
                for (int i = 0; i < m_chanelPerScanLine; i++)
                {
                    int value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]) - 256;

                    firstScanData[i].push_back(value);
                }

                return;
            }


            QVector<SINGAL_CHANEL_DATA>& signalScanTenChanelData = m_repeateScanLines[m_currScanLine].tenChanelData;
            

            for (int i = 0; i < m_chanelPerScanLine; i++)
            {
                int value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]) - 256;

                signalScanTenChanelData[i].push_back(value);
            }

            qInfo("cols: %d", signalScanTenChanelData[0].size());
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

    //测试数据传输，将其显示出来
    //showData(checkedData);


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

//void MySerialPort::showData(QVector<QVector<double>>& checkedData)
//{
//    //默认为HEX
//    QString str;
//    for (const auto& vec : checkedData) { // 遍历每个 vector
//        for (const auto& val : vec) { // 遍历 vector 中的每个元素
//            str += QString::number(val) + " ";
//        }
//        str += "\n"; // 每个 vector 后添加换行符
//    }

//    emit displayRecDataSignal( str );
//}

int MySerialPort::toIntData(quint8 lowByte, quint8 highByte)
{
    qint16 rawValue = (qint16)((highByte << 8) | lowByte); // convert to signed short
    int signedValue = static_cast<int>(rawValue); // convert to signed int
    return signedValue;
}




















