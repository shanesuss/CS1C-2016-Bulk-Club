#include "Member.h"
#include <ostream>
Member::~Member() {}

Member::Member()
{
    name = "";
    idNum = 0;
    memberType = "Regular";
    expDate.SetDate(0,0,0);
    totalSpent = 0.0;
}

Member::Member(QString newName, int newID, Date newDate, double newTotal)
{
    name = newName;
    idNum = newID;
    memberType = "Regular";
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


bool Member::operator>(Member compareto) const
{
    if(idNum > compareto.idNum) { return true; }
    else { return false; }
}

bool Member::operator<(Member compareto) const
{
    if(idNum < compareto.idNum) { return true; }
    else { return false; }
}

int Member::GetId() const
{
    return idNum;
}

QString Member::GetMemberInfo() const
{

    ostringstream output;
    output  << fixed << left << "| " << setw(25) << name.toStdString()
                << " | "  << setw(5) << idNum << " | "
                << setw(12) << expDate.DisplayDate() << " | "
                <<  "$" << setprecision(2) << fixed << setw(8) << totalSpent << " |\n";
    return QString::fromStdString(output.str());
}

QString Member::GetMemberType() const
{
    return memberType;
}

QString Member::GetName() const
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

void Member::SetMemberType(QString newMemberType)
{
    memberType = newMemberType;
}

void Member::SetName(QString newName)
{
    name = newName;
}

void Member::SetTotalSpent(double newTotalSpent)
{
    totalSpent = newTotalSpent;
}

void Member::SetMember(QString newName, int newNum, Date newDate, double newSpent)
{
    name = newName;
    idNum = newNum;
    expDate = newDate;
    totalSpent = newSpent;
}

void Member::AddPurchase(SalesInventory newPurchase)
{
    purchaseList.AddItem(newPurchase);
}

SalesList Member::GetSalesList() const
{
    return purchaseList;
}

bool Member::ShouldChangeMember()
{
    return (totalSpent * 0.035 > 80) ? true : false;
}
