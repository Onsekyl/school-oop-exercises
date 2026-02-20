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

private:
    Ui::MainWindow *ui;
    int fieldInFocus = 0;

private slots:
    void numberButtonHandler();
    void arithmeticButtonHandler();
    void actionButtonHandler();
    void lineEditPressHandler();
};
#endif // MAINWINDOW_H
