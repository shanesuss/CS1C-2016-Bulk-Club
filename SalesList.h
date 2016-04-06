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

class MemberList;

class SalesList
{
public:
    SalesList();
    void InitializeSalesList();
    void AddItem(SalesInventory newItem);
    bool DeleteItem(QString itemName);
    void PrintItemList();
    void SelectionSort(vector<SalesInventory> &list, int id);
    void SelectionSort(vector<SalesInventory> &list, QString names);
    unsigned int GetSize() const;
  //  void UpdatePurchases(MemberList myList);
    SalesInventory GetItem(QString name) const;
    SalesInventory GetItem(int index) const;
    void UpdateItem(QString name, int newQuant);
    void CopySalesList(vector<SalesInventory> &newList);
    bool FindItem(QString name);

    QString GetSalesListInfo() const;
    QString GetMemberSalesList(int id) const;


private:
    vector<SalesInventory> inventoryList;
};

#endif // SALESLIST_H
