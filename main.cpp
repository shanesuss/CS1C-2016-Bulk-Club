#include "mainwindow.h"
#include "regular.h"
#include "date.h"
#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <string>
#include <QDebug>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QList<Regular> regMemList;

    QFile shoppers("BulkClubMembers.txt");
    QTextStream infile(&shoppers);
    QString memName;
    QString memNum;
    QString memType;
    QString memExpDate;
    int     newMonth;
    int     newDay;
    int     newYear;
    double  memNumber;
    Date    currDate(newMonth,newDay,newYear);
    Regular newRegMem;
    bool    ok;

    //open the text file to read from
    if(shoppers.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        //will keep reading until the end of the file is reached &
        //will read line by line and store info as a QString which
        //will then be used to convert to whatever data type is
        //needed
       while(!infile.atEnd())
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
    }
    shoppers.close();

    return a.exec();
}
