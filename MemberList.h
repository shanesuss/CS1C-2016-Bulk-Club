#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Executive.h"
#include <vector>
#include <QString>

class MemberList
{
public:
    MemberList();
    ~MemberList();

    //Should add member to bottom of list
    void AddMember(Member newMember);

    //Should delete member by ID, return true if successful, false if member not in list
    bool DeleteMember(int idNum);

    //Should return pos. of member in list, or -1 if not in list
    int SearchMember(int idNum) const;

    //should return copy of member in list.
    /* THIS NEEDS ERROR HANDLING. Code will throw -1 if Member with GetID() == idNum is not in memberList. */
    Member GetMember(int idNum) const;

    QString GetMemberList() const;

    QString GetMemberOnlyList() const;
    QString GetExecutiveOnlyList() const;

private:
    vector<Member> memberList;

};

#endif // MEMBERLIST_H
