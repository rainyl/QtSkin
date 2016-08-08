#include "mineview.h"
#include <QPalette>
#include <QVBoxLayout>
#include <QDebug>
MineView::MineView(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setAttribute(Qt::WA_TranslucentBackground);
    TitleBar *pTitleBar = new TitleBar(this);
    pTitleBar->setGeometry(30,0,15,15);
    setWindowTitle("Custom Window");
       QVBoxLayout *pLayout = new QVBoxLayout();
       pLayout->addWidget(pTitleBar);
       pLayout->addStretch(0);
       pLayout->setSpacing(0);
       pLayout->setContentsMargins(0, 2, 2, 2);
       setLayout(pLayout);
}

void MineView::mousePressEvent(QMouseEvent *)
{

}

void MineView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/Res/View/BG.png"));
    qDebug()<<"Emit";
}
