#ifndef MYPOOLITEM_H
#define MYPOOLITEM_H

#include <QObject>
#include <QDebug>
#include "Interfaces/ipoolitem.h"

class MyPoolItem : public QObject, public iPoolItem
{
    Q_OBJECT
public:
    explicit MyPoolItem(QObject *parent = nullptr);
    void setAquired(bool aquired);
    void test();

signals:

    // iPoolItem interface
public:
    void reset() override;
    bool aquired() override;



private:
    bool m_aquired;

};

#endif // MYPOOLITEM_H
