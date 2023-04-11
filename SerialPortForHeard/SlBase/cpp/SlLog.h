#pragma once


#include "SlBase_global.h"
#include <QString>

class SLBASE_EXPORT SlLog
{
public:
    static QtMessageHandler getPrevMessageHandler();

    static bool init();
    static void reset();

    static void trace(const QString& file, int line, const QString& func, const QString& msg);
public:
    static bool purgeExpiredFiles();

public:
    static void test();
};

class SLBASE_EXPORT _SlLogFunc
{
public:
    _SlLogFunc(const QString& file, int line, const QString& func);
    ~_SlLogFunc(void);

public:
    double m_msEntry = {};

    QString m_file;
    int     m_line;
    QString m_func;

};

#define SlLog_logFunc()  _SlLogFunc _slf( __FILE__, __LINE__, __FUNCTION__ )

#define SlLog_trace( msg ) SlLog::trace( __FILE__, __LINE__, __FUNCTION__, (msg) )
