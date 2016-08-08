#ifndef MAXBUTTON_H
#define MAXBUTTON_H

#include "Button/buttoncommon.h"
class MaxButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MaxButton(QWidget *parent = 0);

signals:

public slots:
    void paintEvent(QPaintEvent *);
private:
    QPixmap pixmap;
};

#endif // MAXBUTTON_H
