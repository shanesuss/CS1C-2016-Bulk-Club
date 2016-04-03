#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Member.h"
#include "Executive.h"
#include "Date.h"
#include "MemberList.h"
#include "memreport.h"
#include "deletemember.h"
#include "deleteitem.h"
#include "additem.h"
#include "SalesList.h"
#include <QApplication>
#include <iostream>
#include <iomanip>
#include <QTextStream>
#include <QFile>
#include <string>
#include <QDebug>
#include <fstream>
#include <sstream>
#include <ostream>
#include <vector>
#include "execreg.h"
#include<QString>
#include <string>

using namespace std;

namespace Ui {
class MainWindow;
}

class ExecReg;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool FindMemInstance(vector<QString> nameList,
                         QString         currName);

private slots:

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

    ExecReg *membership;

    MemReport *memReportUi;

    DeleteMember *delMemUi;

    AddItem *addItemUi;

    DeleteItem *delItemUi;

    MemberList accessMemList;

    SalesList accessSalesList;

    void InitializeItemList();
};

#endif // MAINWINDOW_H
