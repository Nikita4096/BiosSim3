#ifndef TASKS_H
#define TASKS_H

#include <QWidget>

namespace Ui {
class Tasks;
}

class Tasks : public QWidget
{
    Q_OBJECT

public:
    explicit Tasks(QWidget *parent = 0);
    ~Tasks();

private:
    Ui::Tasks *ui;
};

#endif // TASKS_H
