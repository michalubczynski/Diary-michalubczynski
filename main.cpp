#include "mainwindow.h"
#include "uslugi.h"
#include "edycyjne.h"
#include "dane.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uslugi us;
    MainWindow _main(nullptr,&us);
    Edycyjne edycyjne(nullptr,&us);
    dane dana(nullptr,&us);
    _main.show();
    return a.exec();
}
