#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Member.h"
#include "Executive.h"
#include "Date.h"
#include "MemberList.h"
#include "dailysales.h"
#include "memreport.h"
#include "deletemember.h"
#include "deleteitem.h"
#include "additem.h"
#include "SalesList.h"
#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <string>
#include <QDebug>
#include <fstream>
#include <vector>
#include "execreg.h"


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

private slots:

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::MainWindow *ui;

    ExecReg *membership;

    DailySales *reportUi;

    MemReport *memReportUi;

    DeleteMember *delMemUi;

    AddItem *addItemUi;

    DeleteItem *delItemUi;

    void InitializeItemList();
};

#endif // MAINWINDOW_H
