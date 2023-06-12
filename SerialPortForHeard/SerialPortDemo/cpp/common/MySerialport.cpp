#include "MySerialport.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QTime>

int count = 0;
MySerialPort::MySerialPort(QObject *parent) : QObject(parent)
{
    myPort = new QSerialPort;
    m_repeateScanLineNum = 0;
    m_repeateScanLines.repeateTimes.push_back(0);

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
            if ( buffer[start + 43] == static_cast<char>(0x10)) {
                int value = 0;
                //10Mhz的实部
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
                    m_10MhzReal[i] = value;
                }
                //10Mhz的虚部
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    value = toIntData(buffer[start + 4 + i * 4], buffer[start + 5 + i * 4]);
                    m_10MhzImag[i] = value;

                }
                m_b10MhzIsReady = true;

            }

            if ( buffer[start + 43] == static_cast<char>(0x10)) {
                int value = 0;
                //25Mhz的实部
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    value = toIntData(buffer[start + 2 + i * 4], buffer[start + 3 + i * 4]);
                    m_25MhzReal[i] = value;
                }
                //25Mhz的虚部
                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    value = toIntData(buffer[start + 4 + i * 4], buffer[start + 5 + i * 4]);
                    m_25MhzImag[i] = value;

                }
                m_b25MhzIsReady = true;

            }

            if ( m_b10MhzIsReady && m_b25MhzIsReady) {
                m_dhardValue[0] = CalculateHardnessValue(233.6357622799130000, -0.0000004636015717, -0.0029766105353473, 1.1188569350816500, -0.0000107457924237, 0.0605556050769001,
                                                                          -107.7777240553940000, 0.0000379097734229, 0.0083447466319129, -108.7299127535720000, 0.0102620251718539, -2.4874284024906800, 198.5673144853010000,
                                                                            m_25MhzReal[0],
                                                                            m_25MhzImag[0],
                                                                            m_10MhzReal[0],
                                                                            m_10MhzImag[0]);

                m_dhardValue[1] = CalculateHardnessValue(214.0939961647550000, -0.0000110562160986, -0.1368779327462140, -564.6312807726110000, 0.0000070950797249, -0.0176766869237083,
                                                          12.2687124825107000, 0.0009326224926361, 2.6346387211140800, 2481.4322870968900000, 0.0036333140430002, -0.8595099948940170, 64.6469256389558000,
                                                            m_25MhzReal[1],
                                                            m_25MhzImag[1],
                                                            m_10MhzReal[1],
                                                            m_10MhzImag[1]);

                m_dhardValue[2] = CalculateHardnessValue(464.7457830200320000, 0.0000001523242025, 0.0141602174938791, 122.6581347937220000, 0.0000427004095325, -0.2882462412281990,
                                                          561.9764421745020000, -0.0001655102991507, -0.2992265991896710, -76.6222953836146000, -0.0098294755387214, 1.6624792265004900, -98.3321738970879000,
                                                            m_25MhzReal[2],
                                                            m_25MhzImag[2],
                                                            m_10MhzReal[2],
                                                            m_10MhzImag[2]);

                m_dhardValue[3] = CalculateHardnessValue(553.8620573274600000, 0.0000017689502613, 0.0221633283182934, 92.8535023570581000, 0.0000355608044337, -0.1386138559454010,
                                                          181.1895426146600000, -0.0000350950031572, -0.1232578273115480, -140.2451597047500000, -0.0031912635520178, 0.7702777675174180, -63.7554450849623000,
                                                            m_25MhzReal[3],
                                                            m_25MhzImag[3],
                                                            m_10MhzReal[3],
                                                            m_10MhzImag[3]);

                m_dhardValue[4] = CalculateHardnessValue(590.7925822212660000, 0.0000009470690063, 0.0247512155637817, 161.5695472040070000, 0.0000419385374007, -0.0930927711307803,
                                                          26.4063940305428000, 0.0001798303738185, 0.0462655534993658, -460.2842611065420000, 0.0318111134082847, -7.6689641627411200, 610.5998934209270000,
                                                            m_25MhzReal[4],
                                                            m_25MhzImag[4],
                                                            m_10MhzReal[4],
                                                            m_10MhzImag[4]);

                m_dhardValue[5] = CalculateHardnessValue(531.5598037645290000, -0.0000005910825346, -0.0035862110186896, 4.2866117136678700, 0.0000573569411294, -0.2317034891376540,
                                                          312.1941595093730000, 0.0002106354847714, 0.5390852072330090, 434.1537950954780000, 0.0059924707750264, -1.4424369695266200, 109.8438389353020000,
                                                            m_25MhzReal[5],
                                                            m_25MhzImag[5],
                                                            m_10MhzReal[5],
                                                            m_10MhzImag[5]);

                m_dhardValue[6] = CalculateHardnessValue(467.1671016488780000, -0.0000015309291814, -0.0240553235612617, -124.8498284550870000, -0.0002378364841416, 1.0499227839082200,
                                                          -1547.2173272956600000, -0.0004859677585936, -1.5166930312041200, -1576.7694154766100000, 0.0017036163646597, -0.3305366034585010, 22.6763877783943000,
                                                            m_25MhzReal[6],
                                                            m_25MhzImag[6],
                                                            m_10MhzReal[6],
                                                            m_10MhzImag[6]);

                m_dhardValue[7] = CalculateHardnessValue(-204.5948220070660000, -0.0000080819684009, -0.1126099539465590, -522.8094073702790000, 0.0000326698814422, -0.1643280538733100,
                                                          270.9419663543420000, 0.0006602714303081, 2.2475663194316100, 2541.0187527681800000, -0.0007662645079330, 0.2314506957187800, -24.2832294152971000,
                                                            m_25MhzReal[7],
                                                            m_25MhzImag[7],
                                                            m_10MhzReal[7],
                                                            m_10MhzImag[7]);

                m_dhardValue[8] = CalculateHardnessValue(568.5392441640500000, -0.0000035377647084, -0.0414302277007929, -159.6137935076620000, 0.0000454455774608, -0.1551449203629900,
                                                          175.8419953571760000, 0.0004184368666466, 1.1071437386647000, 963.2335192474690000, 0.0158031275206806, -3.5589101895367600, 262.1907371816380000,
                                                            m_25MhzReal[8],
                                                            m_25MhzImag[8],
                                                            m_10MhzReal[8],
                                                            m_10MhzImag[8]);

                m_dhardValue[9] = CalculateHardnessValue(-101.3717065918510000, -0.0000033929359137, -0.0298483047255472, -32.3666705875837000, -0.0000273584312211, 0.1043770443034260,
                                                          -109.6309495301820000, 0.0000413209191922, -0.0125383464921552, -220.1734278171370000, 0.1107847032543260, -12.6646401841493000, 474.0282460334500000,
                                                            m_25MhzReal[9],
                                                            m_25MhzImag[9],
                                                            m_10MhzReal[9],
                                                            m_10MhzImag[9]);

                for (int i = 0; i < m_chanelPerScanLine; ++i) {
                    m_repeateScanLines.ChanelData[i].push_back(m_dhardValue[i]);
                }

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

double MySerialPort::CalculateHardnessValue(double b0, double b1, double b2, double b3, double b4, double b5, double b6, double b7, double b8, double b9, double b10, double b11, double b12, double x1, double x2, double x3, double x4)
{
    double HardnessValue = b0
        + (b1 * qPow(x1, 3)) + (b2 * qPow(x1, 2)) + (b3 * x1)
        + (b4 * qPow(x2, 3)) + (b5 * qPow(x2, 2)) + (b6 * x2)
        + (b7 * qPow(x3, 3)) + (b8 * qPow(x3, 2)) + (b9 * x3)
        + (b10 * qPow(x4, 3)) + (b11 * qPow(x4, 2)) + (b12 * x4);


    return HardnessValue;
}


