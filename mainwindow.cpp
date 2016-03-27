#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MemberList accessMemList;

    accessMemList.InitializeMemberList();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::InitializeItemList()
{
    QFile itemsDay1(":/day1.txt");
    QFile itemsDay2(":/day2.txt");
    QFile itemsDay3(":/day3.txt");
    QFile itemsDay4(":/day4.txt");
    QFile itemsDay5(":/day5.txt");
    QTextStream infile1(&itemsDay1);
    QTextStream infile2(&itemsDay2);
    QTextStream infile3(&itemsDay3);
    QTextStream infile4(&itemsDay4);
    QTextStream infile5(&itemsDay5);
    Item newItem;
    Item newItem2;
    Item newItem3;
    Item newItem4;
    Item newItem5;

    itemsDay1.open(QIODevice::ReadOnly);
    itemsDay2.open(QIODevice::ReadOnly);
    itemsDay3.open(QIODevice::ReadOnly);
    itemsDay4.open(QIODevice::ReadOnly);
    itemsDay5.open(QIODevice::ReadOnly);


    while(!infile1.atEnd())
    {
        //reads through the first line
        infile1.readLine();
        infile2.readLine();
        infile3.readLine();
        infile4.readLine();
        infile5.readLine();

        //reads through the second line
        infile1.readLine();
        infile2.readLine();
        infile3.readLine();
        infile4.readLine();
        infile5.readLine();

        newItem.name = infile1.readLine();
        newItem2.name= infile2.readLine();
        newItem3.name= infile3.readLine();
        newItem4.name= infile4.readLine();
        newItem5.name= infile5.readLine();

        QStringList strList1 = infile1.readLine().split("    ");
        QStringList strList2 = infile2.readLine().split("    ");
        QStringList strList3 = infile3.readLine().split("    ");
        QStringList strList4 = infile4.readLine().split("    ");
        QStringList strList5 = infile5.readLine().split("    ");

















    }
}

void MainWindow::on_pushButton_11_clicked()
{
    membership = new ExecReg(this);

    membership->show();
}
