#include "salesinventory.h"



SalesInventory::SalesInventory()
{
    access.invItem = " ";
    access.invPrice = 0.0;
    access.invQuantity = 0;
    invDate = Date::SetDate(0,0,0);
    int invMemId = 0;

}

SalesInventory::SalesInventory(Date date, int memId, QString item, float price, int quantity){
    invDate = date;
    invMemId = memId;
    access.invItem = item;
    access.invPrice = price;
    access.invQuantity = quantity;
}
