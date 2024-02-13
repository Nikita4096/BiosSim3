#include "dialog.h"
#include "ui_dialog.h"

//#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //if()
    //QString str123 =QString ("Виконано правильно завдань - 4/10");//.arg(grade);
    //QString str234 = QString::number(5/12);


    //qDebug()<<a;

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::receiveData(const QString data)
{
    a = 10 - data.length();
    d = data;


    QString str123 =QString ("Виконано правильно завдань - %1/10").arg(a);
    QString str234 = QString("Оцінка - %1/12").arg((int)(a*1.2+0.5));
    QString str1235 =QString ("Виконано правильно завдань - 0/10");
    QString str2345= QString("Оцінка - 1/12");
    if(a == 10)
    {
        qDebug()<<"yes";
        ui->label->setText(str1235);
        ui->label_2->setText(str2345);

    }
    else
    {
        ui->label->setText(str123);
        ui->label_2->setText(str234);
    }

}

void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
   // qDebug()<<a;
    //qDebug()<<a;
    QApplication::quit();
}


void Dialog::on_Dialog_rejected()
{
    QApplication::quit();
}


void Dialog::on_pushButton_clicked()
{
    setlocale(LC_ALL, "Russian");
    for(int i = 0; d.length(); i++)
    {
        switch(int(d[i].unicode()))
        {
            case ('a' + 0):{ qDebug()<<texts.at('a'); break; }
            case ('b' + 0):{ qDebug()<<texts.at('b'); break;}
            case ('c' + 0):{ qDebug()<<texts.at('c'); break; }
            case ('d' + 0):{ qDebug()<<texts.at('d'); break; }

            case ('e' + 0):{ qDebug()<<texts.at('e'); break; }
            case ('f' + 0):{ qDebug()<<texts.at('f');break; }
            case ('g' + 0):{ qDebug()<<texts.at('g');break; }
            case ('h' + 0):{ qDebug()<<texts.at('h');break; }
            case ('i' + 0):{ qDebug()<<texts.at('i');break; }

            case ('j' + 0):{ qDebug()<<texts.at('j');break; }
            case ('k' + 0):{ qDebug()<<texts.at('k');break; }
            case ('l' + 0):{ qDebug()<<texts.at('l');break; }
            case ('m' + 0):{ qDebug()<<texts.at('m');break; }
            case ('n' + 0):{ qDebug()<<texts.at('n');break; }
            case ('o' + 0):{ qDebug()<<texts.at('o');break; }

            case ('p' + 0):{ qDebug()<<texts.at('p');break; }
            case ('q' + 0):{ qDebug()<<texts.at('q');break; }




        }
    }
}

