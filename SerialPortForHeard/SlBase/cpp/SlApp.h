#pragma once

#include "SlBase_global.h"
#include <QTextCodec>

class SLBASE_EXPORT SlApp
{
public:
    static QString getAppCodecName();
    static QTextCodec* getAppCodec();

    static QString getAppName();
    static QString getAppVersion();
    static QString getAppExeFile();

    static QString getAppPath();
    static QString getAppDataPath();
    static QString getAppLogPath();

    static QString getAppIniFile();

    static void init(const QString& codecName, const QString& appVersion);
    static void exit(int ret);
};

