#include "pin.h"
#include "ui_pin.h"
#include <QDebug>

PIN::PIN(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PIN)
{
    ui->setupUi(this);


    connect(ui->pushButton,&QPushButton::clicked,
            this,&PIN::handleClick);

    connect(pQtimer,&QTimer::timeout,
            this,&PIN::handleTimeout);

    pQtimer->start(10000);
}

PIN::~PIN()
{
    delete ui;
}

void PIN::handleClick()
{
    qDebug()<<"PIN luokan handle Click";
    emit sendPIN(ui->lineEdit->text());
    //qDebug()<<"Nyt vasta suoritan stop kaskyn";
    //pQtimer->stop();
}

void PIN::handleTimeout()
{
    qDebug()<<"Timeout handler";
    emit sendTimeOut();

}
