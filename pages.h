#ifndef PAGES_H
#define PAGES_H

#include <QStackedWidget>
#include <QKeyEvent>

namespace Ui {
class Pages;
}

class Pages : public QStackedWidget
{
    Q_OBJECT

public:
    explicit Pages(QWidget *parent = nullptr);
    ~Pages();


private:
    Ui::Pages *ui;
};

#endif // PAGES_H
