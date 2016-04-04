#ifndef SALESINVENTORY_H
#define SALESINVENTORY_H
#include <QString>
#include"Date.h"
#include<ostream>
#include<sstream>
#include<iostream>
#include<iomanip>
using namespace std;
class SalesInventory
{
public:
    SalesInventory();
    SalesInventory(Date myDate, int id, QString item, float price, int quantity);

    void setItem(Date mydate, int id, QString item, float price, int quantity);

    QString GetItemName() const;

    int GetId() const;

    int GetQuantity() const;

    void UpdateQuantity (int newQuant);

    QString getSalesInfo() const;

private:
    Date    invDate;
    int     invId;
    QString invItem;
    float   invPrice;
    int     invQuantity;

};

#endif // SALESINVENTORY_H
