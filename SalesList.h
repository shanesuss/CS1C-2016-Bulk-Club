#ifndef SALESLIST_H
#define SALESLIST_H
#include "salesinventory.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <iomanip>
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>

class SalesList
{
public:
    SalesList();
    void InitializeSalesList();
    void AddItem(item newItem);
    void DeleteItem();
    void PrintItemList();
    

private:
    vector<Item> inventory;
};

#endif // SALESLIST_H