#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtConcurrent>
#include "database.h"
#include "dbdata.h"
#include "dbdata.h"
#include "dialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void ScreenDataFromDB(QTableView *widget, int typeRequest);   //Слот отображает значение в QTableWidget
    void ReceiveStatusConnectionToDB(bool status);      //Метод изменяет стотояние формы
    void ReceiveStatusRequestToDB(QSqlError err);       //Метод визуализирует ошибки


private slots:
    void on_act_addData_triggered();        //Слот отображает форму для ввода данных
    void on_act_connect_triggered();        //Слот выполняет подключение к БД
    void on_pb_request_clicked();       //Обработчик кнопки "Получить"


    void on_pb_clear_clicked();     //Обработчик кнопки "Очистить"

signals:
    void sig_RequestToDb(QString request);

private:

    QVector<QString> dataForConnect; //Данные для подключения к БД.

    Ui::MainWindow *ui;
    DbData *dataDb;
    Dialog * dialog;
    DataBase* dataBase;
    QMessageBox* msg;
    QTableView* tbView = nullptr;
    QString request = "";
};
#endif // MAINWINDOW_H
