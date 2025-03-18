#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>



#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"

//Количество полей данных необходимых для подключения к БД
#define NUM_DATA_FOR_CONNECT_TO_DB 5

//Перечисление полей данных
enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

//Типы запросов
enum requestType{

    requestAllFilms = 1,
    requestComedy   = 2,
    requestHorrors  = 3

};



class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");      //Метод добавляет БД к экземпляру класса QSqlDataBase
    void DisconnectFromDataBase(QString nameDb = "");       //Метод производит отключение от БД
    void RequestToDB(QString request);      //Метод формирует запрос к БД.
    QSqlError GetLastError(void);       //Метод возвращает последнюю ошибку БД
    void ConnectToDataBase(QVector<QString> dataForConnect);        //Метод подключается к БД
    void ReadAnswerFromDB( int answerType );        //Заполнить таблицу


signals:

    void sig_SendDataFromDB(QTableView *tableWg, int typeR);
    void sig_SendStatusConnection(bool);
    void sig_SendStatusRequest(QSqlError err);


private:

    QSqlDatabase* dataBase;
    QSqlQuery* simpleQuery;
    QTableView* tableView;
    QSqlQueryModel* model;
    QSqlTableModel* tabmodel;
};

#endif // DATABASE_H
