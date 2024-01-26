#ifndef DIALOG_H
#define DIALOG_H

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

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
