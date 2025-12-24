#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Http_Client : public QObject
{
    Q_OBJECT
public:
    explicit Http_Client(QObject *parent = nullptr);
    ~Http_Client();
    void getManager(QString*);

public slots:
    void replyFinished(QNetworkReply *reply);    // Слот обработки ответа о полученных данных

signals:
    void sig_Finished(QNetworkReply*);
    void sig_errorString();

private:
    QNetworkAccessManager *manager;
    QNetworkRequest *request;
    bool timeFlag = true;
    int fff = 0;  //udalit
};

#endif // HTTP_CLIENT_H
