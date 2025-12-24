#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "splashscreen.h"
#include <QFile>
#include <QtConcurrent>
#include <QMessageBox>
#include <QTextEdit>
#include "database.h"
#include "parser_html_1.h"

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
    void slot_connectINI();

public slots:
    void slot_show();
    void ReceiveStatusConnectionToDB(bool status);
    void ErrorStatusRequestToDB(QSqlError err);
    void ScreenDataFromDB(QTableView *tableWg);
    void slot_TableWidgetEmpty();

private slots:
    void slot_ReceiveStatusConnectionToINI(bool status);
    void slot_StartParser(QNetworkReply *reply);
    void slot_ResultReady();

    void on_pB_Search_clicked();

signals:
    void sig_StatusConnectionINI(bool);
    void sig_ResultReady();

private:
    Ui::MainWindow *ui;
    SplashScreen *splash;
    QFile file;
    QMessageBox *msg;
    QList<QString> config;
    DataBase *dataBase;
    QTableView *tbView = nullptr;
    QTextEdit *textEdit;
    parser_Html_1 *parser;  //?

    void lineParser(QString &text);

protected:
    void onDoubleClick(const QModelIndex &index);
};
#endif // MAINWINDOW_H
