/***************************************************************
* 文件名称: 程序信息
* 文件功能: 获取程序的各种信息
* 文件说明：获取内容包括名称，版本，路径，数据路径，日志路径等等
***************************************************************/
#include "SlApp.h"
#include "SlLog.h"
#include "SlTime.h"

#include <QCoreApplication>
#include <QDir>

static double m_msAppInit = 0;

static QString m_appCodecName;
static QTextCodec* m_appCodec = NULL;

static QString m_appName;
static QString m_appVersion;
static QString m_appExeFile;

static QString m_appPath;
static QString m_appDataPath;
static QString m_appLogPath;

static QString m_appIniFile;

QString SlApp::getAppCodecName() { return m_appCodecName; }
QTextCodec* SlApp::getAppCodec() { return  m_appCodec; }

QString SlApp::getAppName() { return  m_appName; }
QString SlApp::getAppVersion() { return  m_appVersion; }
QString SlApp::getAppExeFile() { return  m_appExeFile; }

QString SlApp::getAppPath() { return  m_appPath; }
QString SlApp::getAppDataPath() { return m_appDataPath; }
QString SlApp::getAppLogPath() { return  m_appLogPath; }

QString SlApp::getAppIniFile() { return m_appIniFile; }

void SlApp::init(const QString &codecName, const QString &appVersion)
{
    if( !m_appName.isEmpty() )
    {
        return;
    }

    m_appCodecName = codecName;
    m_appCodec = QTextCodec::codecForName( m_appCodecName.toUtf8().data() );
    QTextCodec::setCodecForLocale( m_appCodec );

    SlLog::init();

    m_msAppInit = SlTime::getMs();

    m_appExeFile = QDir::fromNativeSeparators( QCoreApplication::applicationFilePath() );
    {
        QFileInfo fileInfo( m_appExeFile );
        m_appName = fileInfo.completeBaseName();
        m_appVersion = appVersion;
        m_appPath = fileInfo.path();
    }

    for( ; ; )
    {
        QFileInfo fileInfo( m_appPath);
        QString file = fileInfo.fileName().toLower();
        if( file == "debug"
            || file == "release"
            || file == "x64")
        {
            m_appPath = fileInfo.path();
            continue;
        }
        break;
    }
    m_appDataPath = m_appPath + "/Data";
    m_appLogPath = m_appPath + "/Log";

    m_appIniFile = m_appPath + "/" + m_appName + ".ini";

    QDir dir;
    dir.mkdir( m_appDataPath );
    dir.mkdir( m_appLogPath );

    qInfo("");
    qInfo("---- App Info ----");
    qInfo("%s V%s, compiled at %s", m_appName.toUtf8().data(), m_appVersion.toUtf8().data(), __TIMESTAMP__);
    qInfo("Exe file: %s", m_appExeFile.toUtf8().data() );
    qInfo("App path: %s", m_appPath.toUtf8().data() );
    qInfo("check chinese support: 012汉字abc");
    qInfo("---- %f, %s", m_msAppInit, SlTime::msToString( m_msAppInit ).toUtf8().data() );

}

void SlApp::exit(int ret)
{
    double ms = SlTime::getMs();

    qInfo("---- %f, %s, %s", ms, SlTime::msToString( ms ).toUtf8().data(),
          SlTime::msToString( ms - m_msAppInit ).toUtf8().data() );
    qInfo("app return: %d", ret);
    qInfo("---- App exit ----");
}



