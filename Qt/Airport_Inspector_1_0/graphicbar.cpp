#include "graphicbar.h"

graphicBar::graphicBar(QBarCategoryAxis *axisX, QValueAxis *axisY) : axisX{axisX}, axisY{axisY}
{
    this->ptrGraph = new QBarSeries(this);
}


void graphicBar::AddDataToBar(QVector<double> y)
{
    this->set0 = new QBarSet("Рейсы", this);
    //Добавление точе в серию осуществляется при помощи метода append.
    this->set0->append(y);

    this->ptrGraph->append(this->set0);
}

void graphicBar::ClearBar(QChart *chart)
{
    if(chart->series().size())
    {
        //Очищаем серии
        this->ptrGraph->clear();
        //Удаляем серии из графика
        chart->removeSeries(this->ptrGraph);
    }
}

void graphicBar::UpdateBar(QChart *chart)
{
    chart->addSeries(this->ptrGraph);
    this->ptrGraph->attachAxis(this->axisX);
    this->ptrGraph->attachAxis(this->axisY);
}
