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

          if(FindItem(item))
          {
               UpdateItem(item, quantity);
          }
          else
          {
              newInv.setItem(newDate, memNumber, item, price, quantity);
              inventoryList.push_back(newInv);
          }
    }
}

void SalesList::AddItem(SalesInventory newItem)
{
    inventoryList.push_back(newItem);
}

bool SalesList::DeleteItem(QString itemName)
{
    for(unsigned int i = 0; i < inventoryList.size(); i++)
    {
        if(inventoryList[i].GetItemName() == itemName)
        {
            inventoryList.erase(inventoryList.begin() + i);

            return true;
        }
    }
    return false;
}

void SalesList::PrintItemList()
{

}

void SalesList::UpdateItem(QString name,
                           int     newQuant)
{
    int  index;
    int  currQuant;
    bool found;

    index    = 0;
    found    = false;

    while(!found)
    {
        if(inventoryList[index].GetItemName() == name)
        {
            found = true;

            inventoryList[index].UpdateQuantity(newQuant);
        }
        else
        {
            index++;
        }
    }
}

bool SalesList::FindItem(QString name)
{
    bool           foundMem;
    int            index;

    foundMem = false;
    index    = 0;

    while(!foundMem && index < inventoryList.size())
    {
        if(inventoryList[index].GetItemName() == name)
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

QString SalesList::GetSalesList() const
{
    QString tempInfo;

    for(unsigned int i = 0; i < inventoryList.size(); i++)
    {
        tempInfo += inventoryList[i].getSalesInfo();
    }

    return tempInfo;

}
