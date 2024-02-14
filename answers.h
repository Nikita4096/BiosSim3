#ifndef ANSWERS_H
#define ANSWERS_H

#include <QDialog>

namespace Ui {
class Answers;
}

class Answers : public QDialog
{
    Q_OBJECT

public:
    explicit Answers(QWidget *parent = nullptr);
    ~Answers();

private:
    Ui::Answers *ui;
};

#endif // ANSWERS_H
