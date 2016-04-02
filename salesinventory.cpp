#include "salesinventory.h"

SalesInventory::SalesInventory()
{

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
