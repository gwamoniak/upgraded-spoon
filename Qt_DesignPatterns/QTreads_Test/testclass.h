#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>
#include <QThread>

class TestClass : public QObject//public QThread
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);
    ~TestClass();


signals:
 void finished();
public:
    int value;
     int getValue() const;
    void setValue(int value);

public slots:
    void run();

protected:
    //void run() override;
};

#endif // TESTCLASS_H
