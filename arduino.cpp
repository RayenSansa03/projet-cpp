#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QThread>
#include <limits>
#include <QStringList>
#include <QString>

Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
               serial_port_info.productIdentifier() == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }
    qDebug() << "arduino_port_name is :" << arduino_port_name;
    if(arduino_is_available) {
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "Connected to Arduino on port:" << arduino_port_name;
            return 0;
        } else {
            qDebug() << "Failed to open serial port";
            return 1;
        }
    }
    qDebug() << "No Arduino available on specified vendor and product ID";
    return -1;
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }

 }


int Arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}

float Arduino::readTemperature() {
    if (!serial->isOpen()) {
        qDebug() << "Trying to open serial port";
        if (connect_arduino() != 0) {
            qDebug() << "Failed to connect to Arduino";
            return std::numeric_limits<float>::quiet_NaN();
        }
    }

    QThread::sleep(3);  // Attendre 3 secondes avant de lire les données

    if (serial->waitForReadyRead(3000)) {  // Attend encore jusqu'à 3 secondes pour les données
        QByteArray rawData = serial->readAll();
        qDebug() << "Data received:" << rawData;

        QString data = rawData;  // Utilisez les données réelles au lieu d'une chaîne simulée
        QStringList temperatures = data.split("\r\n"); // Diviser les données par des sauts de ligne

        bool ok;
        float temp;
        foreach (const QString &value, temperatures) {
            temp = value.toFloat(&ok);
            if (ok && temp >= 10.0 && temp <= 50.0) {  // Vérifie que la température est entre 10.0°C et 50.0°C
                qDebug() << "Parsed temperature:" << temp;
                return temp;  // Renvoie la première température valide
            }
        }
        qDebug() << "No valid temperature found.";
        return std::numeric_limits<float>::quiet_NaN();  // Renvoie NaN si aucune température valide n'est trouvée
    } else {
        qDebug() << "No data available to read";
        return std::numeric_limits<float>::quiet_NaN();  // Renvoie NaN si aucune donnée n'est prête
    }
}
