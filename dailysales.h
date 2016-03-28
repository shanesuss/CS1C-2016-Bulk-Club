#ifndef DAILYSALES_H
#define DAILYSALES_H

#include <QDialog>

namespace Ui {
class DailySales;
}

class DailySales : public QDialog
{
    Q_OBJECT

public:
    explicit DailySales(QWidget *parent = 0);
    ~DailySales();

private:
    Ui::DailySales *ui;
};

#endif // DAILYSALES_H
