/***********************************************
 * Name: Kayvon Haghighi
 * Class: CS 1C
 * Project: 1
************************************************/

#include <QString>
#include <iomanip>
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
    Member(QString newName, int newID, QString newType, Date newDate, double newTotal);

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
    /* SetName - change name */
    void SetName(int newName);

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
private:
    QString name;
    int    idNum;
    QString memberType;
    Date   expDate;
    double totalSpent;
};
