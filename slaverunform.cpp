#include "slaverunform.h"
#include "ui_slaverunform.h"
#include "slavesetupform.h"

SlaveRunForm::SlaveRunForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SlaveRunForm)
{
    ui->setupUi(this);
}

SlaveRunForm::~SlaveRunForm()
{
    delete ui;
}

void SlaveRunForm::on_pushButton_2_clicked()
{
    close();
    SlaveSetupForm *slaveSetup = new SlaveSetupForm(this);
    slaveSetup->setModal(false);
    slaveSetup->setFixedSize(400,300);
    slaveSetup->show();

}
