#include "regular.h"

Regular::Regular()
{
    name      = "";
    memberNum = 0;
    type      = "";
    expDate.SetDate(0,0,1900);
    totSpent  = 0;
}

Regular::Regular(QString newName,
                 double  newNum,
                 QString newType,
                 Date    newDate,
                 float   newSpent)
{
    name      = newName;
    memberNum = newNum;
    type      = newType;
    expDate   = newDate;
    totSpent  = newSpent;
}

Regular::~Regular() {}

void Regular::SetMember(QString newName,
                        double  newNum,
                        QString newType,
                        Date    newDate,
                        float   newSpent)
{
    name      = newName;
    memberNum = newNum;
    type      = newType;
    expDate   = newDate;
    totSpent  = newSpent;
}

void Regular::ChangeName(QString newName)
{
    name = newName;
}

void Regular::ChangeMemNum(double newMemNum)
{
    memberNum = newMemNum;
}

void Regular::ChangeType(QString newType)
{
    type = newType;
}

void Regular::ChangeExpDate(Date newDate)
{
    expDate = newDate;
}

void Regular::ChangeTotSpent(float newSpent)
{
    totSpent = newSpent;
}
