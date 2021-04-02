#ifndef MYPOOL_H
#define MYPOOL_H

#include <QObject>

class MyPool : public QObject
{
    Q_OBJECT
public:
    explicit MyPool(QObject *parent = nullptr);

signals:

};

#endif // MYPOOL_H
