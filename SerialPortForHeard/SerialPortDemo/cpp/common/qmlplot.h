#ifndef QMLPLOT_H
#define QMLPLOT_H

#include <QtQuick>
#include "Globals.h"

class QCustomPlot;
class QCPAbstractPlottable;

class DDuiBasePlotItem : public QQuickPaintedItem
{
    Q_OBJECT
public:
    DDuiBasePlotItem( QQuickItem* parent = 0 );
    virtual ~DDuiBasePlotItem();
    void paint( QPainter* painter );
    virtual void initCustomPlotUI(){}

    QCustomPlot *getPlot();
protected:
    virtual void hoverMoveEvent(QHoverEvent *event);
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );
    virtual void wheelEvent( QWheelEvent *event );

    void routeMouseEvents( QMouseEvent* event );
    void routeWheelEvents( QWheelEvent* event );
public slots:
    void graphClicked( QCPAbstractPlottable* plottable );
    void onCustomReplot();
    void updateCustomPlotSize();
private:
    QCustomPlot*         m_CustomPlot;
};

class CustomPlotItem : public DDuiBasePlotItem
{
    Q_OBJECT
    Q_PROPERTY(int aisle READ aisle WRITE setAisle NOTIFY aisleChanged)
public:
    CustomPlotItem( QQuickItem* parent = 0 );
    virtual ~CustomPlotItem();
    Q_INVOKABLE void initCustomPlot();

    int aisle() const { return m_aisle; }

    void setAisle(int value) {
            if (m_aisle != value) {
                m_aisle = value;
                emit aisleChanged();
            }
        }

signals:
    void aisleChanged();

private:
    int m_aisle = 0;

protected:
    virtual void timerEvent(QTimerEvent *event);
private:
    int                  m_timerId;
};


class CustomPlotBarItem : public DDuiBasePlotItem
{
    Q_OBJECT
    Q_PROPERTY(QColor barColor READ barColor WRITE setBarColor NOTIFY barColorChanged)
public:
    CustomPlotBarItem( QQuickItem* parent = 0 );
    virtual ~CustomPlotBarItem();    
    Q_INVOKABLE void initCustomPlot();
    QColor barColor();
    void setBarColor(const QColor &color);
signals:
    void barColorChanged(const QColor &color);
private:
    QColor mBarColor{Qt::blue};
};

class CustomKLine : public DDuiBasePlotItem{
  Q_OBJECT
public:
    explicit CustomKLine(QQuickItem* parent = 0);
    Q_INVOKABLE void initCustomPlot();
};

//class CustomColorMap : public DDuiBasePlotItem{
//  Q_OBJECT
//public:
//    explicit CustomColorMap(QQuickItem* parent = 0);
//    Q_INVOKABLE void initCustomPlot();
//};

class CustomBarChart: public DDuiBasePlotItem
{
  Q_OBJECT
public:
    explicit CustomBarChart(QQuickItem *parent=0){}

    Q_INVOKABLE void iniCustomPlot();
};
#endif // QMLPLOT_H
