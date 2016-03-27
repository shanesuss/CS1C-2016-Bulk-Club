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
    ~NewRegular();

private:
    Ui::NewRegular *ui;
};

#endif // NEWREGULAR_H
