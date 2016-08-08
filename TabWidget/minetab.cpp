#include "minetab.h"
#include <QFile>
#include <QString>
#include <QLatin1String>
MineTab::MineTab(QWidget *parent) : QTabWidget(parent)
{
    QString qss;
    QFile qssFile(":/TabWidget/tabwidget.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
}
