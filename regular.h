#ifndef REGULAR_H
#define REGULAR_H

#include <iostream>
#include <QString>
#include "date.h"

using namespace std;

class Regular
{
public:
    Regular();
    Regular(QString newName,
            double  newNum,
            QString newType,
            Date    newDate,
            float   newSpent);
    ~Regular();
    void SetMember(QString newName,
                   double  newNum,
                   QString newType,
                   Date    newDate,
                   float   newSpent);

    void ChangeName(QString newName);

    void ChangeMemNum(double newMemNum);

    void ChangeType(QString newType);

    void ChangeExpDate(Date newDate);

    void ChangeTotSpent(float newSpent);

private:
    QString name;
    double  memberNum;
    QString type;
    Date    expDate;
    float   totSpent;
};

#endif // REGULAR_H
