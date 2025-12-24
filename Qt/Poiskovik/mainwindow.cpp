#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splash = new SplashScreen(this);
    connect(splash, &SplashScreen::sig_show, this, &MainWindow::slot_show);
    connect(splash, &SplashScreen::sig_StartParser, this, &MainWindow::slot_StartParser);  //16

    msg = new QMessageBox(this);
    connect(this, &MainWindow::sig_StatusConnectionINI, this, &MainWindow::slot_ReceiveStatusConnectionToINI);  //4
    connect(this, &MainWindow::sig_ResultReady, this, &MainWindow::slot_ResultReady);

    dataBase = new DataBase(this);
    dataBase->AddDataBase(POSTGRE_DRIVER);  //1
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);  //6
    connect(dataBase, &DataBase::sig_ErrorStatusRequest, this, &MainWindow::ErrorStatusRequestToDB);  //9
    connect(dataBase, &DataBase::sig_ExitRequest, this, &MainWindow::slot_show);  //10
    connect(dataBase, &DataBase::sig_SendStatusRequest, this, [this]{splash->thisShow(config);});  //11
    connect(dataBase, &DataBase::sig_SendDataFromDB, this, &MainWindow::ScreenDataFromDB);
    connect(dataBase, &DataBase::sig_TableWidgetEmpty, this, &MainWindow::slot_TableWidgetEmpty);
    connect(dataBase, &DataBase::sig_onDoubleClick, this, &MainWindow::onDoubleClick);

    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete splash;
    dataBase->DisconnectFromDataBase();
    if(tbView){delete tbView;}
    delete textEdit;
}

void MainWindow::slot_connectINI()  //1
{
    auto connINI = [&]{
        file.setFileName("configurations.ini");
        bool status{file.open(QIODevice::ReadOnly | QIODevice::Text)};
        emit sig_StatusConnectionINI(status);};  //4

    QFuture<void> fut = QtConcurrent::run(connINI);
}

void MainWindow::slot_show()
{
    ui->vL_Reply->addWidget(textEdit);
    ui->pB_Search->setEnabled(true);

    this->show();
    //splash->show();     //удалить
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)  //6
{
    if(status)
    {
        auto reqToDb = [this]{dataBase->CreateTableToDB();};  //7
        QFuture<void> futRcvData = QtConcurrent::run(reqToDb);
    }
    else
    {
        dataBase->DisconnectFromDataBase();
        msg->setIcon(QMessageBox::Critical);
        msg->setInformativeText("<b>Ошибка подключения к базе данных.</b>");
        msg->setText(dataBase->GetLastError().text());
        msg->exec();
        qApp->exit();
    }
}

void MainWindow::ErrorStatusRequestToDB(QSqlError err)  //9
{
    msg->setIcon(QMessageBox::Critical);
    msg->setInformativeText("<b>Ошибка в запросе к базе данных.</b>");
    msg->setText(err.text());
    msg->exec();
    qApp->exit();
}

void MainWindow::ScreenDataFromDB(QTableView *widget)
{
    tbView = widget;
    ui->vL_Reply->addWidget(tbView);

    tbView->hideColumn(1);
    tbView->setColumnWidth(0,2000);
    tbView->show();
    textEdit->hide();
    textEdit->clear();
    ui->pB_Search->setEnabled(true);
}

void MainWindow::slot_TableWidgetEmpty()
{
    textEdit->append(QString("'%1' Нет совподений.").arg(ui->lE_Search->text()));
    textEdit->show();
    if(tbView){tbView->hide();}

    ui->pB_Search->setEnabled(true);
}

void MainWindow::slot_ReceiveStatusConnectionToINI(bool status)  //4
{
    if (status)
    {
        config = QString(file.readAll()).split("\n", Qt::SkipEmptyParts);
        file.close();

        if(config.size() != 7)
        {
            msg->setIcon(QMessageBox::Critical);
            msg->setInformativeText("<b>Ошибка содержания файла configurations.ini</b>");
            msg->setText("Неверное количество строк.");
            msg->exec();
            qApp->exit();
        }
        else
        {
            auto connBD = [&]{dataBase->ConnectToDataBase(config);};  //5
            QFuture<void> fut = QtConcurrent::run(connBD);
        }
    }
    else
    {
        msg->setIcon(QMessageBox::Critical);
        msg->setInformativeText("<b>Ошибка подключения к configurations.ini</b>");
        msg->setText(file.errorString());
        msg->exec();
        file.close();
        qApp->exit();
    }
}

void MainWindow::slot_StartParser(QNetworkReply *reply)  //16
{
    parser = new parser_Html_1(reply);

    auto startR = [&]{

        parser->toWork(splash->recursionLinks->getParserFlag());  //18
        dataBase->SetDataInBD(parser->getLink(), parser->getWords());  //22
        if(splash->recursionLinks->getParserFlag()) splash->recursionLinks->addToList(parser->getNewListLink());
        delete parser;
        emit sig_ResultReady();
    };
    QFuture<void> fut = QtConcurrent::run(startR);
}

void MainWindow::slot_ResultReady()
{
    splash->recursionLinks->startRecursion();
}

void MainWindow::on_pB_Search_clicked()
{
    ui->pB_Search->setEnabled(false);
    QString text = ui->lE_Search->text();

    lineParser(text);
    dataBase->DataBaseSearch(text);
}

void MainWindow::lineParser(QString &text)
{
    text.prepend(' ').append(' ');

    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i].isUpper()) { text[i] = text[i].toLower(); }
        else if (!(text[i].isLetter())) { text[i] = ' '; }
    }

    qsizetype j{ 0 };
    qsizetype jj;
    while ((j = text.indexOf(' ', j)) != -1)
    {
        if ((jj = text.indexOf(' ' , j + 1)) != -1)
        {
            if(jj - j <= 4 || jj - j >= 20) text.remove(j, jj - j);
            else j = jj;
        }
        else ++j;
    }

    j = 0;
    while ((j = text.indexOf(' ', j)) != -1)
    {
        if ((jj = text.indexOf(' ' , j + 1)) != -1)
        {
            text.insert(jj,"\',");
            text.insert(j + 1,'\'');
            j = jj;

        }
        else
        {
            text.chop(2);
            ++j;
        }
    }

    if(text.isEmpty()) { text = "\' \'"; }
}

void MainWindow::onDoubleClick(const QModelIndex &index)
{
    QString text = QVariant(tbView->model()->data( index, Qt::DisplayRole)).toString();
    textEdit->setText(text);
    textEdit->show();
    if(tbView){tbView->hide();}
}
            //  'align', 'border', 'страницы'
            // обсуждение скрыть страницы
