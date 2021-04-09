#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QThread>
#include <QRunnable>
#include <QDebug>
#include <QRandomGenerator>


class TestClass : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);
    ~TestClass();

signals:
    void started();
    void finished();
    void progress(int value);


public:
    void run() override;

};

#endif // TESTCLASS_H
