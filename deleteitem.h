#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QDialog>

namespace Ui {
class DeleteItem;
}

class DeleteItem : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteItem(QWidget *parent = 0);
    ~DeleteItem();

private:
    Ui::DeleteItem *ui;
};

#endif // DELETEITEM_H
