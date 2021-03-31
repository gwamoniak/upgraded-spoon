#include "bernarddog.h"

BernardDog::BernardDog(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

BernardDog::~BernardDog()
{
    qInfo() << this << "Destroyed";
}


void BernardDog::eat()
{
    qInfo() << this << "Eat";
}

void BernardDog::sleep()
{
    qInfo() << this << "Sleep";
}

void BernardDog::move()
{
    qInfo() << this << "Move";
}
