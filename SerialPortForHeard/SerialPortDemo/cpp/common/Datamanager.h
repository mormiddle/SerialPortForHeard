#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QVector>
#include <QFile>
#include <QDataStream>
#include <QDateTime>
#include <QStringList>
#include <QObject>
#include <QVariant>
#include <QDir>
#include <QDebug>
#include "Globals.h"

class DataManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList fileNames READ fileNames NOTIFY fileNamesChanged)

public:
    explicit DataManager(QObject *parent = nullptr);
    QVariantList fileNames() const { return m_fileNames; }

public slots:
    void saveData();
    void saveDataToFile();
    void loadData(const QString &fileName);
    void loadExistingFiles();
    void saveClos();

signals:
    void fileNamesChanged();

private:
    QVariantList m_fileNames;
    QString dirPath = "D:/SacarLog";

};

#endif // DATAMANAGER_H
