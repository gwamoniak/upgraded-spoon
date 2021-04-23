#include <QCoreApplication>


// template design pattern

#include <QDebug>
#include "testclass.h"



void addItem(QList<TestClass*> &list)
{
   list.append(new TestClass());
}

void removeItem(QList<TestClass*> &list, int index)
{
    if(index >= list.length()) return;
    TestClass* testclass = list.at(index);
    list.removeAt(index);
    delete testclass;
}

void fillList(QList<TestClass*> &list)
{
    for(int i = 0; i < 10; i++)
    {
      addItem(list);
    }
}

void printList(QList<TestClass*> &list)
{
    foreach (TestClass* testclass, list) {
        qInfo() << testclass;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<TestClass*> list;
    addItem(list);
    qInfo() << list.length();

    fillList(list);

    removeItem(list,4);
    printList(list);

    qDeleteAll(list);

    return a.exec();
}
