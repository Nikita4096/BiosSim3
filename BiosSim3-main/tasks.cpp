#include "tasks.h"
#include "ui_tasks.h"
#include "mainwindow.cpp"

Tasks::Tasks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tasks)
{
    ui->setupUi(this);
    if(str5 = "Serial Port1 Address 3F8/IRQ4")
        ui->listWidget->editItem(ui->listWidget->item(2)).setStrikeOut(true);
}

Tasks::~Tasks()
{
    delete ui;
}
