#ifndef MINEMENU_H
#define MINEMENU_H

#include <QWidget>
#include <QTreeWidget>
#include <QMenu>
#include <QContextMenuEvent>
#include <QAction>
class MineMenu : public QMenu
{
    Q_OBJECT
public:
    explicit MineMenu(QWidget *parent = 0);

signals:

public slots:

private:
    QMenu *menu;
    QAction *a1;
    QAction *a2;
    QAction *a3;
    QAction *a4;
};

#endif // MINEMENU_H
