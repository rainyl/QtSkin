#include "titlebar.h"
#include <QHBoxLayout>
#include <qt_windows.h>
#include <QWidget>

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(45);
    title = new QLabel(this);
    btnclose = new CloseButton(this);
    btnMin = new MinButton(this);
    btnMax = new MaxButton(this);

    title->setText("About");
    title->setFixedSize(30,30);
    title->setScaledContents(true);
    title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    btnclose->setFixedSize(15,15);
    btnMax->setFixedSize(15,15);
    btnMin->setFixedSize(15,15);

    btnclose->setToolTip(tr("关闭"));
    btnMax->setToolTip(tr("最大化"));
    btnMin->setToolTip(tr("最小化"));

    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(btnclose);
    pLayout->addWidget(btnMin);
    pLayout->addWidget(btnMax);
    pLayout->addSpacing(0);
    pLayout->addWidget(title);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 5, 0, 5);
    setLayout(pLayout);
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture())
    {
        QWidget *pWindow = this->window();
        if (pWindow->isTopLevel())
        {
           SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }
       event->ignore();
#else
#endif
}

void TitleBar::paintEvent(QPaintEvent *)
{
    /*QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/Res/View/TitleBar.png"));*/
}

void TitleBar::onCliked()
{

}
