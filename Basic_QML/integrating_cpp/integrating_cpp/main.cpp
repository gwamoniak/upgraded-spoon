#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "testclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    // Register way
    qmlRegisterType<TestClass>("Monty",1,0,"TestClass");


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // Context way
    //TestClass testClass;
    //QQmlContext * rootContext = engine.rootContext();
    //rootContext->setContextProperty("classA",&testClass);





    return app.exec();
}
