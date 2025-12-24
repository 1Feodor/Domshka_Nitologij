#include "recursion.h"

Recursion::Recursion(QObject *parent)
    : QObject{parent}
{
    client = new Http_Client(this);
    connect(client, &Http_Client::sig_errorString, this, [this]{startRecursion();});  //15
    connect(client, &Http_Client::sig_Finished, this, &Recursion::sig_StartParser);  //16

    beginStandard = begin = size = 0;
    end = 1;

    //if((idealThread = QThread::idealThreadCount()) <= 2) idealThread = 1;
    //else idealThread -= 2;
}

void Recursion::startRecursion(QList<QString> &config)  //11
{
    recursion = config.at(1).toInt();
    listOfLinks.clear();
    listOfLinks.append(config.at(0));
    recursionLinks();  //12
}

void Recursion::addToList(QList<QString> *replyList)
{
    for (auto var = replyList->begin(); var != replyList->end(); ++var)
    {
        if(!listOfLinks.contains(*var))
        {
            listOfLinks.append(*var);
        }
    }
}

bool Recursion::getParserFlag()
{
    return parserFlag;
}

void Recursion::recursionLinks()  //12
{
    if(begin >= size)
    {
        size = listOfLinks.size();
        if(recursion > end)
        {
            ++end;
        }
        else
        {
            parserFlag = false;
        }
    }

    if(begin < size)
    {
        client->getManager(&listOfLinks[begin]);  //13
        ++begin;
    }
    else
    {
        emit sig_ExitRecursion();  //10
    }
}

void Recursion::startRecursion()  //15
{
    ++beginStandard;

    if (beginStandard >= begin)
    {
        recursionLinks();  //12
    }
}
