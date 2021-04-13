#include "longdelay.h"

LongDelay::LongDelay(QObject *parent) : QObject(parent)
{
    m_complete = false;
}


void LongDelay::delay(int ms)
{
    m_complete = false;
    m_timer.singleShot(ms,this,&LongDelay::timeout);

}

bool LongDelay::isComplete()
{
    return m_complete;
}

void LongDelay::timeout()
{
    m_complete = true;
}
