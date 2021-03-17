#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);
    ~AppWrapper() = default;

    Q_INVOKABLE void fetchPosts(const int number);
    Q_INVOKABLE void removeLast();

    // geter and seter for jokes
    QStringList jokes() const;
    void setJokes(const QStringList &jokes);

    bool initialize();

signals:

public slots:

private slots:
    void dataReadyRead();
    void dataReadFinished();


private:
    QNetworkAccessManager * mNetMenager;
    QNetworkReply * mNetReply;
    QByteArray *mDataBuffer;
    QStringList mJokes;
    // dont need to initilize as it is on stack
    QQmlApplicationEngine mEngine;

    void resetModel();
};

#endif // APPWRAPPER_H
