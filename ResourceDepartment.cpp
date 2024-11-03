#include "ResourceDepartment.h"

/**
 * @brief Destructor to clean up Resources.
 */
ResourceDepartment::~ResourceDepartment()
{
    for (Resources *resource : resources)
    {
        delete resource; // Clean up each Resource
    }
    for (Utility *utility : utilities)
    {
        delete utility; // Clean up each Utility
    }
}

/**
 * @brief Add a Resource to the department.
 * 
 * @param resource Pointer to the Resource to be added.
 */
void ResourceDepartment::addResource(Resources *resource)
{
    resources.push_back(resource);
    std::cout << "ResourceDepartment: Added resource " << std::endl;
}

/**
 * @brief Check if a specific Resource has sufficient amount available.
 * 
 * @param resource Pointer to the Resource to check.
 * @param amount The amount to check for sufficiency.
 * @return true if sufficient resources are available, false otherwise.
 */
bool ResourceDepartment::hasSufficientResource(Resources *resource, float amount)
{
    // Uncomment and complete logic to check resource sufficiency
    // for (Resources* res : resources) {
    //     if (res == resource && res->getAvailableAmount() >= amount) {
    //         return true;
    //     }
    // }
    return false; // Placeholder return statement
}

/**
 * @brief Consume a specified amount of a Resource.
 * 
 * @param resource Pointer to the Resource to consume from.
 * @param amount The amount to consume.
 */
void ResourceDepartment::consumeResource(Resources *resource, float amount)
{
    for (Resources *res : resources)
    {
        // Uncomment and complete logic to consume resource
        // if (res == resource) {
        //     res->consume(amount);
        //     std::cout << "ResourceDepartment: Consumed " << amount << " units of " << res->getName() << std::endl;
        //     return;
        // }
    }
    std::cout << "ResourceDepartment: Resource not found!" << std::endl;
}

/**
 * @brief Release or add back a specified amount of a Resource.
 * 
 * @param resource Pointer to the Resource to release.
 * @param amount The amount to release.
 */
void ResourceDepartment::releaseResource(Resources *resource, float amount)
{
    for (Resources *res : resources)
    {
        // Uncomment and complete logic to release resource
        // if (res == resource) {
        //     res->release(amount);
        //     std::cout << "ResourceDepartment: Released " << amount << " units of " << res->getName() << std::endl;
        //     return;
        // }
    }
    std::cout << "ResourceDepartment: Resource not found!" << std::endl;
}

/**
 * @brief Add a utility to the department for management and tracking.
 * 
 * @param utility Pointer to the Utility to be added.
 */
void ResourceDepartment::addUtility(Utility *utility)
{
    utilities.push_back(utility);
    std::cout << "ResourceDepartment: Added utility " << std::endl;
}

/**
 * @brief Notify utilities in case of outages or issues with Resources.
 * 
 * @param message The message to send to utilities about the outage.
 */
void ResourceDepartment::notifyUtilityOutage(const std::string &message)
{
    for (Utility *utility : utilities)
    {
        // Uncomment and complete logic to notify utility of the outage
        // utility->notifyResourcesDivision(message);
    }
}

/**
 * @brief Update utilities based on Resource availability or scheduled checks.
 */
void ResourceDepartment::updateUtilities()
{
    // Placeholder for utility update logic
}

/**
 * @brief Check total levels of Resources and notify in case of shortages.
 */
void ResourceDepartment::checkResourceLevels()
{
    for (Resources *res : resources)
    {
        // Placeholder for resource level check logic
    }
}

/**
 * @brief Constructor with budget.
 * 
 * @param budget The initial budget for the ResourceDepartment.
 */
ResourceDepartment::ResourceDepartment(float budget)
{
    this->budget = budget;
}

/**
 * @brief Process a resource request from a utility.
 * 
 * @param utiName The name of the utility making the request.
 * @param amount The amount of resource requested.
 * @return true if the request was successfully processed, false otherwise.
 */
bool ResourceDepartment::processResourceRequest(std::string utiName, float amount)
{
    return true; // Placeholder return statement
}
