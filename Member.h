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
	Member(string newName, int newID, string newType, Date newDate, double newTotal);
	
	/* Destructor - delete instance of object */
	~Member();
	

/* Accessors */
	/* GetName - return name */
	string GetName() const;
	
	/* GetId - return idNum */
	int GetId() const;

	/* GetMemberType - return memberType */
	string GetMemberType() const;

	/* GetExpirationDate - return instance of expDate */
	Date GetExpirationDate() const;

	/* GetTotalSpent - return totalSpent */
	double GetTotalSpent() const;
	
	/* GetMemberInfo - return formatted list of user info */
	string GetMemberInfo() const;

/* Modifiers */
	/* SetName - change name */
	void SetName(int newName);

	/* SetID - change idNum */ 
	void SetID(int newId);

	/* SetMemberType - change memberType */
	void SetMemberType(string newMemberType);
	
	/* SetExpirationDate - change expDate */
	void SetExpirationDate(Date newExpDate);

	/* SetTotalSpent - change totalSpent */
	void SetTotalSpent(double newTotalSpent);

	/* AddPurchase - adds newPurchase to totalSpent (i.e. a new transaction) */
	void AddPurchase(double newPurchase);
private:
	qstring name;
	int    idNum;
	qstring memberType;
	Date   expDate;
	double totalSpent;
};
