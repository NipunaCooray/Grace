#include "runform.h"
#include "ui_runform.h"
#include "setupform.h"
#include "savestyleform.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include "global.h"


using namespace std;
using namespace cv;

RunForm::RunForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RunForm)
{
//    myPlayer = new Player();
//    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
//                                  this, SLOT(updatePlayerUI(QImage)));

//    myPlayer->loadVideo();

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateLCD()));
    timer->start(1000);

    ui->setupUi(this);

}

RunForm::~RunForm()
{
    delete ui;
}

void RunForm::updatePlayerUI(QImage img)
{
//    if (!img.isNull())
//    {
//        ui->label->setAlignment(Qt::AlignCenter);
//        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),Qt::KeepAspectRatio, Qt::FastTransformation));
//    }
}


void RunForm::on_pushButton_setupAgain_clicked()
{
    close();
    SetupForm *setupForm = new SetupForm(this);
    setupForm->setModal(false);
    setupForm->setFixedSize(395,300);
    setupForm->show();


}

void RunForm::on_pushButton_clicked()
{
      //close();

//    SaveStyleForm saveForm;
//    saveForm.setModal(false);
//    saveForm.exec();
    RunForm::close();

    SaveStyleForm* saveForm = new SaveStyleForm(this);
    saveForm->setModal(false);
    saveForm->setFixedSize(474,300);
    saveForm->show();



}

void RunForm::updateLCD(){

    int foldWidth = GlobalData::styleData.getDynamicFoldwidth();

    ui->lcdNumber->display(foldWidth);
}
