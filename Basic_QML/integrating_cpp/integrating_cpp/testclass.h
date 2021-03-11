#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class TestClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged)

public:
    explicit TestClass(QObject *parent = nullptr);
    Q_INVOKABLE void blablaFunction();
    Q_INVOKABLE QString getSomeVar();
    QString someVar();

signals:
    void someVarChanged();

public slots:
    void callMe();
    void setSomeVar(QString);

   private:
    QString m_someVar;

};

#endif // TESTCLASS_H
