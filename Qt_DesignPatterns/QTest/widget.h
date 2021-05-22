#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QtTest>
#include <QTest>

class Widget : public QObject
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);

    void setAge(int age);
signals:

private slots:
    void testFail();
    void testAge();
    void testAge_data();
    void testWidget();
private:
    int m_age;
};

#endif // WIDGET_H
