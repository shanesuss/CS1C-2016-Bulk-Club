#include "Executive.h"

Executive::Executive() :Regular()
{
    rebate = 0;
}

Executive::Executive(QString newName,
                     double  newNum,
                     QString newType,
                     Date    newDate,
                     float   newSpent,
                     float   newRebate)
                     :Regular(newName,newNum,newType,newDate,newSpent)
{
    rebate = newRebate;
}

Executive::~Executive() {}

void Executive::SetMember(QString newName,
                          double  newNum,
                          QString newType,
                          Date    newDate,
                          float   newSpent,
                          float   newRebate)
{
    Regular::SetMember(newName,newNum,newType,newDate,newSpent);

    rebate = newRebate;
}

void Executive::SetTotalSpent(float newSpent)
{
    this->totalSpent = newSpent;
    UpdateRebate();
}

void Executive::UpdateRebate()
{
    rebate = this->totalSpent * REBATE_AMT;
}

float Executive::GetRebate() const
{
    return rebate;
}
