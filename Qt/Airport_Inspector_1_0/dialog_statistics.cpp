#include "dialog_statistics.h"
#include "ui_dialog_statistics.h"

Dialog_statistics::Dialog_statistics(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog_statistics)
{
    ui->setupUi(this);

    axisX = new QValueAxis;
    axisX->setTickCount(16);
    axisX->setLabelFormat("%i");

    axisY = new QValueAxis;
    axisY->setTickCount(11);
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Количество");

    chart = new QChart();
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->setTitle("Прилеты - Вылеты.");
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    graphClass = new GraphicChart(NUM_GRAPHS, axisX, axisY);

    layout = new QGridLayout;
    ui->widget->setLayout(layout);
    layout->addWidget(chartView);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
/////////////////////////////////////////////////////////////////////

    axisXBar = new QBarCategoryAxis;
    QStringList categories {"Сентябрь", "Октябрь", "Ноябрь", "Декабрь", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август"};
    axisXBar->append(categories);
    //axisXBar->setMin(QDateTime::fromString("1 09 2016", "d MM yyyy"));
    //axisXBar->setMax(QDateTime::fromString("31 08 2017", "d MM yyyy"));

    axisYBar = new QValueAxis;
    axisYBar->setTickCount(11);
    axisYBar->setRange(0, 1500 );
    axisYBar->setLabelFormat("%i");

    chartBar = new QChart();
    chartBar->setTheme(QChart::ChartThemeBlueCerulean);
    chartBar->setTitle("Прилеты - Вылеты.");
    chartBar->setAnimationOptions(QChart::SeriesAnimations);

    chartViewBar = new QChartView(chartBar);

    graphBar = new graphicBar(axisXBar, axisYBar);

    layoutBar = new QGridLayout;
    ui->tab_year->setLayout(layoutBar);
    layoutBar->addWidget(chartViewBar);

    chartBar->addAxis(axisXBar, Qt::AlignBottom);
    chartBar->addAxis(axisYBar, Qt::AlignLeft);
}

Dialog_statistics::~Dialog_statistics()
{
    delete ui;

    delete chart;
    delete graphClass;
    delete chartView;

    delete chartBar;
    delete graphBar;
    delete chartViewBar;
}

void Dialog_statistics::PreparationGraph()
{
    ui->tbWidget->setCurrentIndex(0);
    if(ui->cB_month_numer->currentIndex() == 0)
    {
        axisX->setTitleText(ui->cB_month_numer->currentText());
        emit sigResultMonth(0);
    }
    else
    {
        ui->cB_month_numer->setCurrentIndex(0);
    }
}

void Dialog_statistics::on_cB_month_numer_currentIndexChanged(int index)
{
    ui->cB_month_numer->setEnabled(false);
    axisX->setTitleText(ui->cB_month_numer->currentText());
    emit sigResultMonth(index);
}

void Dialog_statistics::ScreenDataFromDBChart(QStringList *text)
{
    double ind{ 1 };
    double min = text->at(0).toDouble();
    double max = min;

    QVector<double> X_Data;
    QVector<double> Y_Data;

    for (const auto &item : std::as_const(*text))
    {
        X_Data.push_back(ind++);
        Y_Data.push_back(QString(item).toDouble());

        if(min > Y_Data.back()) min = Y_Data.back();
        if(max < Y_Data.back()) max = Y_Data.back();
    }
    graphClass->ClearGraph(chart);
    graphClass->AddDataToGrahp(X_Data, Y_Data, 0);
    axisX->setRange(1, 31);
    axisY->setRange(min - 5 + (5 - static_cast<int>(min)%5), max + 5 - (static_cast<int>(max)%5) );
    graphClass->UpdateGraph(chart);
    ui->cB_month_numer->setEnabled(true);
}

void Dialog_statistics::ScreenDataFromDBChartBar(QStringList *text)
{
    double max = text->at(0).toDouble();

    QVector<double> Y_Data;

    for (const auto &item : std::as_const(*text))
    {
        Y_Data.push_back(QString(item).toDouble());
        if(max < Y_Data.back()) max = Y_Data.back();
    }
    graphBar->ClearBar(chartBar);
    graphBar->AddDataToBar(Y_Data);

    axisYBar->setRange(0, max + 10 - (static_cast<int>(max) % 10));
    graphBar->UpdateBar(chartBar);
}
