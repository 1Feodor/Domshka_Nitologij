#ifndef DIALOG_STATISTICS_H
#define DIALOG_STATISTICS_H

#include <QDialog>
#include <QtConcurrent>
#include "graphicchart.h"
#include "graphicbar.h"

#define NUM_GRAPHS 1

namespace Ui {
class Dialog_statistics;
}

class Dialog_statistics : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_statistics(QWidget *parent = nullptr);
    ~Dialog_statistics();

public slots:
    void ScreenDataFromDBChart(QStringList *text);   //Слот test
    void ScreenDataFromDBChartBar(QStringList *text);   //Слот test
    void PreparationGraph();

signals:
    void sigResultMonth(int month);

private slots:
    void on_cB_month_numer_currentIndexChanged(int index);

private:
    Ui::Dialog_statistics *ui;

    GraphicChart *graphClass;

    QChart *chart;
    QChartView *chartView;
    QGridLayout *layout;
    QValueAxis *axisX;
    QValueAxis* axisY;

    graphicBar* graphBar;

    QChart *chartBar;
    QChartView *chartViewBar;
    QGridLayout *layoutBar;
    QBarCategoryAxis *axisXBar;
    QValueAxis* axisYBar;

};

#endif // DIALOG_STATISTICS_H
