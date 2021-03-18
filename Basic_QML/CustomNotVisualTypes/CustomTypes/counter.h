#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QTimer>
#include "counting.h"

class Counter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    //Q_PROPERTY(bool up READ up WRITE setUp NOTIFY upChanged)
    Q_PROPERTY(Counting::CountDirection Counting READ Counting WRITE setCounting NOTIFY CountingChanged)




public:
    explicit Counter(QObject *parent = nullptr);
    ~Counter()= default;


    int count() const;


    void setCount(int count);

    // helper methods
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    Counting::CountDirection Counting() const;

public slots:
    void setCounting(Counting::CountDirection Counting);

signals:

    void countChanged(int count);
    //void upChanged(bool up);

    void CountingChanged(Counting::CountDirection Counting);

private:
    int m_count;    
    Counting::CountDirection m_counting;
    QTimer * m_timer;
};

#endif // COUNTER_H
