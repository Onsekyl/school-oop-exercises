#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reader = new Reader(this);
    reader->readInfo();
    connect(reader, &Reader::sendData, this, &MainWindow::handleCardNumber);
    qDebug() << "Did port open:" << reader->open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCardNumber(QByteArray value)
{
    qDebug() << "[MAINWINDOW HANDLECARDNUMBER]";
    ui->lineEdit->setText(value);
}

