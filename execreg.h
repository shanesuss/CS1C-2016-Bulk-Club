#ifndef EXECREG_H
#define EXECREG_H

#include <QDialog>
#include "newregular.h"
#include "newexecutive.h"

namespace Ui {
class ExecReg;
}

class NewRegular;

class NewExecutive;

class ExecReg : public QDialog
{
    Q_OBJECT

public:
    explicit ExecReg(QWidget *parent = 0);
    ~ExecReg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ExecReg *ui;

    NewRegular *regularWindow;

    NewExecutive *execWindow;
};

#endif // EXECREG_H
