#include "mypool.h"

MyPool::MyPool(QObject *parent) : QObject(parent)
{

}

MyPool::~MyPool()
{
    qDeleteAll(m_list); //redundant if we set the parent
    m_list.clear();
}

iPoolItem *MyPool::aquire()
{
    foreach(MyPoolItem* item, m_list)
    {
        if(item->aquired() == false)
        {
            item->setAquired(true);
            return item;
        }
    }

    MyPoolItem* item = new MyPoolItem(); //setting the parent will make that not thread friendly
    item->setAquired(true);
    m_list.append(item);
    return item;

}

void MyPool::release(iPoolItem *item)
{
    if(!item) return;
    item->reset();
}
