#ifndef ADVANCEDFRIDGE_H
#define ADVANCEDFRIDGE_H

// Hybred object with both interfaces and inheritances

#include <QObject>
#include <QDebug>
#include "basicfridge.h"
#include "Interfaces/iRadio.h"

class AdvancedFridge : public BasicFridge
{
    Q_OBJECT
public:
    explicit AdvancedFridge(QObject *parent = nullptr);

    void deepFreeze();

    iRadio *radio() const;
    void setRadio(iRadio *radio);

signals:

private:
    iRadio *m_radio;

};

#endif // ADVANCEDFRIDGE_H
