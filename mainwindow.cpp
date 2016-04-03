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



void MainWindow::on_pushButton_9_clicked()
{
    memReportUi = new MemReport(this);

    memReportUi->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    QFile day5(":/day5.txt");
    QTextStream infile(&day5);
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
    vector<QString> nameList;

    day5.open(QIODevice::ReadOnly);

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

        out << left << setw(25) << memName.toStdString() << " | "
            << setw(19) << item.toStdString() << " | " << quantity << " |\n";

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

    day5.close();

    out << fixed << setprecision(2);
    out << "\n\nTOTAL REVENUE FOR THE DAY: " << "$" <<  totalRev << endl
        << "TOTAL # OF EXECUTIVE MEMBERS: " << totExecs << endl
        << "TOTAL # OF REGULAR MEMBERS: " << totRegs;

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
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
    ui->textBrowser_7->setText(accessMemList.GetMemberOnlyList());
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

        out << left << setw(25) << memName.toStdString() << " | "
            << setw(19) << item.toStdString() << " | " << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

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

bool MainWindow::FindMemInstance(vector<QString> nameList,
                                 QString         currName)
{
   int memInst = 0;
   int index = 0;
   bool moreThanOnce;

   while(index < nameList.size())
   {
       if(currName == nameList[index])
       {
           memInst++;
       }
       else
       {
           index++;
       }
   }
   if(memInst == 0)
   {
       moreThanOnce = false;
   }
   else
   {
       moreThanOnce = true;
   }

   return moreThanOnce;
}


void MainWindow::on_pushButton_8_clicked()
{
    QFile day2(":/day2.txt");
    QTextStream infile(&day2);
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
    vector<QString> nameList;

    day2.open(QIODevice::ReadOnly);

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

        out << left << setw(25) << memName.toStdString() << " | "
            << setw(19) << item.toStdString() << " | " << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            totExecs++;
        }
        else
        {
            totRegs++;
        }
    }

    day2.close();

    out << fixed << setprecision(2);
    out << "\n\nTOTAL REVENUE FOR THE DAY: " << "$" <<  totalRev << endl
        << "TOTAL # OF EXECUTIVE MEMBERS: " << totExecs << endl
        << "TOTAL # OF REGULAR MEMBERS: " << totRegs;

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_10_clicked()
{
    QFile day3(":/day3.txt");
    QTextStream infile(&day3);
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
    vector<QString> nameList;

    day3.open(QIODevice::ReadOnly);

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

        out << left << setw(25) << memName.toStdString() << " | "
            << setw(19) << item.toStdString() << " | " << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));


    }

    day3.close();

    out << fixed << setprecision(2);
    out << "\n\nTOTAL REVENUE FOR THE DAY: " << "$" <<  totalRev << endl
        << "TOTAL # OF EXECUTIVE MEMBERS: " << totExecs << endl
        << "TOTAL # OF REGULAR MEMBERS: " << totRegs;

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_11_clicked()
{
    QFile day4(":/day4.txt");
    QTextStream infile(&day4);
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
    vector<QString> nameExecList;
    vector<QString> nameRegList;


    day4.open(QIODevice::ReadOnly);

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

        out << left << setw(25) << memName.toStdString() << " | "
            << setw(19) << item.toStdString() << " | " << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            totExecs++;
        }
        else
        {
            totRegs++;
        }
    }

    day4.close();

    out << fixed << setprecision(2);
    out << "\n\nTOTAL REVENUE FOR THE DAY: " << "$" <<  totalRev << endl
        << "TOTAL # OF EXECUTIVE MEMBERS: " << totExecs << endl
        << "TOTAL # OF REGULAR MEMBERS: " << totRegs;

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_3_clicked()
{
    accessMemList.DeleteMember(ui->lineEdit_8->text());
}

void MainWindow::on_pushButton_5_clicked()
{
    QString itemName;
    QString itemPrice;
    float   price;
    SalesInventory newItem;

    itemName = ui->lineEdit_9->text();

    itemPrice = ui->lineEdit_10->text();

    price = itemPrice.toFloat();


}
