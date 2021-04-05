#include <QCoreApplication>
#include <QList>
#include "testclass.h"

// memory leaks
// for dangling pointers try to use weak pointers


void fillList(QList<TestClass*> &list, int max)
{
    for (auto i = 0;i < max ;i++ )
    {
        TestClass *testClass = new TestClass(); // if not deleted memory leak
        testClass->setObjectName("Object name:" + QString::number(i));
        list.append(testClass);
    }
}

void demoLeak()
{
    qInfo() << "Making a leak";
    QList<TestClass*> list;
    fillList(list,5);

    list.clear(); // memory leak
}

void demoDanglingPointer()
{

    qInfo() << "Making a dangling pointer";
    QList<TestClass*> list;
    fillList(list,5);

    // Delete some memory
    delete list.at(2);// memory is gone

    qInfo() <<"?: " << list.length();
    foreach(TestClass * item, list)
    {
        qInfo() << item->objectName();
    }

}

void demoCorrect()
{

    qInfo() << "Making a correct way";
    QList<TestClass*> list;
    fillList(list,5);

    qDeleteAll(list); // free memory important !!!
    list.clear(); // removes the dangling pointers

    qInfo() <<"?: " << list.length();
    foreach(TestClass * item, list)
    {
        qInfo() << item->objectName();
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //demoLeak();
    //demoDanglingPointer(); // deadly
    demoCorrect();
    return a.exec();
}
