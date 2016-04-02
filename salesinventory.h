#ifndef SALESINVENTORY_H
#define SALESINVENTORY_H
#include <QString>
#include"Date.h"

class SalesInventory
{
public:
    SalesInventory();
    SalesInventory(Date mydate, int id, QString item, float price, int quantity);

    void setItem(Date mydate, int id, QString item, float price, int quantity);

    int GetId() const;

    int GetQuantity() const;

    void UpdateQuantity (int newQuant);

private:
    Date invDate;
    int invId;
    QString invItem;
    float invPrice;
    int invQuantity;

};

#endif // SALESINVENTORY_H
