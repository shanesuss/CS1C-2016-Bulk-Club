#include "Executive.h"

Executive::Executive() :Regular()
{
    rebate = 0;
    memberType = "Executive";
}

Executive::Executive(QString newName,
                     double  newNum,
                     Date    newDate,
                     float   newSpent)
                     :Regular(newName,newNum,newDate,newSpent)
{
    UpdateRebate();
    memberType = "Executive";
}

Executive::~Executive() {}

void Executive::SetMember(QString newName,
                          double  newNum,
                          QString newType,
                          Date    newDate,
                          float   newSpent)
{
    Regular::SetMember(newName,newNum,newDate,newSpent);
    UpdateRebate();
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
