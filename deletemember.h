#ifndef DELETEMEMBER_H
#define DELETEMEMBER_H

#include <QDialog>

namespace Ui {
class DeleteMember;
}

class DeleteMember : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteMember(QWidget *parent = 0);
    ~DeleteMember();

private:
    Ui::DeleteMember *ui;
};

#endif // DELETEMEMBER_H
