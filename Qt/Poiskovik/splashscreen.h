#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>
//#include <QPainter>
//#include <QPointF>
//#include <QTimer>
#include "recursion.h"
#include "mainpaint.h"

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = nullptr);
    ~SplashScreen();
    void thisShow(QList<QString> config);
    Recursion *recursionLinks;

private:
    Ui::SplashScreen *ui;
    QPainter *painter;
    bool exitFlag{ true };
    MainPaint *paint;

signals:
    void sig_show();
    void sig_StartParser(QNetworkReply *reply);

public slots:
    void slot_exitFlag();

protected:
    void closeEvent(QCloseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // SPLASHSCREEN_H
