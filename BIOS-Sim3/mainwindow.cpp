#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDialog>
#include <QStyledItemDelegate>
class NoFocusDelegate : public QStyledItemDelegate
{
protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QStyleOptionViewItem itemOption(option);
        if (itemOption.state & QStyle::State_HasFocus)
            itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
        QStyledItemDelegate::paint(painter, itemOption, index);
    }
};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    //this->setStyleSheet("QWidget{font-size:20px;}");

    ui->centralwidget->setAttribute( Qt::WA_TransparentForMouseEvents );
    ui->tableWidget_14->setCurrentCell(0, 0);
    ui->Pages->hide();
    ui->LanqSelect->hide();
    ui->portsPref->hide();
    ui->onOff->hide();
    ui->stackedWidget_2->hide();
    ui->stackedWidget_3->hide();
    ui->stackedWidget_4->hide();
    ui->onOff_4->hide();
    ui->tableWidget_10->hideRow(1);
    ui->stackedWidget_5->hide();
    ui->onOff_6->hide();

    ui->tableWidget_2->setCurrentCell(0, 0);
    ui->tableWidget_3->setCurrentCell(0, 0);
    ui->tableWidget_4->setCurrentCell(0, 0);
    ui->tableWidget_6->setCurrentCell(0, 0);
    ui->tableWidget->setCurrentCell(0, 0);

    //QFont strike = ui->label_2->font();
    //strike.setStrikeOut(true);
    ui->tableWidget->setItemDelegate(new NoFocusDelegate());
    ui->tableWidget_2->setItemDelegate(new NoFocusDelegate());
    ui->tableWidget_3->setItemDelegate(new NoFocusDelegate());
    ui->tableWidget_4->setItemDelegate(new NoFocusDelegate());
    ui->tableWidget_5->setItemDelegate(new NoFocusDelegate());
    ui->tableWidget_6->setItemDelegate(new NoFocusDelegate());
    ui->address->setItemDelegate(new NoFocusDelegate());
    ui->address_2->setItemDelegate(new NoFocusDelegate());

//    ui->tableWidget_5->setAttribute( Qt::WA_TransparentForMouseEvents );
//    ui->address->setAttribute( Qt::WA_TransparentForMouseEvents );


//    ui->address_2->setAttribute( Qt::WA_TransparentForMouseEvents );


//    ui->tableWidget->setAttribute( Qt::WA_TransparentForMouseEvents );



//    ui->tableWidget_2->setAttribute( Qt::WA_TransparentForMouseEvents );


//    ui->tableWidget_3->setAttribute( Qt::WA_TransparentForMouseEvents );


//    ui->tableWidget_4->setAttribute( Qt::WA_TransparentForMouseEvents );


//    ui->tableWidget_5->setAttribute( Qt::WA_TransparentForMouseEvents );
    ui->tableWidget_5->setItem(0, 0, item1);
    ui->tableWidget_5->setItem(1, 0, item2);
    //ui->Pages->setCurrentWidget(ui->serialPort);
   // ui->Pages->show();


    //ui->LanqSelect->hide();

    //ui->tableWidget->setFrameShape(QAbstractScrollArea::NoFrame);
   /* switch(ui->stackedWidget->currentIndex())
    {
    case 0: ui->tableWidget_14->selectRow(0);
        break;
    case 1: ui->tableWidget_14->selectRow(1);
        break;
    case 2: ui->tableWidget_14->selectRow(2);
        break;
    case 3: ui->tableWidget_14->selectRow(3);
        break;
    case 4: ui->tableWidget_14->selectRow(0);
        break;
    }
*/
   // ui->tableWidget_10->setCurrentCell(0, 0);
    //ui->tableWidget_11->setCurrentCell(0, 1);
    //ui->tableWidget_12->setCurrentCell(0, 2);
    //ui->tableWidget_13->setCurrentCell(0, 3);
    //ui->tableWidget_14->setCurrentCell(0, 4);
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


        //ui->Pages->setCurrentWidget(ui->lanq);
        ui->LanqSelect->show();
        ui->LanqSelect->setFocus();
        ui->LanqSelect->setCurrentCell(0, 0);

    }
    if (row == 1)
    {
        closeMain();
        ui->Pages->setCurrentWidget(ui->audio);
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
    ui->LanqSelect->hide();
    ui->tableWidget->setFocus();
    ui->tableWidget->setCurrentCell(0, 0);

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

        ui->tableWidget_5->setCurrentCell(0, 0);
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
    {
        closeMain();
        ui->Pages->setCurrentWidget(ui->usb);
        ui->Pages->show();
        ui->tableWidget_8->setFocus();
        ui->tableWidget_8->setCurrentCell(0, 0);
    }
        break;
    case 3:
        break;
    case 4:
        closeMain();
        ui->Pages->setCurrentWidget(ui->video);
        ui->Pages->show();
        ui->tableWidget_10->setFocus();
        ui->tableWidget_10->setCurrentCell(0, 0);
        break;
    case 5:
        closeMain();
        ui->Pages->setCurrentWidget(ui->audio);
        ui->Pages->show();
        ui->tableWidget_7->setFocus();
        ui->tableWidget_7->setCurrentCell(0, 0);
        break;
    case 6:
        closeMain();
        ui->Pages->setCurrentWidget(ui->net);
        ui->Pages->show();
        ui->tableWidget_11->setFocus();
        ui->tableWidget_11->setCurrentCell(0, 0);
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        disableMovement = true;
        // ui->stackedWidget->setDisabled(true);
        //qDebug() << "I'm right"<<Qt::endl;


        //ui->Pages->setCurrentWidget(ui->lanq);
        ui->onOff_4->show();
        ui->onOff_4->setFocus();
        ui->onOff_4->setCurrentCell(0, 0);
        break;
    }
}
void MainWindow::on_tableWidget_5_cellActivated(int row, int column)
{
    qDebug() << row;
    ui->portsPref->show();
    if(row == 0)
    {
        ui->portsPref->setCurrentIndex(0);
        ui->address->setFocus();
        ui->address->setCurrentCell(0, 0);
    }

    else
    {
        ui->portsPref->setCurrentIndex(1);
        ui->address_2->setFocus();
        ui->address_2->setCurrentCell(0, 0);

    }

}


void MainWindow::on_address_cellActivated(int row, int column)
{
    auto a = ui->address->item(row, column);
    value1 = a->text();

    ui->portsPref->hide();
    ui->tableWidget_5->setFocus();
    ui->tableWidget_5->setCurrentCell(0, 0);
    //ui->tableWidget_5->removeCellWidget(0, 0);
    QString str4 =QString ("Serial Port1 Address [%1]").arg(value1);
    QTableWidgetItem *ad1 = new QTableWidgetItem(str4);
    ui->tableWidget_5->setItem(0, 0, ad1);
    /*if(str4 == "Serial Port1 Address [2F8/IRQ3]" && adr1ch == false )
    {
        count +=1;
        qDebug() <<"Yes";
        adr1ch = true;
    }*/


    ui->label_2->setStyleSheet("text-decoration: line-through");
}


void MainWindow::on_address_2_cellActivated(int row, int column)
{
    auto b = ui->address_2->item(row, column);
    value2 = b->text();

    ui->portsPref->hide();
    ui->tableWidget_5->setFocus();
    ui->tableWidget_5->setCurrentCell(1, 0);
   // ui->tableWidget_5->removeCellWidget(0, 1);
    QString str5 =QString ("Serial Port1 Address [%1]").arg(value2);
    QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
    ui->tableWidget_5->setItem(1, 0, ad2);
    /*if(str5 == "Serial Port1 Address [3F8/IRQ4]" && adr2ch == false )
    {
        count +=1;
        qDebug() <<"Yes2";
        adr2ch = true;
    }*/                                                                                             //for later


    ui->label_3->setStyleSheet("text-decoration: line-through");
}


void MainWindow::on_tableWidget_5_cellChanged(int row, int column)
{
}

/*void onOffs(MainWindow* window, int row, QString text, QLabel* label, QTableWidget* table)
{
    window->on_onOff_cellActivated(row, 0, text, label, table);
}*/
void MainWindow::on_tableWidget_7_cellActivated(int row, int column)
{
    if(row ==2)
    {
        third_layer = true;
        ui->onOff->show();
        ui->onOff->setFocus();
        ui->onOff->setCurrentCell(0, 0);

    }
}



void MainWindow::on_onOff_cellActivated(int row, int column/*, QString text, QLabel* label, QTableWidget* table*/)
{
    if(row == 0)
    {
        QString str5 =QString ("Microphone  [Enabled]");
        QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
        ui->tableWidget_7->setItem(2, 0, ad2);
    }
    if(row ==1)
    {
        QString str6 =QString ("Microphone  [Disabled]");
        QTableWidgetItem *ad = new QTableWidgetItem(str6);
        ui->tableWidget_7->setItem(2, 0, ad);
    }
    ui->label_4->setStyleSheet("text-decoration: line-through");
    ui->onOff->hide();
    ui->tableWidget_7->setFocus();
    ui->tableWidget_7->setCurrentCell(0, 0);



}
void MainWindow::on_tableWidget_3_cellActivated(int row, int column)
{
    if(row == 4)
    {
        disableMovement = true;
        ui->stackedWidget_2->show();
        ui->stackedWidget_2->setCurrentWidget(ui->page_7);
        ui->onOff_2->setFocus();
        ui->onOff_2->setCurrentCell(0, 0);

    }
}





void MainWindow::on_onOff_2_cellActivated(int row, int column)
{
    if(row == 0)
    {
        QString str5 =QString ("Quick Boot  [Enabled]");
        QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
        ui->tableWidget_3->setItem(4, 0, ad2);
    }
    if(row ==1)
    {
        QString str6 =QString ("Quick Boot  [Disabled]");
        QTableWidgetItem *ad = new QTableWidgetItem(str6);
        ui->tableWidget_3->setItem(4, 0, ad);
    }
    disableMovement = false;
    ui->label_5->setStyleSheet("text-decoration: line-through");
    ui->stackedWidget_2->hide();

    ui->tableWidget_3->setFocus();
    //ui->tableWidget_3->setCurrentCell(0, 0);


}


void MainWindow::on_tableWidget_8_cellActivated(int row, int column)
{
    if(row == 0)
    {
        third_layer = true;
        focus = ui->tableWidget_8;
        ui->stackedWidget_3->show();
        ui->stackedWidget_3->setCurrentWidget(ui->page_9);
        ui->onOff_3->setFocus();
        ui->onOff_3->setCurrentCell(0, 0);
    }
}


void MainWindow::on_onOff_3_cellActivated(int row, int column)
{

    if(row == 0)
    {
        QString str5 =QString ("USB Support  [Enabled]");
        QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
        ui->tableWidget_8->setItem(0, 0, ad2);
        if(rowhidden_usb ==true)
            for(int i=1; i<ui->tableWidget_8->rowCount(); i++)
            {
                ui->tableWidget_8->showRow(i);
            }
    }
    if(row ==1)
    {
        QString str6 =QString ("USB Support  [Disabled]");
        QTableWidgetItem *ad = new QTableWidgetItem(str6);
        ui->tableWidget_8->setItem(0, 0, ad);
        for(int i=1; i<ui->tableWidget_8->rowCount(); i++)
        {
            ui->tableWidget_8->hideRow(i);
        }
        rowhidden_usb = true;
    }
    //disableMovement = false;
    ui->label_6->setStyleSheet("text-decoration: line-through");
    ui->stackedWidget_3->hide();
    ui->tableWidget_8->setFocus();
    ui->tableWidget_8->setCurrentCell(0, 0);

}


void MainWindow::on_tableWidget_4_cellActivated(int row, int column)
{
    if(row ==0 )
    {
        QDialog *dialog = new Dialog(this);
        dialog->show();
    }
}


void MainWindow::on_tableWidget_6_cellActivated(int row, int column)
{
    if(row ==0)
    {
        closeMain();
        ui->Pages->setCurrentWidget(ui->setup);
        ui->Pages->show();
        ui->tableWidget_9->setFocus();
        ui->tableWidget_9->setCurrentCell(0, 0);
    }
}


void MainWindow::on_tableWidget_9_cellActivated(int row, int column)
{
    if(row ==3)
    {
        third_layer = true;
        focus = ui->tableWidget_9;
        ui->stackedWidget_4->show();
        ui->stackedWidget_4->setCurrentWidget(ui->page_15);
        ui->onOff_5->setFocus();
        ui->onOff_5->setCurrentCell(0, 0);
    }
    if(row ==6)
    {
        third_layer = true;
        focus = ui->tableWidget_9;
        ui->stackedWidget_4->show();
        ui->stackedWidget_4->setCurrentWidget(ui->page_11);
        ui->cselect->setFocus();
        ui->cselect->setCurrentCell(0, 0);

    }
    if(row == 8)
    {
        third_layer = true;
        focus = ui->tableWidget_9;
        ui->stackedWidget_4->show();
        ui->stackedWidget_4->setCurrentWidget(ui->page_12);
        ui->clock->setFocus();
        ui->clock->setCurrentCell(0, 0);
    }
}


void MainWindow::on_cselect_cellActivated(int row, int column)
{
    auto a = ui->cselect->item(row, column);
    value3 = a->text();
    //qDebug() <<value3;
    ui->stackedWidget_4->hide();

    //ui->tableWidget_5->removeCellWidget(0, 0);
    QString str4 =QString ("C State Support  [%1]").arg(value3);
    QTableWidgetItem *ad1 = new QTableWidgetItem(str4);
    ui->tableWidget_9->setItem(6, 0, ad1);
    ui->tableWidget_9->setFocus();
    ui->tableWidget_9->setCurrentCell(0, 0);
    ui->label_10->setStyleSheet("text-decoration: line-through");
}

void MainWindow::on_onOff_4_cellActivated(int row, int column)
{
    if(row == 0)
    {
        QString str5 =QString ("Bluetooth  [Enabled]");
        QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
        ui->tableWidget_2->setItem(9, 0, ad2);
    }
    if(row ==1)
    {
        QString str6 =QString ("Bluetooth  [Disabled]");
        QTableWidgetItem *ad = new QTableWidgetItem(str6);
        ui->tableWidget_2->setItem(9, 0, ad);
    }
    disableMovement = false;
    //ui->label_5->setStyleSheet("text-decoration: line-through");
    ui->onOff_4->hide();

    ui->tableWidget_2->setFocus();
    //ui->tableWidget_3->setCurrentCell(0, 0);


}


void MainWindow::on_clock_cellActivated(int row, int column)
{
    auto a = ui->clock->item(row, column);
    value4 = a->text();
    //qDebug() <<value3;
    ui->stackedWidget_4->hide();

    //ui->tableWidget_5->removeCellWidget(0, 0);
    QString str4 =QString ("CPU Clock Ratio  [%1]").arg(value4);
    QTableWidgetItem *ad1 = new QTableWidgetItem(str4);
    ui->tableWidget_9->setItem(8, 0, ad1);
    ui->tableWidget_9->setFocus();
    ui->tableWidget_9->setCurrentCell(0, 0);
    ui->label_11->setStyleSheet("text-decoration: line-through");
}


void MainWindow::on_tableWidget_10_cellActivated(int row, int column)
{
    if(row ==0)
    {
        third_layer = true;
        focus = ui->tableWidget_10;
        ui->stackedWidget_5->show();
        ui->stackedWidget_5->setCurrentWidget(ui->page_14);
        ui->alloc->setFocus();
        ui->alloc->setCurrentCell(0, 0);
    }
    if(row ==1)
    {
        third_layer = true;
        focus = ui->tableWidget_10;
        ui->stackedWidget_5->show();
        ui->stackedWidget_5->setCurrentWidget(ui->page_13);
        ui->graphicsource->setFocus();
        ui->graphicsource->setCurrentCell(0, 0);
    }

}


void MainWindow::on_alloc_cellActivated(int row, int column)
{
    if(row ==1)
    {
        ui->tableWidget_10->showRow(1);
    }
    if(row == 0)
    {
        ui->tableWidget_10->hideRow(1);
    }
    auto a = ui->alloc->item(row, column);
    //a->text();
    //qDebug() <<value3;
    ui->stackedWidget_5->hide();

    //ui->tableWidget_5->removeCellWidget(0, 0);
    QString str4 =QString ("Select Active Video  [%1]").arg(a->text());
    QTableWidgetItem *ad1 = new QTableWidgetItem(str4);
    ui->tableWidget_10->setItem(0, 0, ad1);
    ui->tableWidget_10->setFocus();
    ui->tableWidget_10->setCurrentCell(0, 0);
    ui->label_9->setStyleSheet("text-decoration: line-through");
}


void MainWindow::on_graphicsource_cellActivated(int row, int column)
{
    auto a = ui->graphicsource->item(row, column);
    //a->text();
    //qDebug() <<value3;
    ui->stackedWidget_5->hide();

    //ui->tableWidget_5->removeCellWidget(0, 0);
    QString str4 =QString ("Pre-Allocated Memory Size  [%1]").arg(a->text());
    QTableWidgetItem *ad1 = new QTableWidgetItem(str4);
    ui->tableWidget_10->setItem(1, 0, ad1);
    ui->tableWidget_10->setFocus();
    ui->tableWidget_10->setCurrentCell(0, 0);
    ui->label_9->setStyleSheet("text-decoration: line-through");
}


void MainWindow::on_onOff_5_cellActivated(int row, int column)
{
    if(row == 0)
    {
        QString str5 =QString ("Intel(R) Virtualization Technology [Enabled]");
        QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
        ui->tableWidget_9->setItem(3, 0, ad2);
    }
    if(row ==1)
    {
        QString str6 =QString ("Intel(R) Virtualization Technology [Disabled]");
        QTableWidgetItem *ad = new QTableWidgetItem(str6);
        ui->tableWidget_9->setItem(3, 0, ad);
     //   std::call_once ( onceFlag, [ ]{ ++grade; } );
    }
    //disableMovement = false;
    //ui->label_5->setStyleSheet("text-decoration: line-through");
    ui->stackedWidget_4->hide();

    ui->tableWidget_9->setFocus();
    //ui->tableWidget_3->setCurrentCell(0, 0);


}


void MainWindow::on_tableWidget_11_cellActivated(int row, int column)
{
    onOff_6_i = row;
    //if(row ==0)
   // {
        third_layer = true;
        focus = ui->tableWidget_11;
        ui->onOff_6->show();
        ui->onOff_6->setFocus();
        ui->onOff_6->setCurrentCell(0, 0);

   // }
}


void MainWindow::on_onOff_6_cellActivated(int row, int column)
{
    if(onOff_6_i == 0)
    {
        if(row == 0)
        {
            QString str5 =QString ("Onboard Ethernet Controller  [Enabled]");
            QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
            ui->tableWidget_11->setItem(0, 0, ad2);
        }
        if(row ==1)
        {
            QString str6 =QString ("Onboard Ethernet Controller  [Disabled]");
            QTableWidgetItem *ad = new QTableWidgetItem(str6);
            ui->tableWidget_11->setItem(0, 0, ad);
        }
    }
    if(onOff_6_i == 1)
    {
        if(row == 0)
        {
            QString str5 =QString ("Wireless LAN Access  [Enabled]");
            QTableWidgetItem *ad2 = new QTableWidgetItem(str5);
            ui->tableWidget_11->setItem(1, 0, ad2);
        }
        if(row ==1)
        {
            QString str6 =QString ("Wireless LAN Access  [Disabled]");
            QTableWidgetItem *ad = new QTableWidgetItem(str6);
            ui->tableWidget_11->setItem(1, 0, ad);
        }
        ui->label_8->setStyleSheet("text-decoration: line-through");
    }
    //disableMovement = false;
    //ui->label_5->setStyleSheet("text-decoration: line-through");
    ui->onOff_6->hide();

    ui->tableWidget_11->setFocus();
    //ui->tableWidget_3->setCurrentCell(0, 0);

}

