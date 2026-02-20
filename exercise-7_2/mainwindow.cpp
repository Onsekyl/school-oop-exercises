/*
 * I made the button connections in forms designer.
 *
*/

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

void MainWindow::numberButtonHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonName = button->objectName();
    qDebug() << "[NUMBERBUTTONHANDLER]: " << buttonName << " pressed";

    switch (state)
    {
        case 1:
            qDebug() << "Adding " << buttonName.last(1) << " to Number 2 field";
            ui->num2->insert(buttonName.last(1));
            break;

        default:
            qDebug() << "Adding " << buttonName.last(1) << " Number 1 field";
            ui->num1->insert(buttonName.last(1));
            break;
    }
}

void MainWindow::arithmeticButtonHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonName = button->objectName();
    qDebug() << "[ARITHMETICBUTTONHANDLER]: " << buttonName << " pressed";

    int num1 = ui->num1->text().toInt();
    int num2 = ui->num2->text().toInt();

    // Maybe check that both fields have a value
    // + that we are not dividing with a 0.
    // You can disable buttons with ui->buttonName->SetEnable(false);
    // (and enable with true).

    qDebug() << "Performing: " << buttonName;

    // Switch operation doesn't support string data type
    if (buttonName == "addition")
    {
        ui->result->setText(QString::number(num1 + num2));
    }
    else if (buttonName == "subtraction")
    {
        ui->result->setText(QString::number(num1 - num2));
    }
    else if (buttonName == "division")
    {
        ui->result->setText(QString::number(num1 / num2));
    }
    else if (buttonName == "multiplication")
    {
        ui->result->setText(QString::number(num1 * num2));
    }
}

void MainWindow::actionButtonHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonName = button->objectName();
    qDebug() << "[ACTIONBUTTONHANDLER]: " << buttonName << " pressed";

    if (buttonName == "enter")
    {
        qDebug() << "Focusing the other field";
        state == 0 ? state = 1 : state = 0;
    }
    else if (buttonName == "clear")
    {
        qDebug() << "Clearing the fields and starting over";
        ui->num1->clear();
        ui->num2->clear();
        state = 0;
    }
}
