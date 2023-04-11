#pragma once

#include "SlBase_global.h"
#include <QSettings>

class SLBASE_EXPORT SlIni
{
public:
    SlIni(const QString& file = NULL, QSettings::Format format = QSettings::IniFormat);
    ~SlIni();

protected:
    QSettings* m_pIni = NULL;

    QString m_file;
    QSettings::Format m_format;

public:
    QSettings* getHandle();
    QString getFile();

    //force flush
    void reopen();

    //向ini文件中写入键值对
    //section, key不能为汉字
    void setValue(const QString& section, const QString& key, const QString& val);
    void setValue(const QString& section, const QString& key, int val);
    void setValue(const QString& section, const QString& key, __int64 val);
    void setValue(const QString& section, const QString& key, float val);
    void setValue(const QString& section, const QString& key, double val);

    //从 INI 文件中获取指定的键值对应的值
    //section, key不能为汉字
    QString getString(const QString& section, const QString& key, const QString& vDefault = NULL, bool bAutoCreate = false);
    int getInt(const QString& section, const QString& key, int vDefault = 0, bool bAutoCreate = false);
    __int64 getInt64(const QString& section, const QString& key, __int64 vDefault = 0, bool bAutoCreate = false);
    float getFloat(const QString& section, const QString& key, float vDefault = 0, bool bAutoCreate = false);
    double getDouble(const QString& section, const QString& key, double vDefault = 0, bool bAutoCreate = false);

    static void test();

};


