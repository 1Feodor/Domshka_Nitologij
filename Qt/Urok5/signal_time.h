#ifndef SIGNAL_TIME_H
#define SIGNAL_TIME_H

#include <QObject>
#include <QTimer>

class Signal_time : public QObject
{
    Q_OBJECT
public:
    explicit Signal_time(QObject *parent = nullptr);
    void set_countdown_zero();
    QString get_time_seconds();
    QString get_time_circle();
    void start_timer(QTimer*);
    void stop_timer(QTimer*);

public slots:
    void slot_timer();

signals:
    void sig_size_circle(QString);

private:
    int countdown{0};
    int num_sec{0};
    QString time_seconds;
    QString time_circle{"00:00:00.0"};
    void Cislo_Wo_Wrema(int, QString*);
};

#endif // SIGNAL_TIME_H
