#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableWidget>
#include <QSqlTableModel>
#include <QHeaderView>

#define POSTGRE_DRIVER "QPSQL"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
    void AddDataBase(QString driver);
    void ConnectToDataBase(QList<QString>);
    void DisconnectFromDataBase();
    QSqlError GetLastError(void);
    void SetDataInBD(QString link, QMap<QString, int> *word);
    void CreateTableToDB();
    void DataBaseSearch(QString text);

signals:
    void sig_SendStatusConnection(bool);
    void sig_SendStatusRequest();
    void sig_ExitRequest();
    void sig_ErrorStatusRequest(QSqlError err);
    void sig_TableWidgetEmpty();
    void sig_SendDataFromDB(QTableView *tableWg);
    void sig_onDoubleClick(const QModelIndex &index);

private:
    void SetLinkInDB(QString link);
    void SetWordInDB(QMap<QString, int> *word);
    void SetAddressWord(int sizeWord);
    bool StatusRequest(QString);

    QSqlDatabase *dataBase;
    QSqlQuery *simpleQuery;
    QList<QString> requestStart;
    QTableView* tableView;
    QSqlTableModel* tabmodel;
    int count;
    int countWords;
    bool matchingLink;
};

#endif // DATABASE_H
