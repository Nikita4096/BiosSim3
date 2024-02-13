#include "pages.h"
#include "ui_pages.h"

Pages::Pages(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::Pages)
{
    ui->setupUi(this);
}

Pages::~Pages()
{
    delete ui;
}
