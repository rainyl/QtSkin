#include "listbutton.h"
#include "QPoint"
ListButton::ListButton(QWidget *parent) : QPushButton(parent)
{
    menu = new MineButtonMenu(this);
    connect(this,SIGNAL(clicked()),this,SLOT(popupmenu()));
}

void ListButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap = QPixmap(":/Res/Button/ListButton.png");
    painter.drawPixmap(0,0,150,26,pixmap);
}

MineButtonMenu *ListButton::getmenu()
{
    return menu;
}

void ListButton::popupmenu()
{
    QPoint pos;
    int y = pos.y();
    pos.setY(y+this->geometry().height());
    menu->exec(this->mapToGlobal(pos));

}
