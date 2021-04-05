#include <QCoreApplication>


// parent child memory management -Qt way

#include "testclass.h"


void createChildren(TestClass* parent, int count)
{
    if(!parent) return;

    qInfo() << "Creating children";

    for (auto i = 0; i < count ; i++ )
    {
        TestClass *child = new TestClass(parent); //heap
        child->setObjectName("Child: " + QString::number(i));
    }
}

void listChildren(TestClass *parent)
{
    if(!parent) return;
    qInfo() << "Listing children";

    foreach(QObject *obj, parent->children())
    {

        TestClass *child =qobject_cast<TestClass*>(obj);
        // test child
        qInfo() << child;
    }
}

void findChild(TestClass* parent, QString name)
{
    if(!parent) return;
    qInfo() << "Find a child";

    QList<QObject *> list = parent->findChildren<QObject*>(name);
    qInfo()<< "Found " << list.length();

    foreach(QObject *obj, list)
    {
        TestClass *child =qobject_cast<TestClass*>(obj);
        qInfo() << "Found: " << child;
    }


}

void testQt()
{
    TestClass parent(nullptr); //stack
    parent.setObjectName("parent");
    createChildren(&parent,5);
    listChildren(&parent);
    findChild(&parent,"Child: 3");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testQt();

    return a.exec();
}
