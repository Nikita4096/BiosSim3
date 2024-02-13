#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <mutex>
#include <random>
#include <time.h>

//
//std::once_flag onceFlag;
//int grade = 0;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



signals:
    void sendData(const QString data);


protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if(ui->stackedWidget->isEnabled() && !disableMovement)
        {
        switch (event->key()) {
            case Qt::Key_Left:
                ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex() - 1 + ui->stackedWidget->count()) % ui->stackedWidget->count());
                ui->tableWidget_14->setCurrentCell(0, ui->stackedWidget->currentIndex());
                qDebug()<<ui->stackedWidget->currentIndex();
                ui->tableWidget_14->repaint();
                break;
            case Qt::Key_Right:
                ui->stackedWidget->setCurrentIndex((ui->stackedWidget->currentIndex() + 1) % ui->stackedWidget->count());
                ui->tableWidget_14->setCurrentCell(0, ui->stackedWidget->currentIndex());
                qDebug()<<ui->stackedWidget->currentIndex();
                ui->tableWidget_14->repaint();
                break;
        case Qt::Key_Escape:
            //ui->Pages->hide();
            //ui->stackedWidget->show();
            break;
        default:
            QMainWindow::keyPressEvent(event);
        }
        }

        switch (event->key()) {
        case Qt::Key_Escape:

            ui->stackedWidget_6->hide();   //- temporary (nope, it works so it's permanenet)
            ui->portsPref->hide();

            ui->stackedWidget_2->hide();
            ui->LanqSelect->hide();
            ui->onOff_4->hide();
            //if(ui->Pages->isVisible())

            if(third_layer)
            {
           // ui->Pages->currentWidget()->setFocus();

                ui->stackedWidget_3->hide();
                ui->stackedWidget_4->hide();
                ui->stackedWidget_5->hide();
                ui->onOff_6->hide();

            //ui->Pages->currentWidget()->setFocus();
            third_layer = false;
                focus->setFocus();
            //qDebug()<<QApplication::focusWidget()->objectName();
            goto a;
            }
            if(ui->Pages->isVisible())
            {
            ui->Pages->hide();
            }

        ui->stackedWidget->setDisabled(false);
        //qDebug() << ui->stackedWidget->currentIndex();
        switch(ui->stackedWidget->currentIndex())
        {

        case 0: ui->tableWidget->setFocus(); break;
        case 2: ui->tableWidget_2->setFocus(); break;
        case 3: ui->tableWidget_3->setFocus(); break;
        case 4: ui->tableWidget_4->setFocus(); break;
        case 1: ui->tableWidget_6->setFocus(); break;
        }

        ui->stackedWidget->show();
            disableMovement = false;
            break;
            a:
        default:
            QMainWindow::keyPressEvent(event);
        }


    }

private slots:
    void on_tableWidget_cellActivated(int row, int column);


    void on_LanqSelect_cellActivated(int row, int column);

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_tableWidget_2_cellActivated(int row, int column);

    void on_tableWidget_5_cellActivated(int row, int column);

    void on_address_cellActivated(int row, int column);

    void on_address_2_cellActivated(int row, int column);

    void on_tableWidget_5_cellChanged(int row, int column);

    void on_tableWidget_7_cellActivated(int row, int column);


    void on_tableWidget_3_cellActivated(int row, int column);


    void on_onOff_2_cellActivated(int row, int column);

    void on_tableWidget_8_cellActivated(int row, int column);

    void on_onOff_3_cellActivated(int row, int column);

//public slots:
    void on_onOff_cellActivated(/*int n,*/ int row, int column/*, QString text, QLabel* label, QTableWidget* table*/);
    void on_tableWidget_4_cellActivated(int row, int column);

    void on_tableWidget_6_cellActivated(int row, int column);

    void on_tableWidget_9_cellActivated(int row, int column);

    void on_cselect_cellActivated(int row, int column);

    void on_onOff_4_cellActivated(int row, int column);

    void on_clock_cellActivated(int row, int column);

    void on_tableWidget_10_cellActivated(int row, int column);

    void on_alloc_cellActivated(int row, int column);

    void on_graphicsource_cellActivated(int row, int column);

    void on_onOff_5_cellActivated(int row, int column);

    void on_tableWidget_11_cellActivated(int row, int column);

    void on_onOff_6_cellActivated(int row, int column);

    void on_onOff_7_cellActivated(int row, int column);

    void on_stackedWidget_6_currentChanged(int arg1);


public:
    Ui::MainWindow *ui;
    //QStackedWidget *nw = new QStackedWidget();
    void closeMain()
    {
        ui->stackedWidget->setDisabled(true);
        ui->stackedWidget->hide();
    }

    bool disableMovement = false;

    QString value1 = "3F8/IRQ4";
    QString str1 = QString("Serial Port1 Address [%1]").arg(value1);
    QTableWidgetItem *item1 = new QTableWidgetItem(str1);


    QString value2 = "2F8/IRQ3";
    QString str2 = QString("Serial Port2 Address [%1]").arg(value2);
    QTableWidgetItem *item2 = new QTableWidgetItem(str2);

    QString value3 = "C1C3C6C7C8";
    QString value4 = "Auto";
    bool adr1ch = false;
    bool adr2ch = false;
    bool micch = false;
    bool rowhidden_usb = false;

    int count = 0;
    int onOff_6_i = -1;
    bool third_layer = false;

    QWidget * focus;
    QDialog *dialog = new Dialog(this);
    int grade = 0;
    QString buffer=randomTasks();
    QString temp = buffer;

    /*int checkGrade(QString str)
    {
        buffer;
        return buffer.length();

    }*/

    QString randomTasks() {
        for(int i=0; i<5; i++)
        srand(time(0));
        QSet<QChar> charSet;
        while (charSet.size() < 10) {
            charSet.insert(QChar('a' + rand() % 17));
        }
        QList<QChar> charList(charSet.begin(), charSet.end());
        QString result;
        for (const QChar& c : charList) {
            result.append(c);
        }
        return result;

    }

    void init();
    QLabel *labels[11];



    std::unordered_map<QChar, std::string> texts
        {

            {'a', "Змінити адресу SerialPort1 на 2F8/IRQ3"},
            {'b', "Змінити адресу SerialPort2 на 3F8/IRQ4"},
            {'c', "Вимкнути мікрофон"},
            {'d', "Увімкнути швидке завантаження"},
            {'e', "Відключити підтримку USB"},
            {'f', "Поставити С-стан у С1"},
            {'g', "Змінити коефіцієнт частоти процесора на х12"},
            {'h', "Змінити графічну відеокарту на внутрішню, виділити 1024МБ відеопам'яті"},
            {'i', "Вимкнути віртуалізацію"},//
            {'j', "Включити підтримку бездротового з'єднання"},
            {'k', "Вимкнути Bluetooth"},
            {'l', "Вимкнути Ethernet"},
            {'m', "Увімкнути Turbo режим"},
            {'n', "Вимкнути мультипоточність "},
            {'o', "Вимкнути підтримку C1E"},
            {'p', "Перевести режим завантаження в USB"},
            {'q', "Вимкнути динамік"}//d
            /*{"r", nullptr},
            {"s", nullptr},
            {"t", nullptr},
            {"u", nullptr},
            {"v", nullptr},
            {"w", nullptr},
            {"x", nullptr},
            {"y", nullptr},
            {"z", nullptr},*/


        };
        /*ui->label_2->setText("a");
        ui->label_3->setText("a");
        ui->label_4->setText("a");
        ui->label_5->setText("a");
        ui->label_6->setText("a");
        ui->label_7->setText("a");
        ui->label_8->setText("a");
        ui->label_9->setText("a");
        ui->label_10->setText("a");
        ui->label_11->setText("a");
        ui->label_12->setText("a");*/


std::unordered_map<QChar, int> index
    {
        {'a', -1 },
        {'b', -1 },
        {'c', -1 },
        {'d', -1 },
        {'e', -1 },
        {'f', -1 },
        {'g', -1 },
        {'h', -1 },
        {'i', -1 },//
        {'j', -1 },
        {'k', -1 },
        {'l', -1 },
        {'m', -1 },
        {'n', -1 },
        {'o', -1 },
        {'p', -1 },
        {'q', -1 }//d
    };
};

#endif // MAINWINDOW_H
