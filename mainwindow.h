#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Member.h"
#include "Executive.h"
#include "Date.h"
#include "MemberList.h"
#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <string>
#include <QDebug>
#include <fstream>
#include <vector>
#include "execreg.h"

struct Item
{
    QString name;
    float   cost;
    unsigned short totQuant;
};

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

private:
    Ui::MainWindow *ui;

    ExecReg *membership;

    vector<Item> inventory;

    void InitializeItemList();
};

#endif // MAINWINDOW_H
