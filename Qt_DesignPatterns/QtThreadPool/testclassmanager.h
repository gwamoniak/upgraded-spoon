#ifndef TESTCLASSMANAGER_H
#define TESTCLASSMANAGER_H

#include <QObject>
#include <QThreadPool>
#include <QRunnable>
#include "testclass.h"

class TestClassManager : public QObject
{
    Q_OBJECT
public:
    explicit TestClassManager(QObject *parent = nullptr);

    void run();

signals:

public slots:
    void started();
    void finished();
    void progress(int value); // return as parameter like value if dealing with Threads


};

#endif // TESTCLASSMANAGER_H
