#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SHADOW_WIDTH            3
#define WINDOW_WIDTH            680
#define WINDOW_HEIGHT           372
#define WINDOW_START_X          0
#define WINDOW_START_Y          0
#define WINDOW_PAGE_COUNT       4
#define WINDOW_BUTTON_COUNT     4
#define WINDOW_PAGE_MOVE        20
#define WINDOW_ONEBUTTON_WIDTH  170

#include <QApplication>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>
#include <QPainter>
#include <QtMath>
#include <QColor>
#include <QTimer>
#include "Button/maxbutton.h"
#include "Button/closebutton.h"
#include "Button/minbutton.h"
#include "Button/minebutton.h"
#include "Button/listbutton.h"
#include "CheckBox/minecheckbox.h"
#include "RadioButton/mineradiobutton.h"
#include "Slider/mineslider.h"
#include "LineEdit/minelineedit.h"
#include "ScrollBar/minescrollbar.h"
#include "Menu/minemenu.h"
#include "TabWidget/minetab.h"
#include "ComboBox/minecombobox.h"
#include "View/mineview.h"
class MainWindow;
class QColor;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void start();

private:
    void drawWinowShadow(QPainter &painter);
    void InitView();
    void InitEvents();
    void mousePressEvent(QMouseEvent *event);

#ifdef Q_OS_OSX
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent();
    bool m_Drag = false;
    QPoint m_DragPosition;
#else
#endif
    QPushButton *btnExit;
    void paintEvent(QPaintEvent *event);
    MaxButton *btnMax;
    CloseButton *btnclose;
    MinButton * btnMin;
    MineMenu *menu;
    ListButton *btnlist;
    MineButton *btn;
    MineTab *tw;

    MineComboBox *cbox;
    MineView *view;

public slots:
    void ApplicationExit();
    void ApplicationMin();
    void ViewShow();
};

#endif // MAINWINDOW_H
