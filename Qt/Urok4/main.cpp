#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette pall;
    pall.setBrush(w.backgroundRole(),QBrush(QPixmap(":/imege_form.jpg")));
    w.setPalette(pall);
    w.setWindowTitle("«Виджеты»");
    w.resize(300,100);
    w.show();
    return a.exec();
}
