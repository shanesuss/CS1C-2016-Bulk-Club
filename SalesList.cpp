#include "SalesList.h"
SalesList::SalesList()
{

}
void SalesList::InitializeSalesList()
{
    QFile       inventory(":/SalesReports.txt");
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
SalesInventory SalesList::GetItem(int index) const
{
    return inventoryList[index];
}

unsigned int SalesList::GetSize() const
{
    return inventoryList.size();
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

void SalesList::SelectionSort(vector<SalesInventory> &list, int id)
{
    int pos_min;
    SalesInventory temp;
    int n = this->GetSize();

    for(int i = 0; i < n-1; i++)
    {
        pos_min = i;
        for(int j = i+1; j<n; j++)
        {
            qDebug() << list[j].GetId();
            if(list[j].GetId() < list[pos_min].GetId())
            {
                pos_min = j;
            }
        }
        if(pos_min != i)
        {
            temp = list[i];
            list[i] = list[pos_min];
            list[pos_min] = temp;
        }
    }
}

void SalesList::SelectionSort(vector<SalesInventory> &list, QString names)
{
    int pos_min;
    SalesInventory temp;
    int n = this->GetSize();

    for(int i = 0; i < n-1; i++)
    {
        pos_min = i;
        for(int j = i+1; j<n; j++)
        {
            qDebug() << list[j].GetId();
            if(list[j].GetItemName() < list[pos_min].GetItemName())
            {
                pos_min = j;
            }
        }
        if(pos_min != i)
        {
            temp = list[i];
            list[i] = list[pos_min];
            list[pos_min] = temp;
        }
    }
}

void SalesList::CopySalesList(vector<SalesInventory> &newList)
{
    for(int i = 0; i < inventoryList.size(); i++)
    {
        newList.push_back(inventoryList[i]);
    }
}

QString SalesList::GetSalesListInfo() const
{
    QString tempInfo;

    for(unsigned int i = 0; i < inventoryList.size(); i++)
    {
        tempInfo += inventoryList[i].getSalesInfo();
    }

    return tempInfo;

}


SalesInventory SalesList::GetItem(QString name) const
{
    for(unsigned int i = 0; i < inventoryList.size(); i++)
    {
        if(inventoryList[i].GetItemName() == name)
        {
            return inventoryList[i];
        }
    }
    throw -1;
}

QString SalesList::GetMemberSalesList(int id) const
{
    ostringstream output;
    for(unsigned int i = 0; i < inventoryList.size(); i++)
    {
        if(inventoryList[i].GetId() == id)
        {
            output << inventoryList[i].getSalesInfo().toStdString();
        }
    }
    return QString::fromStdString(output.str());
}


bool operator<(const SalesInventory &s1, const SalesInventory &s2)
{
    return (s1.GetItemName() < s2.GetItemName());
}

bool operator>(const SalesInventory &s1, const SalesInventory &s2)
{
    return (s1.GetItemName() > s2.GetItemName());
}

//inventoryList = sort(accessSalesList.begin(), accessSalesList.end());
