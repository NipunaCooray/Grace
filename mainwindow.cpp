#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setupform.h"
#include "loadstyleform.h"
#include "styledata.h"
#include "global.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clicked()
    {
    SetupForm *setupForm = new SetupForm(this);
    setupForm->setModal(false);
    setupForm->setFixedSize(395,300);
    setupForm->show();


}

void MainWindow::on_pushButton_loadStyle_clicked()
{
    LoadStyleForm *loadStyleForm = new LoadStyleForm(this);
    loadStyleForm->setModal(false);
    loadStyleForm->show();
}





void MainWindow::on_btn_close_clicked()
{
    GlobalData::isEdge = true;
}
