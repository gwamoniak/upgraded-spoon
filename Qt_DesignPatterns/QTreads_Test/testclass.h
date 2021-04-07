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

public:
    int value;
    // QThread interface
    int getValue() const;
    void setValue(int value);

protected:
    void run() override;
};

#endif // TESTCLASS_H
