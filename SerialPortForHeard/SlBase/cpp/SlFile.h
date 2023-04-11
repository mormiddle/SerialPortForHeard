#pragma once

#include "SlBase_global.h"
#include <QString>

class SLBASE_EXPORT SlFile
{
public:
    SlFile();
    ~SlFile();

protected:
    FILE* m_pFile = nullptr;

public:
    bool open(const QString& file, const QString& mode);
    FILE* getHandle();
    void close();

    int getSize();

    //begin from 0
    int getPos();
    bool setPos(int pos);

    bool read(void* pData, int bytes, int pos = -1);
    bool read(QByteArray& data, int bytes, int pos = -1);

    bool write(const void* pData, int bytes, int pos = -1);
    bool write(const QByteArray& data, int pos = -1);

public:
    static void test();
};


