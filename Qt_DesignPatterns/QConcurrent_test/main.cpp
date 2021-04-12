#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QThread>
#include <QTextStream>
#include "filescanner.h"

// QConcurrent
// remeber to add QT += concurrent

QString getPath()
{
    QTextStream stream(stdin);

    qInfo() << "Enter the path please";
    QString value = stream.readLine();
    QFileInfo file(value);
    if(!file.exists())
    {
        qWarning() << "Not a valid path!";
        value.clear();

    }
    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QString path = getPath();
    while (path.isEmpty())
    {
        path = getPath();
    }

    qInfo() << path;
    FileScanner fileScanner;
    fileScanner.scan(path);

    return a.exec();
}
