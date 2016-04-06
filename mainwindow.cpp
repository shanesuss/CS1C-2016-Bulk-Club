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
    UpdateMemberList();
    accessMemList.GetMember(77777).UpdateSales();
    ui->textBrowser_7->setText(accessMemList.GetMemberOnlyList());
    ui->textBrowser_8->setText(accessMemList.GetExecutiveOnlyList());
    ui->textBrowser_6->setText(accessSalesList.GetSalesListInfo());
    accessMemList.GetRebates();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{
    vector<SalesInventory> tempList;

    QString text;
    ostringstream output;

    accessSalesList.CopySalesList(tempList);
    accessSalesList.SelectionSort(tempList, "");

    for(unsigned int i = 0; i < tempList.size(); i++)
    {
        output << fixed << setprecision(2);
        output << left << "| " << setw(26) << tempList[i].GetItemName().toStdString() << " | "
               << setw(3) << tempList[i].GetQuantity()<< " | "
               << "$" << setw(7) << tempList[i].GetPrice() << " | " << endl;

        text += QString::fromStdString(output.str());
    }

    ui->textBrowser_5->setText(QString::fromStdString(output.str()));
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
    vector<QString> execList;
    vector<QString> regList;

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

        out << left << setw(30) << memName.toStdString() << " | "
            << setw(26) << item.toStdString() << " | " << setw(2) << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            if(execList.size() == 0 || !FindMemInstance(execList, memName))
            {
               execList.push_back(memName);
            }
        }
        else
        {
            if(regList.size() == 0 || !FindMemInstance(regList, memName))
            {
                regList.push_back(memName);
            }
        }
    }
    day5.close();

    out << fixed << setprecision(2);
    out << setw(30) << "\n\nTOTAL REVENUE FOR THE DAY" << ": "<< "$" <<  totalRev << endl
        << setw(28) << "TOTAL # OF EXECUTIVE MEMBERS"  << ": "<< execList.size() << endl
        << setw(28) << "TOTAL # OF REGULAR MEMBERS"    << ": "<< regList.size();

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
}


void MainWindow::on_pushButton_4_clicked()
{
    accessMemList.ReturnSortedList();
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
    vector<QString> execList;
    vector<QString> regList;

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

        out << left << setw(30) << memName.toStdString() << " | "
            << setw(26) << item.toStdString() << " | " << setw(2) << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            if(execList.size() == 0 || !FindMemInstance(execList, memName))
            {
               execList.push_back(memName);
            }
        }
        else
        {
            if(regList.size() == 0 || !FindMemInstance(regList, memName))
            {
                regList.push_back(memName);
            }
        }
    }

    day1.close();

    out << fixed << setprecision(2);
    out << setw(30) << "\n\nTOTAL REVENUE FOR THE DAY" << ": "<< "$" <<  totalRev << endl
        << setw(28) << "TOTAL # OF EXECUTIVE MEMBERS"  << ": "<< execList.size() << endl
        << setw(28) << "TOTAL # OF REGULAR MEMBERS"    << ": "<< regList.size();

    ui->textBrowser_5->setText(QString::fromStdString(out.str()));
}

bool MainWindow::FindMemInstance(vector<QString> nameList,
                                 QString         currName)
{
   int memInst = 0;
   bool moreThanOnce;

   for(int i = 0; i < nameList.size(); i++)
   {
       if(currName == nameList[i])
       {
           memInst++;
       }
   }

   if(memInst >= 1)
   {
       moreThanOnce = true;
   }
   else
   {
       moreThanOnce = false;
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
    vector<QString> execList;
    vector<QString> regList;

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

        out << left << setw(30) << memName.toStdString() << " | "
            << setw(26) << item.toStdString() << " | " << setw(2) << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            if(execList.size() == 0 || !FindMemInstance(execList, memName))
            {
               execList.push_back(memName);
            }
        }
        else
        {
            if(regList.size() == 0 || !FindMemInstance(regList, memName))
            {
                regList.push_back(memName);
            }
        }
    }

    day2.close();

    out << fixed << setprecision(2);
    out << setw(30) << "\n\nTOTAL REVENUE FOR THE DAY" << ": "<< "$" <<  totalRev << endl
        << setw(28) << "TOTAL # OF EXECUTIVE MEMBERS"  << ": "<< execList.size() << endl
        << setw(28) << "TOTAL # OF REGULAR MEMBERS"    << ": "<< regList.size();

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
    vector<QString> execList;
    vector<QString> regList;

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

        out << left << setw(30) << memName.toStdString() << " | "
            << setw(26) << item.toStdString() << " | " << setw(2) << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            if(execList.size() == 0 || !FindMemInstance(execList, memName))
            {
               execList.push_back(memName);
            }
        }
        else
        {
            if(regList.size() == 0 || !FindMemInstance(regList, memName))
            {
                regList.push_back(memName);
            }
        }
    }
    day3.close();

    out << fixed << setprecision(2);
    out << setw(30) << "\n\nTOTAL REVENUE FOR THE DAY" << ": "<< "$" <<  totalRev << endl
        << setw(28) << "TOTAL # OF EXECUTIVE MEMBERS"  << ": "<< execList.size() << endl
        << setw(28) << "TOTAL # OF REGULAR MEMBERS"    << ": "<< regList.size();

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
    vector<QString> execList;
    vector<QString> regList;


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

        out << left << setw(30) << memName.toStdString() << " | "
            << setw(26) << item.toStdString() << " | " << setw(2) << quantity << " |\n";

        ui->textBrowser_5->setText(QString::fromStdString(out.str()));

        totalRev += (price * static_cast<float>(quantity));

        if(memType == "Executive")
        {
            if(execList.size() == 0 || !FindMemInstance(execList, memName))
            {
               execList.push_back(memName);
            }
        }
        else
        {
            if(regList.size() == 0 || !FindMemInstance(regList, memName))
            {
                regList.push_back(memName);
            }
        }
    }
    day4.close();

    out << fixed << setprecision(2);
    out << setw(30) << "\n\nTOTAL REVENUE FOR THE DAY" << ": "<< "$" <<  totalRev << endl
        << setw(28) << "TOTAL # OF EXECUTIVE MEMBERS"  << ": "<< execList.size() << endl
        << setw(28) << "TOTAL # OF REGULAR MEMBERS"    << ": "<< regList.size();

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
    Date newDate(4,3,2016);

    itemName = ui->lineEdit_9->text();

    itemPrice = ui->lineEdit_10->text();

    price = itemPrice.toFloat();

    newItem = SalesInventory(newDate, 394850, itemName, price, 100);

    accessSalesList.AddItem(newItem);

    ui->textBrowser_6->setText(accessSalesList.GetSalesListInfo());
}

void MainWindow::on_pushButton_6_clicked()
{
    accessSalesList.DeleteItem(ui->lineEdit_9->text());

    ui->textBrowser_6->setText(accessSalesList.GetSalesListInfo());
}

void MainWindow::on_pushButton_ExpirationDates_clicked()
{
    int month = ui->lineEdit_ExpirationDate->text().toInt();
    ui->textBrowser_ExpirationDate->setText(accessMemList.GetExpirationDates(month));
}

void MainWindow::on_pushButton_ItemReport_clicked()
{
    ostringstream output;
    try{
     SalesInventory temp = accessSalesList.GetItem(ui->lineEdit_9->text());
     output << left << "| "<< temp.GetItemName().toStdString() << " | $"
            << temp.GetPrice() << " | " << temp.GetQuantity() << " |";

    }catch (int e)
    {
        output << "Error while processing input -- not in list!";
    }
    ui->textBrowser_6->setText(QString::fromStdString(output.str()));
}

void MainWindow::on_pushButton_MemberPurchases_clicked()
{
    ui->textBrowser_ExpirationDate->setText(accessSalesList.GetMemberSalesList(ui->lineEdit_MemberPurchases->text().toInt()));
}

void MainWindow::on_pushButton_MembershipStatus_clicked()
{
    ui->textBrowser_7->setText(accessMemList.GetMemberUpgrades());
    ui->textBrowser_8->setText(accessMemList.GetExecutiveDowngrades());
}

void MainWindow::UpdateMemberList()
{
    Member temp;
    int id;

    for(unsigned int i = 0; i < accessSalesList.GetSize(); i++)
    {
        id = accessSalesList.GetItem(i).GetId();
        temp = accessMemList.GetMember(id);
        accessMemList.DeleteMember(id);
        temp.AddPurchase(accessSalesList.GetItem(i).GetPrice(), accessSalesList.GetItem(i).GetQuantity());
        accessMemList.AddMember(temp);
    }
}

void MainWindow::on_pushButton_GetRebates_clicked()
{
    ui->textBrowser_8->setText(accessMemList.GetRebates());
}

void MainWindow::on_pushButton_clicked()
{
    vector<SalesInventory> tempList;
    float totCosts = 0;
    QString newText;
    ostringstream output;

    accessSalesList.CopySalesList(tempList);

    accessSalesList.SelectionSort(tempList, 0);

    for(int i = 0; i < tempList.size(); i++)
    {
        newText += tempList[i].getSalesInfo();

        totCosts += tempList[i].GetPrice() * tempList[i].GetQuantity();
    }

    output << fixed << setprecision(2);
    output << "\nTOTAL COST OF ALL PURCHASES: " << totCosts;

    newText += QString::fromStdString(output.str());

    ui->textBrowser_6->setText(newText);
}

