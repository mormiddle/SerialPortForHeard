#ifndef SLBASE_H
#define SLBASE_H

#include "SlBase_global.h"

#include "SlApp.h"
#include "SlLog.h"
#include "SlTime.h"
#include "SlIni.h"
#include "SlFile.h"

#include <QString>

class SLBASE_EXPORT SlBase
{
public:
    SlBase();

public:
    int add(int a, int b);
    QString getTime();

public:
    static QByteArray toByteArray(const uchar* pData, int bytes);
    static QByteArray toHex(const uchar* pData, int bytes, char separator = ' ');

};

#endif // SLBASE_H
