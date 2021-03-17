#include <QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
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
    if(!mJokes.isEmpty())
    {
        mJokes.removeLast();
        resetModel();
    }
}

QStringList AppWrapper::jokes() const
{
    return mJokes;
}

void AppWrapper::setJokes(const QStringList &jokes)
{
    mJokes = jokes;
}

bool AppWrapper::initialize()
{

    mEngine.rootContext()->setContextProperty("Wrapper",this);
    resetModel();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    mEngine.load(url);
    if(mEngine.rootObjects().isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
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

           mJokes.append(joke);
           //qDebug() << joke;
       }
       if(array.size() != 0)
       {
         resetModel();

       }

       mDataBuffer->clear();

    }
}

void AppWrapper::resetModel()
{
    mEngine.rootContext()->setContextProperty("myModel",QVariant::fromValue(mJokes));
}
