#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include "Button/buttoncommon.h"
class CloseButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CloseButton(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
private:
    enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    ButtonStatus status;
    bool mouse_press;

};

#endif // CLOSEBUTTON_H
