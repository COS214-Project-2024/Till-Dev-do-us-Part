/**
 * @file ResourceDepartment.cpp
 * @brief Implements the ResourceDepartment class methods for managing resources and utilities.
 */

#include "ResourceDepartment.h"

/**
 * @brief Destructor to clean up Resources and Utilities.
 */
ResourceDepartment::~ResourceDepartment()
{
    for (Resources *resource : resources)
    {
        delete resource; // Clean up each resource
    }
    for (Utility *utility : utilities)
    {
        delete utility; // Clean up each utility
    }
}

/**
 * @brief Adds a resource to the department.
 * @param resource Pointer to the resource to be added
 */
void ResourceDepartment::addResource(Resources *resource)
{
    resources.push_back(resource);
    std::cout << "ResourceDepartment: Added resource." << std::endl;
}

/**
 * @brief Checks if a specific resource has a sufficient amount available.
 * @param resource Pointer to the resource to check
 * @param amount Amount to check against
 * @return True if sufficient resources are available, false otherwise
 */
bool ResourceDepartment::hasSufficientResource(Resources *resource, float amount)
{
    // for (Resources *res : resources)
    // {
    //     if (res == resource && res->getAvailableAmount() >= amount)
    //     {
    //         return true; // Sufficient resources found
    //     }
    // }
    return false; // Insufficient resources
}

/**
 * @brief Consumes a specified amount of a resource.
 * @param resource Pointer to the resource to consume
 * @param amount Amount to consume
 */
void ResourceDepartment::consumeResource(Resources *resource, float amount)
{
    for (Resources *res : resources)
    {
        if (res == resource)
        {
            res->consume(amount);
            std::cout << "ResourceDepartment: Consumed " << amount << " units of " << res->getName() << std::endl;
            return;
        }
    }
    std::cout << "ResourceDepartment: Resource not found!" << std::endl;
}

/**
 * @brief Releases or adds back a specified amount of a resource.
 * @param resource Pointer to the resource to release
 * @param amount Amount to release
 */
void ResourceDepartment::releaseResource(Resources *resource, float amount)
{
    // for (Resources *res : resources)
    // {
    //     if (res == resource)
    //     {
    //         res->release(amount);
    //         std::cout << "ResourceDepartment: Released " << amount << " units of " << res->getName() << std::endl;
    //         return;
    //     }
    // }
    std::cout << "ResourceDepartment: Resource not found!" << std::endl;
}

/**
 * @brief Adds a utility to the department for management and tracking.
 * @param utility Pointer to the utility to be added
 */
void ResourceDepartment::addUtility(Utility *utility)
{
    utilities.push_back(utility);
    std::cout << "ResourceDepartment: Added utility." << std::endl;
    std::cout << "Budget: " << budget - 2000 << std::endl;
}

/**
 * @brief Notifies utilities in case of outages or issues with resources.
 * @param message Message to be sent to utilities
 */
void ResourceDepartment::notifyUtilityOutage(const std::string &message)
{
    for (Utility *utility : utilities)
    {
        // utility->notifyResourcesDivision(message); // Notify each utility
    }
}

/**
 * @brief Updates utilities based on resource availability or scheduled checks.
 */
void ResourceDepartment::updateUtilities()
{
    // Implementation for updating utilities can be added here
}

/**
 * @brief Checks total levels of resources and notifies in case of shortages.
 */
void ResourceDepartment::checkResourceLevels()
{
    for (Resources *res : resources)
    {
        // Implement logic to check resource levels
    }
}

/**
 * @brief Constructor with budget.
 * @param budget Initial budget for the resource department
 */
ResourceDepartment::ResourceDepartment(float budget) : budget(budget) {}

/**
 * @brief Processes resource requests from utilities.
 * @param utiName Name of the utility requesting resources
 * @param amount Amount of resources requested
 * @return True if the request is processed successfully, false otherwise
 */
bool ResourceDepartment::processResourceRequest(string utiName, float amount)
{
    for (auto utility : utilities)
    {
        // Check if utility is a ProductionUtility and if it provides the requested product
        if (ProductionUtility *prodUtility = dynamic_cast<ProductionUtility *>(utility))
        {
            if (prodUtility->getProduct() == utiName)
            {
                if (prodUtility->getCurrentProduction() >= amount)
                {
                    prodUtility->setCurrentProduction(prodUtility->getCurrentProduction() - amount);
                    std::cout << "Resource request granted." << std::endl;
                    prodUtility->incrementRequestCounter();
                    return true;
                }
                else
                {
                    prodUtility->incrementRequestCounter(); 
                    // prodUtility->startProduction(); // Restart production if insufficient
                    std::cout << utiName << " production restarted due to insufficient resources." << std::endl;
                }
            }
        }
    }
    std::cout << "Resource request denied: insufficient resources." << std::endl;
    return false; // Request could not be fulfilled
}
