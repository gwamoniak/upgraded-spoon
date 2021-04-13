#ifndef LONGDELAY_H
#define LONGDELAY_H

#include <QObject>
#include <QTimer>
#include "interfaces/idelay.h"

class LongDelay : public QObject, public iDelay
{
    Q_OBJECT
public:
    explicit LongDelay(QObject *parent = nullptr);


    // iDelay interface
public:
    void delay(int ms) override;
    bool isComplete() override;

private slots:
    void timeout();

private:
    QTimer m_timer;
    bool m_complete;


signals:

};

#endif // LONGDELAY_H
