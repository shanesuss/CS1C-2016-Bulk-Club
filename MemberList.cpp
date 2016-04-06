#include "MemberList.h"
#include <QDebug>

MemberList::MemberList() {}

MemberList::~MemberList() {}

void MemberList::InitializeMemberList()
{
    QFile       shoppers(":BulkClubMembers.txt");
    QTextStream infile(&shoppers);
    QString     memName;
    QString     memNum;
    QString     memType;
    QString     memExpDate;
    int         newMonth = 0;
    int         newDay = 0;
    int         newYear = 0;
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
             qDebug() << newExec.GetMemberInfo();

             memberList.push_back(newExec);
         }
         else if(memType == "Regular")
         {
             newMem.SetMember(memName,memNumber,newDate,0);
                qDebug () << newMem.GetMemberInfo();
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
    string newLine = "\n";

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Executive")
        {
            tempInfo += memberList[i].GetMemberInfo() + QString::fromStdString(newLine);
        }
    }
    return tempInfo;
}

QString MemberList::GetMemberOnlyList() const
{
    QString tempInfo;
    string  newLine = "\n";

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Regular")
        {
            tempInfo += memberList[i].GetMemberInfo() + QString::fromStdString(newLine);
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

void MemberList::GetVector(vector<Member> &list) const
{
    list = memberList;
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

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetName() == searchName) {return i;}
    }
    return -1;
}

void MemberList::FindMemberAndType(int     id,
                                   QString &theName,
                                   QString &theType)
{
        int index = 0;
        bool found = false;

        while(!found && index < memberList.size())
        {
            if(id == memberList[index].GetId())
            {
                theName = memberList[index].GetName();

                theType = memberList[index].GetMemberType();

                found = true;
            }
            else
            {
                index++;
            }
        }
}

QString MemberList::GetExpirationDates(int month) const
{
    ostringstream out;
    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetExpirationDate().GetMonth() == month)
        {
            out << left << "| " << setw(32) << memberList[i].GetName().toStdString() << " | " << memberList[i].GetId() << " | ";

            if(memberList[i].GetMemberType() == "Executive")
            {
                out << "$125 |\n";
            }
            else
            {
                out << setw(4) << "$45" << " |\n";
            }
        }
    }
return QString::fromStdString(out.str());
}

QString MemberList::GetExecutiveDowngrades()
{
    QString output;
    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Executive")
        {
            if(!memberList[i].ShouldChangeMember())
            {
                output += memberList[i].GetMemberInfo();
            }
        }
    }
    return output;
}

QString MemberList::GetMemberUpgrades()
{
    QString output;
    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Regular")
        {
            if(memberList[i].ShouldChangeMember())
            {
                output += memberList[i].GetMemberInfo();
            }
        }
    }
    return output;
}

QString MemberList::GetRebates()
{
    ostringstream output;

    SelectionSort(memberList);

    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetMemberType() == "Executive")
        {
            output << left << "| "<< setw(30) << memberList[i].GetName().toStdString() << " | " << memberList[i].GetId() << " | "
                   << setw(7) << memberList[i].GetTotalSpent() * 0.035 << " |\n";
        }
    }
qDebug() << "FAIL 2\n";

qDebug() << "FAIL 3\n";
    return QString::fromStdString(output.str());
}

void MemberList::UpdateSalesList()
{
    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        memberList[i].UpdateSales();
    }
}

//void MemberList::AddPurchase(int index, SalesInventory inv)
//{
//    for(unsigned int i = 0; i < memberList.size(); i++)
//    {
//        if(memberList[i].GetId() == index)
//        {
//            memberList[i].AddPurchase(inv);
//        }
//    }
//}

unsigned int MemberList::GetSize() const
{
    return memberList.size();
}

Member MemberList::GetIndex(int i)
{
    return memberList[i];
}

void MemberList::ReturnSortedList()
{
  sort(memberList.begin(), memberList.end());
}


void MemberList::SelectionSort(vector<Member> &list)
{
    int pos_min;
    Member temp;
    int n = this->GetSize();
qDebug() << "FAIL 2.1\n";
    for(int i = 0; i < n-1; i++)
    {
qDebug() << "FAIL 2.2\n";
        pos_min = i;
        for(int j = i+1; j<n; j++)
        {
            if(list[j].GetId() < list[pos_min].GetId())
            {
                pos_min = j;
            }
        }
        if(pos_min != i)
        {
            temp = list[i];
            list[i] = list[pos_min];
            list[pos_min] = temp;
        }
    }
qDebug() << "FAIL 2.5\n";
}
