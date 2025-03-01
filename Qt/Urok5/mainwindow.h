#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include "signal_time.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_start_toggled(bool checked);

    void on_pB_clear_clicked();

    void on_pB_circle_clicked();

public slots:
    void slot_size_circle(QString);

private:
    Ui::MainWindow *ui;
    int size_circle{0};
    Signal_time *sig;
    QTimer *time;
    QLabel* maus_xY;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
