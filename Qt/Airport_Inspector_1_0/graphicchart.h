#ifndef GRAPHICCHART_H
#define GRAPHICCHART_H

#include <QObject>
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>


class GraphicChart : public QObject
{
    Q_OBJECT
public:
    GraphicChart(uint32_t numberGr = 0, QValueAxis* axisX = nullptr, QValueAxis* axisY = nullptr);

    void AddDataToGrahp(QVector<double> x, QVector<double> y, uint32_t numGraph);
    void ClearGraph(QChart* chart);
    void UpdateGraph(QChart* chart);

signals:

private:

    QList<QLineSeries*> ptrGraph;
    uint32_t numGraphs;
    QValueAxis* axisX;
    QValueAxis* axisY;
};

#endif // GRAPHICCHART_H
