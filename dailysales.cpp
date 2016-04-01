#include "dailysales.h"
#include "ui_dailysales.h"

DailySales::DailySales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailySales)
{
    ui->setupUi(this);
}

DailySales::~DailySales()
{
    delete ui;
}
