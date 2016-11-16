#include "serialreadwrite.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>
#include <QtWidgets>
#include"QObject"
#include "global.h"
#include "QMessageBox"
using namespace std;

SerialReadWrite::SerialReadWrite()
{
    arduino_is_available = false;
    arduino_port_name = "";
    arduino = new QSerialPort;
    serialBuffer = "";


    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }


    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                    qDebug() << "Arduino port name " << arduino_port_name<<endl;

                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setDataTerminalReady(true);
        QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }else{
        // give error message if not available
        //QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
        qDebug() << "Couldn't find the development board' " <<endl;

        QMessageBox messageBox;
        messageBox.critical(0,"Error","Connect nucleo");
        messageBox.setFixedSize(500,200);

    }
}

SerialReadWrite::~SerialReadWrite()
{
    if(arduino->isOpen()){
        arduino->flush();
        arduino->close();
    }

}

void SerialReadWrite::writeToSerial(QString command)
{


    if(arduino->isWritable()){

        //arduino->write(command.toStdString().c_str());
        arduino->write(command.toUtf8());

        //qDebug()<< "Success";

    }else{
        qDebug() << "Couldn't write to serial!";

    }
}

void SerialReadWrite::readSerial(){
    //qDebug()<< "Serial reading works";
    serialData = arduino->readAll();
    //serialBuffer += QString::fromStdString(serialData.toStdString());
    serialBuffer += QString::fromStdString(serialData.constData());
    //qDebug()<<serialBuffer;
    QStringList splitList = serialBuffer.split("\n");
    //qDebug()<< splitList[0];
    QString value = splitList[0];

    int val = GlobalData::styleData.getDynamicFoldwidth();

    if(splitList[0]!=""){
        val = value.toInt();
    }

    qDebug()<<val;
    GlobalData::styleData.setDynamicFoldwidth(val);

    //qDebug()<<splitList;
    serialBuffer = "";

}
