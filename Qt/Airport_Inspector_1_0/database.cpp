#include "database.h"

DataBase::DataBase(QObject *parent) : QObject{parent}
{
    text = new QStringList;
    dataBase = new QSqlDatabase();
    simpleQuery = new QSqlQuery();
    tabmodel = new QSqlTableModel();
    tableView = new QTableView();
}

DataBase::~DataBase()
{
    delete text;
    delete dataBase;
    delete simpleQuery;
    delete tabmodel;
}

void DataBase::AddDataBase(QString driver)
{
    *dataBase = QSqlDatabase::addDatabase(driver);
}

void DataBase::ConnectToDataBase()
{
    dataBase->setHostName(QString("981757-ca08998.tmweb.ru"));
    dataBase->setDatabaseName(QString("demo"));
    dataBase->setUserName(QString("netology_usr_cpp"));
    dataBase->setPassword(QString("CppNeto3"));
    dataBase->setPort(5432);

    bool status{dataBase->open()};
    emit sig_SendStatusConnection(status);
}

void DataBase::DisconnectFromDataBase()
{
    *dataBase = QSqlDatabase::database();
    dataBase->close();
}

QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

void DataBase::RequestToDB(QString &request)
{
    *simpleQuery = QSqlQuery(*dataBase);

    ///Тут должен быть код ДЗ
    bool statusRequest = simpleQuery->exec(request);
    if(statusRequest)
    {
        emit sig_SendStatusRequest(simpleQuery->lastError());
    }
    else
    {
        qDebug() << "Error";
        emit sig_SendStatusRequest(simpleQuery->lastError());
    }
}

void DataBase::ReadAnswerFromDB(int answerType, QStringList &heading)
{
    switch (answerType)
    {
    case requestStart:
        text->clear();
        heading.clear();
        while(simpleQuery->next())
        {
            heading << simpleQuery->value(1).toString();
            *text << simpleQuery->value(0).toString();
        }
        emit sig_SendDataFromDBtext(text);
        break;
    case requestArrival:
        tabmodel->setQuery(std::move(*simpleQuery));
        tabmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tabmodel->select();
        tabmodel->setHeaderData(0, Qt::Horizontal, heading[0]);
        tabmodel->setHeaderData(1, Qt::Horizontal, heading[1]);
        tabmodel->setHeaderData(2, Qt::Horizontal, heading[2]);
        tableView->setModel(tabmodel);

        emit sig_SendDataFromDB(tableView);
        break;
    case requestYear:
        text->clear();
        heading.clear();
        while(simpleQuery->next())
        {
            *text << simpleQuery->value(0).toString();
        }
        emit sig_SendDataFromDBChartBar(text);
        break;
    case requestMonth:
        text->clear();
        heading.clear();
        while(simpleQuery->next())
        {
            *text << simpleQuery->value(0).toString();
        }
        emit sig_SendDataFromDBChart(text);
        break;
    default:
        break;
    }
}
