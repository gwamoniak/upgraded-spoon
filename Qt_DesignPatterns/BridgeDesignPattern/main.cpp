#include <QCoreApplication>


// bridge desing pattenr

#include "Interface/iLogger.h"

#include "simplelogger.h"
#include "advancelogger.h"

void log(iLogger * logger)
{
    for (auto i = 0; i < 5 ; i++ ) {
        logger->write("ithem" + QString::number(i));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SimpleLogger slog;
    AdvanceLogger alog;

        //log(&slog);
        log(&alog);

    return a.exec();
}
