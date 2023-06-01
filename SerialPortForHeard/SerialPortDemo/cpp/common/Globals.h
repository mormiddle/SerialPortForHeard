#pragma once


#include <QVector>

extern  int m_chanelPerScanLine;

typedef QVector<int>			SINGAL_CHANEL_DATA;

typedef struct {
    int								cols = 0;
    int                             rows = 0;
    QVector<SINGAL_CHANEL_DATA>		ChanelData;
} SINGAL_SCAN_LINE;

extern SINGAL_SCAN_LINE             m_repeateScanLines;

//extern  QVector<SINGAL_SCAN_LINE>		m_repeateScanLines;
extern  int								m_repeateScanLineNum;
	
