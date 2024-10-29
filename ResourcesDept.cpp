////hold  utilities?
///make it map? 
#include "ResourcesDept.h"

ResourcesDept:: ResourcesDept(float budget)
{
    this.budget=budget;
}
void ResourcesDept:: adddUtility()
{
    utilities.push_back(utility);
}
void ResourcesDept:: processResourceRequest(float amount)
{
    budget-=amount
    if(budget<0)
    {
        budget=0;
    }
}