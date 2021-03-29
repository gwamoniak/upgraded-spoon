#include <QCoreApplication>
#include "basicfridge.h"
#include "advancedfridge.h"
#include "basicradio.h"

//Don't repeat yourself
//The DRY principle is stated as "Every piece of knowledge must have a single
//, unambiguous, authoritative representation within a system"


void testBasic(BasicFridge * fridge)
{
    fridge->chill();
    fridge->freeze();

}


void testAdvance(AdvancedFridge * afridge)
{
    afridge->chill();
    afridge->freeze();
    afridge->deepFreeze();

    if(afridge->radio())
    {
        afridge->radio()->play();
        // listen to music for a while
        afridge->radio()->stop();
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    BasicFridge fridge;
    testBasic(&fridge);
    AdvancedFridge afridge;

    BasicRadio radio;
    afridge.setRadio(&radio);

    // test advance and basic functionality of advanced fridge
    testBasic(&afridge);
    testAdvance(&afridge);

    return a.exec();
}
