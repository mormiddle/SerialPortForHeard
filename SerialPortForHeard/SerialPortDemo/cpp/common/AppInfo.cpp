#include "AppInfo.h"
#include "SlBase.h"
#include <QDir>



AppInfo *AppInfo::getInstance()
{
    static AppInfo* pObj = new AppInfo;

    return pObj;
}

QString AppInfo::getTitle()
{
    QString str;
    if( !m_file.isEmpty() )
    {
        QFileInfo fileInfo( m_file );
        str = "[" + fileInfo.fileName() + " , " + fileInfo.path() + "] ";
    }
    return str + SlApp::getAppName() + " V " +SlApp::getAppVersion();
}

QString AppInfo::getFile()
{
    return m_file;
}

void AppInfo::setFile(const QString &file)
{
    qInfo( "%s", file.toUtf8().data() );

    if( m_file != file)
    {
        m_file = file;

        emit titleChanged();
    }
}
