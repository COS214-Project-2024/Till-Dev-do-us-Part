#include "FinanceDept.h"

/**
 * @brief Constructs a FinanceDept instance with a specified budget.
 * 
 * The budget is divided equally between the Finance Department's
 * operations and the CRS.
 * 
 * @param budget The total budget allocated for the Finance Department.
 */
FinanceDept::FinanceDept(float budget)
{
    this->budget = budget/2; 
    crs = new CRS(budget/2); 
}

/**
 * @brief Registers a new business with the Finance Department.
 * 
 * The provided business is added to the list of managed businesses.
 * 
 * @param business A pointer to the Business instance to be added.
 */
void FinanceDept::newBusiness(Business* business)
{
    businesses.push_back(business); 
}

/**
 * @brief Removes a business from the Finance Department.
 * 
 * If the specified business is found, it is removed from the list of
 * managed businesses.
 * 
 * @param business A pointer to the Business instance to be removed.
 */
void FinanceDept::removeBusiness(Business* business)
{
    auto it = find(businesses.begin(), businesses.end(), business);
    if (it != businesses.end())
    {
        businesses.erase(it);
    }
}

/**
 * @brief Retrieves the list of registered businesses.
 * 
 * @return A vector containing pointers to all managed Business instances.
 */
vector<Business*> FinanceDept::getBusinesses()
{
    return businesses; 
}

/**
 * @brief Retrieves the City Revenue Service instance.
 * 
 * @return A pointer to the CRS managed by the Finance Department.
 */
CRS* FinanceDept::getCRS()
{
    return crs; 
}

/**
 * @brief Destroys the FinanceDept instance and releases resources.
 * 
 * This destructor deallocates the CRS instance to prevent memory leaks.
 */
FinanceDept::~FinanceDept()
{
    delete crs; 
    crs = nullptr; 
}