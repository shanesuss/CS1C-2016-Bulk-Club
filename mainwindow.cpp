#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    accessMemList.InitializeMemberList();
    ui->textBrowser_7->setText(accessMemList.GetMemberOnlyList());
    ui->textBrowser_8->setText(accessMemList.GetExecutiveOnlyList());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_11_clicked()
{
    membership = new ExecReg(this, )
    membership->show();
    /*The following code is unimplemented as AddMember is not finished:
     *
     * ui->textBrowser_7->setText(accessMemList.GetMemberOnlyList());
     */
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


void MainWindow::on_pushButton_16_clicked()
{
    delItemUi = new DeleteItem(this);

    delItemUi->show();
}

void MainWindow::on_pushButton_15_clicked()
{
    addItemUi = new AddItem(this);
    addItemUi->show();
}
