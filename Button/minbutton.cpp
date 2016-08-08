#include "minbutton.h"
#include <QPixmap>
MinButton::MinButton(QWidget *parent) : QPushButton(parent)
{
   status = NORMAL;
   mouse_press = false;
   this->setFlat(true);
}

void MinButton::enterEvent(QEvent *)
{
    status = ENTER;
    update();
}

void MinButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}

void MinButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}

void MinButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(mouse_press  && this->rect().contains(e->pos()))
        {
            mouse_press = false;
            status = ENTER;
            update();
            emit clicked();
        }
}

void MinButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    painter.setRenderHint(QPainter::Antialiasing,true);
    switch (status)
    {
    case NORMAL:
        pixmap.load(":/Res/buttonMinNOMAL.png");
        break;
    case ENTER:
        pixmap.load(":/Res/buttonMinENTER.png");
        break;
    case PRESS:
        pixmap.load(":/Res/buttonMinPRESS.png");
        break;
    case NOSTATUS:
        pixmap.load(":/Res/buttonMinENTER.png");
        break;
    default:
        pixmap.load(":/Res/buttonMinNOMAL.png");
        break;
    }
    painter.drawPixmap(0,0,15,15,pixmap);
}
