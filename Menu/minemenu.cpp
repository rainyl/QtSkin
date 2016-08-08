#include "minemenu.h"
#include <QFile>
#include <QString>
#include <QLatin1String>
#include <QAction>
MineMenu::MineMenu(QWidget *parent) : QMenu(parent)
{
    a1 = new QAction(this);
    a1->setText(tr("Open"));
    a2 = new QAction(this);
    a2->setText(tr("Close"));
    a3 = new QAction(this);
    a3->setText(tr("About"));
    a4 = new QAction(this);
    a4->setText(tr("Exit"));
    QString qss;
    QFile qssFile(":/Menu/menu.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
    menu = new QMenu();
    menu->addAction(a1);
    menu->addAction(a2);
    menu->addAction(a3);
    menu->addAction(a4);
    menu->exec(QCursor::pos());
}

