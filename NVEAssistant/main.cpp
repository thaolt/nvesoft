#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

extern "C" {
    #include "LiteCAD.h"
}

int main(int argc, char *argv[])
{
    qDebug() << lcLoadLib64();
    lcInitialize();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
