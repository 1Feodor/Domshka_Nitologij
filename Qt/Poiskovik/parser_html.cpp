#include "parser_html.h"

parser_Html::parser_Html(QObject *parent)
    : QObject{parent}
{
    fileLog.setFileName("fileLOG.txt");
    fileLog2.setFileName("fileLOG2.txt");
}

void parser_Html::slot_Parser_Html(QNetworkReply *reply)
{
    auto replyThread = [&]{return replyQString(reply);};
    auto linksThread = [&](QString res){return lookForLinks(res);};
    auto deletingThread = [&](QString res){deletingUnnecessary(res);};

    if(parserFlag)
    {
        QFuture<void> fut1 = QtConcurrent::run(replyThread).then(linksThread).then(deletingThread);
    }
    else
    {
        QFuture<void> fut1 = QtConcurrent::run(replyThread).then(deletingThread);
    }
}

QString parser_Html::replyQString(QNetworkReply *reply)
{
    QString data = reply->readAll();
    reply->deleteLater();
    return data;
}

QString parser_Html::lookForLinks(QString data)
{
    QList<QString> listOfLinks;

    //if(fileLog.open(QFile::WriteOnly))
    {
        //fileLog.write(data.toUtf8());
        //fileLog.close();
    }

    int arr{0};
    qDebug() << data.size();

    qsizetype j = 0;
    qsizetype jj;
    while ((j = data.indexOf("<a href=\"h", j)) != -1)
    {
        j += 9;

        if ((jj = data.indexOf("\"" , j)) != -1)
        {
            listOfLinks.append(data.mid(j, jj - j));
            j = jj;
            ++arr;
        }
    }
    qDebug() << "ERRORrrrrrrrrrr" << arr;

    emit sig_ResultLinks(listOfLinks);
    return data;
}

QString parser_Html::deletingUnnecessary(QString data)
{
    qsizetype j = 0;
    qsizetype jj;
    while ((j = data.indexOf("<script>", j)) != -1)
    {
        if ((jj = data.indexOf("</script>" , j)) != -1)
        {
            data.replace(j, jj - j + 9, ' ');
        }
    }

    j = 0;

    while ((j = data.indexOf("<", j)) != -1)
    {
        if ((jj = data.indexOf(">" , j)) != -1)
        {
            data.replace(j, jj - j + 1, ' ');
        }
    }

    data.replace('\t', ' ').replace('\n', ' ');

    j = 0;
    while ((j = data.indexOf(' ', j)) != -1)
    {
        if ((jj = data.indexOf(' ' , j + 1)) != -1)
        {
            if(jj - j <= 4 || jj - j >= 20) data.remove(j, jj - j);
            else j = jj;
        }
        else ++j;
    }

    for (int i = 0; i < data.size(); ++i)
        if ((data[i] >= (char)33 && data[i] <= (char)64) || data[i] == (char)171 || data[i] == (char)187)
            data[i] = ' ';

    j = 0;
    while ((j = data.indexOf(' ', j)) != -1)
    {
        if ((jj = data.indexOf(' ' , j + 1)) != -1)
        {
            if(jj - j <= 4) data.remove(j, jj - j);
            else j = jj;
        }
        else ++j;
    }

    data = data.toLower();

    qDebug() << data.size();

    if(fileLog2.open(QFile::WriteOnly))
    {
        fileLog2.write(data.toUtf8());
        fileLog2.close();
    }
    emit sig_ResultParser();
    return data;
}
