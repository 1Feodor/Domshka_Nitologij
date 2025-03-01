#include "signal_time.h"

Signal_time::Signal_time(QObject *parent) : QObject{parent} {}

void Signal_time::set_countdown_zero()
{
    this->countdown = this->num_sec = 0;
}

QString Signal_time::get_time_seconds()
{
    return this->time_seconds;
}

QString Signal_time::get_time_circle()
{
    Cislo_Wo_Wrema(this->countdown - this->num_sec, &this->time_circle);
    this->num_sec = this->countdown;

    return this->time_circle;
}

void Signal_time::slot_timer()
{
    Cislo_Wo_Wrema(++this->countdown, &this->time_seconds);
    emit sig_size_circle(this->time_seconds);
}

void Signal_time::Cislo_Wo_Wrema(int t, QString* sec_str)
{
    sec_str->clear();
    sec_str->push_front(QString::number(t  % 10));
    sec_str->push_front(".");
    t /= 10;
    sec_str->push_front(QString::number(t  % 10));
    t /= 10;
    t = t + (t / 6) * 4;
    sec_str->push_front(QString::number(t  % 10));
    sec_str->push_front(":");
    t /= 10;
    sec_str->push_front(QString::number(t  % 10));
    t /= 10;
    t = t + (t / 6) * 4;
    sec_str->push_front(QString::number(t  % 10));
    sec_str->push_front(":");
    t /= 10;
    t = t + (t / 24) * 76;
    sec_str->push_front(QString::number(t  % 10));
    t /= 10;
    sec_str->push_front(QString::number(t  % 10));
}
