#ifndef HOUSEDOG_H
#define HOUSEDOG_H

#include <QObject>
#include "../

class HouseDog : public QObject
{
    Q_OBJECT
public:
    explicit HouseDog(QObject *parent = nullptr);

signals:

};

#endif // HOUSEDOG_H
