#ifndef RUNFORM_H
#define RUNFORM_H

#include <QDialog>
#include <player.h>

namespace Ui {
class RunForm;
}

class RunForm : public QDialog
{
    Q_OBJECT

public:
    explicit RunForm(QWidget *parent = 0);
    ~RunForm();

private slots:

    void on_pushButton_setupAgain_clicked();

    void on_pushButton_clicked();

    //Display video frame in player UI
    void updatePlayerUI(QImage img);


private:
    Ui::RunForm *ui;
    Player* myPlayer;
    QTimer *timer;

public slots:
    void updateLCD();

};

#endif // RUNFORM_H
