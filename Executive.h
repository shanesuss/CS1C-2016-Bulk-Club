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

    void ChangeType(QString newType);

    void ChangeTotSpent(float newSpent);

    void UpdateRebate(float newRebate);
    
     QString GetName() const;

    double GetMemNum() const;

    QString GetNewType() const;

    Date GetDate() const;

    float GetTotSpent() const;
    
    float GetRebate() const;

private:
    float rebate;
};

#endif // EXECUTIVE_H
