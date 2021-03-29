#include "basicfridge.h"

BasicFridge::BasicFridge(QObject *parent) : QObject(parent)
{

}

void BasicFridge::chill()
{
    qInfo() << this << "Chilling the food";
}

void BasicFridge::freeze()
{
    qInfo() << this << "Freezing the food";
}
