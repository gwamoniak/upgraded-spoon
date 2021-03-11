#include "testclass.h"
#include <QDebug>

TestClass::TestClass(QObject *parent) : QObject(parent), m_someVar("bla bla")
{
    qDebug() << "I have been created";
}

void TestClass::blablaFunction()
{
    qDebug() << "Blabla Function";
}

QString TestClass::getSomeVar()
{
    return m_someVar;
}

QString TestClass::someVar()
{
    return m_someVar;
}

void TestClass::callMe()
{
    qDebug() << "Great Call!";
}

void TestClass::setSomeVar(QString newVar)
{
    if(m_someVar != newVar)
    {
        m_someVar = newVar;
        emit someVarChanged();
    }

}
