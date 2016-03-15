#include "Executive.h"

Executive::Executive()
{}

void Executive::SetTotalSpent(float newSpent)
{
    this->totalSpent = newSpent;
    UpdateRebate();
}

void Executive::UpdateRebate()
{
    rebate = this->totalSpent * REBATE_AMT;
}

float Executive::GetRebate() const
{
    return rebate;
}
