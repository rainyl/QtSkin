#ifndef MINESCROLLBAR_H
#define MINESCROLLBAR_H

#include <QWidget>
#include <QScrollBar>
class MineScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    explicit MineScrollBar(QWidget *parent = 0);

signals:

public slots:
};

#endif // MINESCROLLBAR_H
