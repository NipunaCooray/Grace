#include "savestyleform.h"
#include "ui_savestyleform.h"
#include "global.h"

using namespace std;


SaveStyleForm::SaveStyleForm(QWidget *parent) :
    QDialog(parent),



    ui(new Ui::SaveStyleForm)
{
    ui->setupUi(this);
    lineEditkeyboard = new Keyboard();
    connect(ui->lineEdit_styleID ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_styleNo ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_size ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    connect(ui->lineEdit_material ,SIGNAL(selectionChanged()),this,SLOT(run_keyboard_lineEdit()));
    setValues();


}

SaveStyleForm::~SaveStyleForm()
{
    delete ui;
}

void SaveStyleForm::on_pushButton_clicked()
{
    close();
}

void SaveStyleForm::setValues(){
   ui->lineEdit_RPM_1->setText( QString::number(GlobalData::styleData.getSpeed_1()));
   ui->lineEdit_RPM_2->setText( QString::number(GlobalData::styleData.getSpeed_2()));
   ui->lineEdit_RPM_3->setText( QString::number(GlobalData::styleData.getSpeed_3()));
   ui->lineEdit_RPM_4->setText( QString::number(GlobalData::styleData.getSpeed_4()));
   ui->lineEdit_Tension_1->setText( QString::number(GlobalData::styleData.getTension_1()));
   ui->lineEdit_Tension_2->setText( QString::number(GlobalData::styleData.getTension_2()));
   ui->lineEdit_Tension_3->setText( QString::number(GlobalData::styleData.getTension_3()));
   ui->lineEdit_Tension_4->setText( QString::number(GlobalData::styleData.getTension_4()));
   ui->lineEdit_FoldWidth->setText( QString::number(GlobalData::styleData.getFoldWidth()));

   int RGB_val = GlobalData::styleData.getRGB();
   if(RGB_val==1){
       ui->lineEdit_RGB->setText("White");
   }else{
       ui->lineEdit_RGB->setText("Black");
   }

}

void SaveStyleForm::requestShowPage(){
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(requestReceived(QNetworkReply*)));

//    QUrlQuery query;

//    QUrl url("projectgrace.top/add.php?");

//    query.addQueryItem("styleID", "test");
//    query.addQueryItem("styleNumber", "test");
//    query.addQueryItem("size", "test");
//    query.addQueryItem("material", "test");
//    url.setQuery(query.query());

    QString urlString;

    urlString = "projectgrace.top/add.php?";
    urlString.append("styleID=");
    urlString.append(GlobalData::styleData.getStyleNo());
    urlString.append("&styleNumber=");
    urlString.append(GlobalData::styleData.getStyleValue());
    urlString.append("&size=");
    urlString.append(GlobalData::styleData.getSize());
    urlString.append("&material=");
    urlString.append(GlobalData::styleData.getMaterial());
    urlString.append("&speed_1=");
    urlString.append(QString::number(GlobalData::styleData.getSpeed_1()));
    urlString.append("&speed_2=");
    urlString.append(QString::number(GlobalData::styleData.getSpeed_2()));
    urlString.append("&speed_3=");
    urlString.append(QString::number(GlobalData::styleData.getSpeed_3()));
    urlString.append("&speed_4=");
    urlString.append(QString::number(GlobalData::styleData.getSpeed_4()));
    urlString.append("&tension_1=");
    urlString.append(QString::number(GlobalData::styleData.getTension_1()));
    urlString.append("&tension_2=");
    urlString.append(QString::number(GlobalData::styleData.getTension_2()));
    urlString.append("&tension_3=");
    urlString.append(QString::number(GlobalData::styleData.getTension_3()));
    urlString.append("&tension_4=");
    urlString.append(QString::number(GlobalData::styleData.getTension_4()));
    urlString.append("&foldWidth=");
    urlString.append(QString::number(GlobalData::styleData.getFoldWidth()));
    urlString.append("&RGB=");
    urlString.append(QString::number(GlobalData::styleData.getRGB()));


    //qInfo() << urlString;
    cout<<urlString.toStdString()<<endl;


//    manager->get(QNetworkRequest(QUrl::fromUserInput("projectgrace.top/add.php?styleID=006&styleNumber=style_006")));
    manager->get(QNetworkRequest( QUrl::fromUserInput(urlString)));
}

void SaveStyleForm::requestReceived(QNetworkReply *reply){
    reply->deleteLater();

    if(reply->error()==QNetworkReply::NoError){
         QString replyText = reply->readAll();

         ui->txt_debug->appendPlainText(replyText);
    }else{
        ui->txt_debug->appendPlainText(reply->errorString());
    }

    reply->manager()->deleteLater();

}

void SaveStyleForm::on_pushButton_submitToServer_clicked()
{
    QString style_ID_Text = ui->lineEdit_styleID->text();
    QString style_Number_Text = ui->lineEdit_styleNo->text();
    QString size_Text = ui->lineEdit_size->text();
    QString material_Text = ui->lineEdit_material->text();

    GlobalData::styleData.setStyleNo(style_ID_Text);
    GlobalData::styleData.setStyleValue(style_Number_Text);
    GlobalData::styleData.setSize(size_Text);
    GlobalData::styleData.setMaterial(material_Text);

    requestShowPage();

//    nam= new QNetworkAccessManager();


//    connect(nam, SIGNAL(finished(QNetworkReply*)),
//            this, SLOT(replyFinished(QNetworkReply*)));


//    QUrl url("http://projectgrace.top/add.php");
//    QUrlQuery query;

//    query.addQueryItem("styleID", "003");
//    query.addQueryItem("styleNumber", "style_3");

//    url.setQuery(query.query());

//    QNetworkRequest request(url);

//    nam->get(request);


}

void SaveStyleForm::run_keyboard_lineEdit(){
    QLineEdit *line = (QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
}


