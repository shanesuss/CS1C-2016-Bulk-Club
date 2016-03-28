#include "deleteitem.h"
#include "ui_deleteitem.h"

DeleteItem::DeleteItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteItem)
{
    ui->setupUi(this);
}

DeleteItem::~DeleteItem()
{
    delete ui;
}
