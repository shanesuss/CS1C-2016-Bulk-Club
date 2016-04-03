#ifndef SALESLIST_H
#define SALESLIST_H
#include "salesinventory.h"
#include <QApplication>
#include <iostream>
#include <QApplication>
#include <iomanip>
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

using namespace std;

class SalesList
{
public:
    SalesList();
    void InitializeSalesList();
    void AddItem(SalesInventory newItem);
    bool DeleteItem(QString itemName);
    void PrintItemList();
    void UpdateItem(QString name, int newQuant);
    bool FindItem(QString name);
    QString GetSalesList() const;

private:
    vector<SalesInventory> inventoryList;
};

#endif // SALESLIST_H
