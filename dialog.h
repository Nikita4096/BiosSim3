#ifndef DIALOG_H
#define DIALOG_H

#include <QLabel>
#include <qabstractbutton>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_Dialog_rejected();
    void on_pushButton_clicked();

public slots:
    void receiveData(const QString data);

private:
    Ui::Dialog *ui;
    int a;
    QLabel *labels[11];
    QString d;
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
};

#endif // DIALOG_H
