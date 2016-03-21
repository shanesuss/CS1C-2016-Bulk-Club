#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Member.h"

const float REBATE_AMT = .035;

class Executive: public Member{
public:
    Executive();
    Executive(QString newName,
              int  newNum,
              Date    newDate,
              double   newSpent);

    ~Executive();

    //void ChangeType(QString newType);

    void SetMember(QString newName,
                   int newNum,
                   Date    newDate,
                   double   newSpent);

    void SetTotalSpent(float newSpent);
                   
    QString GetName() const;

    int GetId() const;

    double GetMemNum() const;

    QString GetNewType() const;

    Date GetDate() const;

    float GetTotalSpent() const;

    float GetRebate() const;

private:
    float rebate;

    void UpdateRebate();
};

#endif // EXECUTIVE_H
