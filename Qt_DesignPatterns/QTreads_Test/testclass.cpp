#include "testclass.h"

TestClass::TestClass(QObject *parent) : QThread(parent)
{
    qInfo()<< this << "Constructed on: " << QThread::currentThread();
}

TestClass::~TestClass()
{
    qInfo()<< this << "DeConstructed on:" << QThread::currentThread();
}

void TestClass::run()
{
    qInfo() << this << "Run on: " << QThread::currentThread();

    // do thread stuff here
    QThread::currentThread()->msleep(5000);

    qInfo() << this << "Finished on" << QThread::currentThread();
}
