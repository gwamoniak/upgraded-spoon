#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include "counter.h"
#include "errorlevel.h"
#include "counting.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<Counter>("com.upgraded_spoon",1,0,"Counter");

    qRegisterMetaType<ErrorStatus>("ErrorStatus");
    qmlRegisterUncreatableType<ErrorLevel>("error.upgraded_spoon",1,0,"ErrorStatus",
                                           "Cannot create ErroLevel in QML");

    qRegisterMetaType<CountingStatus>("CountingStatus");
    qmlRegisterUncreatableType<Counting>("com.upgraded_spoon",1,0,"CountingStatus",
                                           "Cannot create CountingStatus in QML");


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
