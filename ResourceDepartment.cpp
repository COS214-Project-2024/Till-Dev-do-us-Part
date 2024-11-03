#include "ResourceDepartment.h"

// Destructor to clean up Resourcess
ResourceDepartment::~ResourceDepartment()
{
    for (Resources *Resources : resources)
    {
        delete Resources;
    }
    for (Utility *utility : utilities)
    {
        delete utility;
    }
}

// Add a Resources to the department
void ResourceDepartment::addResource(Resources *resource)
{
    resources.push_back(resource);
    std::cout << "ResourcesDepartment: Added Resources " << std::endl;
}

// Check if a specific Resources has sufficient amount available
bool ResourceDepartment::hasSufficientResource(Resources *resource, float amount)
{
    // for (Resources* res : resources) {
    //     if (res == resources && res->getAvailableAmount() >= amount) {
    //         return true;
    //     }
    // }
    return false;
}

// Consume a specified amount of a Resources
void ResourceDepartment::consumeResource(Resources *resource, float amount)
{
    for (Resources *res : resources)
    {
        // if (res == resource) {
        //     res->consume(amount);
        //     std::cout << "ResourcesDepartment: Consumed " << amount << " units of " << res->getName() << std::endl;
        //     return;
        // }
    }
    std::cout << "ResourcesDepartment: Resources not found!" << std::endl;
}

// Release or add back a specified amount of a Resources
void ResourceDepartment::releaseResource(Resources *resource, float amount)
{
    for (Resources *res : resources)
    {
        // if (res == resources) {
        //     res->release(amount);
        //     std::cout << "ResourcesDepartment: Released " << amount << " units of " << res->getName() << std::endl;
        //     return;
        // }
    }
    std::cout << "ResourcesDepartment: Resources not found!" << std::endl;
}

// Add a utility to the department for management and tracking
void ResourceDepartment::addUtility(Utility *utility)
{
    utilities.push_back(utility);
    std::cout << "ResourcesDepartment: Added utility " << std::endl;
}

// Notify utilities in case of outages or issues with Resourcess
void ResourceDepartment::notifyUtilityOutage(const std::string &message)
{
    for (Utility *utility : utilities)
    {
        // utility->notifyResourcesDivision(message);
    }
}

// Update utilities based on Resources availability or scheduled checks
void ResourceDepartment::updateUtilities()
{
}

// Check total levels of Resourcess and notify in case of shortages
void ResourceDepartment::checkResourceLevels()
{
    for (Resources *res : resources)
    {
    }
}

ResourceDepartment::ResourceDepartment(float budget)
{
    this->budget = budget;
}
// void ResourceDepartment:: addUtility()
// {
//     utilities.push_back(utility);
// }
bool ResourceDepartment::processResourceRequest(string utiName, float amount)
{
    return true;
}