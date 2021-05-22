#include "widget.h"

Widget::Widget(QObject *parent) : QObject(parent)
{
    m_age = 0;
}

void Widget::setAge(int age)
{
    m_age = age;
}

void Widget::testFail()
{
    QFAIL("JUST FAILED!!");
}

void Widget::testAge()
{
    //if(!m_age) QFAIL("Age not set!");

    // later
    QFETCH(QString,name);
    QFETCH(int,age);

    qInfo() << "testing age..." << name << "is:" << age ;
    if(age < 1 || age > 100) QFAIL("Invalid age!");
    if(age < 18) QFAIL("Must be adult");


}

void Widget::testAge_data()
{
   qInfo() << "Generating data!!! ";

   QTest::addColumn<QString>("name");
   QTest::addColumn<int>("age");

   QTest::addRow("Invalid") << "Robert" << 156;
   QTest::addRow("Old") << "Helmut" << 75;
   QTest::addRow("Young") << "Bob" << 25;
   QTest::addRow("Under age") << "Sebastian" << 15;

   qInfo() << "Data Generated!!! ";

}

void Widget::testWidget()
{
    int age = 45;
    QVERIFY(m_age > 0 && m_age < 100);

    // warnings
    if(m_age > 40) QWARN("Age is over 40");
    if(m_age < 18) QFAIL("Must be adult");

    // compare
    QCOMPARE(m_age, age);
}
