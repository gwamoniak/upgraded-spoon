#ifndef SHORTDELAY_H
#define SHORTDELAY_H

#include <QObject>
#include <QThread>
#include "interfaces/idelay.h"

class ShortDelay : public QObject, public iDelay
{
    Q_OBJECT
public:
    explicit ShortDelay(QObject *parent = nullptr);

signals:


    // iDelay interface
public:
    void delay(int ms) override;
    bool isComplete() override;

private:
    bool m_complete;

};

#endif // SHORTDELAY_H
