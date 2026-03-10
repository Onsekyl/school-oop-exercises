#ifndef PIN_H
#define PIN_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class PIN;
}

class PIN : public QDialog
{
    Q_OBJECT

public:
    explicit PIN(QWidget *parent = nullptr);
    ~PIN();

signals:
    void sendPIN(QString);
    void sendTimeOut();

private slots:
    void handleClick();
    void handleTimeout();

private:
    Ui::PIN *ui;
    QTimer * pQtimer = new QTimer(this);
};

#endif // PIN_H
