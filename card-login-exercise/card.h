#ifndef CARD_H
#define CARD_H

#include <QDialog>

namespace Ui {
class CARD;
}

class CARD : public QDialog
{
    Q_OBJECT

public:
    explicit CARD(QWidget *parent = nullptr);
    ~CARD();

signals:
    void sendCard(QString);

private slots:
    void handleClick();


private:
    Ui::CARD *ui;
};

#endif // CARD_H
