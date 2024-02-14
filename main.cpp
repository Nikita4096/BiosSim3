#include "mainwindow.h"
#include <QDialog>




#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QApplication a(argc, argv);


    MainWindow w;
    w.setWindowTitle("BiosSim");

    QDialog d;

    //int grade;

    w.show();

    return a.exec();
}
