#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->insertCardButton, &QPushButton::clicked, this, &MainWindow::handleClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCard(QString cardNumberSent)
{
    qDebug() << "Mainwindow handleCard()";
    cardNumber = cardNumberSent.toInt();
    ui->currentCard->setText(cardNumberSent);

    if (pPin == nullptr)
    {
        pPin = new PIN(this);
        connect(pPin, &PIN::sendPIN, this, &MainWindow::handlePin);
        connect(pPin, &PIN::sendTimeout, this, &MainWindow::handleTimeOut);

        card->hide();
        pPin->show();
    }
    else
    {
        card->hide();
        pPin->show();
    }
}

void MainWindow::handlePin(QString pinNumberSent)
{
    pin = pinNumberSent.toInt();
    ui->currentPin->setText(pinNumberSent);
    // this->hide();
    // pPin->hide();
    delete pPin;
    pPin = nullptr;
}

void MainWindow::handleTimeOut()
{
    qDebug() << "Mainwindow handleTimeOut()";
    delete pPin;
    pPin = nullptr;
    card->show();
}

void MainWindow::handleClick()
{
    qDebug() << "Mainwindow handleClick()";

    // Create RFID card reader object
    if (card == nullptr)
    {
        card = new Card(this);
        connect(card, &Card::sendCard, this, &MainWindow::handleCard);
        // this->hide();
        card->show();
    }
    else
    {
        // this->hide();
        card->show();
    }
    // Connect its signal
    // Hide this class' UI
    // Open RFID reader UI
}

