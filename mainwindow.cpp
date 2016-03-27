#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeMemberList()
{
    QFile       shoppers(":/BulkClubMembers.txt");
    QFile       inventory(":/SalesReport.txt");
    QTextStream inFile(&inventory);
    QTextStream infile(&shoppers);
    QString     memName;
    QString     memNum;
    QString     memType;
    QString     memExpDate;
    int         newMonth;
    int         newDay;
    int         newYear;
    int      memNumber;
    Date        currDate(newMonth,newDay,newYear);
    Member      newRegMem;
    Executive   newExecMem;
    bool        ok;
    QString     item;
    float       price;
    int         quantity;

    //open the text file to read from
    shoppers.open(QIODevice::ReadOnly);

    //will keep reading until the end of the file is reached &
    //will read line by line and store info as a QString which
    //will then be used to convert to whatever data type is
    //needed
    while(!infile.atEnd())
    {
        memName = infile.readLine();

        memNum = infile.readLine();
        memNumber = memNum.toInt();

        memType = infile.readLine();

        memExpDate = infile.readLine();

        //splits the date into month, day and year
        QStringList dateStr = memExpDate.split("/");

        dateStr.at(0).toInt(&ok, 10);
        dateStr.at(1).toInt(&ok, 10);
        dateStr.at(2).toInt(&ok, 10);

        Date newDate(dateStr.at(0).toInt(&ok, 10),
                     dateStr.at(1).toInt(&ok, 10),
                     dateStr.at(2).toInt(&ok, 10));

        //set info for specific member
         newRegMem = Member(memName,memNumber,newDate,0.0);

         if(memType == "Executive")
         {
             newExecMem.SetMember(memName,memNumber,newDate,0.0);
         }
         else if(memType == "Regular")
         {
             newRegMem.SetMember(memName,memNumber,newDate,0.0);
         }

         //add member to list
         regMemList.append(newRegMem);
         execMemList.append(newExecMem);        
    }

    inventory.open(QIODevice::ReadOnly);
    while(!inFile.atEnd()){

        memExpDate = infile.readLine();
        QStringList dateStr = memExpDate.split("/");

        dateStr.at(0).toInt(&ok, 10);
        dateStr.at(1).toInt(&ok, 10);
        dateStr.at(2).toInt(&ok, 10);

          Date newDate(dateStr.at(0).toInt(&ok, 10),
                     dateStr.at(1).toInt(&ok, 10),
                     dateStr.at(2).toInt(&ok, 10));

    }
}
