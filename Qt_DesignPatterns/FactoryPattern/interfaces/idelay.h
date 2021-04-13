#ifndef IDELAY_H
#define IDELAY_H

#include <QObject>

class iDelay
{

public:

    virtual void delay(int ms) = 0;
    virtual bool isComplete() = 0;
    virtual ~iDelay() {} //This will annoy people
};


#endif // IDELAY_H
