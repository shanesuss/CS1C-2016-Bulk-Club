#ifndef MEMBERLIST_H
#define MEMBERLIST_H

/*Example cases:
 *
 * while(inFile){
 *
 * output >> tempName;
 * output >> tempId;
 * output >> tempMemberType;
 * (etc)
 *
 * if(tempMemberType == "Executive")
 * {
 *   Member tempMember = Member(tempName, tempId, etc);
 *   myMemberList.AddMember(tempMember);
 * }
 *  else
 * {
 *  Executive tempExecutive = Executive(tempName, tempId, etc);
 *  myMemberList.AddMember(tempMember);
 * }
 * }
 * #######
 * cout << "Please enter the ID number of your employee:"
 * cin >> input;
 * try{ myMemberList.GetMember(input);}
 * catch (int e) { cout << "Error: member not in list.";}
 *
 */

#include "Executive.h"
#include "Member.h"
#include <QApplication>
#include <iostream>
#include <iomanip>
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <algorithm>

using namespace std;

class MemberList
{
public:
    MemberList();
    ~MemberList();

    void InitializeMemberList();

    //Should add member to bottom of list
    void AddMember(Member newMember);

    //Should delete member by ID, return true if successful, false if member not in list
    bool DeleteMember(int idNum);
    
    bool DeleteMember(QString searchName);

    //Should return pos. of member in list, or -1 if not in list
    int SearchMember(int idNum) const;

    int SearchMember(QString searchName) const;
    
    //should return copy of member in list.
    /* THIS NEEDS ERROR HANDLING. Code will throw -1 if Member with GetID() == idNum is not in memberList. */
    Member GetMember(int idNum) const;

    QString GetMemberList() const;

    QString GetMemberOnlyList() const;

    QString GetExecutiveOnlyList() const;

    void GetVector(vector<Member> &list) const;


private:
    vector<Member> memberList;

};

#endif // MEMBERLIST_H
