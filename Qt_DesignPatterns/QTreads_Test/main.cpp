#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QThread>
#include <QSharedPointer>
#include "testclass.h"


// java style thread inheritance

TestClass *thread;
QTimer *timer;

//void timeout()
//{
//    if(!thread) return;
//    if(!timer)  return;

//    if(thread->isRunning() == true && thread->isFinished() == false)
//    {
//        qInfo() << "Thread is running!";
//    }

//    if(thread->isRunning() == false && thread->isFinished() == true)
//    {
//        qInfo() << "Thread is finished!";
//        timer->stop();
//        thread->deleteLater();
//        timer->deleteLater();
//    }

//}

// move to thread option

QThread *threadMove;
TestClass *testclass;

void timeout2()
{
    if(!threadMove) return;
    if(!timer)  return;

    if(threadMove->isRunning() == true && threadMove->isFinished() == false)
    {
        qInfo() << "Thread is running!";
    }

    if(threadMove->isRunning() == false && threadMove->isFinished() == true)
    {
        qInfo() << "Thread is finished!";
        timer->stop();
        threadMove->deleteLater();
        timer->deleteLater();
        testclass->deleteLater();
    }

}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

// java style thread inheritance

//    thread = new TestClass(&a);
//    timer = new QTimer(&a);

//    thread->setObjectName("Child Thread");
//    timer->setInterval(1000);

//    QObject::connect(timer,&QTimer::timeout, timeout);
//    timer->start();
//    thread->start(); // QThread::start calls QThread::run()

//    // this will brake things, use carefully
//    thread->value = 55;

    // move Thread option
     QThread::currentThread()->setObjectName("Main Tread");
     threadMove = new QThread(&a);
     threadMove->setObjectName("Child thread");
     timer = new QTimer(&a);
     testclass = new TestClass(nullptr); // no parent

     QObject::connect(timer, &QTimer::timeout, timeout2); //Auto connection
     QObject::connect(threadMove, &QThread::started, testclass,&TestClass::run, Qt::QueuedConnection); //cross thread signal / slot
     QObject::connect(testclass, &TestClass::finished, threadMove,&QThread::quit, Qt::QueuedConnection); //cross thread signal / slot


     testclass->moveToThread(threadMove); //Will fail if there is a parent!
     timer->setInterval(1000);

     timer->start();
     threadMove->start(); //QThread::start calls QThread::run()

    return a.exec();
}
