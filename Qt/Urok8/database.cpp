#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();
    simpleQuery = new QSqlQuery( );
    //tableWidget = new QTableWidget( );
    tableView = new QTableView();
    model = new QSqlQueryModel();
    tabmodel = new QSqlTableModel();
}

DataBase::~DataBase()
{
    delete dataBase;
    delete simpleQuery;
    delete tabmodel;
    delete model;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{
    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());


    ///Тут должен быть код ДЗ


    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}

void DataBase::ReadAnswerFromDB(int answerType)
{
    switch (answerType) {
    //Для наших запросов вид таблицы не поменяетя. Поэтому бужет единый обработчик.
    case requestAllFilms:
    {
        tabmodel->setQuery(std::move(*simpleQuery));
        tabmodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tabmodel->select();
        tabmodel->setHeaderData(0, Qt::Horizontal, tr("Название фильма"));
        tabmodel->setHeaderData(1, Qt::Horizontal, tr("Описание фильма"));
        tableView->setModel(tabmodel);

        /*
         * После заполнения всей таблицы мы ее передаем в MainWindow при помощи сигнала.
        */
        emit sig_SendDataFromDB(tableView, answerType);

        break;

    }
    case requestComedy:
    {
        model->setQuery(std::move(*simpleQuery));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));
        tableView->setModel(model);

        /*
         * После заполнения всей таблицы мы ее передаем в MainWindow при помощи сигнала.
        */
        emit sig_SendDataFromDB(tableView, answerType);

        break;

    }
    case requestHorrors:
    {
        model->setQuery(std::move(*simpleQuery));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Название фильма"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Описание фильма"));
        tableView->setModel(model);

        /*
         * После заполнения всей таблицы мы ее передаем в MainWindow при помощи сигнала.
        */
        emit sig_SendDataFromDB(tableView, answerType);

        break;

    }
    default:
        break;
    }
}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();
    //dataBase->removeDatabase(nameDb);
}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    *simpleQuery = QSqlQuery(*dataBase);

    ///Тут должен быть код ДЗ
    bool statusRequest = simpleQuery->exec(request);
    if(statusRequest){
        emit sig_SendStatusRequest(simpleQuery->lastError());
    }
    else{
        qDebug() << "Error";
        emit sig_SendStatusRequest(simpleQuery->lastError());
    }

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
