#ifndef MEMBER_H
#define MEMBER_H

/***********************************************
 * Name: Kayvon Haghighi
 * Class: CS 1C
 * Project: 1
************************************************/

#include <QString>
#include <iomanip>
#include <ostream>
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Member
{
public:

/* Constructors/Destructors */
    /* Default Constructor - Initialize with default values of 0 */
    Member();

    /* Non-Default Constructor - Initialize with referenced values */
    Member(QString newName, int newID, Date newDate, double newSpent);

    /* Destructor - delete instance of object */
    ~Member();


/* Accessors */
    /* GetName - return name */
    QString GetName() const;

    /* GetId - return idNum */
    int GetId() const;

    /* GetMemberType - return memberType */
    QString GetMemberType() const;

    /* GetExpirationDate - return instance of expDate */
    Date GetExpirationDate() const;

    /* GetTotalSpent - return totalSpent */
    double GetTotalSpent() const;

    /* GetMemberInfo - return formatted list of user info */
    QString GetMemberInfo() const;

/* Modifiers */
    void SetMember(QString newName,
                   int  newNum,
                   Date    newDate,
                   double newSpent);

    /* SetName - change name */
    void SetName(QString newName);

    /* SetID - change idNum */
    void SetID(int newId);

    /* SetMemberType - change memberType */
    void SetMemberType(QString newMemberType);

    /* SetExpirationDate - change expDate */
    void SetExpirationDate(Date newExpDate);

    /* SetTotalSpent - change totalSpent */
    void SetTotalSpent(double newTotalSpent);

    /* AddPurchase - adds newPurchase to totalSpent (i.e. a new transaction) */
    void AddPurchase(double newPurchase);

    bool operator<(Member compareto) const;
    bool operator>(Member compareto) const;
private:
    QString name;
    int    idNum;
    QString memberType;
    Date   expDate;
    double  totalSpent;
};


#endif // MEMBER_H
