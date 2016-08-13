#ifndef TRANSPATEVIEW_H
#define TRANSPATEVIEW_H

#include <QWidget>
#include <QPainterPath>
#include <QPaintEvent>
#include <QPainter>
#include <QDialog>
#include <Button/closebutton.h>
class TranspateView : public QDialog
{
    Q_OBJECT
public:
    explicit TranspateView(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
private:
    CloseButton *btnClose;
signals:

public slots:
    void closeView();
};

#endif // TRANSPATEVIEW_H
