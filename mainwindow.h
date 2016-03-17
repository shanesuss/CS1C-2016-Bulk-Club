#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Member.h"
#include "Executive.h"
#include "date.h"
#include <QApplication>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <string>
#include <QDebug>
#include <fstream>

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

    QList<Executive> execMemList;
    QList<Member>   regMemList;
    
    void InitializeMemberList();
};

#endif // MAINWINDOW_H
