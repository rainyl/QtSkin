#ifndef LISTBUTTON_H
#define LISTBUTTON_H

#include <QWidget>
#include "Button/buttoncommon.h"
#include "Menu/minebuttonmenu.h"
class QMenu;
class ListButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ListButton(QWidget *parent = 0);

    MineButtonMenu * getmenu();
signals:

public slots:
    void popupmenu();
private:
    void paintEvent(QPaintEvent *);
    MineButtonMenu * menu;
};

#endif // LISTBUTTON_H
