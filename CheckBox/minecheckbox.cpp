#include "minecheckbox.h"
#include <QFile>
#include <QString>
#include <QLatin1String>

#include <QDebug>
MineCheckBox::MineCheckBox(QWidget *parent) : QCheckBox(parent)
{
    QString qss;
    QFile qssFile(":/CheckBox/CheckBoxStyle.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }

    connect(this, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
}

void MineCheckBox::onStateChanged(int state)
{
    if (state == Qt::Checked)
        {
            qDebug()<<("选择");
        }
        else if(state == Qt::PartiallyChecked)
        {
            qDebug()<<("半选");
        }
        else
        {
            qDebug()<<("未选择");
        }

}

void MineCheckBox::ifTristate(bool YN)
{
    if(YN == true)
    {
        setTristate();
    }else if(YN == false)
    {
        setTristate(false);
    }
}
