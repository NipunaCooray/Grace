#ifndef SLAVESETUPFORM_H
#define SLAVESETUPFORM_H

#include <QDialog>

namespace Ui {
class SlaveSetupForm;
}

class SlaveSetupForm : public QDialog
{
    Q_OBJECT

public:
    explicit SlaveSetupForm(QWidget *parent = 0);
    ~SlaveSetupForm();

private slots:
    void on_pushButton_setupAgain_clicked();

private:
    Ui::SlaveSetupForm *ui;
};

#endif // SLAVESETUPFORM_H
