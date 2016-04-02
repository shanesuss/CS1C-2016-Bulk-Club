#include "SalesList.h"

SalesList::SalesList()
{

}
void SalesList::InitializeSalesList()
{
    QFile       inventory(":SalesReports.txt");
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

        while(!inFile.atEnd())
        {
            memExpDate = inFile.readLine();
            QStringList dateStr = memExpDate.split("/");

            dateStr.at(0).toInt(&ok, 10);
            dateStr.at(1).toInt(&ok, 10);
            dateStr.at(2).toInt(&ok, 10);

              Date newDate(dateStr.at(0).toInt(&ok, 10),
                           dateStr.at(1).toInt(&ok, 10),
                           dateStr.at(2).toInt(&ok, 10));

              memNum = inFile.readLine();
              memNumber = memNum.toInt();

              item  = inFile.readLine();
              QString stuff = inFile.readLine();

              QStringList splitList = stuff.split(' ', QString::SkipEmptyParts);
              price = splitList.at(0).toFloat();

              quantity = splitList.at(1).toInt(&ok, 10);

              if(FindItem(memNumber))
              {
                   UpdateItem(memNumber, quantity);
              }
              else
              {
                  newInv.setItem(newDate, memNumber, item, price, quantity);
                  inventoryList.push_back(newInv);
              }
        }
}

//void SalesList::AddItem(SalesInventory newItem)
//{
//    inventoryList.push_back(newItem);
//}

//void SalesList::DeleteItem()
//{

//}

void SalesList::PrintItemList()
{

}

void SalesList::UpdateItem(int memNum, int newQuant)
{
    SalesInventory currItem;
    int  index;
    int  currQuant;
    bool found;

    index    = 0;
    found    = false;

    while(!found)
    {
        currItem = inventoryList[index];

        if(currItem.GetId() == memNum)
        {
            found = true;

            currItem.UpdateQuantity(newQuant);

            inventoryList[index] = currItem;
        }
        else
        {
            index++;
        }
    }
}

bool SalesList::FindItem(int memNum)
{
    SalesInventory currItem;
    bool           foundMem;
    int            index;

    foundMem = false;
    index    = 0;

    while(!foundMem && index < inventoryList.size())
    {
        currItem = inventoryList[index];

        if(currItem.GetId() == memNum)
        {
            foundMem = true;
        }
        else
        {
            index++;
        }
    }

    return foundMem;
}
