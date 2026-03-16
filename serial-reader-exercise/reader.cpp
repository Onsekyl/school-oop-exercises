#include "reader.h"
#include <QDebug>
#include <QSerialPortInfo>


Reader::Reader(QObject *parent) : QObject(parent)
{
    qDebug() << "[READER CONSTRUCTOR]";
    port = new QSerialPort(this);
}

Reader::~Reader()
{
    qDebug() << "[READER DESTRUCTOR]";
}

void Reader::readInfo()
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
        for (const QSerialPortInfo &portInfo : serialPortInfos) {
            qDebug() << "\n"
                     << "Port:" << portInfo.portName() << "\n"
                     << "Location:" << portInfo.systemLocation() << "\n"
                     << "Description:" << portInfo.description() << "\n"
                     << "Manufacturer:" << portInfo.manufacturer() << "\n"
                     << "Serial number:" << portInfo.serialNumber() << "\n"
                     << "Vendor Identifier:"
                     << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                     << "Product Identifier:"
                     << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
        }
}

bool Reader::open()
{
    // Serial number: OL56E09005B8EBC

    // Only works with explicit portname!
    // Real implementation should use serial number.
    bool success = false;
    port->setPortName("COM8");
    success = port->open(QIODeviceBase::ReadOnly);

    if (success)
    {
        connect(port, &QSerialPort::readyRead, this, &Reader::handleInterrupt);
    }

    return success;
}

void Reader::handleInterrupt()
{
    qDebug() << "readyRead serial port";
    QByteArray luettu = port->readAll();
    emit sendData(luettu);
    qDebug() << luettu;
}
