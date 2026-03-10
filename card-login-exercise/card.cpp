#include "card.h"
#include "ui_card.h"

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);
    connect(ui->readCardButton, &QPushButton::clicked, this, &Card::handleClick);
}

Card::~Card()
{
    delete ui;
}

void Card::handleClick()
{
    qDebug() << "Card class handleClick()";
    // Read QString from linedit
    QString readValue = ui->lineEdit->text();
    // Send signal with the QString
    emit sendCard(readValue);
}
