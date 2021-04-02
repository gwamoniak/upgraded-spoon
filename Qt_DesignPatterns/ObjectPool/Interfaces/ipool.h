#ifndef IPOOL_H
#define IPOOL_H

#include "ipooIitem.h"

class iPool
{

public:

    virtual ~iPool() {}
    virtual iPoolItem* aquire() = 0;
    virtual void release(iPoolItem* item) = 0;


};

#endif // IPOOL_H

