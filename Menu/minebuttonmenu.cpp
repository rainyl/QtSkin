#include "minebuttonmenu.h"
#include <QFile>
#include <QString>
#include <QLatin1String>

MineButtonMenu::MineButtonMenu(QWidget *parent) : QMenu(parent)
{
    QString qss;
    QFile qssFile(":/Menu/menu.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
}
