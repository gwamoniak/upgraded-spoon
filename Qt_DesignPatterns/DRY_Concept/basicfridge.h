#ifndef BASICFRIDGE_H
#define BASICFRIDGE_H

#include <QObject>
#include <QDebug>
#include "Interfaces/iFridge.h"

class BasicFridge : public QObject , public iFridge
{
    Q_OBJECT
public:
    explicit BasicFridge(QObject *parent = nullptr);

signals:


    // iFridge interface
public:
    void chill() override;
    void freeze() override;
};

#endif // BASICFRIDGE_H
