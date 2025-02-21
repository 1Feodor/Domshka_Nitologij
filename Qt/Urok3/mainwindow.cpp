#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_notepad_clicked()
{
    QProcess *process;
    process->startDetached("Notepad.exe");
}

void MainWindow::on_lE_host_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_host->text();
    ui->lab_host->setText(QString::number(size_char.size()) + "/25");
}

void MainWindow::on_lE_bd_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_bd->text();
    ui->lab_bd->setText(QString::number(size_char.size()) + "/25");
}


void MainWindow::on_lE_login_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_login->text();
    ui->lab_login->setText(QString::number(size_char.size()) + "/25");
}


void MainWindow::on_lE_password_textChanged(const QString &arg1)
{
    QString size_char = ui->lE_password->text();
    ui->lab_password->setText(QString::number(size_char.size()) + "/20");
}

