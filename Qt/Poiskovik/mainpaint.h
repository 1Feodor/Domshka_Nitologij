#ifndef MAINPAINT_H
#define MAINPAINT_H

#include <QObject>
#include <QPainter>
#include <QPointF>
#include <QTimer>

class MainPaint : public QObject
{
    Q_OBJECT
public:
    explicit MainPaint(QObject *parent = nullptr);
    void MainPaintEvent(QPainter *painter);

public slots:
    void slot_timer();

private:
    QPointF figure{400 / 2, 300 / 2};
    double DEGREES{M_PI / 180};
    double cosFigure;
    double sinFigure;
    double cosHour;
    double sinHour;
    double cosMinut;
    double sinMinut;
    QTimer *time;
    QList<QPointF> shape{ QPointF(110, 0), QPointF(125, 0), QPointF(130, 0)};
    QList<QPointF> shapeBig{ QPointF(15, 0), QPointF(85, 0)};
    QList<QPointF> shapeLittle{ QPointF(0, -15), QPointF(0, -120)};

signals:
    void sig_timer();

};

#endif // MAINPAINT_H
