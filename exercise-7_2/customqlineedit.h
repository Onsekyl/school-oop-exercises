/*
 * The program ignored switching QLineEdit fields via the mouse click,
 * so I made CustomQLineEdit class for sending a signal to the MainWindow,
 * which then has a handler for changing the fieldInFocus (state) accordingly
*/

#ifndef CUSTOMQLINEEDIT_H
#define CUSTOMQLINEEDIT_H

#include <QLineEdit>

class CustomQLineEdit : public QLineEdit
{
    Q_OBJECT

signals:
    void wasFocused();

public:
    explicit CustomQLineEdit(QWidget *parent = nullptr);

protected:
    void focusInEvent(QFocusEvent *event) override;
};

#endif // CUSTOMQLINEEDIT_H
