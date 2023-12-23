#include "mainwindow.h"
#include <QDialog>


#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDialog d;
    w.show();

    return a.exec();
}
