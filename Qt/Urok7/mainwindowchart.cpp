#include "mainwindowchart.h"
#include "ui_mainwindowchart.h"
#include "mainwindow.h"

MainWindowChart::MainWindowChart(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowChart)
{
    ui->setupUi(this);
    //this->resize(640, 480);
    this->setGeometry(100,300,800,600);
    //this->pos();
    axisX = new QValueAxis;
    axisX->setTickCount(6);
    axisX->setLabelFormat("%.1f");
    axisX->setRange(0, 1);
    axisX->setTitleText("Время");

    axisY = new QValueAxis;
    axisY->setTickCount(5);
    //axisY->setLabelFormat("%.2f");
    //axisY->setRange(-1, -0.8);
    axisY->setTitleText("Попугаи");

    chart = new QChart( );
    //chart->legend()->setVisible(false);
    chart->setTitle("Попугаи в секунду.");
    //Объект QChartView является виджетом отображальщиком графика. В его конструктор необходимо передать ссылку
    //на объект QChart.
    chartView = new QChartView(chart);
    //chartView->setRubberBand(QChartView::RectangleRubberBand);
    //И создадим объект нашего класса.
    graphClass = new GraphicChart(NUM_GRAPHS, axisX, axisY);
    //chart -> chartVuiew -> данные для отображения

    layout = new QGridLayout;
    ui->centralwidget->setLayout(layout);
    layout->addWidget(chartView);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
}

MainWindowChart::~MainWindowChart()
{
    delete ui;
    //Обяхательно освободим память
    delete chart;
    delete graphClass;
    delete chartView;
}

void MainWindowChart::ViewGraph()
{
    //chartView->chart()->createDefaultAxes();
    chartView->show( );
    this->show();
}

QChart *MainWindowChart::GetChart() {return chart;}


QValueAxis *MainWindowChart::GetAxisY() {return axisY;}
