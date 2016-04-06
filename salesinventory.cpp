#include "salesinventory.h"

SalesInventory::SalesInventory()
{

}

SalesInventory::SalesInventory(Date myDate,
                               int id,
                               QString item,
                               float price,
                               int quantity)
{
    invDate = myDate;
    invId  = id;
    invItem = item;
    invPrice = price;
    invQuantity = quantity;
}

float SalesInventory::GetPrice() const
{
    return invPrice;
}

void SalesInventory::setItem(Date    mydate,
                             int     id,
                             QString item,
                             float   price,
                             int     quantity)
{
    invDate = mydate;
    invId = id;
    invItem = item;
    invPrice = price;
    invQuantity = quantity;
}

QString SalesInventory::GetItemName() const
{
    return invItem;
}
int SalesInventory::GetId() const
{
    return invId;
}

int SalesInventory::GetQuantity() const
{
    return invQuantity;
}

void SalesInventory::UpdateQuantity(int newQuant)
{
    invQuantity += newQuant;
}

QString SalesInventory::getSalesInfo()const{


        ostringstream output;
        output  << fixed << left << "| " << invId << " | " << setw(26) << invItem.toStdString()
                << " | "  <<  "$" << setprecision(2) << fixed << setw(6) << invPrice << " |\n";
        return QString::fromStdString(output.str());
    }

void SalesInventory::RemovebyIndex(int index, vector<SalesInventory> &list)
{
    list.erase(list.begin() + index);
}
