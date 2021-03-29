#ifndef BASICRADIO_H
#define BASICRADIO_H

#include <QObject>
#include <QDebug>
#include "Interfaces/iRadio.h"

class BasicRadio : public QObject, public iRadio
{
    Q_OBJECT
public:
    explicit BasicRadio(QObject *parent = nullptr);

signals:


    // iRadio interface
public:
    void play() override;
    void stop() override;
};

#endif // BASICRADIO_H
