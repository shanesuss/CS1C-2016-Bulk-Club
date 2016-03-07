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
