#include <QCoreApplication>

// Factory method
// Define an interfac for creating an object, but let subclasses

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QSharedPointer>
#include <QTextStream>
#include "interfaces/idelay.h"
#include "longdelay.h"
#include "shortdelay.h"

QSharedPointer<iDelay> spIdelay;
QSharedPointer<QTimer> timer;


void timeout()
{
    qInfo() << "Do what you like while we wait...";
    if(spIdelay->isComplete())
    {
        timer->stop();
        qInfo() << "Completed";
    }

}

iDelay* getDelay(int ms)
{
  if(ms < 100)
  {
      qInfo() << "Short delay here...";
      return new ShortDelay();
  }
  // longer than 100 ms
  qInfo() << " LoOng delay here";
  return new LongDelay();

}

int getTimeout()
{
   QTextStream stream(stdin);

    qInfo() << " Please enter number of milliseconds to delay: ";

    QString data = stream.readLine();

    bool ok;
    int value = data.toInt(&ok);
    if(ok) return value;

    return getTimeout();

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

     timer.reset(new QTimer);
     timer->setInterval(1000);
     QObject::connect(&a, &QCoreApplication::aboutToQuit,timer.data(),&QTimer::stop);
     QObject::connect(timer.data(),&QTimer::timeout, timeout);

     int value = getTimeout();
     spIdelay.reset(getDelay(value));
     timer->start();
     spIdelay->delay(value);

    return a.exec();
}
