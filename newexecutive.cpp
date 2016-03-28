#include "newexecutive.h"
#include "ui_newexecutive.h"

NewExecutive::NewExecutive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewExecutive)
{
    ui->setupUi(this);
}

NewExecutive::~NewExecutive()
{
    delete ui;
}

void NewExecutive::on_pushButton_clicked()
{
    QString newName;
    QString newId;
    QString newMonth;
    QString newDay;
    QString newYear;
    QString newTotal;
    QString newRebate;
    int     id;
    int     month;
    int     day;
    int     year;
    double  totalSpent;
    bool    ok;
    Executive newExecMem;
    MemberList myList;
    vector<Member> currList;

    newName = ui->lineEdit->text();

    newId = ui->lineEdit_2->text();

    id = newId.toInt(&ok, 10);

    newDay = ui->lineEdit_3->text();

    day = newDay.toInt(&ok, 10);

    newMonth = ui->lineEdit_4->text();

    month = newMonth.toInt(&ok, 10);

    newMonth = ui->lineEdit_5->text();

    month = newMonth.toInt(&ok, 10);

    Date newExpDate(month, day, year);

    newTotal = ui->lineEdit_6->text();

    totalSpent = newTotal.toDouble();

    newExecMem = Executive(newName,id,newExpDate,totalSpent);


}
