#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include "Button/closebutton.h"
#include "Button/maxbutton.h"
#include "Button/minbutton.h"
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
class QLabel;
class CloseButton;
class MaxButton;
class MinButton;
class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = 0);
protected:

    virtual void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void onCliked();
private:
    QLabel *title;
    CloseButton *btnclose;
    MaxButton *btnMax;
    MinButton *btnMin;
};

#endif // TITLEBAR_H
