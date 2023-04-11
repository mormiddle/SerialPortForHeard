#pragma once

#include "SlBase_global.h"
#include <QDateTime>

class SLBASE_EXPORT SlTime
{
public:
    //since system start
    static double getMs();

    //[day]hh:mm:ss:zzz
    static QString secToString( int sec );
    static QString msToString( __int64 ms );

    //yyyy-MM-dd hh:mm:ss.zzz
    static QString toString( const QDate& date );
    static QString toString( const QTime& time, bool bWithMs = false );
    static QString toString( const QDateTime& dt, bool bWithMs = false );

    static void test();
};


