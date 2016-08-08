#include "mineslider.h"
#include <QFile>
#include <QString>
#include <QLatin1String>

MineSlider::MineSlider(QWidget *parent) : QSlider(Qt::Horizontal,parent)
{
    QString qss;
    QFile qssFile(":/Slider/slider.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
}
