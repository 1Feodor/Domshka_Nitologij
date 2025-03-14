#include "graphicchart.h"

GraphicChart::GraphicChart(uint32_t numberGr, QValueAxis *axisX, QValueAxis *axisY) : numGraphs{numberGr}, axisX{axisX}, axisY{axisY}
{
    ptrGraph.resize(numGraphs);
    //Создадим объекты серий
    for(int i = 0; i<numGraphs; i++){
        ptrGraph[i] = new QLineSeries(this);
    }
}

/*!
 * \brief Метод добавляет данные на график.
 * \param x - данные по оси Х
 * \param y - по оси У
 * \param numGraph - количество графиков
 */
void GraphicChart::AddDataToGrahp(QVector<double> x, QVector<double> y, uint32_t numGraph)
{

    //Зададим размер графика, т.е. количество точек.
    uint32_t size = 0;
    //Необходимо, чтобы х и у были равны.
    if(x.size() >= y.size()){
        size = y.size();
    }
    else{
        size = x.size();
    }

    //Добавление точе в серию осуществляется при помощи метода append.
    for(int j = 0; j<size; j++){
        ptrGraph[numGraph]->append(x[j],y[j]);
    }
}
/*!
 * \brief Метод очищает данные на графике
 * \param chart - указатель на график
 */
void GraphicChart::ClearGraph(QChart *chart)
{
    if(chart->series().size())
    {
        //Необходимо очистить все графики
        for(int i = 0; i<numGraphs; i++){
            //Очищаем серии
             ptrGraph[i]->clear();
            //Удаляем серии из графика
            chart->removeSeries(ptrGraph[i]);
        }
    }
}

/*!
 * \brief Метод добавляет серии к графику
 * \param chart - указатель на график
 */
void GraphicChart::UpdateGraph(QChart *chart)
{
    for(int i = 0; i<numGraphs; i++){
        chart->addSeries(ptrGraph[i]);
        ptrGraph[i]->attachAxis(this->axisX);
        ptrGraph[i]->attachAxis(this->axisY);
    }
}

void GraphicChart::SetNameSeries(int a)
{
    for(int i = 0; i<numGraphs; i++){
       ptrGraph[i]->setName("Номер канала: " + QString::number(a));
    }
}
