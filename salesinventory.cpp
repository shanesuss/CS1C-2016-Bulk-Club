#include "salesinventory.h"



SalesInventory::SalesInventory()
{
    invItem = " ";
    invPrice = 0.0;
    invQuantity = 0;
    invDate.SetDate(0,0,0);
    int invMemId = 0;

}

SalesInventory::SalesInventory(Date date, int memId, QString item, float price, int quantity){
    invDate = date;
    invMemId = memId;
    invItem = item;
    invPrice = price;
    invQuantity = quantity;
}

void SalesInventory::setItem(Date date,int memId, QString item, float price, int quantity)
{
    invDate = date;
    invMemId = memId;
    invItem = item;
    invPrice = price;
    invQuantity = quantity;

}

void SalesInventory::print()
{
    qDebug() << invItem;
}
