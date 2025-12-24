#include "http_client.h"

Http_Client::Http_Client(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
    request = new QNetworkRequest();

    connect(manager, &QNetworkAccessManager::finished, this, &Http_Client::replyFinished);  //14
}

Http_Client::~Http_Client()
{
    delete request;
    delete manager;
}

void Http_Client::getManager(QString *link)  //13
{
    request->setUrl(QUrl(*link));
    manager->get(*request);
    if(timeFlag)
    {
        manager->setTransferTimeout(500);
        timeFlag = false;
    }
}

void Http_Client::replyFinished(QNetworkReply *reply)  //14
{
    if(reply->error())
    {
        qDebug() << "ERROR" << " " << fff++;
        qDebug() << reply->errorString();
        emit sig_errorString();  //15
    } else
    {
        emit sig_Finished(reply);  //16
    }
}
