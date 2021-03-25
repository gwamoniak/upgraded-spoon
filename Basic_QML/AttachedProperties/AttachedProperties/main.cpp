#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "timer.h"
#include "timerattached.h"
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<TimerAttached>(); // cannot create instance
    qmlRegisterType<Timer>("Timing",1,0,"Timer");
    qmlRegisterType<Person>("People",1,0,"Person");

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
