#include "boxerdog.h"

BoxerDog::BoxerDog(QObject *parent) : QObject(parent)
{
     qInfo() << this << "Created";
}

BoxerDog::~BoxerDog()
{
  qInfo() << this << "Destroyed";
}


void BoxerDog::eat()
{
     qInfo() << this << "Eat";
}

void BoxerDog::sleep()
{
     qInfo() << this << "Sleep";
}

void BoxerDog::move()
{
     qInfo() << this << "Move";
}
