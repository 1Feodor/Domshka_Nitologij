#ifndef MAINWINDOWCHART_H
#define MAINWINDOWCHART_H

#include <QMainWindow>
#include "graphicchart.h"

#define NUM_GRAPHS 1

namespace Ui {
class MainWindowChart;
}

class MainWindowChart : public QMainWindow
{
    Q_OBJECT

public:
    GraphicChart *graphClass;

    explicit MainWindowChart(QWidget *parent = nullptr);
    ~MainWindowChart();
    void ViewGraph(void);
    QChart* GetChart();
    QValueAxis* GetAxisY();
private:
    Ui::MainWindowChart *ui;

    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
    QGridLayout *layout;
};

#endif // MAINWINDOWCHART_H
