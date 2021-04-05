#include "testclass.h"

TestClass::TestClass(QObject *parent) : QObject(parent)
{
    qInfo()<< this << "Constructed";
}

TestClass::~TestClass()
{
   qInfo()<< this << "DeConstructed";
}
