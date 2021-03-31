#include "housedog.h"

HouseDog::HouseDog(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Created";
}

HouseDog::~HouseDog()
{
    qInfo() << this << "Destroyed";
}


void HouseDog::eat()
{
    qInfo() << this << "Eat";
}

void HouseDog::sleep()
{
    qInfo() << this << "Sleep";
}

void HouseDog::move()
{
    qInfo() << this << "Move";
}
