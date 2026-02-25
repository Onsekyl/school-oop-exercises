#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    connectionSetup();
}

MainWindow::~MainWindow()
{
    if (timer)
    {
        timer->stop();
        delete timer;
    }

    delete ui;
}

void MainWindow::timeOut()
{
    currentPlayer == 1 ? player1Time-- : player2Time--;
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    ui->progressBar_1->setValue(player1Time / double(gameTime) * 100);
    ui->progressBar_2->setValue(player2Time / double(gameTime) * 100);
}

void MainWindow::setStatusLabel(QString input, short fontSize)
{
    QFont labelFont = ui->statusLabel->font();
    labelFont.setPointSize(fontSize);
    ui->statusLabel->setFont(labelFont);

    ui->statusLabel->setText(input);
}

void MainWindow::setStatusLabel(QString input)
{
    ui->statusLabel->setText(input);
}

void MainWindow::connectionSetup()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::timeOut);

    connect(ui->startButton, &QPushButton::clicked, this, [this](){
        qDebug() << "Start button pressed";

        ui->switchButton_1->setEnabled(true);
        ui->timeButton_120s->setEnabled(false);
        ui->timeButtons_5min->setEnabled(false);
        ui->startButton->setEnabled(false);

        currentPlayer = 1;
        ui->statusLabel->setText("Player 1 turn");
        timer->start();
    });

    connect(ui->stopButton, &QPushButton::clicked, this, [this](){
        qDebug() << "Stop button pressed";

        timer->stop();

        ui->timeButton_120s->setEnabled(true);
        ui->timeButtons_5min->setEnabled(true);
        ui->startButton->setEnabled(false);
        ui->switchButton_1->setEnabled(false);
        ui->switchButton_1->setEnabled(false);
        ui->progressBar_1->setValue(0);
        ui->progressBar_2->setValue(0);

        ui->statusLabel->setText("Select gametime and press 'Start'");
    });

    connect(ui->timeButton_120s, &QPushButton::clicked, this, [this](){
        qDebug() << "Time button (120 sec) pressed";

        ui->startButton->setEnabled(true);

        gameTime = 120;
        player1Time = gameTime;
        player2Time = gameTime;

        updateProgressBar();
        setStatusLabel("Gametime: " + QString::number(gameTime) + " s, press 'Start' to begin");
        qDebug() << "Gametime set to" << gameTime << 's';
    });

    connect(ui->timeButtons_5min, &QPushButton::clicked, this, [this](){
        qDebug() << "Time button (5 min) pressed";

        ui->startButton->setEnabled(true);

        gameTime = 300;
        player1Time = gameTime;
        player2Time = gameTime;

        updateProgressBar();
        setStatusLabel("Gametime: " + QString::number(gameTime) + " s, press 'Start' to begin");
        qDebug() << "Gametime set to" << gameTime << 's';
    });

    connect(ui->switchButton_1, &QPushButton::clicked, this, [this](){
        qDebug() << "Switch button 1 pressed";

        currentPlayer = 2;

        ui->switchButton_2->setEnabled(true);
        ui->switchButton_1->setEnabled(false);

        ui->statusLabel->setText("Player 2 turn");
        qDebug() << "Switched to player 2";
    });

    connect(ui->switchButton_2, &QPushButton::clicked, this, [this](){
        qDebug() << "Switch button 2 pressed";

        currentPlayer = 1;

        ui->switchButton_1->setEnabled(true);
        ui->switchButton_2->setEnabled(false);

        ui->statusLabel->setText("Player 1 turn");
        qDebug() << "Switched to player 1";
    });
}
