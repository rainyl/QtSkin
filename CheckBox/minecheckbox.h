#ifndef MINECHECKBOX_H
#define MINECHECKBOX_H

#include <QWidget>
#include <QCheckBox>
class MineCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    explicit MineCheckBox(QWidget *parent = 0);

signals:

public slots:
    void onStateChanged(int state);
    void ifTristate(bool YN);
};

#endif // MINECHECKBOX_H
