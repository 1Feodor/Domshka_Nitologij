#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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

