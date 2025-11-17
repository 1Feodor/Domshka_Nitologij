#ifndef HEADINGFILE_H
#define HEADINGFILE_H

#include <QDialog>
#include <QFile>
#include <QtConcurrent>
#include <QMessageBox>
#include "http_client.h"
#include "parser_html.h"
#include "mainwindow.h"

namespace Ui {
class HeadingFile;
}

class HeadingFile : public QDialog
{
    Q_OBJECT

public:
    explicit HeadingFile(QWidget *parent = nullptr);
    ~HeadingFile();
    void connectINI();

signals:
    void sig_StatusConnectionINI(bool);
    void sig_LinksConnection(QString*);
    void sig_Chekc();

public slots:
    void addToList(QList<QString>);

private slots:
    void slot_ReceiveStatusConnectionToINI(bool status);

private:
    Ui::HeadingFile *ui;
    Http_Client *client;
    parser_Html *parser;
    QFile file;
    QMessageBox *msg;
    QList<QString> listOfLinks;
    QList<QString> config;

    int recursion;
    int begin = 0;
    int beginStandard = 0;
    int size = 0;
    int end = 0;
    int idealThread;
    bool exitFlag = true;
    void RecursionLinks();
    void StartRecursion();

protected:
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
};

#endif // HEADINGFILE_H
