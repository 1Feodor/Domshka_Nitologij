#include "mainpaint.h"

MainPaint::MainPaint(QObject *parent)
    : QObject{parent}
{
    cosFigure = std::cos(this->DEGREES * 30);
    sinFigure = std::sin(this->DEGREES * 30);
    cosHour = std::cos(this->DEGREES * 0.5);
    sinHour = std::sin(this->DEGREES * 0.5);
    cosMinut = std::cos(this->DEGREES * (-1.5));
    sinMinut = std::sin(this->DEGREES * (-1.5));

    time = new QTimer(this);
    QObject::connect(time, &QTimer::timeout, this, &MainPaint::slot_timer);
    time->setInterval(30);
    time->start();
}

void MainPaint::MainPaintEvent(QPainter *painter)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::blue, 3, Qt::SolidLine));

    QPointF temp;
    for (int i = 0; i < 12; ++i)
    {
        if(i % 3 == 0)
        {
            painter->drawLine(QPointF(figure.rx() + shape[0].rx(), figure.ry() + shape[0].ry()), QPointF(figure.rx() + shape[2].rx(), figure.ry() + shape[2].ry()));
        }
        else
        {
            painter->drawLine(QPointF(figure.rx() + shape[0].rx(), figure.ry() + shape[0].ry()), QPointF(figure.rx() + shape[1].rx(), figure.ry() + shape[1].ry()));
        }

        for (QPointF &var: shape)
        {
            temp.rx() = (cosFigure * var.rx()) - (sinFigure * var.ry());
            temp.ry() = (sinFigure * var.rx()) + (cosFigure * var.ry());
            var = temp;
        }
    }

    QPen pen(Qt::black, 9, Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    painter->setPen(pen);

    painter->drawLine(QPointF(figure.rx() + shapeBig[0].rx(), figure.ry() + shapeBig[0].ry()), QPointF(figure.rx() + shapeBig[1].rx(), figure.ry() + shapeBig[1].ry()));
    painter->drawLine(QPointF(figure.rx() + shapeLittle[0].rx(), figure.ry() + shapeLittle[0].ry()), QPointF(figure.rx() + shapeLittle[1].rx(), figure.ry() + shapeLittle[1].ry()));
}

void MainPaint::slot_timer()
{
    QPointF temp;
    for (QPointF &var: shapeBig)
    {
        temp.rx() = (cosHour * var.rx()) - (sinHour * var.ry());
        temp.ry() = (sinHour * var.rx()) + (cosHour * var.ry());
        var = temp;
    }
    for (QPointF &var: shapeLittle)
    {
        temp.rx() = (cosMinut * var.rx()) - (sinMinut * var.ry());
        temp.ry() = (sinMinut * var.rx()) + (cosMinut * var.ry());
        var = temp;
    }
    emit sig_timer();
}


