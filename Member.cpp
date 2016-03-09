#include "Member.h"

Member::~Member() {}

Member::Member()
{
    name = "";
    idNum = 0;
    memberType = "";
    expDate.SetDate(0,0,0);
    totalSpent = 0.0;
}

Member::Member(string newName, int newID, string newType, Date newDate, double newTotal)
{
    name = newName;
    idNum = newID;
    memberType = newType;
    expDate = newDate;
    totalSpent = newTotal;
}

void Member::AddPurchase(double newPurchase)
{
    totalSpent += newPurchase;
}

Date Member::GetExpirationDate() const
{
    return expDate;
}


int Member::GetId() const
{
    return idNum;
}

string Member::GetMemberInfo() const
{
    // to be written later
    return "";
}

string Member::GetMemberType() const
{
    return memberType;
}

string Member::GetName() const
{
    return name;
}

double Member::GetTotalSpent() const
{
    return totalSpent;
}

void Member::SetExpirationDate(Date newExpDate)
{
    expDate = newExpDate;
}

void Member::SetID(int newId)
{
    idNum = newId;
}

void Member::SetMemberType(string newMemberType)
{
    memberType = newMemberType;
}

void Member::SetName(int newName)
{
    name = newName;
}

void Member::SetTotalSpent(double newTotalSpent)
{
    totalSpent = newTotalSpent;
}

