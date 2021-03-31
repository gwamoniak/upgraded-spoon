#ifndef BERNARDDOG_H
#define BERNARDDOG_H

#include <QObject>
#include <QDebug>
#include "../Interfaces/iAnimal.h"

class BernardDog : public QObject, public iAnimal
{
    Q_OBJECT
public:
    explicit BernardDog(QObject *parent = nullptr);
    ~BernardDog();

signals:


    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // BERNARDDOG_H
