#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QProcess>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
signals:
    void sig_sendData(QVector<QString> dbData);

private slots:

    void on_pB_notepad_clicked();

    void on_lE_host_textChanged(const QString &arg1);

    void on_lE_bd_textChanged(const QString &arg1);

    void on_lE_login_textChanged(const QString &arg1);

    void on_lE_password_textChanged(const QString &arg1);

    void on_pB_connect_clicked();

private:
    Ui::Dialog *ui;
    QVector<QString> data;
};

#endif // DIALOG_H
