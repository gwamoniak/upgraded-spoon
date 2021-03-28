#include <QApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QRandomGenerator>
#include <QMap>
#include "dialog.h"

class Test
{

   public:
    explicit Test(){
        qInfo() << "Constructred";
    };


    ~Test(){qInfo() << "DeConstructred";} ;

    QString text() const;
    void setText(const QString &text);

private:
    QString  m_text;

};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog dialog;
    dialog.show();

    return a.exec();
}

QString Test::text() const
{
return m_text;
}

void Test::setText(const QString &text)
{
m_text = text;
}
