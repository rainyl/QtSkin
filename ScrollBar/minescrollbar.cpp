#include "minescrollbar.h"
#include <QFile>
#include <QGraphicsOpacityEffect>
MineScrollBar::MineScrollBar(QWidget *parent) : QScrollBar(parent)
{
    QGraphicsOpacityEffect *e = new QGraphicsOpacityEffect(this);
    setGraphicsEffect(e);
    e->setOpacity(0.5);
    QFile file(":/ScrollBar/scrollbar.qss");
    file.open(QFile::ReadOnly);
    setStyleSheet(file.readAll());
}
