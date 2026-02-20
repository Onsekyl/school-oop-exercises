#include "customqlineedit.h"


CustomQLineEdit::CustomQLineEdit(QWidget *parent)
    : QLineEdit{parent}
{

}

void CustomQLineEdit::mousePressEvent(QMouseEvent *event) {
    qDebug() << "[CUSTOMQLINEEDIT]: Focused manually on " << this->objectName();
    emit wasPressed();

    // Also do the base functionality of QLineEdit::mousePressEvent()
    QLineEdit::mousePressEvent(event);
}
