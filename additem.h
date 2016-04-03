#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include "SalesList.h"
#include "salesinventory.h"

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
