#include "salesinventory.h"

//08/01/2015
//12345
//1 gallon milk
//6.09	88
SalesInventory::SalesInventory()
{
    invDate = Date.SetDate(0,0,0);
    invId =0;
    invItem = "";
    invPrice = 0;
    invQuantity =0;
}
SalesInventory::SalesInventory(Date date, int id, QString item, float price, int quantity)
{
    invDate = date;
    invId = id;
    invItem = item;
    invPrice = price;
    invQuantity = quantity;

}

SalesInventory::SetInventory(Date date, int id, QString item, float price, int quantity)
{
    invDate = date;
    invId = id;
    invItem = item;
    invPrice = price;
    invQuantity = quantity;
}
