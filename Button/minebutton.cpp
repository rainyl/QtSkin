#include "minebutton.h"
#include <QGraphicsDropShadowEffect>
MineButton::MineButton(QWidget *parent) : QPushButton(parent)
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(2, 2);
    shadow->setColor(Qt::gray);
    shadow->setBlurRadius(1);
    setGraphicsEffect(shadow);
    status = NORMAL;
    mouse_press = false;
    this->setFlat(true);
}

void MineButton::enterEvent(QEvent *)
{
    status = ENTER;
    update();
}

void MineButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}

void MineButton::mouseReleaseEvent(QMouseEvent *event)
{
    if(mouse_press  && this->rect().contains(event->pos()))
        {
            mouse_press = false;
            status = ENTER;
            update();
            emit clicked();
        }
}

void MineButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}

void MineButton::setButtonText(QString text)
{
    getText = text;
}

void MineButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    painter.setRenderHint(QPainter::Antialiasing,true);
    QFont font(".萍方-简",15,QFont::Light);
    /*int nIndex = QFontDatabase::addApplicationFont(":/Res/Font/HANYITime.ttf");
    if (nIndex != -1)
    {
    QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
    if (strList.count() > 0)
    {
    font = QFont(strList.at(0));
    font.setPointSize(13);
    }
    }*/
    painter.setFont(font);
    switch (status) {
    case NORMAL:
        pixmap.load(":/Res/MineButtonNOMRMAL.png");
        break;
    case ENTER:
        pixmap.load(":/Res/MineButtonENTER.png");
        break;
    case PRESS:
        pixmap.load(":/Res/MineButtonPress.png");
        break;
    case NOSTATUS:
        pixmap.load(":/Res/MineButtonENTER.png");
        break;
    default:
        pixmap.load(":/Res/MineButtonNOMRMAL.png");
        break;
    }
    painter.drawPixmap(0,0,90,26,pixmap);
    painter.drawText(rect(),Qt::AlignCenter,getText);
}
