//author:Nice_try
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("calc");
    w.setWindowIcon(QIcon(":doc/calc.svg"));

    w.show();
    return a.exec();
}
