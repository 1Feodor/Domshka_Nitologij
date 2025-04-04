#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableWidget>

#define POSTGRE_DRIVER "QPSQL"
//#define DB_NAME "MyDB"

enum requestType
{
    requestStart = 1,
    requestArrival = 2,
    requestYear = 3,
    requestMonth = 4
};

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
    void AddDataBase(QString driver);      //Метод добавляет БД к экземпляру класса QSqlDataBase
    void ConnectToDataBase();        //Метод подключается к БД
    void DisconnectFromDataBase();       //Метод производит отключение от БД
    QSqlError GetLastError(void);       //Метод возвращает последнюю ошибку БД
    void RequestToDB(QString &request);      //Метод формирует запрос к БД.
    void ReadAnswerFromDB( int answerType, QStringList &heading);        //Заполнить таблицу

signals:
    void sig_SendStatusConnection(bool);
    void sig_SendStatusRequest(QSqlError err);
    void sig_SendDataFromDBtext(QStringList *text);
    void sig_SendDataFromDB(QTableView *tableWg);
    void sig_SendDataFromDBChart(QStringList *text);
    void sig_SendDataFromDBChartBar(QStringList *text);

private:

    QSqlDatabase* dataBase;
    QSqlQuery* simpleQuery;
    QStringList* text;
    QSqlTableModel* tabmodel;
    QTableView* tableView;
};

#endif // DATABASE_H
