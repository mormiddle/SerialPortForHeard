#include "SlBase.h"
#include <QDateTime>

SlBase::SlBase()
{
}

int SlBase::add(int a, int b)
{
    return  a + b;
}

QString SlBase::getTime()
{
    return SlTime::toString( QDateTime::currentDateTime(), true);
}

QByteArray SlBase::toByteArray(const uchar *pData, int bytes)
{
    return QByteArray( ( const char* ) pData, bytes );
}

QByteArray SlBase::toHex(const uchar *pData, int bytes, char separator)
{
    return QByteArray( (const char* ) pData, bytes ).toHex( separator);
}

