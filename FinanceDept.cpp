#include "FinanceDept.h"

void FinanceDept::newBusiness(Business* business)
{
    businesses.push_back(business); 
}

void FinanceDept::removeBusiness(Business* business)
{
    auto it = find(businesses.begin(), businesses.end(), business);
    if (it != businesses.end())
    {
        businesses.erase(it);
    }
}

vector<Business*> FinanceDept::getBusinesses()
{
    return businesses; 
}