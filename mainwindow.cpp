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
    btnclose->setGeometry(7,10,15,15);

    btnMin = new MinButton(this);
    btnMin->setGeometry(30,10,15,15);

    btnMax = new MaxButton(this);
    btnMax->setGeometry(53,10,15,15);

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



void MainWindow::paintEvent(QPaintEvent *)
{
    /*
    setAttribute(Qt::WA_TranslucentBackground);
    QPainter painter(this);
    this->drawWinowShadow(painter);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));*/
    /*QPainterPath path;
       path.setFillRule(Qt::WindingFill);
       path.addRect(9, 9, this->width()-18, this->height()-18);


       QPainter painter(this);
       painter.setRenderHint(QPainter::Antialiasing, true);
       painter.fillPath(path, QBrush(Qt::white));


       QColor color(0, 0, 0, 50);
       for(int i=0; i<9; i++)
       {
           QPainterPath path;
           path.setFillRule(Qt::WindingFill);
           path.addRect(9-i, 9-i, this->width()-(9-i)*2, this->height()-(9-i)*2);
           color.setAlpha(150 - qSqrt(i)*50);
           painter.setPen(color);
           painter.drawPath(path);
       }*/
}

void MainWindow::drawWinowShadow(QPainter &painter)
{
    /*
    QList<QPixmap> pixmaps;
    pixmaps.append(QPixmap(":/shadow/shadow_left.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_right.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_top.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_bottom.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_left_top.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_right_top.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_left_bottom.png"));
    pixmaps.append(QPixmap(":/shadow/shadow_right_bottom.png"));
    painter.drawPixmap(0, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[4]);
    painter.drawPixmap(this->width()-SHADOW_WIDTH, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[5]);
    painter.drawPixmap(0,this->height()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[6]);
    painter.drawPixmap(this->width()-SHADOW_WIDTH, this->height()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[7]);
    painter.drawPixmap(0, SHADOW_WIDTH, SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH, pixmaps[0].scaled(SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));
    painter.drawPixmap(this->width()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH, pixmaps[1].scaled(SHADOW_WIDTH, this->height()- 2*SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, 0, this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[2].scaled(this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, this->height()-SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[3].scaled(this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH));
    */
}
