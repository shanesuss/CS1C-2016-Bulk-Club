#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "regular.h"
#include "date.h"

const float REBATE_AMT = .035;

class Executive: public Regular
{
public:
    Executive(QString newName,
              double  newNum,
              QString newType,
              Date    newDate,
              float   newSpent,
              float   newRebate);

    ~Executive();

    void ChangeName(QString newName);

    void ChangeMemNum(double newMemNum);

    void ChangeType(QString newType);

    void ChangeExpDate(Date newDate);

    void ChangeTotSpent(float newSpent);

    void UpdateRebate(float newRebate);

private:
    float rebate;
};

#endif // EXECUTIVE_H
