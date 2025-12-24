#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
    dataBase = new QSqlDatabase();
    simpleQuery = new QSqlQuery();
    tableView = new QTableView();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->horizontalHeader()->setVisible(false);
    connect(tableView, &QTableView::doubleClicked, this, &DataBase::sig_onDoubleClick);

    tabmodel = new QSqlTableModel();

    requestStart.append("SELECT EXISTS (SELECT 1 FROM information_schema.tables WHERE table_schema = 'public' AND table_name = 'addressword')");
    requestStart.append("CREATE TABLE if NOT EXISTS addresshttp (address_id SERIAL PRIMARY KEY, http_addr VARCHAR NOT NULL)");
    requestStart.append("CREATE TABLE if NOT EXISTS word (word_id SERIAL PRIMARY KEY, http_word VARCHAR(120) NOT NULL)");
    requestStart.append("CREATE TABLE if NOT EXISTS addressword (id_address INTEGER REFERENCES addressHttp(address_id), "
                        "id_word INTEGER REFERENCES word(word_id), "
                        "word_size INTEGER NOT NULL, "
                        "constraint pk PRIMARY KEY(id_address, id_word))");
}

DataBase::~DataBase()
{
    delete dataBase;
    delete simpleQuery;
    delete tabmodel;
}

void DataBase::AddDataBase(QString driver)  //1
{
    *dataBase = QSqlDatabase::addDatabase(driver);
}

void DataBase::ConnectToDataBase(QList<QString> config)  //5
{
    dataBase->setHostName(config[2]);
    dataBase->setDatabaseName(config[3]);
    dataBase->setUserName(config[4]);
    dataBase->setPassword(config[5]);
    dataBase->setPort(config[6].toInt());

    bool status{dataBase->open()};
    emit sig_SendStatusConnection(status);  //6
}

void DataBase::DisconnectFromDataBase()
{
    if(dataBase->isOpen())
    {
        *dataBase = QSqlDatabase::database();
        dataBase->close();
    }
}

QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}

void DataBase::SetLinkInDB(QString link)  //23
{
    *simpleQuery = QSqlQuery(*dataBase);
    QString boolRequest = "SELECT (SELECT address_id FROM addresshttp WHERE http_addr = \'" + link + "\')";
    if(StatusRequest(boolRequest)) return;

    simpleQuery->next();
    matchingLink = simpleQuery->value(0).toInt();
    if(!matchingLink)
    {
        if(StatusRequest("SELECT COUNT(*) FROM addresshttp")) return;

        simpleQuery->next();
        count = simpleQuery->value(0).toInt() + 1;
        if(count < 1) count = 1;
        QString insertRequest = QString("INSERT INTO addresshttp VALUES ('%1', \'" + link + "\')").arg(QString::number(count));

        if(StatusRequest(insertRequest)) return;
    }
}

void DataBase::SetWordInDB(QMap<QString, int> *word)  //24
{
    *simpleQuery = QSqlQuery(*dataBase);
    for(auto it = word->begin(); it != word->end(); ++it)
    {
        QString boolRequest = "SELECT (SELECT word_id FROM word WHERE http_word = \'" + it.key() + "\')";
        if(StatusRequest(boolRequest)) return;

        simpleQuery->next();
        countWords = simpleQuery->value(0).toInt();
        if(!countWords)
        {
            if(StatusRequest("SELECT COUNT(*) FROM word")) return;
            simpleQuery->next();
            countWords = simpleQuery->value(0).toInt() + 1;
            if(countWords < 1) countWords = 1;
            QString insertRequest = QString("INSERT INTO word VALUES ('%1', \'" + it.key() + "\')").arg(QString::number(countWords));

            /*simpleQuery->prepare("INSERT INTO addresshttp "
                      "VALUES (?, ?)");
        simpleQuery->bindValue(0, QString::number(count));
        simpleQuery->bindValue(1, link);
        simpleQuery->exec();*/

            if(StatusRequest(insertRequest)) return;
        }
        SetAddressWord(it.value());  //25
    }
}

void DataBase::SetAddressWord(int sizeWord)  //25
{
    *simpleQuery = QSqlQuery(*dataBase);
    QString request = QString("SELECT (SELECT word_size FROM addressword WHERE id_address = '%1' "
                              "and id_word = '%2')").arg(QString::number(count), QString::number(countWords));
    if(StatusRequest(request)) return;

    simpleQuery->next();
    int size = simpleQuery->value(0).toInt();
    if(size)
    {
        if(size != sizeWord)
        {
            request = QString("UPDATE addressword SET word_size = '%3' WHERE id_address = '%1' "
                              "and id_word = '%2'").arg(QString::number(count), QString::number(countWords), QString::number(sizeWord));
            if(StatusRequest(request)) return;
        }
    }
    else
    {
        request = QString("INSERT INTO addressword VALUES ('%1', '%2', '%3')").arg(QString::number(count), QString::number(countWords), QString::number(sizeWord));
        if(StatusRequest(request)) return;
    }
}

void DataBase::SetDataInBD(QString link, QMap<QString, int> *word)  //22
{
    SetLinkInDB(link);  //23
    if(!matchingLink)
    {
        SetWordInDB(word);  //24
    }

}

void DataBase::CreateTableToDB()  //7
{
    *simpleQuery = QSqlQuery(*dataBase);

    for(int i = 0; i < requestStart.size(); ++i)
    {
        if(StatusRequest(requestStart.at(i))) return;  //8

        if(i == 0)
        {
            simpleQuery->next();
            bool matching = simpleQuery->value(0).toBool();
            if(matching)
            {
                emit sig_ExitRequest();  //10
                return;
            }
        }
    }
    emit sig_SendStatusRequest();  //11
}

void DataBase::DataBaseSearch(QString text)
{
    *simpleQuery = QSqlQuery(*dataBase);
    QString request = QString("SELECT http_addr, sum(word_size) FROM addressword "
                      "JOIN addresshttp ON addressword.id_address = addresshttp.address_id "
                      "JOIN word ON word.word_id  = addressword.id_word "
                      "WHERE http_word IN (%1) "
                      "GROUP BY addresshttp.http_addr "
                      "ORDER BY sum(word_size) DESC "
                      "LIMIT 10").arg(text);
    if(StatusRequest(request)) return ;

    if(simpleQuery->size())
    {
        tabmodel->setQuery(std::move(*simpleQuery));
        tabmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tabmodel->select();

        tableView->setModel(tabmodel);
        emit sig_SendDataFromDB(tableView);
    }
    else
    {
        emit sig_TableWidgetEmpty();
    }
}

bool DataBase::StatusRequest(QString request)  //8
{
    simpleQuery->exec(request);
    if(simpleQuery->lastError().isValid( ))
    {
        emit sig_ErrorStatusRequest(simpleQuery->lastError());  //9
        return true;
    }
    return false;
}
