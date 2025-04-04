#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QtConcurrent>
#include "database.h"
#include "dialog_statistics.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connect_BD();

public slots:
    void ReceiveStatusConnectionToDB(bool status);      //Метод изменяет стотояние формы
    void ReceiveStatusRequestToDB(QSqlError err);       //Метод визуализирует ошибки
    void ScreenDataFromDBtext(QStringList *text);   //Слот test
    void ScreenDataFromDB(QTableView *tableWg);   //Слот test
    void StatisticsClose();
    void RequestSetMonth(int month);
    void WinShow ();

private slots:
    void on_pB_search_clicked();
    void on_cB_list_airports_currentIndexChanged(int index);
    void on_pB_statistics_clicked();

signals:
    void sigWinShow();

private:
    Ui::MainWindow *ui;
    int time_counter{5};
    requestType requestT;
    QTimer *time;
    QLabel* status_BD;
    QLabel* timer_connect;
    DataBase* dataBase;
    QMessageBox* msg;
    QString request = "";
    QTableView* tbView = nullptr;
    QStringList heading;
    QStringList airport_code;
    Dialog_statistics *statistics;

    void Time_connect();

};
#endif // MAINWINDOW_H
