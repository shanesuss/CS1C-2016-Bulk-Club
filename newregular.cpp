#include "newregular.h"
#include "ui_newregular.h"
#include "mainwindow.h"
#include <QDebug>
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

void NewRegular::on_pushButton_clicked()
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
    qDebug () << "Test";
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

    newMember = Member(newName,id,newExpDate,totalSpent);

}

Member NewRegular::GetMember()
{
    return newMember;
}
