#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Member.h"
#include "Date.h"

const float REBATE_AMT = .035;

class Executive: public Member{
public:
    Executive();
    Executive(QString newName,
              double  newNum,
              QString newType,
              Date    newDate,
              float   newSpent,
              float   newRebate);

    ~Executive();

    //void ChangeType(QString newType);

    void SetTotalSpent(float newSpent);

    void SetMember(QString newName,
                   double  newNum,
                   QString newType,
                   Date    newDate,
                   float   newSpent,
                   float   newRebate);
                   
    // QString GetName() const;

    //double GetMemNum() const;

    //QString GetNewType() const;

    //Date GetDate() const;

    
    float GetRebate() const;

private:
    float rebate;

    void UpdateRebate();
};

#endif // EXECUTIVE_H
