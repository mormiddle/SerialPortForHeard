#include "qmlplot.h"
#include "qcustomplot.h"
#include <QDebug>
DDuiBasePlotItem::DDuiBasePlotItem( QQuickItem* parent ) : QQuickPaintedItem( parent )
    , m_CustomPlot( new QCustomPlot() )
{
    setFlag( QQuickItem::ItemHasContents, true );
    setAcceptedMouseButtons( Qt::AllButtons );
    setAcceptHoverEvents(true);

    connect( this, &QQuickPaintedItem::widthChanged, this, &DDuiBasePlotItem::updateCustomPlotSize );
    connect( this, &QQuickPaintedItem::heightChanged, this, &DDuiBasePlotItem::updateCustomPlotSize );
}

DDuiBasePlotItem::~DDuiBasePlotItem()
{
    delete m_CustomPlot;
    m_CustomPlot = nullptr;
}

void DDuiBasePlotItem::paint( QPainter* painter )
{
    if (m_CustomPlot)
    {
        QPixmap    picture( boundingRect().size().toSize() );
        QCPPainter qcpPainter( &picture );

        m_CustomPlot->toPainter( &qcpPainter );

        painter->drawPixmap( QPoint(), picture );
    }
}

QCustomPlot *DDuiBasePlotItem::getPlot()
{
    if( !m_CustomPlot){
        m_CustomPlot = new QCustomPlot;
    }
    return m_CustomPlot;
}

void DDuiBasePlotItem::mousePressEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void DDuiBasePlotItem::mouseReleaseEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void DDuiBasePlotItem::mouseMoveEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void DDuiBasePlotItem::mouseDoubleClickEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void DDuiBasePlotItem::wheelEvent( QWheelEvent *event )
{
    routeWheelEvents( event );
}
void DDuiBasePlotItem::graphClicked( QCPAbstractPlottable* plottable )
{
    qDebug() << Q_FUNC_INFO << QString( "Clicked on graph '%1 " ).arg( plottable->name() );
}

void DDuiBasePlotItem::routeMouseEvents( QMouseEvent* event )
{
    if (m_CustomPlot)
    {
        QMouseEvent* newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );
        QCoreApplication::postEvent( m_CustomPlot, newEvent );
    }
}

void DDuiBasePlotItem::routeWheelEvents( QWheelEvent* event )
{
    if (m_CustomPlot)
    {
        QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
        QCoreApplication::postEvent( m_CustomPlot, newEvent );
    }
}

void DDuiBasePlotItem::hoverMoveEvent(QHoverEvent *event)
{
    //qDebug() << Q_FUNC_INFO<<event->pos();
}

void DDuiBasePlotItem::updateCustomPlotSize()
{
    if (m_CustomPlot)
    {
        m_CustomPlot->setGeometry(0, 0, (int)width(), (int)height());
        m_CustomPlot->setViewport(QRect(0, 0, (int)width(), (int)height()));
    }
}

void DDuiBasePlotItem::onCustomReplot()
{
    //qDebug() << Q_FUNC_INFO;
    update();
}
////
/// \brief CustomPlotItem::CustomPlotItem
/// \param parent
///
CustomPlotItem::CustomPlotItem( QQuickItem* parent ) : DDuiBasePlotItem( parent )
{
}

CustomPlotItem::~CustomPlotItem()
{
}

void CustomPlotItem::initCustomPlot()
{
    updateCustomPlotSize();
    getPlot()->addGraph();
    getPlot()->graph( 0 )->setPen( QPen( Qt::red ) );
    getPlot()->xAxis->setLabel( "t" );
    getPlot()->yAxis->setLabel( "S" );
    getPlot()->xAxis->setRange( 0, 100 );
    getPlot()->yAxis->setRange( 0, 5 );
    getPlot() ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom );

    //startTimer(500);

    connect( getPlot(), &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );

    getPlot()->replot();
}

void CustomPlotItem::setAisleValue(int value)
{
    m_aisle = value;
    emit aisleValueChanged(value);
    qDebug() << "aisle = " << m_aisle;
}


void CustomPlotItem::upAisleData()
{
//    static double t, U;
//    U = ((double)rand() / RAND_MAX) * 5;
//    getPlot()->graph(0)->addData(t, U);
//    //qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2").arg(t).arg(U);
//    t++;
//    getPlot()->replot();

    if( t < checkedData.count() )
    {
        U = checkedData[t][m_aisle];
        if( U > maxValue )
            maxValue = U;
        if( U < minValue )
            minValue = U;
        getPlot()->graph(0)->addData(t, U);
        t++;


        // 计算曲线的最大值和最小值
        if( t > 100 )
            getPlot()->xAxis->setRange( t-100, t);
        if( maxValue > minValue )
          getPlot()->yAxis->setRange(minValue - 10, maxValue + 10);


        getPlot()->replot();
    }

    qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2, count = %3").arg(t).arg(U).arg(checkedData.count());


}

void CustomPlotItem::saveData()
{

    QString filePath = QFileDialog::getSaveFileName(NULL, "保存文件", "", "文本文件 (*.txt);;所有文件 (*)");
    if (filePath.isEmpty()) {
        // 用户取消了选择
        return;
    }
    saveDataToTxt(checkedData, filePath);
    QMessageBox::information(NULL, tr("保存成功"), tr("数据已保存至文件: %1").arg(filePath));

//    QString filePath = "C:/data.txt";
    //    saveDataToTxt(checkedData, filePath);
}

void CustomPlotItem::clearData()
{
    checkedData.clear();
}

void CustomPlotItem::saveDataToTxt(const QVector<QVector<double> > &data, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing: " << filePath;
        return;
    }

    QTextStream out(&file);
    for (int i = 0; i < data.size(); i++) {
        out << QString::number(data[i][m_aisle]) << " ";
    }

    if (file.flush()) {
            // 成功
            QMessageBox::information(NULL, tr("保存成功"), tr("数据已保存至文件: %1").arg(filePath));
        } else {
            // 失败
            QMessageBox::warning(NULL, tr("保存失败"), tr("数据保存失败，请重试"));
        }

    file.close();
    qDebug() << "Data saved to file: " << filePath;


}




