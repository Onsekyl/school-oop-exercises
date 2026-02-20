#include "customqlineedit.h"


CustomQLineEdit::CustomQLineEdit(QWidget *parent)
    : QLineEdit{parent}
{

}

void CustomQLineEdit::focusInEvent(QFocusEvent *event)
{
    qDebug() << "Focused manually on " << this->objectName();
    emit wasFocused();

    // Also do the base functionalities of QLineEdit
    QLineEdit::focusInEvent(event);
}
