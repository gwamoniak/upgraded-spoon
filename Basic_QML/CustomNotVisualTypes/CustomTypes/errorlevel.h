#ifndef ERRORLEVEL_H
#define ERRORLEVEL_H

#include <QObject>


// exposing enum in QML
class ErrorLevel
{

    Q_GADGET
public:
    enum ErrorValue{
        INFORMATION,
        WARNING,
        DEBUG,
        MESSAGE
    };

    Q_ENUM(ErrorValue)

private:
    ErrorLevel() = default;

};
typedef ErrorLevel::ErrorValue ErrorStatus ;

#endif // ERRORLEVEL_H
