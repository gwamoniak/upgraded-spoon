#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>
#include <QThread>

class TestClass : public QThread
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);
    ~TestClass();

signals:


    // QThread interface
protected:
    void run() override;
};

#endif // TESTCLASS_H
