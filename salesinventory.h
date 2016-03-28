#ifndef SALESINVENTORY_H
#define SALESINVENTORY_H
#include <Qstring>
#include"Date.h"

class SalesInventory
{
public:
    SalesInventory();
    SalesInventory(Date mydate, int id, QString item, float price, int quantity);

    void setdItem(Date mydate, int id, QString item, float price, int quantity);

private:
    Date invDate;
    int invId;
    QString invItem;
    float invPrice;
    int invQuantity;

};

#endif // SALESINVENTORY_H
