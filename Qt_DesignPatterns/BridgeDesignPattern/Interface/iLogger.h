#ifndef ILOGGER_H
#define ILOGGER_H


#include <QString>
#include <QDebug>

class iLogger
{
public:
    iLogger() = default;
    virtual ~iLogger() = default;
    virtual void write (QString message) = 0;
};
#endif // ILOGGER_H
