#ifndef PARSER_HTML_1_H
#define PARSER_HTML_1_H

#include <QObject>
#include <QNetworkReply>

class parser_Html_1 : public QObject
{
    Q_OBJECT
public:
    parser_Html_1(QNetworkReply *reply);
    ~parser_Html_1();
    void toWork(bool parserFlag);
    QString getLink();
    QMap<QString, int>* getWords();
    QList<QString>* getNewListLink();

private:
    void lookForLinks();
    void deletingUnnecessary();
    void dataInMap();

    QUrl *link;
    QString *replyHttp;
    QList<QString> *listOfLinks;
    QMap<QString, int> *map;
};

#endif // PARSER_HTML_1_H
