#include "MemberList.h"

MemberList::MemberList()
{
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

bool MemberList::DeleteMember(string searchName)
{
    forf(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetName() == searchName)
        {
            memberList.erase(memberList.begin() + i)
            return true;
        }
    }
    return false;
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

int MemberList::SearchMember(string searchName) const
{
    for(unsigned int i = 0; i < memberList.size(); i++)
    {
        if(memberList[i].GetName() == searchName) {return i;}
    }
    return -1;
}
