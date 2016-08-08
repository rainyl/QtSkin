#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.setAttribute(Qt::WA_TranslucentBackground);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setMinimumSize(1024,700);
    w.show();

    return a.exec();
}
