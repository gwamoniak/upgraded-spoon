#include "shortdelay.h"

ShortDelay::ShortDelay(QObject *parent) : QObject(parent)
{
    m_complete = false;
}


void ShortDelay::delay(int ms)
{
    m_complete = false;
    QThread::currentThread()->msleep(ms);
    m_complete = true;
}

bool ShortDelay::isComplete()
{
    return m_complete;
}
