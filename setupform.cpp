#include "setupform.h"
#include "ui_setupform.h"
#include "mainwindow.h"
#include "runform.h"
#include "global.h"
#include <QMessageBox>


SetupForm::SetupForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupForm)
{
    ui->setupUi(this);
    lineEditkeyboard = new Keyboard();
    connect(ui->lineEdit_RPM_1 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_RPM_2 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_RPM_3,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_RPM_4 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_Tension_1 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_Tension_2 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_Tension_3 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_Tension_4 ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_FoldLength ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));

    ui->comboBox_RGB->addItems({ "Black", "Yellow" });

}

SetupForm::~SetupForm()
{
    delete ui;
}

void SetupForm::run_keyboard_lineEdit()
{
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
}

void SetupForm::on_pushButton_back_clicked()
{
  //int data = GlobalData::styleData.getSpeed_1();
  //cout<< data<<endl;
  close();

}

void SetupForm::on_pushButton_save_clicked()
{

    bool ok;
    //Saving data entered by user to the styleData object
    QString RPM_1_Text = ui->lineEdit_RPM_1->text();
    int RPM_1 = RPM_1_Text.toInt(&ok,10);
    QString RPM_2_Text = ui->lineEdit_RPM_2->text();
    int RPM_2 = RPM_2_Text.toInt(&ok,10);
    QString RPM_3_Text = ui->lineEdit_RPM_3->text();
    int RPM_3 = RPM_3_Text.toInt(&ok,10);
    QString RPM_4_Text = ui->lineEdit_RPM_4->text();
    int RPM_4 = RPM_4_Text.toInt(&ok,10);

    QString Tension_1_Text = ui->lineEdit_Tension_1->text();
    int Tension_1 = Tension_1_Text.toInt(&ok,10);
    QString Tension_2_Text = ui->lineEdit_Tension_2->text();
    int Tension_2 = Tension_2_Text.toInt(&ok,10);
    QString Tension_3_Text = ui->lineEdit_Tension_3->text();
    int Tension_3 = Tension_3_Text.toInt(&ok,10);
    QString Tension_4_Text = ui->lineEdit_Tension_4->text();
    int Tension_4 = Tension_4_Text.toInt(&ok,10);

    QString FoldWidth_Text = ui->lineEdit_FoldLength->text();
    int FoldWidth = FoldWidth_Text.toInt(&ok,10);

    QString RGB_Text = ui->comboBox_RGB->currentText();
    int rgb=0;
    if(RGB_Text=="Black"){
        rgb = 1;
    }else{
        rgb = 2;
    }

    //Putting extraced data to the Global Object
    GlobalData::styleData.setSpeed_1(RPM_1);
    GlobalData::styleData.setSpeed_2(RPM_2);
    GlobalData::styleData.setSpeed_3(RPM_3);
    GlobalData::styleData.setSpeed_4(RPM_4);
    GlobalData::styleData.setTension_1(Tension_1);
    GlobalData::styleData.setTension_2(Tension_2);
    GlobalData::styleData.setTension_3(Tension_3);
    GlobalData::styleData.setTension_4(Tension_4);
    GlobalData::styleData.setFoldWidth(FoldWidth);
    GlobalData::styleData.setRGB(rgb);
    GlobalData::styleData.display();

    QString view = GlobalData::styleData.toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox :: question(this,"Check values again",view,QMessageBox::Yes|QMessageBox::No);

    if(reply== QMessageBox::Yes){
        close();

        RunForm *runForm = new RunForm(this);
        runForm->setModal(false);
        runForm->setFixedSize(395,300);
        runForm->show();;
        GlobalData::isDynamicValue = false;
    }





}
