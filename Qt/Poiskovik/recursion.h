#ifndef RECURSION_H
#define RECURSION_H

#include <QObject>
#include <QThread>
#include "http_client.h"

class Recursion : public QObject
{
    Q_OBJECT
public:
    explicit Recursion(QObject *parent = nullptr);
    void startRecursion(QList<QString> &config);

    void addToList(QList<QString>*);
    bool getParserFlag();
    void startRecursion();

signals:
    void sig_ExitRecursion();
    void sig_StartParser(QNetworkReply *reply);

private:
    Http_Client *client;
    QList<QString> listOfLinks;
    int recursion;
    int begin = 0;
    int beginStandard = 0;
    int size = 0;
    int end = 0;
    //int idealThread;
    bool parserFlag = true;
    void recursionLinks();
};

#endif // RECURSION_H
