#include <QCoreApplication>
//#include <QtSql>        //Модуль QtSql не должен включаться напрямую
#include <QSqlDatabase>
#include <QSqlError>

#include <QUdpSocket>
#include <QNetworkDatagram>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase qtdb = QSqlDatabase::addDatabase("QSQLITE");
    qtdb.setDatabaseName("db_name.sql");

    if (!qtdb.open()) {
        qDebug() << qtdb.lastError().text();
    }
    else
    {
        qDebug() << "Создал первый попавшийся экземпляр класса модуля для работы с БД.";
    }
    qDebug() << "/////////////////////////////////////////";

    QByteArray sent_message{"Создал первый попавшийся экземпляр класса модуля для работы с сетью."};

    QNetworkDatagram received_message;
    QUdpSocket udpSocket;

    udpSocket.bind(QHostAddress::LocalHost, 5577);
    qDebug() << "Количество отправленных байтов: " << udpSocket.writeDatagram(sent_message, QHostAddress::LocalHost, 5577);

    while (udpSocket.hasPendingDatagrams()) {

        qDebug() <<  "Размер первой ожидающей UDP-датаграммы: " << udpSocket.pendingDatagramSize();

        received_message = udpSocket.receiveDatagram(-1);
        qDebug() << "Количество доступных каналов чтения: " << udpSocket.readChannelCount();
        qDebug() << static_cast<QString>(received_message.data());
    }
    udpSocket.close();

//QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.


    a.exit();       //Вызовите .quit() или.exit(), чтобы завершить работу приложения.
    //return a.exec();      //Если вам не нужен запущенный цикл обработки событий Qt, удалите вызов функции .exec()
}
