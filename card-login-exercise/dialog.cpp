#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->readCardButton, &QPushButton::clicked, this, &Dialog::handleClick);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::handleClick()
{
    qDebug() << "Card class handleClick()";
    // Read QString from linedit
    QString readValue = ui->lineEdit->text();
    // Send signal with the QString
    emit sendCard(readValue);
}
