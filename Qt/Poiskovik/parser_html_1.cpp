#include "parser_html_1.h"

parser_Html_1::parser_Html_1(QNetworkReply *reply)
{
    map = new QMap<QString, int>;
    listOfLinks = new QList<QString>;
    link = new QUrl(reply->url());
    replyHttp = new QString(reply->readAll());
    reply->deleteLater();
}

parser_Html_1::~parser_Html_1()
{
    delete map;
    delete listOfLinks;
    delete link;
    delete replyHttp;
}

void parser_Html_1::toWork(bool parserFlag)  //18
{
    if(parserFlag)lookForLinks();  //19
    deletingUnnecessary();  //20
    dataInMap();  //21
}

QString parser_Html_1::getLink()
{
    return link->url();
}

QMap<QString, int>* parser_Html_1::getWords()
{
    return map;
}

QList<QString> *parser_Html_1::getNewListLink()
{
    return listOfLinks;
}

void parser_Html_1::lookForLinks()  //19
{
    qsizetype j{ 0 };
    qsizetype jj;
    while ((j = replyHttp->indexOf("<a href=\"h", j)) != -1)
    {
        j += 9;

        if ((jj = replyHttp->indexOf("\"" , j)) != -1)
        {
            listOfLinks->append(replyHttp->mid(j, jj - j));
            j = jj;
        }
    }
}

void parser_Html_1::deletingUnnecessary()  //20
{
    qsizetype j{ 0 };
    qsizetype jj;
    while ((j = replyHttp->indexOf("<script>", j)) != -1)
    {
        if ((jj = replyHttp->indexOf("</script>" , j)) != -1)
        {
            replyHttp->replace(j, jj - j + 9, ' ');
        }
    }

    j = 0;

    while ((j = replyHttp->indexOf("<", j)) != -1)
    {
        if ((jj = replyHttp->indexOf(">" , j)) != -1)
        {
            replyHttp->replace(j, jj - j + 1, ' ');
        }
    }

    replyHttp->replace('\t', ' ').replace('\n', ' ');

    for (int i = 0; i < replyHttp->size(); ++i)
    {
        if ((*replyHttp)[i].isUpper())
        {
            (*replyHttp)[i] = (*replyHttp)[i].toLower();
        }
        else if (!((*replyHttp)[i].isLetter()))
        {
            (*replyHttp)[i] = ' ';
        }
    }

    j = 0;
    while ((j = replyHttp->indexOf(' ', j)) != -1)
    {
        if ((jj = replyHttp->indexOf(' ' , j + 1)) != -1)
        {
            if(jj - j <= 4 || jj - j >= 20) replyHttp->remove(j, jj - j);
            else j = jj;
        }
        else ++j;
    }
}

void parser_Html_1::dataInMap()  //21
{
    qsizetype j{ 0 };
    qsizetype jj;
    while ((j = replyHttp->indexOf(' ', j)) != -1)
    {
        if ((jj = replyHttp->indexOf(' ' , ++j)) != -1)
        {
            QString temp = replyHttp->mid(j, jj - j);
            if(map->contains(temp))
            {
                auto it = map->find(temp);
                ++it.value();
            }
            else
            {
                map->insert(temp, 1);
            }
        }
    }
    qDebug() << *link;      //удалить
    qDebug() << map->size();
}
