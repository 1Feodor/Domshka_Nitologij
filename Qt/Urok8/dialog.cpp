#include "dialog.h"
#include "database.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->lE_host->setText("981757-ca08998.tmweb.ru");
    ui->lE_bd->setText("netology_cpp");
    ui->lE_login->setText("netology_usr_cpp");
    ui->lE_password->setText("CppNeto3");
    ui->sB_port->setValue(5432);
    data.resize(NUM_DATA_FOR_CONNECT_TO_DB);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pB_notepad_clicked()
{
    QProcess *process;
    process->startDetached("Notepad.exe");
}


void Dialog::on_lE_host_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_host->text();
    ui->lab_host->setText(QString::number(size_char.size()) + "/25");
}


void Dialog::on_lE_bd_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_bd->text();
    ui->lab_bd->setText(QString::number(size_char.size()) + "/25");
}


void Dialog::on_lE_login_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_login->text();
    ui->lab_login->setText(QString::number(size_char.size()) + "/25");
}


void Dialog::on_lE_password_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_password->text();
    ui->lab_password->setText(QString::number(size_char.size()) + "/20");
}


void Dialog::on_pB_connect_clicked()
{
    //Добавляем данные в контейнер и передаем в главное окно
    data[hostName] = ui->lE_host->text();
    data[dbName] = ui->lE_bd->text();
    data[login] = ui->lE_login->text();
    data[pass] = ui->lE_password->text();
    data[port] = QString::number(ui->sB_port->value());

    emit sig_sendData(data);
    this->close();
}

