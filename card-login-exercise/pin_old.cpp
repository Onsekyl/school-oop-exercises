#include "pin_old.h"
#include "ui_pin_old.h"

Pin::Pin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pin)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Pin::handleClick);
}

Pin::~Pin()
{
    delete ui;
}

void Pin::handleClick()
{
    sendPin(ui->lineEdit->text());
}
