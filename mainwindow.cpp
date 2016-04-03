#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    accessMemList.InitializeMemberList();
    accessSalesList.InitializeSalesList();

    ui->textBrowser_7->setText(accessMemList.GetMemberOnlyList());
    ui->textBrowser_8->setText(accessMemList.GetExecutiveOnlyList());
    ui->textBrowser_6->setText(accessSalesList.GetSalesList());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_8_clicked()
{
    reportUi = new DailySales(this);
    reportUi->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    memReportUi = new MemReport(this);

    memReportUi->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    delMemUi = new DeleteMember(this);

    delMemUi->show();
}


void MainWindow::on_pushButton_16_clicked()
{
    delItemUi = new DeleteItem(this);

    delItemUi->show();
}

void MainWindow::on_pushButton_15_clicked()
{
    addItemUi = new AddItem(this);

    addItemUi->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser_7->setText(accessMemList.GetMemberList());
    ui->textBrowser_8->setText(accessMemList.GetExecutiveOnlyList());
}


void MainWindow::on_pushButton_2_clicked()
{
    QString newName;
    QString newId;
    QString newMonth;
    QString newDay;
    QString newYear;
    QString newTotal;
    QString newRebate;
    QString newType;
    int     id;
    int     month;
    int     day;
    int     year;
    double  totalSpent;
    bool    ok;
    Executive newExecMem;
    Member newRegMem;

    newName = ui->lineEdit->text();

    newId = ui->lineEdit_2->text();

    id = newId.toInt(&ok, 10);

    newType = ui->lineEdit_7->text();

    newDay = ui->lineEdit_3->text();

    day = newDay.toInt(&ok, 10);

    newMonth = ui->lineEdit_4->text();

    month = newMonth.toInt(&ok, 10);

    newMonth = ui->lineEdit_5->text();

    month = newMonth.toInt(&ok, 10);

    Date newExpDate(month, day, year);

    newTotal = ui->lineEdit_6->text();

    totalSpent = newTotal.toDouble();

    if(newType == "Executive")
    {
        newExecMem = Executive(newName,id,newExpDate,totalSpent);

        accessMemList.AddMember(newExecMem);
    }
    else
    {
        newRegMem = Member(newName,id,newExpDate,totalSpent);

        accessMemList.AddMember(newRegMem);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    QFile day1(":/day1.txt");
    QTextStream infile(&day1);
    ostringstream out;
    QString     memName;
    QString     memNum;
    QString     memType;
    QString     memExpDate;
    int         memNumber;
    bool        ok;
    QString     item;
    QString     output;
    float       price;
    float       totalRev = 0;
    int         quantity;
    int         totExecs = 0;
    int         totRegs = 0;
    int         i = 0;
    vector<QString> nameList;

    day1.open(QIODevice::ReadOnly);

    while(!infile.atEnd())
    {
        memExpDate = infile.readLine();

        memNum = infile.readLine();
        memNumber = memNum.toInt();

        item  = infile.readLine();
        QString stuff = infile.readLine();

        QStringList splitList = stuff.split(' ', QString::SkipEmptyParts);
        price = splitList.at(0).toFloat();

        quantity = splitList.at(1).toInt(&ok, 10);

        accessMemList.FindMemberAndType(memNumber, memName, memType);

        out << memName.toStdString() << " | " << item.toStdString() << " | " << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        nameList.push_back(memName);

        if(memType == "Executive")
        {
            totExecs++;
        }
        else
        {
            totRegs++;
        }
    }

    day1.close();

    out << fixed << setprecision(2);
    out << "\n\nTOTAL REVENUE FOR THE DAY: " << "$" <<  totalRev << endl
        << "TOTAL # OF EXECUTIVE MEMBERS: " << totExecs << endl
        << "TOTAL # OF REGULAR MEMBERS: " << totRegs;

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
}
