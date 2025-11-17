#include "headingfile.h"
#include "ui_headingfile.h"

HeadingFile::HeadingFile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HeadingFile)
{
    ui->setupUi(this);
    msg = new QMessageBox(this);
    client = new Http_Client(this);
    parser = new parser_Html(this);

    if((idealThread = QThread::idealThreadCount()) <= 2)
    {
        idealThread = 1;
    }
    else
    {
        idealThread -= 2;
    }

    connect(this, &HeadingFile::sig_StatusConnectionINI, this, &HeadingFile::slot_ReceiveStatusConnectionToINI);
    connect(this, &HeadingFile::sig_LinksConnection, client, &Http_Client::getManager);
    connect(client, &Http_Client::sig_errorString, this, [this]{StartRecursion();});
    connect(client, &Http_Client::sig_Finished, parser, &parser_Html::slot_Parser_Html);
    connect(parser, &parser_Html::sig_ResultLinks, this, &HeadingFile::addToList);
    connect(parser, &parser_Html::sig_ResultParser, this, [this]{StartRecursion();});
}

HeadingFile::~HeadingFile()
{
    delete ui;
}

void HeadingFile::connectINI()
{
    auto conn = [&]{
        file.setFileName("configurations.ini");
        bool status{file.open(QIODevice::ReadOnly | QIODevice::Text)};
        emit sig_StatusConnectionINI(status);};

    QFuture<void> fut = QtConcurrent::run(conn);
}

void HeadingFile::addToList(QList<QString> replyList)
{
    listOfLinks += replyList;
    //StartRecursion();
}

void HeadingFile::slot_ReceiveStatusConnectionToINI(bool status)
{
    if (status)
    {
        config = QString(file.readAll()).split("\n", Qt::SkipEmptyParts);
        recursion = config[1].toInt();
        //ui->pB_Search->setEnabled(true);
        file.close();

        if(!config.isEmpty())
        {
            //ui->pB_Search->setEnabled(false);
            listOfLinks.clear();
            listOfLinks.append(config[0]);

            beginStandard = begin = end = size = 0;
            RecursionLinks();
        }
    }
    else
    {
        qDebug() << "ERROR_File";
        msg->setIcon(QMessageBox::Critical);
        msg->setInformativeText("<b>Ошибка подключения к configurations.ini</b>");
        msg->setText(file.errorString());
        msg->exec();
        file.close();
        this->close();
    }
}

void HeadingFile::RecursionLinks()
{
    if(recursion > end && begin >= size)
    {
        ++end;
    }
    else
    {
        parser->parserFlag = false;
    }

    size = listOfLinks.size();

    if(begin < size)
    {
        for (int var = 0; var < idealThread; ++var)
        {
            if(begin < size)
            {
                emit sig_LinksConnection(&listOfLinks[begin]);
                ++begin;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        QString result = QString::number(listOfLinks.size()) + '\n';
        result += QString::number(begin) + '\n';
        exitFlag = false;

        emit sig_Chekc();

        this->close();

        //emit sig_Rezult(result);
    }
}

void HeadingFile::StartRecursion()
{
    ++beginStandard;

    if (beginStandard >= begin)
    {
        auto recur = [&]{
            RecursionLinks();};
        QFuture<void> fut = QtConcurrent::run(recur);
    }
}

void HeadingFile::showEvent(QShowEvent *event)
{
    HeadingFile::connectINI();
}

void HeadingFile::closeEvent(QCloseEvent *event)
{
    if(exitFlag)
    {
        qApp->exit();
    }
}
