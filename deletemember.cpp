#include "deletemember.h"
#include "ui_deletemember.h"

DeleteMember::DeleteMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteMember)
{
    ui->setupUi(this);
}

DeleteMember::~DeleteMember()
{
    delete ui;
}
