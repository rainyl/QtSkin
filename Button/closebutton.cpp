#include "closebutton.h"
#include <QPixmap>
#include <QSize>
#include <QDebug>

CloseButton::CloseButton(QWidget *parent) : QPushButton(parent)
{
    status = NORMAL;
    mouse_press = false;
    this->setFlat(true);
}

void CloseButton::enterEvent(QEvent *)
{
    status = ENTER;
    update();
}

void CloseButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}

void CloseButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}
void CloseButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(mouse_press  && this->rect().contains(event->pos()))
        {
            mouse_press = false;
            status = ENTER;
            update();
            emit clicked();
        }
}

void CloseButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    painter.setRenderHint(QPainter::Antialiasing,true);
    switch (status) {
    case NORMAL:
        pixmap.load(":/Res/buttonCloseNORMAL.png");
        break;
    case ENTER:
        pixmap.load(":/Res/buttonCloseENTER.png");
        break;
    case PRESS:
        pixmap.load(":/Res/buttonClosePRESS.png");
        break;
    case NOSTATUS:
        pixmap.load(":/Res/buttonCloseENTER.png");
        break;
    default:
        pixmap.load(":/Res/buttonCloseNORMAL.png");
        break;
    }
    painter.drawPixmap(0,0,15,15,pixmap);
}
