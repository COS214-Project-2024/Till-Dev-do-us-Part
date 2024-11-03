#include "FinanceDept.h"

FinanceDept::FinanceDept(float budget)
{
    this->budget = budget/2; 
    crs = new CRS(budget/2); 
}

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

CRS* FinanceDept::getCRS()
{
    return crs; 
}

FinanceDept::~FinanceDept()
{
    delete crs; 
    crs = nullptr; 
}