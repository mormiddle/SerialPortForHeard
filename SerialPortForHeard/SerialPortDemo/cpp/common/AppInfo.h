#ifndef APPINFO_H
#define APPINFO_H

#include <QObject>

class AppInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QString title READ getTitle NOTIFY titleChanged )

public:
    static AppInfo* getInstance();

public:
    QString getTitle();

    QString getFile();
    void setFile( const QString& file = nullptr);

private:
    QString m_file;

signals:
    void titleChanged();

};

#endif // APPINFO_H
