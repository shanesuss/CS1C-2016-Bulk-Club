#include "memreport.h"
#include "ui_memreport.h"

MemReport::MemReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemReport)
{
    ui->setupUi(this);
}

MemReport::~MemReport()
{
    delete ui;
}
