#include "loadstyleform.h"
#include "ui_loadstyleform.h"
#include "slaverunform.h"

LoadStyleForm::LoadStyleForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadStyleForm)
{
    ui->setupUi(this);
}

LoadStyleForm::~LoadStyleForm()
{
    delete ui;
}

void LoadStyleForm::on_pushButton_cancel_clicked()
{
    close();
}

void LoadStyleForm::on_pushButton_loadStyle_clicked()
{
    //Loading from server should include here
    if(true){
        close();
        SlaveRunForm *slaveRunForm = new SlaveRunForm(this);
        slaveRunForm->setModal(false);
        slaveRunForm->setFixedSize(400,300);
        slaveRunForm->show();

    }
}
