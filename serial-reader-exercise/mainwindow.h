#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reader.h"
#include <QMainWindow>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    Reader *reader;

public slots:
    void handleCardNumber(QByteArray);
};
#endif // MAINWINDOW_H
