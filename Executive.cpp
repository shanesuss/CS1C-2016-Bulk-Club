#include "Executive.h"

Executive::Executive() :Member()
{
    rebate = 0;
    SetMemberType("Executive");
}

Executive::Executive(QString newName,
                     int  newNum,
                     Date    newDate,
                     double   newSpent)
                     :Member(newName,newNum,newDate,newSpent)
{
    UpdateRebate();
    SetMemberType("Executive");
}

Executive::~Executive() {}

void Executive::SetMember(QString newName,
                          int  newNum,
                          Date    newDate,
                          double   newSpent)
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

int Executive::GetId() const
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
