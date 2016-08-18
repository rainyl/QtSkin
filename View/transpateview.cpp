#include "transpateview.h"
#include <QPixmap>
#include <QPalette>
#include <QLinearGradient>
#include "View/vieweffect.h"
TranspateView::TranspateView(QWidget *parent) : QDialog(parent)
{
    btnClose = new CloseButton(this);
    btnClose->setGeometry(10,10,15,15);
    setAttribute(Qt::WA_TranslucentBackground);
    connect(btnClose,SIGNAL(clicked()),this,SLOT(closeView()));
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint| windowFlags());
    //this->setAutoFillBackground(true);
//    QPixmap pixmap(":/Res/View/AboutView.jpg");//
//    QPixmap fitpixmap =
//    pixmap.scaled(580, 357);//.scaled(580,357, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    QPalette palette;
//    palette.setBrush(QPalette::Background, QBrush(fitpixmap));
//    this->setPalette(palette);

}
void drawShadow2(QPainter &_painter,qint16 _margin,qreal _radius,QColor _start,QColor _end,qreal _startPosition,qreal _endPosition0, qreal _endPosition1,qreal _width, qreal _height)
{
_painter.setPen(Qt::NoPen);
QLinearGradient gradient;
gradient.setColorAt(_startPosition,_start);
gradient.setColorAt(_endPosition0,_end);
//右边绘制
QPointF right0(_width - _margin, _height / 2);
QPointF right1(_width, _height / 2);
gradient.setStart(right0);
gradient.setFinalStop(right1);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(QPointF(_width - _margin*_radius, _margin),QPointF(_width, _height - _margin)),0.0,0.0);
//左边绘制
QPointF left0(_width - _margin, _height / 2);
QPointF left1(0, _height / 2);
gradient.setStart(left0);
gradient.setFinalStop(left1);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(QPointF(_margin*_radius, _margin),QPointF(0, _height - _margin)),0.0,0.0);
//顶部绘制
QPointF top0(_width - _margin, _margin);
QPointF top1(_width / 2, 0);
gradient.setStart(top0);
gradient.setFinalStop(top1);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(QPointF(_width - _margin, _margin),QPointF(_margin, _margin)),0.0,0.0);
//底部绘制
QPointF bottom0(_width / 2, _height - _margin);
QPointF bottom1(_width / 2, _height);
gradient.setStart(bottom0);
gradient.setFinalStop(bottom1);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(QPointF(_margin, _height - _margin),QPointF(_width -  _margin, _height)),0.0,0.0);
//底部右角
QPointF bottomright0(_width - _margin, _height - _margin);
QPointF bottomright1(_width, _height);
gradient.setStart(bottomright0);
gradient.setFinalStop(bottomright1);
gradient.setColorAt(_endPosition1, _end);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(bottomright0, bottomright1), 0.0,0.0);
//底部左角
QPointF bottomleft0(_margin, _height - _margin);
QPointF bottomleft1(0, _height);
gradient.setStart(bottomleft0);
gradient.setFinalStop(bottomleft1);
gradient.setColorAt(_endPosition1, _end);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(bottomleft0, bottomleft1),0.0,0.0);
//顶部左角
QPointF topleft0(_margin,_margin);
QPointF topleft1(0, 0);
gradient.setStart(topleft0);
gradient.setFinalStop(topleft1);
gradient.setColorAt(_endPosition1, _end);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(topleft0, topleft1),0.0,0.0);
//顶部右角
QPointF topright0(_width - _margin,_margin);
QPointF topright1(_width, 0);
gradient.setStart(topright0);
gradient.setFinalStop(topright1);
gradient.setColorAt(_endPosition1, _end);
_painter.setBrush(QBrush(gradient));
_painter.drawRoundRect(QRectF(topright0, topright1),0.0,0.0);
//窗体
//_painter.setBrush(QBrush("#FFFFFF"));
_painter.setRenderHint((QPainter::Antialiasing));
_painter.drawRoundRect(QRectF(QPointF(_margin, _margin),QPointF(_width - _margin,_height - _margin)),_radius,_radius);
}
void TranspateView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/Res/View/View.png"));




    //drawShadow(painter, 10, 2.0, QColor(120,120,120,32),QColor(255,255,255,0),0.0,1.0,0.6,width(),height());

    // setStyleSheet("background-image: url(:/Res/View/AboutView.jpg)");

}

void TranspateView::closeView()
{
    this->close();
}
