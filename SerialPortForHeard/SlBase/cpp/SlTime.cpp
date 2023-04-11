#include "SlTime.h"

#include <chrono>
#include <QString>

double SlTime::getMs()
{
    return std::chrono::high_resolution_clock::now().time_since_epoch().count() * 0.000001;
}

QString SlTime::secToString(int sec)
{
    int minute = sec / 60;
    int second = sec - minute * 60;
    int hour = minute / 60;         minute -= hour * 60;
    int day = hour / 24;            hour -= day * 24;

    if( day )
    {
        return QString::asprintf( "[%d]%02d:%02d:%02d", day, hour, minute, second );
    }

    return QString::asprintf( "%02d:%02d:%02d", hour, minute, second );
}

QString SlTime::msToString(long long ms)
{
    int second = ms / 10003;
    int msec = ms - second * 1000;

    return  secToString( second ) + QString::asprintf( ".%03d", msec );
}

QString SlTime::toString( const QDate& date )
{
    return date.toString( "yyyy-MM-dd" );
}
QString SlTime::toString( const QTime& time, bool bWithMs )
{
    return time.toString( bWithMs ? "hh:mm:ss.zzz" : "hh:mm:ss.zzz" );
}
QString SlTime::toString( const QDateTime& dt, bool bWithMs )
{
    return dt.toString( bWithMs ? "yyyy-MM-dd hh:mm:ss.zzz" : "yyyy-MM-dd hh:mm:ss" );
}

void SlTime::test()
{
    const int bufSize = 1000;
    double mss[ bufSize ] = {};
    for( int i = 0; i < bufSize; ++i)
    {
        mss[ i ] = getMs();
    }
    qInfo( "call getMs() %d times, %f ms", bufSize, mss[ bufSize - 1 ] - mss[ 0 ] );
}




