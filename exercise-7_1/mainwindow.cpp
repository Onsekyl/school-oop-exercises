#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_countButton_clicked()
{
    checkButton();
    qDebug() << "Upping the result box's value by 1";
    ui->resultBox->setText(QString::number(ui->resultBox->text().toInt() + 1));
}

void MainWindow::on_resetButton_clicked()
{
    checkButton();
    qDebug() << "Resetting the result box's value";
    ui->resultBox->setText("0");
}

void MainWindow::checkButton()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonName = button->objectName();
    qDebug() << buttonName << "pressed";
}
