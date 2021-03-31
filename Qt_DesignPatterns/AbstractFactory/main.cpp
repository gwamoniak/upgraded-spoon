#include <QCoreApplication>
#include <QRandomGenerator>
#include "Dogs/dogfactory.h"
#include "Interfaces/iAnimal.h"

// example of Abstract Factory

void makeAnimals(QList<iAnimal*> &animals, int count)
{
   DogFactory factory;
   for (auto i = 0; i < count ; i++ )
   {
       iAnimal *animal;
       int value =QRandomGenerator::global()->bounded(0,3);

       switch (value)
       {
       case 0:
           animal = factory.createSmall();
           break;
        case 1:
           animal = factory.createMedium();
            break;
        case 2:
           animal = factory.createLarge();
           break;
       }
       animals.append(animal);

   }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<iAnimal*> animals;
    makeAnimals(animals,25);

    foreach (iAnimal* animal, animals) {
        animal->eat();
        animal->move();
        animal->sleep();

    }

    // clean up
    qDeleteAll(animals);
    animals.clear();

    return a.exec();
}
