#ifndef BOXERDOG_H
#define BOXERDOG_H

#include <QObject>
#include <QDebug>
#include "../Interfaces/iAnimal.h"

class BoxerDog : public QObject, public iAnimal
{
    Q_OBJECT
public:
    explicit BoxerDog(QObject *parent = nullptr);
    ~BoxerDog();

signals:


    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // BOXERDOG_H
