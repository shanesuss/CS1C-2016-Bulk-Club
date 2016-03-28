#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MemberList accessMemList;

    accessMemList.InitializeMemberList();
    ui->textBrowser_5->setText(accessMemList.GetMemberList());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_11_clicked()
{
    membership = new ExecReg(this);

    membership->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    reportUi = new DailySales(this);

    reportUi->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    memReportUi = new MemReport(this);

    memReportUi->show();
}

void MainWindow::on_pushButton_12_clicked()
{
    delMemUi = new DeleteMember(this);

    delMemUi->show();
}
