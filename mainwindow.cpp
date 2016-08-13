#include "mainwindow.h"
#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <windowsx.h>
#endif
#include <QRect>
#include <QHoverEvent>
#include <QDebug>
#include <QList>
#include <QStyle>
#include "Menu/minebuttonmenu.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    this->InitView();
    this->InitEvents();
}

MainWindow::~MainWindow()
{
}
void MainWindow::InitView()
{
    btn = new MineButton(this);
    btn->setGeometry(50,50,90,26);
    btn->setButtonText("About");
    btnclose = new CloseButton(this);
    btnclose->setGeometry(16,15,15,15);

    btnMin = new MinButton(this);
    btnMin->setGeometry(39,15,15,15);

    btnMax = new MaxButton(this);
    btnMax->setGeometry(62,15,15,15);

    MineCheckBox *cbF = new MineCheckBox(this);
    cbF->setGeometry(200,200,17,17);
    cbF->ifTristate(true);
    MineCheckBox *cbF2 = new MineCheckBox(this);
    cbF2->setGeometry(250,250,17,17);
    cbF2->ifTristate(false);

    MineRadioButton *rbtn = new MineRadioButton(this);
    rbtn->setGeometry(300,250,20,20);

    MineSlider *slider = new MineSlider(this);
    slider->setGeometry(350,250,200,15);

    MineLineEdit *ledit = new MineLineEdit(this);
    ledit->setGeometry(400,300,150,22);
    btnlist = new ListButton(this);
    btnlist->setGeometry(500,500,150,26);

    MineScrollBar *bar = new MineScrollBar(this);
    bar->setGeometry(100,200,10,300);
    MineButtonMenu *menu = btnlist->getmenu();
    QAction *a1 = menu->addAction(tr("打开文件"));
    QAction *a2 = menu->addAction(tr("退出程序"));

    tw = new MineTab(this);
    tw->setGeometry(600,300,200,20);
    QWidget *tab1 = new QWidget;
    QWidget *tab2 = new QWidget;
    tw->addTab(tab1,"Tab1");
    tw->addTab(tab2,"Tab2");

    cbox = new MineComboBox(this);
    cbox->setGeometry(200,100,80,30);
    cbox->addItem("打开");
    cbox->addItem("关于");

}
void MainWindow::InitEvents()
{
    connect(btnclose,SIGNAL(clicked()),this,SLOT(ApplicationExit()));
    connect(btnMin,SIGNAL(clicked()),this,SLOT(ApplicationMin()));
    connect(btn,SIGNAL(clicked()),this,SLOT(ViewShow()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture())
           SendMessage(HWND(winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
       event->ignore();

#else
#endif
#ifdef Q_OS_OSX
    if (event->button() == Qt::LeftButton) {
            m_Drag = true;
            m_DragPosition = event->globalPos() - this->pos();
            event->accept();
        }
#else
#endif
}
#ifdef Q_OS_OSX
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    if (m_Drag && (event->buttons() && Qt::LeftButton)) {
            move(event->globalPos() - m_DragPosition);
            event->accept();
        }

}

void MainWindow::mouseReleaseEvent()
{
    m_Drag = false;
}
#else
#endif

void MainWindow::ApplicationExit()
{
   qApp->exit();
}

void MainWindow::ApplicationMin()
{
    showMinimized();
    qDebug()<<"Done";
}

void MainWindow::ViewShow()
{
    view = new MineView;
    view->show();
    view->setMinimumSize(500,381);
}

void drawShadow(QPainter &_painter,qint16 _margin,qreal _radius,QColor _start,QColor _end,qreal _startPosition,qreal _endPosition0, qreal _endPosition1,qreal _width, qreal _height)
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
_painter.setBrush(QBrush("#FFFFFF"));
_painter.setRenderHint((QPainter::Antialiasing));
_painter.drawRoundRect(QRectF(QPointF(_margin, _margin),QPointF(_width - _margin,_height - _margin)),_radius,_radius);
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    drawShadow(painter, 10, 2.0, QColor(120,120,120,32),QColor(255,255,255,0),0.0,1.0,0.6,width(),height());
}


