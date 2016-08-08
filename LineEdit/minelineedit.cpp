#include "minelineedit.h"
#include <QIcon>
#include <QDebug>

MineLineEdit::MineLineEdit(QWidget *parent) : QLineEdit(parent)
{
    Cancel = new QAction(this);
    this->setStyleSheet("QLineEdit{ background:rgba(0,0,0,0%); border:1px; font:10pt; border-image:url(:/Res/LineEdit/UnEditing.png);}"
"QLineEdit:hover{ border-image:url(:/Res/LineEdit/Hover.png); }"
"QLineEdit:!hover{background:rgba(0,0,0,0%);}"
"QLineEdit:focus {border-radius:2px;border-image:url(:/Res/LineEdit/Editing.png);}"
                        );

    connect(Cancel, SIGNAL(triggered(bool)), this, SLOT(CancelLineEdit()));
}

void MineLineEdit::CancelLineEdit()
{
    this->setText("");
}

void MineLineEdit::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton)
    {
        Cancel->setIcon(QIcon(":/Res/LineEdit/Cancel.png"));
        addAction(Cancel,QLineEdit::TrailingPosition);
        connect(Cancel, SIGNAL(triggered(bool)), this, SLOT(CancelLineEdit()));
    }
}

void MineLineEdit::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease)
                {

                }
}

bool MineLineEdit::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == this)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->buttons() && Qt::LeftButton)
            {
                Cancel->setIcon(QIcon(":/Res/LineEdit/Cancel.png"));
                addAction(Cancel,QLineEdit::TrailingPosition);

                qDebug()<<"Emit";
            }else if (event->type() == QEvent::MouseButtonRelease)
            {
                removeAction(Cancel);
            }
        }
    }
    return MineLineEdit::eventFilter(watched,event);
}

void MineLineEdit::focusOutEvent(QFocusEvent *)
{
    qDebug()<<"Emit";
    removeAction(Cancel);
}
