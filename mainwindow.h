#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Member.h"
#include "Executive.h"
#include "Date.h"
#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <string>
#include <QDebug>
#include <fstream>
#include <vector>
#include "salesinventory.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


private:
    Ui::MainWindow *ui;
    QList<SalesInventory> inventoryList;
    QList<Executive> execMemList;
    QList<Member>   regMemList;
    
    void InitializeMemberList();
};

#endif // MAINWINDOW_H
