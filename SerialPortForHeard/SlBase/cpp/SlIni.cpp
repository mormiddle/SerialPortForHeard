#include "SlIni.h"
#include "SlApp.h"
#include "SlStr.h"



SlIni::SlIni(const QString &file, QSettings::Format format)
{
    m_file = file;
    if( m_file.isEmpty() )
    {
        m_file = SlApp::getAppIniFile();
    }
    m_format = format;

    reopen();
}

SlIni::~SlIni()
{
    SlDelete( m_pIni );
}

QSettings *SlIni::getHandle()
{
    return m_pIni;
}

QString SlIni::getFile()
{
    return m_file;
}

void SlIni::reopen()
{
    SlDelete( m_pIni );

    m_pIni = new QSettings( m_file, m_format );
    m_pIni->setIniCodec( SlApp::getAppCodec() );
}

void SlIni::setValue(const QString &section, const QString &key, const QString &val)
{
    m_pIni->setValue( section + "/" + key, val );
}
void SlIni::setValue(const QString &section, const QString &key, int val)
{
    m_pIni->setValue( section + "/" + key, val );
}
void SlIni::setValue(const QString &section, const QString &key, long long val)
{
    m_pIni->setValue( section + "/" + key, val );
}
void SlIni::setValue(const QString &section, const QString &key, float val)
{
    m_pIni->setValue( section + "/" + key, val );
}
void SlIni::setValue(const QString &section, const QString &key, double val)
{
    m_pIni->setValue( section + "/" + key, val );
}

QString SlIni::getString(const QString &section, const QString &key, const QString &vDefault, bool bAutoCreate)
{
    QVariant var = m_pIni->value( section + "/" + key );
    if( var.isValid() )
    {
        return var.toString();
    }

    if( bAutoCreate )
    {
        setValue( section, key, vDefault );
    }

    return vDefault;
}
int SlIni::getInt(const QString &section, const QString &key, int vDefault, bool bAutoCreate)
{
    QVariant var = m_pIni->value( section + "/" + key );
    if( var.isValid() )
    {
        return var.toInt();
    }

    if( bAutoCreate )
    {
        setValue( section, key, vDefault );
    }

    return vDefault;
}
long long SlIni::getInt64(const QString &section, const QString &key, long long vDefault, bool bAutoCreate)
{
    QVariant var = m_pIni->value( section + "/" + key );
    if( var.isValid() )
    {
        return var.toLongLong();
    }

    if( bAutoCreate )
    {
        setValue( section, key, vDefault );
    }

    return vDefault;
}
float SlIni::getFloat(const QString &section, const QString &key, float vDefault, bool bAutoCreate)
{
    QVariant var = m_pIni->value( section + "/" + key );
    if( var.isValid() )
    {
        return var.toFloat();
    }

    if( bAutoCreate )
    {
        setValue( section, key, vDefault );
    }

    return vDefault;
}
double SlIni::getDouble(const QString &section, const QString &key, double vDefault, bool bAutoCreate)
{
    QVariant var = m_pIni->value( section + "/" + key );
    if( var.isValid() )
    {
        return var.toDouble();
    }

    if( bAutoCreate )
    {
        setValue( section, key, vDefault );
    }

    return vDefault;
}

void SlIni::test()
{
    SlIni ini;

    ini.setValue( "Sec1", "Key1", "1-1" );
    ini.setValue( "Sec1", "Key2", "1-2" );

    ini.setValue( "Sec2", "Key1", "2-1,汉字" );
    ini.setValue( "Sec2", "Key2", "2-2,汉字" );

    ini.reopen();

    ini.setValue( "Sec3", "Key1", 1 );
    ini.setValue( "Sec3", "Key2", 12345678901234 );
    ini.setValue( "Sec3", "Key3", 12345678901234.5678901234f );
    ini.setValue( "Sec3", "Key4", 12345678901234567890.123456789 );

    qInfo( ini.getString( "Sec1", "Key1", "xxx" ).toUtf8().data() );
    qInfo( ini.getString( "Sec1", "Key2", "xxx" ).toUtf8().data() );

    qInfo( ini.getString( "Sec2", "Key1", "xxx" ).toUtf8().data() );
    qInfo( ini.getString( "Sec2", "Key2", "xxx" ).toUtf8().data() );

    qInfo( "%d", ini.getInt( "Sec3", "Key1" ) );
    qInfo( "%lld", ini.getInt64( "Sec3", "Key2" ) );
    qInfo( "%.16f", ini.getFloat( "Sec3", "Key3" ) );
    qInfo( "%.32f", ini.getDouble( "Sec3", "Key4" ) );
}

