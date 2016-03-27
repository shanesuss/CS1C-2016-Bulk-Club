#ifndef SALESINVENTORY_H
#define SALESINVENTORY_H
#include <QString>
#include <iomanip>
#include <iostream>
#include <string>
#include "Date.h"]
#include<qDebug>


class SalesInventory
{
public:
    SalesInventory();
    SalesInventory(Date date,int memId, QString item, float price, int quantity);

    void setItem(Date date, int memId, QString item, float price, int quantity);

    void print();

    private:

QString invItem;
float invPrice;
int invQuantity;
Date invDate;
int invMemId;

};

#endif // SALESINVENTORY_H