#ifndef SALESINVENTORY_H
#define SALESINVENTORY_H
#include <QString>
#include <iomanip>
#include <iostream>
#include <string>
#include "Date.h"


class SalesInventory
{
public:
    SalesInventory();
    SalesInventory(Date date,int memId, QString item, float price, int quantity);


    private:
struct inventory{
    QString invItem;
    float invPrice;
    int invQuantity;
};
Date invDate;
int invMemId;
inventory access;
};

#endif // SALESINVENTORY_H
