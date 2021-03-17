#include <QGuiApplication>
#include "appwrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    AppWrapper appwraper;

    if(!appwraper.initialize())
       QCoreApplication::exit(-1);;



    return app.exec();
}
