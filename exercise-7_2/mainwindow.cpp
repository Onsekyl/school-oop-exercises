/*
 * Button connections were made via Forms.
 * You can find them in Signals and Slots Editor -tab
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

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

    switch (fieldInFocus)
    {
        case 1:
            qDebug() << "Adding " << buttonName.last(1) << " to Number 2 field";
            ui->num2->insert(buttonName.last(1));
            ui->num2->setFocus();
            break;

        default:
            qDebug() << "Adding " << buttonName.last(1) << " Number 1 field";
            ui->num1->insert(buttonName.last(1));
            ui->num1->setFocus();
            break;
    }
}

void MainWindow::arithmeticButtonHandler()
{
    // Value outside this range will make .hasMatch() return true
    static QRegularExpression regex("[^0-9]");

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonName = button->objectName();
    qDebug() << "[ARITHMETICBUTTONHANDLER]: " << buttonName << " pressed";

    int num1 = ui->num1->text().toInt();
    int num2 = ui->num2->text().toInt();

    qDebug() << "Performing: " << buttonName;

    if (ui->num1->text().isEmpty() || ui->num2->text().isEmpty())
    {
        ui->result->setText("Missing value");
    }
    else if (regex.match(ui->num1->text()).hasMatch() || regex.match(ui->num2->text()).hasMatch())
    {
        qDebug() << "Invalid value";
        ui->result->setText("Invalid value");
    }
    else if (buttonName == "addition")
    {
        ui->result->setText(QString::number(num1 + num2));
    }
    else if (buttonName == "subtraction")
    {
        ui->result->setText(QString::number(num1 - num2));
    }
    else if (buttonName == "division")
    {
        if (num2 != 0)
        {
            ui->result->setText(QString::number(num1 / num2));
        }
        else
        {
            qDebug() << "Trying to divide with 0";
            ui->result->setText("Invalid divisor");
        }
    }
    else if (buttonName == "multiplication")
    {
        ui->result->setText(QString::number(num1 * num2));
    }

    fieldInFocus == 0 ? ui->num1->setFocus() : ui->num2->setFocus();
}

void MainWindow::actionButtonHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonName = button->objectName();
    qDebug() << "[ACTIONBUTTONHANDLER]: " << buttonName << " pressed";

    if (buttonName == "enter")
    {
        qDebug() << "Focusing the other field";

        switch (fieldInFocus)
        {
            case 1:
                fieldInFocus = 0;
                ui->num1->setFocus();
                break;

            default:
                fieldInFocus = 1;
                ui->num2->setFocus();
                break;
        }
    }
    else if (buttonName == "clear")
    {
        qDebug() << "Clearing the fields and starting over";
        ui->num1->clear();
        ui->num2->clear();
        fieldInFocus = 0;
        ui->num1->setFocus();
    }
}
