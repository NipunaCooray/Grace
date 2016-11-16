#ifndef SERIALREADWRITE_H
#define SERIALREADWRITE_H

#include <QSerialPort>


class SerialReadWrite : public QObject
{

Q_OBJECT

public:
    SerialReadWrite();
    ~SerialReadWrite();
     void writeToSerial(QString);


public slots:
     void readSerial();


private slots:
    //void writeToSerial(QString);


private:
    QSerialPort *arduino;
    //static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_vendor_id = 1659;
    //static const quint16 arduino_uno_product_id = 67;
    static const quint16 arduino_uno_product_id = 8963;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray serialData;
    QString serialBuffer;

};

#endif // SERIALREADWRITE_H
