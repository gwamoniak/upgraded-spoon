#include "testclass.h"

TestClass::TestClass(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created on" << QThread::currentThread();
}

TestClass::~TestClass()
{
    qInfo() << this << "Destoyed on" << QThread::currentThread();
}

void TestClass::run()
{
    //What happens in the thread stays in the thread

    qInfo() << this << "Run on" << QThread::currentThread();

    emit started();

    //Do thread stuff here
    for(int i = 0; i < 10; i++)
    {
        int value = QRandomGenerator::global()->bounded(200);
        QThread::currentThread()->msleep(value);
        qInfo() << this << "Progress " << i << "on" << QThread::currentThread();
    }


    emit finished();


}
