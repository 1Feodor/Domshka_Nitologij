#include "mainwindow.h"
#include "headingfile.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    HeadingFile h;
    h.setWindowModality(Qt::ApplicationModal);
    h.show();
    return a.exec();

}
