#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QThread>
#include <QSharedPointer>
#include "testclass.h"


// java style thread inheritance

TestClass *thread;
QTimer *timer;

void timeout()
{
    if(!thread) return;
    if(!timer)  return;

    if(thread->isRunning() == true && thread->isFinished() == false)
    {
        qInfo() << "Thread is running!";
    }

    if(thread->isRunning() == false && thread->isFinished() == true)
    {
        qInfo() << "Thread is finished!";
        timer->stop();
        thread->deleteLater();
        timer->deleteLater();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread = new TestClass(&a);
    timer = new QTimer(&a);

    thread->setObjectName("Child Thread");
    timer->setInterval(1000);

    QObject::connect(timer,&QTimer::timeout, timeout);
    timer->start();
    thread->start(); // QThread::start calls QThread::run()

    // this will brake things
    thread->value = 55;

    return a.exec();
}
