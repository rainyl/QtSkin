#ifndef MINBUTTON_H
#define MINBUTTON_H

#include "Button/buttoncommon.h"

class MinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MinButton(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    ButtonStatus status;
    bool mouse_press;
};

#endif // MINBUTTON_H
