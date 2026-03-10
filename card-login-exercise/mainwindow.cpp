#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,
            this,&MainWindow::handleClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClick()
{
    qDebug()<<"Mainwindow click handler";
    // luodaan RFID kortin lukija olio
    if(pCard == nullptr)
    {
       pCard = new CARD(this);
        connect(pCard,&CARD::sendCard,
               this,&MainWindow::handleCard);
       this->hide();
       pCard->show();

    }
    else
    {
        this->hide();
        pCard->show();
    }
    // kytketään sen signaali
    // laitetaan tämän luokan UI piiloon
    // avataan RFID kortin lukijan UI
}

void MainWindow::handleCard(QString s)
{
    qDebug()<<"Mainwindow handleCard";
    // talletetaan s cardNumber muuttujaan
    cardNumber = s.toUInt();
    ui->CurrentCard->setText(s);
    // laiteaan CARD olion käyttöliittymä piiloon
    //pCard->hide();
    // luodaan PIN olio ja avataan sen käyttöliittymä
    if(pPin == nullptr)
    {
        pPin = new PIN(this);
        connect(pPin,&PIN::sendPIN,
                this,&MainWindow::handlePin);
        connect(pPin,&PIN::sendTimeOut,
                this,&MainWindow::handleTimeOut);

        pCard->hide();
        pPin->show();

    }
    else
    {
        pCard->hide();
        pPin->show();
    }

}

void MainWindow::handlePin(QString s)
{
    qDebug()<<"Mainwindow handlePin handlerissa";
    // talletetaan s pinNumber muuttujaan
    pinNumber = s.toUInt();
    ui->CurrentPin->setText(s);
    this->show();
    //pPin->hide();
    delete pPin;
    pPin = nullptr;
}

void MainWindow::handleTimeOut()
{
    qDebug()<<"Mainwindow handle Timeout";
    delete pPin;
    pPin = nullptr;
    pCard->show();
}
