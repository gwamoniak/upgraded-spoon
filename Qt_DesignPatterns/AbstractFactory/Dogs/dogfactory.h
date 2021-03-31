#ifndef DOGFACTORY_H
#define DOGFACTORY_H

#include <QObject>
#include "housedog.h"
#include "boxerdog.h"
#include "bernarddog.h"
#include "Interfaces/iAnimalFactory.h"

class DogFactory : public QObject, public iAnimalFactory
{
    Q_OBJECT
public:
    explicit DogFactory(QObject *parent = nullptr);
    ~DogFactory() = default;

signals:


    // iAnimalFactory interface
public:
    iAnimal *createSmall() override;
    iAnimal *createMedium() override;
    iAnimal *createLarge() override;
};

#endif // DOGFACTORY_H
