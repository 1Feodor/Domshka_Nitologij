#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gB_list_char->setTitle("Цифры или буквы");
    ui->gB_list_char->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

    ui->rB_digits->setText("Цифры");
    ui->rB_digits->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    ui->rB_letters->setText("Буквы");
    ui->rB_letters->setChecked(true);
    ui->rB_letters->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    ui->cB_list->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);

    ui->pB_Button->setText("Нажми меня!");
    ui->pB_Button->setCheckable(true);
    ui->pB_Button->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    ui->progressBar->setAlignment(Qt::AlignCenter);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);

    QHBoxLayout* phЬxLayout = new QHBoxLayout;
    phЬxLayout->setContentsMargins(5, 5, 5, 5);
    phЬxLayout->setSpacing(15);
    phЬxLayout->addWidget(ui->rB_digits);
    phЬxLayout->addWidget(ui->rB_letters);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->setContentsMargins(5, 5, 5, 5);
    pvbxLayout->setSpacing(15);
    pvbxLayout->addLayout(phЬxLayout);
    pvbxLayout->addWidget(ui->cB_list);

    ui->gB_list_char->setLayout(pvbxLayout);

    QHBoxLayout* xLayout = new QHBoxLayout;
    xLayout->setContentsMargins(5, 5, 5, 5);
    xLayout->setSpacing(15);
    xLayout->addStretch(1);
    xLayout->addWidget(ui->pB_Button);
    xLayout->addStretch(1);

    QVBoxLayout* pvLayout = new QVBoxLayout;
    pvLayout->setContentsMargins(5, 5, 5, 5);
    pvLayout->setSpacing(15);
    pvLayout->addLayout(xLayout);
    pvLayout->addWidget(ui->progressBar);

    QBoxLayout* phЬxgB = new QBoxLayout(QBoxLayout::LeftToRight);
    phЬxgB->addWidget(ui->gB_list_char);
    phЬxgB->addLayout(pvLayout);

    ui->centralwidget->setLayout(phЬxgB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rB_digits_toggled(bool checked)
{
    if(checked)
    {
        ui->cB_list->clear();
        for(int i = 0; i < 10; ++i)
        {
            ui->cB_list->addItem(QString("%1").arg(i));
        }
    }
}

void MainWindow::on_rB_letters_toggled(bool checked)
{
    if(checked)
    {
        ui->cB_list->clear();
        for(int i = 0; i < 10; ++i)
        {
            ui->cB_list->addItem(QString("%1").arg(char('A' + i)));
        }
    }
}

void MainWindow::on_pB_Button_toggled(bool checked)
{
    if(checked)
    {
        int buf = ui->progressBar->value();

        if(buf < 10) ui->progressBar->setValue(++buf);
        else ui->progressBar->setValue(0);
    }
}
