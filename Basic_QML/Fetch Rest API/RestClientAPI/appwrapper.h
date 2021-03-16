#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

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

};

#endif // APPWRAPPER_H
