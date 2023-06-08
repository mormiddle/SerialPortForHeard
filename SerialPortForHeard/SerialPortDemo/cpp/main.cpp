#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSurfaceFormat>

#include "common/AppInfo.h"
#include "common/SwitchPage.h"
#include "common/MySerialport.h"
#include "common/slqmlcustomplot.h"
#include "common/Datamanager.h"

#include "SlBase.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    // antialiasing for shapes
    QSurfaceFormat format;
    format.setSamples( 8 );
    QSurfaceFormat::setDefaultFormat( format );

    //SlApp init
    SlApp::init( "UTF-8", "1.0.0.0" );
    SlLog::purgeExpiredFiles();

    //tets
//    if( 1 )
//    {
//        SlLog_logFunc();
//        SlLog_trace( "012汉字abc ");

//        SlLog::test();
//        SlTime::test();
//        SlIni::test();

//        //SlBase
//        {
//            SlBase slb;
//            qDebug( "SlBase::add( 3 + 4 ) = %d", slb.add(3, 4) );
//            qDebug( "SlBase::getTime() = %s", slb.getTime().toUtf8().data() );
//        }
//    }

    //engine
    QQmlApplicationEngine engine;
    {
        qmlRegisterType<SwitchPage>( "SerialPortDemo.SWitchpage", 1, 0, "TypePage");
        qmlRegisterType<MySerialPort>("MySerialPort", 1, 0, "SerialPort");
        qmlRegisterType<CustomColorMap>("CustomPlot", 1, 0, "CustomColorMap");
        qmlRegisterType<DataManager>("DataManager", 1, 0, "DataManager");
        qRegisterMetaType<SwitchPage::SWITCH_PAGE>( "SWITCH_PAGE" );

        QQmlContext* pContext = engine.rootContext();
        pContext->setContextProperty( "pAppInfo", AppInfo::getInstance() );
        pContext->setContextProperty( "pSwitchPage", new SwitchPage );


    }
    const QUrl url(SwitchPage::getPathQml(SwitchPage::SWITCH_PAGE::PAGE_MAIN) );
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // exec
    int ret = app.exec();
    SlApp::exit( ret );
    return ret;
}
