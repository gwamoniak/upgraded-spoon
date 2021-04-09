#include <QCoreApplication>

#include "testclassmanager.h"



// QThreadpool example
//  Multiple threads automatically managed and reusable


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main thread");

    TestClassManager manager;
    manager.run();

    return a.exec();
}
