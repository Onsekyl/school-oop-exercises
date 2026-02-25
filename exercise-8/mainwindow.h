#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

public slots:
    void timeOut();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    short gameTime, currentPlayer = 1, player1Time, player2Time;

    void connectionSetup();
    void updateProgressBar();
    void setStatusLabel(QString input, short fontSize);
    void setStatusLabel(QString input);
};
#endif // MAINWINDOW_H
