#ifndef SALESINVENTORY_H
#define SALESINVENTORY_H
#include"Date.h"
#include<QString>

class SalesInventory
{
public:
    SalesInventory();
    SalesInventory(Date date, int id, QString item, float price, int quantity);
    SetInventory(Date date, int id, QString item, float price, int quantity);
  
private:

    Date invDate;
    int  invId;
    QString invItem;
    float invPrice;
    int invQuantity;

};

#endif // SALESINVENTORY_H