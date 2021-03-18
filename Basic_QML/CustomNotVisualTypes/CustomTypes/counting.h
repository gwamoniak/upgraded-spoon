#ifndef COUNTING_H
#define COUNTING_H

#include <QObject>

class Counting
{
    Q_GADGET

public:
 enum CountDirection{
   UP,
   DOWN
 };

 Q_ENUM(CountDirection)

private:
    Counting() = default;

};
typedef Counting::CountDirection CountingStatus ;

#endif // COUNTING_H
