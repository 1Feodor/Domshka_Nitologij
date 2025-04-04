#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DataBase dataBase;
    MainWindow w;
    QPalette pall;
    pall.setColor(w.backgroundRole(), Qt::white);
    w.setPalette(pall);
    w.show();
    w.connect_BD();
    return a.exec();
}
