#include "card.h"
#include "ui_card.h"
#include <QDebug>

CARD::CARD(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CARD)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,
            this,&CARD::handleClick);

}

CARD::~CARD()
{
    delete ui;
}

void CARD::handleClick()
{
    qDebug()<<"CARD luokan handle click";
    // luetaan QString lineEditistä
    QString luettu = ui->lineEdit->text();
    // lähetetään QString signaalin mukana
    emit sendCard(luettu);
}
