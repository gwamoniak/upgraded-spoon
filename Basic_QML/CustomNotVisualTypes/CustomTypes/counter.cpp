#include <QDebug>
#include "counter.h"


// counting
Counter::Counter(QObject *parent) : QObject(parent),
    m_count(0),
    m_counting(Counting::CountDirection::DOWN),
    m_timer(new QTimer(this))
{
    m_timer->setInterval(500);
    connect(m_timer,&QTimer::timeout,[=](){
        if(m_counting == Counting::CountDirection::UP)
        {
            ++m_count;
        }
        else
        {
            --m_count;
        }
        emit countChanged(m_count);

    } );
}

int Counter::count() const
{
    return m_count;
}


void Counter::setCount(int count)
{
    if (m_count == count)
        return;

    m_count = count;
    emit countChanged(m_count);
}


void Counter::start()
{
    m_timer->start();
}

void Counter::stop()
{
    m_timer->stop();
}

Counting::CountDirection Counter::Counting() const
{
    return m_counting;
}

void Counter::setCounting(Counting::CountDirection Counting)
{
    if (m_counting == Counting)
        return;

    m_counting = Counting;
    emit CountingChanged(m_counting);
}
