#include "http_client.h"

Http_Client::Http_Client(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
    request = new QNetworkRequest();

    connect(manager, &QNetworkAccessManager::finished, this, &Http_Client::replyFinished);
}

Http_Client::~Http_Client()
{
    delete request;
    delete manager;
}

void Http_Client::getManager(QString *link)
{
    request->setUrl(QUrl(*link));
    manager->get(*request);
    if(timeFlag)
    {
        manager->setTransferTimeout(500);
        timeFlag = false;
    }
}

void Http_Client::replyFinished(QNetworkReply *reply)
{
    if(reply->error())
    {
        emit sig_errorString();
        qDebug() << "ERROR";
        qDebug() << reply->errorString();
    } else
    {
        emit sig_Finished(reply);
    }
}
