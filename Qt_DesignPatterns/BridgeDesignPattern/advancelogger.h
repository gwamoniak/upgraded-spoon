#ifndef ADVANCELOGGER_H
#define ADVANCELOGGER_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include "Interface/iLogger.h"


class AdvanceLogger : public QObject, public iLogger
{
    Q_OBJECT
public:
    explicit AdvanceLogger(QObject *parent = nullptr);

signals:

    // iLogger interface
public:
    void write(QString message) override;

};

#endif // ADVANCELOGGER_H
