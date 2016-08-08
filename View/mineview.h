#ifndef MINEVIEW_H
#define MINEVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <qt_windows.h>
#include <View/titlebar.h>
class MineView : public QWidget
{
    Q_OBJECT
public:
    explicit MineView(QWidget *parent = 0);

signals:

public slots:

private:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
};

#endif // MINEVIEW_H
