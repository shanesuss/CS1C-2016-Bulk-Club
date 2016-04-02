#ifndef SALESLIST_H
#define SALESLIST_H
#include "salesinventory.h"
#include "mainwindow.h"
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
    void DeleteItem();
    void PrintItemList();
    void UpdateItem(int memNum, int newQuant);
    bool FindItem(int memNum);
    

private:
    vector<SalesInventory> inventoryList;
};

#endif // SALESLIST_H
