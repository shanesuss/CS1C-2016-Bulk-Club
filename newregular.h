#ifndef NEWREGULAR_H
#define NEWREGULAR_H

#include <QDialog>
#include "MemberList.h"

namespace Ui {
class NewRegular;
}

class NewRegular : public QDialog
{
    Q_OBJECT

public:
    explicit NewRegular(QWidget *parent = 0);
    Member GetMember();
    ~NewRegular();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewRegular *ui;
    Member newMember;
};

#endif // NEWREGULAR_H
