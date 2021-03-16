#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent),
    mNetMenager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void AppWrapper::fetchPosts(const int number)
{

    //initialize our API data
    const QUrl API_ENDPOINT("http://api.icndb.com/jokes/random/"+QString::number(number));
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetMenager->get(request);
    connect(mNetReply,&QIODevice::readyRead,this,&AppWrapper::dataReadyRead);
    connect(mNetReply,&QNetworkReply::finished,this,&AppWrapper::dataReadFinished);

}

void AppWrapper::removeLast()
{

}

QStringList AppWrapper::jokes() const
{
    return mJokes;
}

void AppWrapper::setJokes(const QStringList &jokes)
{
    mJokes = jokes;
}

void AppWrapper::dataReadyRead()
{
    // add new jokes
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
{
    //parse the JSON
    if(mNetReply->error())
    {
        qWarning() << " There is an error: " << mNetReply->errorString();
    }
    else
    {
       QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
       QJsonObject data = doc.object();
       QJsonArray array = data["value"].toArray();
       for( auto i = 0; i < array.size(); i++)
       {
           QJsonObject object = array.at(i).toObject();
           QString joke = object["joke"].toString();
           qDebug() << joke;
       }

    }
}
