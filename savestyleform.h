#ifndef SAVESTYLEFORM_H
#define SAVESTYLEFORM_H


#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include "keyboard.h"



namespace Ui {
class SaveStyleForm;
}

class SaveStyleForm : public QDialog
{
    Q_OBJECT

public:
    explicit SaveStyleForm(QWidget *parent = 0);
    void setValues();
    ~SaveStyleForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_submitToServer_clicked();
    void requestShowPage();
    void requestReceived(QNetworkReply *reply);
    void run_keyboard_lineEdit();
//    void replyFinished();

private:
    Ui::SaveStyleForm *ui;
    Keyboard *lineEditkeyboard;
//    QNetworkAccessManager *nam;
//    QNetworkReply *reply;

};

#endif // SAVESTYLEFORM_H
