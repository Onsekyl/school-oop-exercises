/*
 * The program ignored switching QLineEdit fields via a mouse press,
 * so I made CustomQLineEdit class that sends a signal for a handler
 * in MainWindow when that happens.
*/

#ifndef CUSTOMQLINEEDIT_H
#define CUSTOMQLINEEDIT_H

#include <QLineEdit>

class CustomQLineEdit : public QLineEdit
{
    Q_OBJECT

signals:
    void wasPressed();

public:
    explicit CustomQLineEdit(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CUSTOMQLINEEDIT_H
