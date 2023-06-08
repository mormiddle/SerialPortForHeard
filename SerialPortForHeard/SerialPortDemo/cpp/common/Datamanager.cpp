#include "Datamanager.h"

DataManager::DataManager(QObject *parent) : QObject(parent)
{
    loadExistingFiles();
}

void DataManager::saveData()
{
    // 创建新的 SINGAL_SCAN_LINE 对象来存储分段后的数据
        m_saveScanLines.cols = m_repeateScanLines.cols;
        m_saveScanLines.repeateTimes = m_repeateScanLines.repeateTimes;

        // 确定最大分段大小，用于后续的填充
        int maxSegmentSize = 0;

        // 根据 repeateTimes 进行分段
        for (int i = 0; i < m_repeateScanLines.repeateTimes.size() - 1; i++) {
            // 获取当前段的开始和结束索引
            int startIndex = m_repeateScanLines.repeateTimes[i];
            int endIndex = m_repeateScanLines.repeateTimes[i + 1];

            // 检查索引是否超出 ChanelData 的范围
            if (startIndex < 0 || endIndex > m_repeateScanLines.ChanelData[0].size()) {
                qDebug() << "Index out of range!";
                return;
            }

            // 对每一段进行处理

            for (int j = 0; j < 10; j++) {
                // 如果是偶数段，则进行反转
                SINGAL_CHANEL_DATA segment;
                if (i % 2 == 1) {
                    for (int k = endIndex - 1; k >= startIndex; --k) {
                        segment.push_back(m_repeateScanLines.ChanelData[j][k]);
                    }
                }
                // 如果是奇数段，则直接添加
                else {
                    for (int k = startIndex; k < endIndex; ++k) {
                        segment.push_back(m_repeateScanLines.ChanelData[j][k]);
                    }
                }


                // 更新最大分段大小
                if (segment.size() > maxSegmentSize) {
                    maxSegmentSize = segment.size();
                }

                m_saveScanLines.ChanelData.push_back(segment);
            }


        }

        // 填充较短的分段，使其长度与最大分段相同
        for (auto& segment : m_saveScanLines.ChanelData) {
            while (segment.size() < maxSegmentSize) {
                segment.push_back(0);
            }
        }


}

void DataManager::saveDataToFile()
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy年MM月dd日hh时mm分");
    QString filename = QString("%1/%2.dat").arg(QDir::homePath(), timestamp);
    QFile file(filename);
       if (!file.open(QIODevice::WriteOnly)) {
           qWarning("Could not open file for writing");
           return;
       }

       QDataStream out(&file);
       out.setVersion(QDataStream::Qt_5_12);
       for (const auto& chanel : m_saveScanLines.ChanelData) {
           out << chanel;
       }

       file.close();
}

SINGAL_SCAN_LINE DataManager::loadData(const QString& path)
{
    SINGAL_SCAN_LINE scanLine;


    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Could not open file for reading");
        return scanLine;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_12);

    while (!in.atEnd()) {
        SINGAL_CHANEL_DATA chanel;
        in >> chanel;
        scanLine.ChanelData.push_back(chanel);
    }

    file.close();
    return scanLine;
}

void DataManager::loadExistingFiles()
{
   QDir dir("D:/EddyLog/");
   QStringList nameFilters;
   nameFilters << "*.dat";
   QFileInfoList files = dir.entryInfoList(nameFilters, QDir::Files);
   for (const QFileInfo &file : files)
   {
       QString fileName = file.baseName(); // 获取文件名，不包括后缀
       // 假设文件名的格式是 "{timestamp}_{dataType}"
       QStringList parts = fileName.split("_");
       if (parts.size() == 2)
       {
           m_fileNames.append(QVariantMap{{"fileName", parts[0]}, {"dataType", parts[1]}});
       }
   }
   emit fileNamesChanged();
}

void DataManager::saveClos()
{
    m_repeateScanLines.repeateTimes.push_back(m_repeateScanLines.cols);
}
