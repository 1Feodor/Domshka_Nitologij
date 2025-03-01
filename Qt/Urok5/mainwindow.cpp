#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    maus_xY = new QLabel(this);
    statusBar()->addWidget(maus_xY);
    maus_xY->setText(QString("Координаты мыши: X=0 - Y=0"));

    ui->lN_timer_H->display("00:00:00.0");
    ui->pB_start->setCheckable(true);

    this->setMouseTracking(true); //включить слежение за мышью
    ui->centralwidget->setMouseTracking(true);
    ui->pB_circle->setMouseTracking(true);
    ui->pB_start->setMouseTracking(true);
    ui->pB_clear->setMouseTracking(true);
    ui->gB_timer->setMouseTracking(true);
    ui->lN_timer_H->setMouseTracking(true);
    ui->label_3->setMouseTracking(true);
    ui->tE_info->setMouseTracking(true);

    sig = new Signal_time(this);
    time = new QTimer(this);
    QObject::connect(time, &QTimer::timeout, sig, &Signal_time::slot_timer);
    time->setInterval(100);

    connect(sig, &Signal_time::sig_size_circle,this ,&MainWindow::slot_size_circle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_start_toggled(bool checked)
{
    if(checked)
    {
        ui->pB_circle->setEnabled(true);
        ui->pB_start->setText("Стоп");
        ui->pB_clear->setEnabled(false);
        time->start();
    }
    else
    {
        time->stop();
        ui->pB_circle->setEnabled(false);
        ui->pB_start->setText("Старт");
        ui->pB_clear->setEnabled(true);
    }
}


void MainWindow::on_pB_clear_clicked()
{
    ui->pB_clear->setEnabled(false);
    ui->tE_info->clear();
    size_circle = 0;
    sig->set_countdown_zero();

    ui->lN_timer_H->display("00:00:00.0");
}


void MainWindow::on_pB_circle_clicked()
{
    ++size_circle;
    ui->tE_info->append(QString("Круг №%1        ").arg(size_circle) + sig->get_time_circle() + "                   " + sig->get_time_seconds());
}

void MainWindow::slot_size_circle(QString buf)
{
    ui->lN_timer_H->display(buf);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    maus_xY->setText(QString("Координаты мыши: X=%1 - Y=%2").arg(event->x()).arg(event->y()));
}

