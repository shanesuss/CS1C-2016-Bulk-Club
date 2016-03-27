#include "MemberList.h"

MemberList::MemberList() {}

MemberList::~MemberList() {}

void MemberList::InitializeMemberList()
{
    QFile       shoppers(":/BulkClubMembers.txt");
    QTextStream infile(&shoppers);
    QString     memName;
    QString     memNum;
    QString     memType;
    QString     memExpDate;
    int         newMonth;
    int         newDay;
    int         newYear;
    int         memNumber;
    Date        currDate(newMonth,newDay,newYear);
    Member      newMem;
    Executive   newExec;
    bool        ok;

    //open the text file to read from
    shoppers.open(QIODevice::ReadOnly);

    //will keep reading until the end of the file is reached &
    //will read line by line and store info as a QString which
    //will then be used to convert to whatever data type is
    //needed
    while(!infile.atEnd())
    {
        memName = infile.readLine();

        memNum = infile.readLine();
        memNumber = memNum.toInt();

        memType = infile.readLine();

        memExpDate = infile.readLine();

        //splits the date into month, day and year
        QStringList dateStr = memExpDate.split("/");

        dateStr.at(0).toInt(&ok, 10);
        dateStr.at(1).toInt(&ok, 10);
        dateStr.at(2).toInt(&ok, 10);

        Date newDate(dateStr.at(0).toInt(&ok, 10),
                     dateStr.at(1).toInt(&ok, 10),
                     dateStr.at(2).toInt(&ok, 10));

        //set info for specific member
         if(memType == "Executive")
         {
             newExec.SetMember(memName,memNumber,newDate,0);

             memberList.push_back(newExec);
         }
         else if(memType == "Regular")
         {
             newMem.SetMember(memName,memNumber,newDate,0);

             memberList.push_back(newMem);
         }
    }

    shoppers.close();
}

void MemberList::AddMember(Member newMember)
{
    memberList.push_back(newMember);
}

bool MemberList::DeleteMember(int idNum)
{
    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetId() == idNum)
        {
            memberList.erase(memberList.begin() + i);
            return true;
        }
    }
    return false;
}

bool MemberList::DeleteMember(QString searchName)
{
    bool remove;

    remove = false;

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetName() == searchName)
        {
            memberList.erase(memberList.begin() + i);

            remove = true;
        }
    }

    return remove;
}

QString MemberList::GetExecutiveOnlyList() const
{
    QString tempInfo;

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Executive")
        {
            tempInfo += memberList[i].GetMemberInfo();
        }
    }
    return tempInfo;
}

QString MemberList::GetMemberOnlyList() const
{
    QString tempInfo;

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Member")
        {
            tempInfo = memberList[i].GetMemberInfo();
        }
    }

    return tempInfo;
}

Member MemberList::GetMember(int idNum) const
{
   for(unsigned int i = 0; i < memberList.size(); i++)
   {
       if(memberList[i].GetId() == idNum)
       {
           return memberList[i];
       }
   }
   throw -1;
}

QString MemberList::GetMemberList() const
{
    QString tempInfo;

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        tempInfo += memberList[i].GetMemberInfo();
    }
    return tempInfo;
}

int MemberList::SearchMember(int idNum) const
{
    for (unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetId() == idNum) { return i;}
    }
    return -1;
}

int MemberList::SearchMember(QString searchName) const
{
    int memberSrch;

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetName() == searchName) {return i;}
    }
    return -1;
}
