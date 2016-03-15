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
    QList<Regular> regMemList;

    QFile       shoppers("BulkClubMembers.txt");
    QTextStream infile(&shoppers);
    QString     memName;
    QString     memNum;
    QString     memType;
    QString     memExpDate;
    int         newMonth;
    int         newDay;
    int         newYear;
    double      memNumber;
    Date        currDate(newMonth,newDay,newYear);
    Regular     newRegMem;
    bool        ok;

    //open the text file to read from
    shoppers.open(QIODevice::ReadOnly | QIODevice::Text);

    qDebug()<<"shopers file open";
    //will keep reading until the end of the file is reached &
    //will read line by line and store info as a QString which
    //will then be used to convert to whatever data type is
    //needed

    memName = infile.readLine();

    while(!shoppers.atEnd())
    {
       memName = infile.readLine();

       memNum = infile.readLine();
       memNumber = memNum.toDouble();

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

       //set info for member
        newRegMem.SetMember(memName,memNumber,memType,newDate,0);

        //add member to list
        regMemList.append(newRegMem);
     }

     shoppers.close();
}
