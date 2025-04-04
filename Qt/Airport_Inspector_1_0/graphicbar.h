#ifndef GRAPHICBAR_H
#define GRAPHICBAR_H

#include <QObject>
#include <QBarSeries>
#include <QtCharts>
#include <QChartView>


class graphicBar : public QObject
{
    Q_OBJECT
public:
    graphicBar(QBarCategoryAxis* axisX = nullptr, QValueAxis* axisY = nullptr);

    void AddDataToBar(QVector<double> y);
    void ClearBar(QChart* chart);
    void UpdateBar(QChart* chart);

private:
    QBarSeries* ptrGraph;
    QBarSet* set0;
    QBarCategoryAxis* axisX;
    QValueAxis* axisY;
};

#endif // GRAPHICBAR_H
