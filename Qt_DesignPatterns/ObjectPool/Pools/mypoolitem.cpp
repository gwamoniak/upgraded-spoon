#include "mypoolitem.h"

MyPoolItem::MyPoolItem(QObject *parent) : QObject(parent)
{
    m_aquired = false;
    qInfo() << this << "constructed";

}

void MyPoolItem::reset()
{
    m_aquired = false;
    qInfo() << this << "reset";
}

bool MyPoolItem::aquired()
{
    return m_aquired;
}

void MyPoolItem::setAquired(bool value)
{
    qInfo() << this << "aquired" << value;
    m_aquired = value;
}

void MyPoolItem::test()
{
    qInfo() << this << "test";
}
