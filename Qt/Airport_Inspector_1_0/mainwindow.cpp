#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent}, ui{new Ui::MainWindow}
{
    ui->setupUi(this);

    status_BD = new QLabel(this);
    status_BD->setText(QString("Статус подключения к базе данных: <font color=red>Отключено</font>"));
    timer_connect = new QLabel(this);
    timer_connect->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    timer_connect->setText(QString(""));

    statusBar()->addWidget(status_BD);
    statusBar()->addWidget(timer_connect, 1);

    dataBase = new DataBase(this);
    msg = new QMessageBox(this);

    dataBase->AddDataBase(POSTGRE_DRIVER);

    connect(dataBase, &DataBase::sig_SendDataFromDBtext, this, &MainWindow::ScreenDataFromDBtext);
    connect(dataBase, &DataBase::sig_SendDataFromDB, this, &MainWindow::ScreenDataFromDB);
    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);
    connect(dataBase, &DataBase::sig_SendStatusRequest, this, &MainWindow::ReceiveStatusRequestToDB);

    time = new QTimer(this);
    time->setInterval(1000);
    QObject::connect(time, &QTimer::timeout, this, &MainWindow::Time_connect);

    request = "SELECT airport_name ->> 'ru' as airport_name, airport_code "
              "FROM bookings.airports_data "
              "ORDER BY airport_name";

    statistics = new Dialog_statistics(this);
    connect(dataBase, &DataBase::sig_SendDataFromDBChart, statistics, &Dialog_statistics::ScreenDataFromDBChart);
    connect(dataBase, &DataBase::sig_SendDataFromDBChartBar, statistics, &Dialog_statistics::ScreenDataFromDBChartBar);
    connect(statistics, &Dialog_statistics::finished, this, &MainWindow::StatisticsClose);
    connect(statistics, &Dialog_statistics::sigResultMonth, this, &MainWindow::RequestSetMonth);

    connect(this, &MainWindow::sigWinShow, this, [this]{WinShow();});
}

MainWindow::~MainWindow()
{
    dataBase->DisconnectFromDataBase();
    if(tbView){delete tbView;}
    delete ui;
}

void MainWindow::connect_BD()
{
    auto conn = [&]{dataBase->ConnectToDataBase();};
    QFuture<void> fut = QtConcurrent::run(conn);
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status)
    {
        requestT = requestStart;
        auto reqToDb = [this]{dataBase->RequestToDB(request);};
        QFuture<void> futRcvData = QtConcurrent::run(reqToDb);

        status_BD->setText(QString("Статус подключения к базе данных: <font color=green>Подключено</font>"));
    }
    else
    {
        dataBase->DisconnectFromDataBase();
        msg->setIcon(QMessageBox::Critical);
        msg->setInformativeText("<b>Ошибка подключения к базе данных.</b>");
        msg->detailedText();
        msg->setDetailedText("Через 5 секунд, после закрытия информационного окна, будет предпринята новая попытка подключения к базе данных.");
        msg->setText(dataBase->GetLastError().text());
        msg->exec();

        time->start();
        Time_connect();
    }
}

void MainWindow::ReceiveStatusRequestToDB(QSqlError err)
{
    if(err.isValid( ))
    {
        msg->setIcon(QMessageBox::Critical);
        msg->setText(err.text());
        msg->exec();
        this->close();
    }
    else
    {
        switch (requestT) {
        case requestStart:
            dataBase->ReadAnswerFromDB(requestStart, airport_code);
            break;
        case requestArrival:
            dataBase->ReadAnswerFromDB(requestArrival, heading);
            break;
        case requestYear:
            dataBase->ReadAnswerFromDB(requestYear, heading);
            break;
        case requestMonth:
            dataBase->ReadAnswerFromDB(requestMonth, heading);
            break;
        default:
            break;
        }
    }
}

void MainWindow::ScreenDataFromDBtext(QStringList *text)
{
    ui->cB_list_airports->addItems(*text);

    ui->gB_list_airports->setEnabled(true);
    ui->gB_flight_direction->setEnabled(true);
    ui->gB_date_flight->setEnabled(true);
    ui->pB_search->setEnabled(true);
    ui->pB_statistics->setEnabled(true);
    ui->gB_statistics->setEnabled(true);
}

void MainWindow::ScreenDataFromDB(QTableView *widget)
{
    tbView = widget;
    ui->gB_list_flights->layout( )->addWidget(tbView);

    tbView->setColumnWidth(0,100);
    tbView->setColumnWidth(1,150);
    tbView->setColumnWidth(2,250);
    //tbView->resizeRowsToContents();
}

void MainWindow::StatisticsClose()
{
    ui->pB_statistics->setEnabled(true);
}

void MainWindow::RequestSetMonth(int month)
{
    request = QString("SELECT count(flight_no), date_trunc('day', scheduled_departure) as \"Day\" from bookings.flights f "
                    "WHERE(scheduled_departure::date between date('2016-09-01') and date('2017-08-31')) and ( departure_airport = '%1' or arrival_airport = '%1') "
                    "and date_part('month', scheduled_departure) = '%2' "
                    "GROUP BY \"Day\"").arg(airport_code[ui->cB_list_airports->currentIndex()], QString::number(month + 1));

    requestT = requestMonth;
    auto reqToDb = [this]{dataBase->RequestToDB(request);};
    QFuture<void> futRcvData = QtConcurrent::run(reqToDb);
}

void MainWindow::WinShow()
{
    statistics->open();
}

void MainWindow::Time_connect()
{
    if (time_counter != 0)
    {
        timer_connect->setText(QString("До подключения к базе данных осталось: <font color=red>%1</font>сек.").arg(time_counter));
        --time_counter;
    }
    else
    {
        time->stop();
        time_counter = 5;
        connect_BD();
        timer_connect->setText(QString(""));
    }
}

void MainWindow::on_pB_search_clicked()
{
    heading.clear();
    if (ui->rB_arrival->isChecked())
    {
        request = QString("SELECT flight_no, TO_CHAR(scheduled_arrival, 'HH24:MI'), ad.airport_name->>'ru' as \"Name\" "
                  "FROM bookings.flights f "
                  "JOIN bookings.airports_data ad on ad.airport_code = f.departure_airport "
                  "WHERE f.arrival_airport = '%1' and date(scheduled_arrival) = '%2' "
                  "ORDER BY scheduled_arrival").arg(airport_code[ui->cB_list_airports->currentIndex()], ui->dateE_flight->date().toString("yyyy-MM-dd"));
        heading << "Номер рейса" << "Время прилета" << "Аэропорт отправления";
    }
    else
    {
        request = QString("SELECT flight_no, TO_CHAR(scheduled_departure, 'HH24:MI'), ad.airport_name->>'ru' as \"Name\" "
                  "FROM bookings.flights f "
                  "JOIN bookings.airports_data ad on ad.airport_code = f.arrival_airport "
                  "WHERE f.departure_airport = '%1' and date(scheduled_departure) = '%2' "
                  "ORDER BY scheduled_departure").arg(airport_code[ui->cB_list_airports->currentIndex()], ui->dateE_flight->date().toString("yyyy-MM-dd"));
        heading << "Номер рейса" << "Время вылета" << "Аэропорт назначения";
    }
    requestT = requestArrival;
    auto reqToDb = [this]{dataBase->RequestToDB(request);};
    QFuture<void> futRcvData = QtConcurrent::run(reqToDb);
}


void MainWindow::on_cB_list_airports_currentIndexChanged(int index)
{
    ui->gB_statistics->setTitle(QString("Просмотр статистики загруженности аэропорта %1").arg(ui->cB_list_airports->currentText()));
}


void MainWindow::on_pB_statistics_clicked()
{
    ui->pB_statistics->setEnabled(false);

    statistics->setWindowTitle(QString("Загруженность аэропорта %1").arg(ui->cB_list_airports->currentText()));

    request = QString("SELECT count(flight_no), date_trunc('month', scheduled_departure) as \"Month\" from bookings.flights f "
                                 "WHERE (scheduled_departure::date between date('2016-09-01') and date('2017-08-31')) and ( departure_airport = '%1' or arrival_airport = '%1') "
                                 "group by \"Month\"").arg(airport_code[ui->cB_list_airports->currentIndex()]);

    requestT = requestYear;
    auto reqYear = [this]{dataBase->RequestToDB(request);};
    auto reqMonth = [this]{statistics->PreparationGraph();};
    auto winShow = [this]{emit sigWinShow();};

    QFuture<void> futRcvData = QtConcurrent::run(reqYear).then(reqMonth).then(winShow);
}

