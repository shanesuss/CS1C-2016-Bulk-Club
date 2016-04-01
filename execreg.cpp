#include "execreg.h"
#include "ui_execreg.h"

ExecReg::ExecReg(QWidget *parent; MemberList myMemberList) :
    QDialog(parent),
    ui(new Ui::ExecReg)
{
    ui->setupUi(this);
}



ExecReg::~ExecReg()
{
    delete ui;
}

void ExecReg::on_pushButton_clicked()
{
    regularWindow = new NewRegular(this);

    regularWindow->show();
}

void ExecReg::on_pushButton_2_clicked()
{
    execWindow = new NewExecutive(this);

    execWindow->show();
}
