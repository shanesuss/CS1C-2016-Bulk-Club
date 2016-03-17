#include "Executive.h"

Executive::Executive() :Member()
{
    rebate = 0;
    GetNewType() = "Executive";
}

Executive::Executive(QString newName,
                     double  newNum,
                     Date    newDate,
                     float   newSpent)
                     :Member(newName,newNum,newDate,newSpent)
{
    UpdateRebate();
    GetNewType() = "Executive";
}

Executive::~Executive() {}

void Executive::SetMember(QString newName,
                          double  newNum,
                          Date    newDate,
                          float   newSpent)
{
    Member::SetMember(newName,newNum,newDate,newSpent);
    UpdateRebate();
}

void Executive::SetTotalSpent(float newSpent)
{
    Member::SetTotalSpent(newSpent);
    UpdateRebate();
}

void Executive::UpdateRebate()
{
    rebate = this->GetTotalSpent() * REBATE_AMT;
}

QString Executive::GetName() const
{
    return Member::GetName();
}

double Executive::GetId() const
{
    return Member::GetId();
}

QString Executive::GetNewType() const
{
    return Member::GetMemberType();
}

float Executive::GetTotalSpent() const
{
    return Member::GetTotalSpent();
}

float Executive::GetRebate() const
{
    return rebate;
}
