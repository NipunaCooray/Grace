#include "slavesetupform.h"
#include "ui_slavesetupform.h"
#include "slaverunform.h"

SlaveSetupForm::SlaveSetupForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlaveSetupForm)
{
    ui->setupUi(this);
}

SlaveSetupForm::~SlaveSetupForm()
{
    delete ui;
}

void SlaveSetupForm::on_pushButton_setupAgain_clicked()
{
    close();
    SlaveRunForm *slaveRunForm = new SlaveRunForm(this);
    slaveRunForm->setModal(false);
    slaveRunForm->show();

}

