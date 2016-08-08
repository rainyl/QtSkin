#include "mineradiobutton.h"
#include <QFile>
#include <QString>
#include <QLatin1String>

MineRadioButton::MineRadioButton(QWidget *parent) : QRadioButton(parent)
{
    QString qss;
    QFile qssFile(":/RadioButton/radiobutton.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
}
