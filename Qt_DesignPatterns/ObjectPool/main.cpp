#include <QCoreApplication>
#include "Pools/mypool.h"
#include "Pools/mypoolitem.h"
#include "Interfaces/ipoolitem.h"


void useItems(MyPool &pool, int max)
{
    qInfo() << "Grabbing" << max << "items";

    QList<MyPoolItem*> items;

    for(int i = 0; i < max; i++)
    {
        MyPoolItem* item = static_cast<MyPoolItem*>(pool.aquire());
        items.append(item);
    }

    foreach (MyPoolItem* item, items)
    {
        item->test();
    }

    foreach (MyPoolItem* item, items)
    {
        pool.release(item);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyPool pool;
    useItems(pool,5);


    MyPoolItem* item = static_cast<MyPoolItem*>(pool.aquire());

    useItems(pool, 3);

    qInfo() << "Releasing a single item";
    pool.release(item);

    return a.exec();
}
