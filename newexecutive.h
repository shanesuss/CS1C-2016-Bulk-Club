#ifndef NEWEXECUTIVE_H
#define NEWEXECUTIVE_H

#include <QDialog>
#include "MemberList.h"

namespace Ui {
class NewExecutive;
}

class NewExecutive : public QDialog
{
    Q_OBJECT

public:
    explicit NewExecutive(QWidget *parent = 0);
    ~NewExecutive();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewExecutive *ui;
};

#endif // NEWEXECUTIVE_H
