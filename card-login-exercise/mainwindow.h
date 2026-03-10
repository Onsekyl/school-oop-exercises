#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "card.h"
#include "pin.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Card *card = nullptr;
    PIN *pPin = nullptr;
    int cardNumber;
    int pin;
    int correctCardNumber = 1234;
    int correctPin = 1111;
    int attemptsLeft = 3;

public slots:
    void handleCard(QString);
    void handlePin(QString);
    void handleTimeOut();

private slots:
    void handleClick();
};
#endif // MAINWINDOW_H
