#include "testclassmanager.h"

TestClassManager::TestClassManager(QObject *parent) : QObject(parent)
{

}

void TestClassManager::run()
{
    qInfo() << "Max Threads: " << QThreadPool::globalInstance()->maxThreadCount();
        for(int  i = 0; i < 25; i++)
        {
            TestClass *testclass = new TestClass(nullptr); //no parent - on main thread
            testclass->setAutoDelete(false); // don't put true in other case "malloc_consolidate(): invalid chunk size" error

            testclass->setObjectName("TestClass: " + QString::number(i));

            connect(testclass,&TestClass::started,this, &TestClassManager::started,  Qt::QueuedConnection);
            connect(testclass,&TestClass::progress,this,&TestClassManager::progress, Qt::QueuedConnection);
            connect(testclass,&TestClass::finished,this,&TestClassManager::finished, Qt::QueuedConnection);

            QThreadPool::globalInstance()->start(testclass); //the apps global thread pool
        }


}

void TestClassManager::started()
{
    TestClass *testclass = qobject_cast<TestClass* >(sender());
    if(!testclass) return;

    // main thread
    qInfo() << testclass << "Started slot: " << QThread::currentThread();
}

void TestClassManager::finished()
{

    TestClass *testclass = qobject_cast<TestClass* >(sender());
    if(!testclass) return;

    // main thread
    qInfo() << testclass << "Finished slot: " << QThread::currentThread();

    // finished with our object
    testclass->deleteLater();

}

void TestClassManager::progress(int value)
{
    TestClass *testclass = qobject_cast<TestClass*>(sender());
    if(!testclass) return;

    //main thread
    qInfo() << testclass << "Progress slot" << value << QThread::currentThread();
}
