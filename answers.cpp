#include "answers.h"
#include "ui_answers.h"

Answers::Answers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Answers)
{
    ui->setupUi(this);
}

Answers::~Answers()
{
    delete ui;
}
