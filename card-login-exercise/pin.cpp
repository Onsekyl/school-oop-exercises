#include "pin.h"
#include "ui_pin.h"

PIN::PIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PIN)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &PIN::handleClick);
    connect(timer, &QTimer::timeout, this, &PIN::handleTimeout);

    timer->start(10000);
}

PIN::~PIN()
{
    delete ui;
}

void PIN::handleClick()
{
    // timer->stop();
    emit sendPIN(ui->lineEdit->text());
}

void PIN::handleTimeout()
{
    qDebug() << "Timeout";
    emit sendTimeout();
}
