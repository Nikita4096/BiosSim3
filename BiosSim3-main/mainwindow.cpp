#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Pages->hide();
    ui->portsPref->hide();


    ui->tableWidget->setAttribute( Qt::WA_TransparentForMouseEvents );


    ui->tableWidget_2->setAttribute( Qt::WA_TransparentForMouseEvents );


    ui->tableWidget_3->setAttribute( Qt::WA_TransparentForMouseEvents );


    ui->tableWidget_4->setAttribute( Qt::WA_TransparentForMouseEvents );


    ui->tableWidget_5->setAttribute( Qt::WA_TransparentForMouseEvents );
    ui->tableWidget_5->setItem(0, 0, item1);
    ui->tableWidget_5->setItem(1, 0, item2);
    //ui->Pages->setCurrentWidget(ui->serialPort);
   // ui->Pages->show();


    //ui->LanqSelect->hide();

    //ui->tableWidget->setFrameShape(QAbstractScrollArea::NoFrame);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_tableWidget_cellActivated(int row, int column)
{
    if (row == 2)
    {
        disableMovement = true;
       // ui->stackedWidget->setDisabled(true);
        //qDebug() << "I'm right"<<Qt::endl;


        ui->Pages->setCurrentWidget(ui->lanq);
        ui->Pages->show();
        ui->LanqSelect->setFocus();

    }
    if (row == 1)
    {
        closeMain();
        ui->Pages->setCurrentWidget(ui->date);
        ui->Pages->show();
    }
    if (row == 0)
    {
        closeMain();
        ui->Pages->setCurrentWidget(ui->summary);
        ui->Pages->show();
    }

}
void MainWindow::on_LanqSelect_cellActivated(int row=0, int column=0)
{
    ui->Pages->hide();
    ui->tableWidget->setFocus();
    disableMovement = false;

}






void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{

}


void MainWindow::on_tableWidget_2_cellActivated(int row, int column=0)
{
    switch(row)
    {
    case 0:
    {
        closeMain();
        ui->Pages->setCurrentWidget(ui->serialPort);
        ui->Pages->show();
        ui->tableWidget_5->setFocus();
       /* if(row == 0)
        {
            auto a = valtext;
            QString str1 = QString("Serial Port1 Address [%1]").arg(valtext);
            QTableWidgetItem *item1 = new QTableWidgetItem(str1);
            ui->tableWidget_5->setItem(0, 0, item1);
        }
        else if(row == 1)
        {
            QString str2 = QString("Serial Port1 Address [%1]").arg(valtext);
            QTableWidgetItem *item2 = new QTableWidgetItem(str2);
            ui->tableWidget_5->setItem(0, 1, item2);
        }*/

    }

        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:

        break;
    case 9:
        break;
    }
}
void MainWindow::on_tableWidget_5_cellActivated(int row, int column)
{
    ui->portsPref->show();
    if(row == 0)
    {
        ui->portsPref->setCurrentIndex(0);
        ui->address->setFocus();
    }

    else
    {
        ui->portsPref->setCurrentIndex(1);
        ui->address_2->setFocus();

    }


}


void MainWindow::on_address_cellActivated(int row, int column)
{
    auto a = ui->address->item(row, column);
    value1 = a->text();

    ui->portsPref->hide();
    ui->tableWidget_2->setFocus();
    //ui->tableWidget_5->removeCellWidget(0, 0);
    QString str4 =QString ("Serial Port1 Address [%1]").arg(value1);
    QTableWidgetItem *ad1 = new QTableWidgetItem(str4);
    ui->tableWidget_5->setItem(0, 0, ad1);


}


void MainWindow::on_address_2_cellActivated(int row, int column)
{
    auto b = ui->address_2->item(row, column);
    value2 = b->text();

    ui->portsPref->hide();
    ui->tableWidget_2->setFocus();
   // ui->tableWidget_5->removeCellWidget(0, 1);
    QString str5 =QString ("Serial Port1 Address [%1]").arg(value2);
    QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
    ui->tableWidget_5->setItem(1, 0, ad2);

}

