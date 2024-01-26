#include "dialog.h"
#include "ui_dialog.h"
//#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //if()
    QString str123 =QString ("Виконано правильно завдань - 4/10");//.arg(grade);
    QString str234 = QString::number(5/12);
   // ui->label->setText(str123);
   // ui->label_2->setText("5");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QApplication::quit();
}


void Dialog::on_Dialog_rejected()
{
    QApplication::quit();
}
