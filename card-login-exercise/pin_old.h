#ifndef PIN_OLD_H
#define PIN_OLD_H

#include <QDialog>

namespace Ui {
class Pin;
}

class Pin : public QDialog
{
    Q_OBJECT

public:
    explicit Pin(QWidget *parent = nullptr);
    ~Pin();

private:
    Ui::Pin *ui;

signals:
    sendPin(QString);

private slots:
    void handleClick();

};

#endif // PIN_OLD_H
