#include "execreg.h"
#include "ui_execreg.h"


ExecReg::ExecReg(QWidget *parent) :
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
    newMember = regularWindow->GetMember();
}

void ExecReg::on_pushButton_2_clicked()
{
    execWindow = new NewExecutive(this);
    execWindow->show();
    newMember = execWindow->GetExec();
}

Member ExecReg::GetMember()
{
    return newMember;
}
