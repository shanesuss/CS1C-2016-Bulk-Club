#include "additem.h"
#include "ui_additem.h"

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_pushButton_clicked()
{
    QString itemName;
    QString itemPrice;

    itemName  = ui->lineEdit->text();

    itemPrice = ui->lineEdit_2->text();


}
