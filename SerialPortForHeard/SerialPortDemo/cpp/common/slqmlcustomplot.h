#ifndef SLQMLCUSTOMPLOT_H
#define SLQMLCUSTOMPLOT_H

#include <QtQuick>
#include "qcustomplot.h"
#include "Globals.h"
class QCustomPlot;
class QCPAbstractPlottable;     //一个抽象基类
                                //是 Qt 开源绘图库 QCustomPlot 中的一个关键类

class SlQmlCustomPlot : public QQuickPaintedItem
{
    Q_OBJECT
public:
    SlQmlCustomPlot(QQuickItem *parent = nullptr);
    virtual ~SlQmlCustomPlot();
    void paint( QPainter* painter );
    virtual void initCustomPlotUI(){}

    QVector<double> labelPositions(const QVector<QString>& labels, double offset);

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
public:
    QCPColorMap* heatmap;
    int m_px = 0;
    int m_py = 0;
    QVector<QString> distance ;
    QVector<QString> aisle = { "通道1", "通道2", "通道3","通道4", "通道5",
                            "通道6", "通道7", "通道8", "通道9", "通道10" };
    //QVector<QVector<double>> myArray;
    int m_psetupPlot = 0;
    int m_visibleLabels = 20;//x轴可见范围
    int m_minSpacing = 1;
private:
    QCustomPlot* m_CustomPlot;
};

class CustomColorMap : public SlQmlCustomPlot{
  Q_OBJECT
public:
    explicit CustomColorMap(QQuickItem* parent = nullptr);
    Q_INVOKABLE void initCustomPlot();
    Q_INVOKABLE void myPlotData();
    void updateXAxisSpacing();
    void onWidgetMouseWheel(QWheelEvent* event);//设置滚轮所发和拖拽
};

#endif // SLQMLCUSTOMPLOT_H
