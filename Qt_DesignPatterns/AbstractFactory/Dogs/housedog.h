#ifndef HOUSEDOG_H
#define HOUSEDOG_H

#include <QObject>
#include <QDebug>
#include "Interfaces/iAnimal.h"

class HouseDog : public QObject, public iAnimal
{
    Q_OBJECT
public:
    explicit HouseDog(QObject *parent = nullptr);
    ~HouseDog();

signals:


    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // HOUSEDOG_H
