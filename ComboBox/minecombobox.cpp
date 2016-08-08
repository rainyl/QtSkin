#include "minecombobox.h"
#include <QFile>
#include <QString>
#include <QLatin1String>
MineComboBox::MineComboBox(QWidget *parent) : QComboBox(parent)
{

    setStyleSheet("QComboBox {border: 1px solid transparent;border-radius: 6px;border-image:  url(:/Res/ComboBox/BG.png);}"
                  "QComboBox::drop-down {subcontrol-origin: padding;subcontrol-position: top right;width: 18px;border-left-width: 3px;border-left-color: #cccccc;border-left-style: solid; border-top-right-radius: 16px; border-bottom-right-radius: 16px;}"
                  "QComboBox::down-arrow {border: 0px solid transparent;image: url(:/Res/ComboBox/A.png);}"
                  "QComboBox::down-arrow:on {border: 0px solid transparent;image: url(:/Res/ComboBox/B.png);}"
                  );



}
