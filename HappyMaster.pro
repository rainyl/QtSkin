#-------------------------------------------------
#
# Project created by QtCreator 2016-08-03T11:07:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HappyMaster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frameless_helper.cpp \
    Button/maxbutton.cpp \
    Button/closebutton.cpp \
    Button/minbutton.cpp \
    Button/minebutton.cpp \
    CheckBox/minecheckbox.cpp \
    RadioButton/mineradiobutton.cpp \
    Slider/mineslider.cpp \
    LineEdit/minelineedit.cpp \
    Button/listbutton.cpp \
    ScrollBar/minescrollbar.cpp \
    Menu/minemenu.cpp \
    Menu/minebuttonmenu.cpp \
    TabWidget/minetab.cpp \
    ComboBox/minecombobox.cpp \
    View/mineview.cpp \
    View/titlebar.cpp

HEADERS  += mainwindow.h \
    frameless_helper.h \
    Button/maxbutton.h \
    Button/closebutton.h \
    Button/minbutton.h \
    Button/buttoncommon.h \
    Button/minebutton.h \
    CheckBox/minecheckbox.h \
    RadioButton/mineradiobutton.h \
    Slider/mineslider.h \
    LineEdit/minelineedit.h \
    Button/listbutton.h \
    ScrollBar/minescrollbar.h \
    Menu/minemenu.h \
    Menu/minebuttonmenu.h \
    TabWidget/minetab.h \
    ComboBox/minecombobox.h \
    View/mineview.h \
    View/titlebar.h

FORMS    += \
    testform.ui

RESOURCES += \
    buttons.qrc \
    checkbox.qrc \
    radiobutton.qrc \
    slider.qrc \
    lineedit.qrc \
    scrollbar.qrc \
    menu.qrc \
    tabwidget.qrc \
    combobox.qrc \
    view.qrc

DISTFILES += \
    RadioButton/radiobutton.qss \
    Slider/slider.qss \
    ScrollBar/scrollbar.qss \
    Menu/menu.qss
