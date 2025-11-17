#ifndef PARSER_HTML_H
#define PARSER_HTML_H

#include <QObject>
#include <QNetworkReply>
#include <QtConcurrent>
#include <QFile>

class parser_Html : public QObject
{
    Q_OBJECT
public:
    explicit parser_Html(QObject *parent = nullptr);

    bool parserFlag = true;

public slots:
    void slot_Parser_Html(QNetworkReply *reply);    // Слот обработки ответа о полученных данных

signals:
    void sig_ResultLinks(QList<QString>);
    void sig_ResultParser();

private:
    QString replyQString(QNetworkReply *reply);
    QString lookForLinks(QString);
    QString deletingUnnecessary(QString);

    QFile fileLog;
    QFile fileLog2;
};

#endif // PARSER_HTML_H
