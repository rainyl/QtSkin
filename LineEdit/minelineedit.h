#ifndef MINELINEEDIT_H
#define MINELINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QMouseEvent>
#include <QAction>
#include <QEvent>
class MineLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MineLineEdit(QWidget *parent = 0);
    QAction *Cancel;
signals:

public slots:
    void CancelLineEdit();
private:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    bool eventFilter(QObject *watched, QEvent *event);
protected:
       virtual void focusOutEvent(QFocusEvent *);
};

#endif // MINELINEEDIT_H
