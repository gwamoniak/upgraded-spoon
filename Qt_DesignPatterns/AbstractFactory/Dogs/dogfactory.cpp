#include "dogfactory.h"

DogFactory::DogFactory(QObject *parent) : QObject(parent)
{

}


iAnimal *DogFactory::createSmall()
{
    return new HouseDog();
}

iAnimal *DogFactory::createMedium()
{
    return new BoxerDog();
}

iAnimal *DogFactory::createLarge()
{
    return new BernardDog();
}
