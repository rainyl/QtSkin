#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#include "Button/buttoncommon.h"
class MineButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MineButton(QWidget *parent = 0);

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
public:
    void setButtonText(QString text);
    QString getText;
};

#endif // MINEBUTTON_H
