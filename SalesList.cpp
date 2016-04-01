#include "saleslist.h"

SalesList::SalesList()
{

}
void SalesList::InitializeSalesList()
{

}

void SalesList::AddItem(item newItem)
{

    QFile       inventory(":/SalesReport.txt");
    QTextStream inFile(&inventory);
    QString     memName;
    QString     memNum;
    QString     memType;
    QString     memExpDate;
    int         newMonth;
    int         newDay;
    int         newYear;
    int         memNumber;
    Date        currDate(newMonth,newDay,newYear);
    SalesInventory newInv;
    bool        ok;
    QString     item;
    float       price;
    int         quantity;



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

              memNum = infile.readLine();
              memNumber = memNum.toInt();
              item  = infile.readLine();
              QString stuff = inFile.readLine();
              QStringList split = stuff.split("\s");
              price = split.at(0).toFloat(&ok, 10);
              quantity = split.at(1).toInt(&ok, 10);
              newInv.setItem(newDate, memNumber, item, price, quantity);
              inventoryList.append(newInv);
        }
}

void SalesList::DeleteItem()
{

}

void SalesList::PrintItemList()
{

}