#include "splashscreen.h"
#include "ui_splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    recursionLinks = new Recursion(this);
    connect(recursionLinks, &Recursion::sig_ExitRecursion, this, &SplashScreen::slot_exitFlag);  //10
    connect(recursionLinks, &Recursion::sig_StartParser, this, &SplashScreen::sig_StartParser);  //16

    this->painter = new QPainter;

    paint = new MainPaint(this);
    QObject::connect(paint, &MainPaint::sig_timer, this, [this]{this->update();});
}

SplashScreen::~SplashScreen()
{
    delete ui;
    delete this->painter;
    delete paint;
}

void SplashScreen::thisShow(QList<QString> config)  //11
{
    this->show();
    recursionLinks->startRecursion(config);  //12
}

void SplashScreen::slot_exitFlag()  //10
{
    exitFlag = false;
    this->close();
}

void SplashScreen::closeEvent(QCloseEvent *event)
{
    if(exitFlag) qApp->exit();
    else emit sig_show();
}

void SplashScreen::paintEvent(QPaintEvent *event)
{
    this->painter->begin(this);
    paint->MainPaintEvent(painter);
    this->painter->end();
}
