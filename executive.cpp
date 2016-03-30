#include "executive.h"

Executive::Executive(QString newName,
                     double  newNum,
                     QString newType,
                     Date    newDate,
                     float   newSpent,
                     float   newRebate)
                     :Regular(newName,newNum,newType,newDate,newSpent)
{
    rebate = newRebate;
}
