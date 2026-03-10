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

private:
    Ui::PIN *ui;
    QTimer *timer = new QTimer(this);

signals:
    void sendPIN(QString);
    void sendTimeout();

private slots:
    void handleClick();
    void handleTimeout();
};

#endif // PIN_H
