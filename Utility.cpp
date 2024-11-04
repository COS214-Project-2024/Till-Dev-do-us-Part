/**
 * @file Utility.cpp
 * @brief Implements the Utility class methods for managing utilities in the simulation.
 * @author rethabile
 */

#include "Utility.h"
#include <iostream>

/**
 * @brief Constructs a Utility with specified name, Resource Department, resource, and maximum workers.
 *        Initializes a Wellness business for the utility.
 * @param name Name of the utility
 * @param resDept Pointer to the Resource Department
 * @param resource Pointer to the resources used by the utility
 * @param maxWorkers Maximum number of workers for the utility
 */
Utility::Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int maxWorkers, WiseBucks* app)
    : name(name), resDept(resDept), resource(resource), MaxWorkers(maxWorkers)
{
    UtilityBus = new Wellness("Utility", MaxWorkers);
    UtilityBus->linkWiseBucks(app);
    std::cout << "Buying Property for Utilities" << std::endl;
    UtilityBus->buyProperty("Plant");
    std::cout << "Hiring Employees for Utilities" << std::endl;

    for (int i = 0; i <= MaxWorkers; i++)
    {
        UtilityBus->hireEmployee();
    }
    ActiveWorkers = UtilityBus->activelyWorking();
}

/**
 * @brief Default destructor for Utility.
 */
Utility::~Utility() = default;

/**
 * @brief Sends a notification message to the Resource Department.
 * @param message The message to be sent to the Resource Department
 */
void Utility::notifyResourceDept(const std::string &message)
{
    std::cout << "Notifying Resource Department: " << message << std::endl;
}

/**
 * @brief Gets the name of the utility.
 * @return The name of the utility
 */
std::string Utility::getName() const
{
    return name;
}

/**
 * @brief Gets the resource pointer used by the utility.
 * @return Pointer to the resources used by the utility
 */
Resources *Utility::getResource() const
{
    return resource;
}

/**
 * @brief Gets the number of currently active workers.
 * @return The number of active workers
 */
int Utility::getActiveWorkers() const
{
    return ActiveWorkers;
}

/**
 * @brief Gets the maximum number of workers allowed for the utility.
 * @return The maximum number of workers
 */
int Utility::getMaxWorkers() const
{
    return MaxWorkers;
}
