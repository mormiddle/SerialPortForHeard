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
    getPlot()->xAxis->setRange( 0, 10 );
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
        getPlot()->graph(0)->addData(t, U);
        t++;
        getPlot()->replot();
    }

    qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2").arg(t).arg(U);


}

///
/// \brief CustomPlotBarItem::CustomPlotBarItem
/// \param parent
///
CustomPlotBarItem::CustomPlotBarItem( QQuickItem* parent ) : DDuiBasePlotItem( parent )
{
}

CustomPlotBarItem::~CustomPlotBarItem()
{
}

void CustomPlotBarItem::initCustomPlot()
{
    updateCustomPlotSize();
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    // create and configure plottables:
    QCPGraph *graph1 = getPlot()->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 = getPlot()->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

    QCPBars *bars1 = new QCPBars(getPlot()->xAxis, getPlot()->yAxis);
    bars1->setWidth(9/(double)x3.size());
    bars1->setData(x3, y3);
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(10, 140, 70, 160));

    QCPBars *bars2 = new QCPBars(getPlot()->xAxis, getPlot()->yAxis);
    bars2->setWidth(9/(double)x4.size());
    bars2->setData(x4, y4);
    bars2->setPen(Qt::NoPen);
    bars2->setBrush(QColor(mBarColor));
    bars2->moveAbove(bars1);

    // move bars above graphs and grid below bars:
    getPlot()->addLayer("abovemain", getPlot()->layer("main"), QCustomPlot::limAbove);
    getPlot()->addLayer("belowmain", getPlot()->layer("main"), QCustomPlot::limBelow);
    graph1->setLayer("abovemain");
    getPlot()->xAxis->grid()->setLayer("belowmain");
    getPlot()->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    getPlot()->xAxis->setBasePen(QPen(Qt::white, 1));
    getPlot()->yAxis->setBasePen(QPen(Qt::white, 1));
    getPlot()->xAxis->setTickPen(QPen(Qt::white, 1));
    getPlot()->yAxis->setTickPen(QPen(Qt::white, 1));
    getPlot()->xAxis->setSubTickPen(QPen(Qt::white, 1));
    getPlot()->yAxis->setSubTickPen(QPen(Qt::white, 1));
    getPlot()->xAxis->setTickLabelColor(Qt::white);
    getPlot()->yAxis->setTickLabelColor(Qt::white);
    getPlot()->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    getPlot()->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    getPlot()->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    getPlot()->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    getPlot()->xAxis->grid()->setSubGridVisible(true);
    getPlot()->yAxis->grid()->setSubGridVisible(true);
    getPlot()->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    getPlot()->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    getPlot()->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    getPlot()->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    getPlot()->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    getPlot()->axisRect()->setBackground(axisRectGradient);

    getPlot()->rescaleAxes();
    getPlot()->yAxis->setRange(0, 2);

    connect( getPlot(), &QCustomPlot::afterReplot, this, &CustomPlotBarItem::onCustomReplot );

    getPlot()->replot();
}

QColor CustomPlotBarItem::barColor(){
    return mBarColor;
}

void CustomPlotBarItem::setBarColor(const QColor &color)
{
    mBarColor = color;
    if(getPlot()){
        getPlot()->replot();
    }
}
///////////////////////////////
/// \brief CustomKLine::CustomKLine
/// \param parent
///
CustomKLine::CustomKLine(QQuickItem *parent): DDuiBasePlotItem( parent )
{
  setFlag( QQuickItem::ItemHasContents, true );
  setAcceptedMouseButtons( Qt::AllButtons );

}

void CustomKLine::initCustomPlot()
{
    updateCustomPlotSize();
    QCustomPlot *plot = getPlot();
    plot->legend->setVisible(true);

    // generate two sets of random walk data (one for candlestick and one for ohlc chart):
    int n = 500;
    QVector<double> time(n), value1(n), value2(n);
    QDateTime start = QDateTime(QDate(2014, 6, 11));
    start.setTimeSpec(Qt::UTC);
    double startTime = start.toTime_t();
    double binSize = 3600*24; // bin data in 1 day intervals
    time[0] = startTime;
    value1[0] = 60;
    value2[0] = 20;
    qsrand(9);
    for (int i=1; i<n; ++i)
    {
      time[i] = startTime + 3600*i;
      value1[i] = value1[i-1] + (qrand()/(double)RAND_MAX-0.5)*10;
      value2[i] = value2[i-1] + (qrand()/(double)RAND_MAX-0.5)*3;
    }

    // create candlestick chart:
    QCPFinancial *candlesticks = new QCPFinancial(plot->xAxis, plot->yAxis);
    candlesticks->setName("Candlestick");
    candlesticks->setChartStyle(QCPFinancial::csCandlestick);
    candlesticks->data()->set(QCPFinancial::timeSeriesToOhlc(time, value1, binSize, startTime));
    candlesticks->setWidth(binSize*0.9);
    candlesticks->setTwoColored(true);
    candlesticks->setBrushPositive(QColor(245, 245, 245));
    candlesticks->setBrushNegative(QColor(40, 40, 40));
    candlesticks->setPenPositive(QPen(QColor(0, 0, 0)));
    candlesticks->setPenNegative(QPen(QColor(0, 0, 0)));

    // create ohlc chart:
    QCPFinancial *ohlc = new QCPFinancial(plot->xAxis, plot->yAxis);
    ohlc->setName("OHLC");
    ohlc->setChartStyle(QCPFinancial::csOhlc);
    ohlc->data()->set(QCPFinancial::timeSeriesToOhlc(time, value2, binSize/3.0, startTime)); // divide binSize by 3 just to make the ohlc bars a bit denser
    ohlc->setWidth(binSize*0.2);
    ohlc->setTwoColored(true);

    // create bottom axis rect for volume bar chart:
    QCPAxisRect *volumeAxisRect = new QCPAxisRect(plot);
    plot->plotLayout()->addElement(1, 0, volumeAxisRect);
    volumeAxisRect->setMaximumSize(QSize(QWIDGETSIZE_MAX, 100));
    volumeAxisRect->axis(QCPAxis::atBottom)->setLayer("axes");
    volumeAxisRect->axis(QCPAxis::atBottom)->grid()->setLayer("grid");
    // bring bottom and main axis rect closer together:
    plot->plotLayout()->setRowSpacing(0);
    volumeAxisRect->setAutoMargins(QCP::msLeft|QCP::msRight|QCP::msBottom);
    volumeAxisRect->setMargins(QMargins(0, 0, 0, 0));
    // create two bar plottables, for positive (green) and negative (red) volume bars:
    plot->setAutoAddPlottableToLegend(false);
    QCPBars *volumePos = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    QCPBars *volumeNeg = new QCPBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    for (int i=0; i<n/5; ++i)
    {
      int v = qrand()%20000+qrand()%20000+qrand()%20000-10000*3;
      (v < 0 ? volumeNeg : volumePos)->addData(startTime+3600*5.0*i, qAbs(v)); // add data to either volumeNeg or volumePos, depending on sign of v
    }
    volumePos->setWidth(3600*4);
    volumePos->setPen(Qt::NoPen);
    volumePos->setBrush(QColor(100, 180, 110));
    volumeNeg->setWidth(3600*4);
    volumeNeg->setPen(Qt::NoPen);
    volumeNeg->setBrush(QColor(180, 90, 90));

    // interconnect x axis ranges of main and bottom axis rects:
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), volumeAxisRect->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
    connect(volumeAxisRect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), plot->xAxis, SLOT(setRange(QCPRange)));
    // configure axes of both main and bottom axis rect:
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeSpec(Qt::UTC);
    dateTimeTicker->setDateTimeFormat("dd. MMMM");
    volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(dateTimeTicker);
    volumeAxisRect->axis(QCPAxis::atBottom)->setTickLabelRotation(15);
    plot->xAxis->setBasePen(Qt::NoPen);
    plot->xAxis->setTickLabels(false);
    plot->xAxis->setTicks(false); // only want vertical grid in main axis rect, so hide xAxis backbone, ticks, and labels
    plot->xAxis->setTicker(dateTimeTicker);
    plot->rescaleAxes();
    plot->xAxis->scaleRange(1.025, plot->xAxis->range().center());
    plot->yAxis->scaleRange(1.1, plot->yAxis->range().center());

    // make axis rects' left side line up:
    QCPMarginGroup *group = new QCPMarginGroup(plot);
    plot->axisRect()->setMarginGroup(QCP::msLeft|QCP::msRight, group);
    volumeAxisRect->setMarginGroup(QCP::msLeft|QCP::msRight, group);
}

//CustomColorMap::CustomColorMap(QQuickItem *parent): DDuiBasePlotItem( parent )
//{
//  setFlag( QQuickItem::ItemHasContents, true );
//  setAcceptedMouseButtons( Qt::AllButtons );
// }

//void CustomColorMap::initCustomPlot()
//{
//    updateCustomPlotSize();

//    QCustomPlot *plot = getPlot();
//    plot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
//    plot->axisRect()->setupFullAxesBox(true);
//    plot->xAxis->setLabel("x");
//    plot->yAxis->setLabel("y");

//    // set up the QCPColorMap:
//    QCPColorMap *colorMap = new QCPColorMap(plot->xAxis, plot->yAxis);
//    int nx = 200;
//    int ny = 200;
//    colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
//    colorMap->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions
//    // now we assign some data, by accessing the QCPColorMapData instance of the color map:
//    double x, y, z;
//    for (int xIndex=0; xIndex<nx; ++xIndex)
//    {
//      for (int yIndex=0; yIndex<ny; ++yIndex)
//      {
//        colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
//        double r = 3*qSqrt(x*x+y*y)+1e-2;
//        z = 2*x*(qCos(r+2)/r-qSin(r+2)/r); // the B field strength of dipole radiation (modulo physical constants)
//        colorMap->data()->setCell(xIndex, yIndex, z);
//      }
//    }

//    // add a color scale:
//    QCPColorScale *colorScale = new QCPColorScale(plot);
//    plot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
//    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
//    colorMap->setColorScale(colorScale); // associate the color map with the color scale
//    colorScale->axis()->setLabel("Magnetic Field Strength");

//    // set the color gradient of the color map to one of the presets:
//    colorMap->setGradient(QCPColorGradient::gpPolar);
//    // we could have also created a QCPColorGradient instance and added own colors to
//    // the gradient, see the documentation of QCPColorGradient for what's possible.

//    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
//    colorMap->rescaleDataRange();

//    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
//    QCPMarginGroup *marginGroup = new QCPMarginGroup(plot);
//    plot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
//    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

//    // rescale the key (x) and value (y) axes so the whole color map is visible:
//    plot->rescaleAxes();
//}

void CustomBarChart::iniCustomPlot()
{
    updateCustomPlotSize();
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));

    QCustomPlot *plot = getPlot();
    plot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(plot->xAxis, plot->yAxis);
    QCPBars *nuclear = new QCPBars(plot->xAxis, plot->yAxis);
    QCPBars *fossil = new QCPBars(plot->xAxis, plot->yAxis);
    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Fossil fuels");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    plot->xAxis->setTicker(textTicker);
    plot->xAxis->setTickLabelRotation(60);
    plot->xAxis->setSubTicks(false);
    plot->xAxis->setTickLength(0, 4);
    plot->xAxis->setRange(0, 8);
    plot->xAxis->setBasePen(QPen(Qt::white));
    plot->xAxis->setTickPen(QPen(Qt::white));
    plot->xAxis->grid()->setVisible(true);
    plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    plot->yAxis->setRange(0, 12.1);
    plot->yAxis->setPadding(5); // a bit more space to the left border
    plot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    plot->yAxis->setBasePen(QPen(Qt::white));
    plot->yAxis->setTickPen(QPen(Qt::white));
    plot->yAxis->setSubTickPen(QPen(Qt::white));
    plot->yAxis->grid()->setSubGridVisible(true);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setLabelColor(Qt::white);
    plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
    nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);

    // setup legend:
    plot->legend->setVisible(true);
    plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    plot->legend->setBrush(QColor(255, 255, 255, 100));
    plot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = qApp->font();
    legendFont.setPointSize(10);
    plot->legend->setFont(legendFont);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
