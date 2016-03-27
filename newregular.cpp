#include "newregular.h"
#include "ui_newregular.h"

NewRegular::NewRegular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewRegular)
{
    ui->setupUi(this);
}

NewRegular::~NewRegular()
{
    delete ui;
}
