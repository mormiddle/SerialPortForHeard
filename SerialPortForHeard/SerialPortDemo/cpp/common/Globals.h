#pragma once


#include <QVector>

extern  int m_chanelPerScanLine;

typedef QVector<int>			SINGAL_CHANEL_DATA;

typedef struct {
	int								cols;
    QVector<SINGAL_CHANEL_DATA>		tenChanelData;
} SINGAL_SCAN_LINE;

extern  QVector<SINGAL_SCAN_LINE>		m_repeateScanLines;
extern  int								m_currScanLine;
	
