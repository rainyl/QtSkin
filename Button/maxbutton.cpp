#include "maxbutton.h"

MaxButton::MaxButton(QWidget *parent) : QPushButton(parent)
{

}

void MaxButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    pixmap = QPixmap(":/Res/buttonMax.png");
    painter.drawPixmap(0,0,15,15,pixmap);
}
