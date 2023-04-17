#include "slqmlcustomplot.h" 
#include <QDebug>

SlQmlCustomPlot::SlQmlCustomPlot( QQuickItem* parent) : QQuickPaintedItem( parent)
  , m_CustomPlot(new QCustomPlot())
{
    setFlag( QQuickItem::ItemHasContents, true );//绘制标志
    setAcceptedMouseButtons(Qt::AllButtons);
    setAcceptHoverEvents(true);


}

SlQmlCustomPlot::~SlQmlCustomPlot()
{
    delete m_CustomPlot;
    m_CustomPlot = nullptr;
}

/***************************************************************
* 函数名称:paint
* 函数功能:CustomPlot的绘图函数
* 参　  数: 无
* 返 回 值: 无
***************************************************************/
void SlQmlCustomPlot::paint(QPainter *painter)
{
    if(m_CustomPlot)
    {
        QPixmap picture(boundingRect().size().toSize());//使用当前对象的边界矩形大小
        QCPPainter qcpPainter(&picture);

        m_CustomPlot->toPainter( &qcpPainter );//将 qcustomplot绘制到QCPPainter中
                                               //将最终绘制好的内容添加到QPixmap中
        painter->drawPixmap(QPoint(), picture);

    }
}

/***************************************************************
* 函数名称:getPlot
* 函数功能:获取一个customplot指针
* 参　  数: 无
* 返 回 值: 无
***************************************************************/
QCustomPlot *SlQmlCustomPlot::getPlot()
{
    if( !m_CustomPlot){
        m_CustomPlot = new QCustomPlot;
    }
    return m_CustomPlot;
}

 void SlQmlCustomPlot::mousePressEvent(QMouseEvent *event)
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents(event);//将 事件转发给 customplot
 }

 void SlQmlCustomPlot::mouseReleaseEvent( QMouseEvent* event )
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );
 }

 void SlQmlCustomPlot::mouseMoveEvent( QMouseEvent* event )
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );
 }

 void SlQmlCustomPlot::mouseDoubleClickEvent( QMouseEvent* event )
 {
     qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );
 }

 void SlQmlCustomPlot::wheelEvent( QWheelEvent *event )
 {
     routeWheelEvents( event );
 }

 void SlQmlCustomPlot::graphClicked( QCPAbstractPlottable* plottable )
 {
     qDebug() << Q_FUNC_INFO << QString( "Clicked on graph '%1 " ).arg( plottable->name() );
 }

 void SlQmlCustomPlot::routeMouseEvents(QMouseEvent *event)
 {
     if(m_CustomPlot)
     {
         QMouseEvent* newEvent = new QMouseEvent(event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers());
         QCoreApplication::postEvent(m_CustomPlot, newEvent);//将指定的事件添加到事件队列中等待处理
     }
 }

 void SlQmlCustomPlot::routeWheelEvents( QWheelEvent* event )
 {
     if (m_CustomPlot)
     {
         QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
         QCoreApplication::postEvent( m_CustomPlot, newEvent );
     }
 }

 void SlQmlCustomPlot::hoverMoveEvent(QHoverEvent *event)
 {
     //qDebug() << Q_FUNC_INFO<<event->pos();
 }


 void SlQmlCustomPlot::updateCustomPlotSize()
 {
     if (m_CustomPlot)
     {
         m_CustomPlot->setGeometry(0, 0, (int)width(), (int)height());
         m_CustomPlot->setViewport(QRect(0, 0, (int)width(), (int)height()));
     }
 }

 void SlQmlCustomPlot::onCustomReplot()
 {
     //qDebug() << Q_FUNC_INFO;
     update();
 }



 QVector<double> SlQmlCustomPlot::labelPositions(const QVector<QString>& labels, double offset = 0)
 {
     QVector<double> result(labels.size());
     for (int i = 0; i < labels.size(); ++i)
         result[i] = i + offset;
     return result;
 }


///////////////////////////////
/// \brief CustomColorMap::CustomColorMap
/// \param parent
///
CustomColorMap::CustomColorMap(QQuickItem *parent) : SlQmlCustomPlot(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);
}

void CustomColorMap::initCustomPlot()
{
    updateCustomPlotSize();

    QCustomPlot *plot = getPlot();
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);//只有这样还无法触发缩放机制
    plot->axisRect()->setRangeDrag(Qt::Horizontal);
    plot->axisRect()->setRangeZoom(Qt::Horizontal);
    connect(plot, &QCustomPlot::afterReplot, this, &CustomColorMap::onCustomReplot);//要将重绘信号和重绘函数连接起来
    connect(plot, &QCustomPlot::mouseWheel, this, &CustomColorMap::onWidgetMouseWheel);

    heatmap = new QCPColorMap(plot->xAxis, plot->yAxis);  // 构造一个颜色图
    heatmap->data()->setSize(distance.size(), aisle.size());   // 设置颜色图数据维度，其内部维护着一个一维数组（一般表现为二维数组），这里可以理解为有多少个小方块
    heatmap->data()->setRange(QCPRange(0.5, distance.size() - 0.5), QCPRange(0.5, aisle.size() - 0.5));  // 颜色图在x、y轴上的范围

    // 设置轴的显示，这里使用文字轴，如果这部分还不会的请看 QCustomPlot之个性化外观（二）这章节
    QSharedPointer<QCPAxisTickerText> xTicker(new QCPAxisTickerText);
    QSharedPointer<QCPAxisTickerText> yTicker(new QCPAxisTickerText);
    xTicker->setTicks(labelPositions(distance, 0.5), distance);
    yTicker->setTicks(labelPositions(aisle, 0.5), aisle);
    xTicker->setSubTickCount(1);
    yTicker->setSubTickCount(1);
    plot->xAxis->setTicker(xTicker);
    plot->yAxis->setTicker(yTicker);
    plot->xAxis->grid()->setPen(Qt::NoPen);
    plot->yAxis->grid()->setPen(Qt::NoPen);
    plot->xAxis->grid()->setSubGridVisible(true);
    plot->yAxis->grid()->setSubGridVisible(true);
    plot->xAxis->setSubTicks(true);
    plot->yAxis->setSubTicks(true);
    plot->xAxis->setTickLength(0);
    plot->yAxis->setTickLength(0);
    plot->xAxis->setSubTickLength(6);
    plot->yAxis->setSubTickLength(6);
    plot->xAxis->setRange(0, distance.size());
    plot->yAxis->setRange(0, aisle.size());


    QCPColorScale* colorScale = new QCPColorScale(plot);  // 构造一个色条
    colorScale->setType(QCPAxis::atBottom);   // 水平显示
    plot->plotLayout()->addElement(1, 0, colorScale); // 在颜色图下面显示
    heatmap->setColorScale(colorScale);
    QCPColorGradient gradient;  // 色条使用的颜色渐变
    gradient.setColorStopAt(0.0, QColor("#f6efa6"));   // 设置色条开始时的颜色
    gradient.setColorStopAt(1.0, QColor("#bf444c"));  // 设置色条结束时的颜色
    heatmap->setGradient(gradient);
    //    colorMap->rescaleDataRange();        // 自动计算数据范围，数据范围决定了哪些数据值映射到QCPColorGradient的颜色渐变当中
    heatmap->setDataRange(QCPRange(0, 10));     // 为了保持与echart的例子一致，我们这里手动设置数据范围
    heatmap->setInterpolate(false);         // 为了显示小方块，我们禁用插值

    // 保持色条与轴矩形边距一致
    QCPMarginGroup* marginGroup = new QCPMarginGroup(plot);
    plot->axisRect()->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);
    colorScale->setMarginGroup(QCP::msLeft | QCP::msRight, marginGroup);

}


void CustomColorMap::myPlotData( QVector<QVector<double>>& myArray )
{
    //qDebug() << "pushbutton is clicked" << endl;

//    QCustomPlot* plot = getPlot();

//    heatmap->data()->setSize(distance.size(), aisle.size());   // 设置颜色图数据维度，其内部维护着一个一维数组（一般表现为二维数组），这里可以理解为有多少个小方块
//    heatmap->data()->setKeyRange(QCPRange(0.5, distance.size() - 0.5));
//    QSharedPointer<QCPAxisTickerText> xTicker(new QCPAxisTickerText);
//    xTicker->setTicks(labelPositions(distance, 0.5), distance);
//    xTicker->setSubTickCount(1);
//    plot->xAxis->setTicker(xTicker);
//    plot->xAxis->grid()->setPen(Qt::NoPen);
//    plot->xAxis->grid()->setSubGridVisible(true);
//    plot->xAxis->setSubTicks(true);
//    plot->xAxis->setTickLength(0);
//    plot->xAxis->setSubTickLength(6);
//    plot->xAxis->setRange(0, distance.size());

//    if( m_px < checkedData.count() )
//    {
//        for( int i = 0; i < m_px; ++i)
//        {
//            for( int j = 0; j < 10; ++j) {
//                int z = checkedData[m_px][j]  - 1300;
//                if (z)
//                    heatmap->data()->setCell(m_px - 1 - i, j, z);  // Change this line
//                else
//                    heatmap->data()->setAlpha(m_px -1 - i, j, 0); // Change this line

//                qDebug() << QString(" m_px = %1, i = %2, z = %3, count = %4").arg(m_px - 1 - i).arg(j).arg(z).arg(checkedData.count() );
//            }
//        }

//        ++m_px;
//        distance.append(QString::number(m_px));
//        updateXAxisSpacing();

//        onCustomReplot();

//    }
//    else {

//    }

    //qDebug() << "pushbutton is clicked" << endl;

    QCustomPlot* plot = getPlot();

    //造数据
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QCPColorMapData* mapData = heatmap->data();

    addCols( plot, heatmap, myArray );
    int keySize = mapData->keySize();
    int n = myArray.size();
    mapData->setKeyRange( QCPRange( 0.5, 0.5 + keySize ) );
    plot->xAxis->setRange( 0, n - 1 );

    update();

}

void CustomColorMap::addCols(QCustomPlot *plot, QCPColorMap *heatmap, QVector<QVector<double> > &array)
{
    QSharedPointer<QCPColorMapData> mapData(heatmap->data());
    int keySize = mapData->keySize();
    int valueSize = mapData->valueSize();

//    array.append( data );
    int cols = array[0].size();
    if ( keySize < cols )
    {
        keySize += 100;
        mapData->setKeySize( keySize + 1 );

        {
            QVector<double> positions;
            QVector<QString> labels;
            int skip = qMax( 1, cols / 20 );
            for ( int i = 0; i < cols; i += skip )
            {
                positions.append( i + 0.5 );
                labels.append( QString( i ) );
            }

            QSharedPointer<QCPAxisTickerText> xTicker( new QCPAxisTickerText );
            xTicker->setTicks( positions, labels );
            xTicker->setSubTickCount( 1 );
            plot->xAxis->setTicker( xTicker );
        }

        for ( int i = 0; i < cols; i++ )
        {
            QVector<qreal>& tmp = array[ i ];
            for ( int j = 0; j < valueSize; j++ )
            {
                mapData->setCell( i, j, tmp[ j ] );
            }
        }
    }
    else
    {
//        int i = cols - 1;
//        for ( int j = 0; j < valueSize; j++ )
//        {
//            mapData->setCell( i, j, data[ j ] );
//        }
    }
}

void CustomColorMap::updateXAxisSpacing()
{
    QCustomPlot* plot = getPlot();
    QVector<double> positions;
    QVector<QString> labels;
    int skip = qMax(1, distance.size() / m_visibleLabels);
    for (int i = 0; i < distance.size(); i += skip)
    {
        positions.append(i + 0.5);
        labels.append(distance.at(i));
    }

    QSharedPointer<QCPAxisTickerText> xTicker(new QCPAxisTickerText);
    xTicker->setTicks(positions, labels);
    xTicker->setSubTickCount(1);
    plot->xAxis->setTicker(xTicker);
}

void CustomColorMap::onWidgetMouseWheel(QWheelEvent* event)
{
    qDebug() << "onWidgetMouseWheel is running" << endl;
    QCustomPlot* plot = getPlot();
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;

    int newVisibleLabels = m_visibleLabels + numSteps; // Change the sign to +
    newVisibleLabels = qBound(1, newVisibleLabels, distance.size());

    if (newVisibleLabels != m_visibleLabels)
    {
        m_visibleLabels = newVisibleLabels;
        plot->xAxis->range();
        updateXAxisSpacing();
        plot->replot();
    }
}










