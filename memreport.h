#ifndef MEMREPORT_H
#define MEMREPORT_H

#include <QDialog>

namespace Ui {
class MemReport;
}

class MemReport : public QDialog
{
    Q_OBJECT

public:
    explicit MemReport(QWidget *parent = 0);
    ~MemReport();

private:
    Ui::MemReport *ui;
};

#endif // MEMREPORT_H
