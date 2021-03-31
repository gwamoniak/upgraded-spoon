#ifndef DOGFACTORY_H
#define DOGFACTORY_H

#include <QObject>
#include "housedog.h"
#include "boxerdog.h"



class DogFactory : public QObject
{
    Q_OBJECT
public:
    explicit DogFactory(QObject *parent = nullptr);

signals:

};

#endif // DOGFACTORY_H
