/**
 * @file Utility.cpp
 * @brief Implements the Utility class for managing utilities within the simulation.
 * 
 * Contains definitions for the Utility class's functions to handle initialization,
 * resource notifications, and status updates.
 * 
 * @see Utility.h for class details.
 */

#include "Utility.h"
#include <iostream>

/**
 * @brief Constructs a Utility object with specified parameters.
 * 
 * Initializes the utility with a name, a pointer to the resource department, a pointer
 * to the resources it will use, and the maximum number of workers. The constructor
 * also creates a Wellness business to manage worker hiring and purchasing properties.
 * 
 * @param name The name of the utility.
 * @param resDept A pointer to the associated Resource Department.
 * @param resource A pointer to the resources managed by this utility.
 * @param maxWorkers The maximum number of workers that can be hired for the utility.
 */
Utility::Utility(const std::string &name, ResourceDepartment *resDept, Resources *resource, int maxWorkers)
    : name(name), resDept(resDept), resource(resource), MaxWorkers(maxWorkers)
{
    std::cout << "segfault" << std::endl;
    UtilityBus = new Wellness("Utility", MaxWorkers);
    std::cout << "Buying Property for Utilities" << std::endl;
    UtilityBus->buyProperty("Plant");
    std::cout << "Hiring Employees for Utilities" << std::endl;
    for (int i = 0; i <= MaxWorkers; i++)
    {
        UtilityBus->hireEmployee();
    }
}

/**
 * @brief Destructor for the Utility class.
 * 
 * Cleans up any resources used by the Utility object.
 */
Utility::~Utility() = default;

/**
 * @brief Notifies the Resource Department with a specific message.
 * 
 * Outputs a message to the console to simulate notifying the Resource Department
 * about utility-specific information or requests.
 * 
 * @param message The message to send to the Resource Department.
 */
void Utility::notifyResourceDept(const std::string &message)
{
    std::cout << "Notifying Resource Department: " << message << std::endl;
}

/**
 * @brief Gets the name of the utility.
 * 
 * @return The name of the utility as a string.
 */
std::string Utility::getName() const
{
    return name;
}

/**
 * @brief Gets the resources managed by the utility.
 * 
 * @return A pointer to the Resources object used by this utility.
 */
Resources *Utility::getResource() const
{
    return resource;
}

/**
 * @brief Retrieves and displays the current status of the utility.
 * 
 * Outputs utility status information, such as resources and worker count, to the console.
 */
void Utility::getStatus() const
{
    std::cout << "---- Utility Status ----" << std::endl;
}

/**
 * @brief Gets the current number of active workers in the utility.
 * 
 * @return The number of active workers.
 */
int Utility::getActiveWorkers() const
{
    return ActiveWorkers;
}

/**
 * @brief Gets the maximum number of workers allowed in the utility.
 * 
 * @return The maximum number of workers.
 */
int Utility::getMaxWorkers() const
{
    return MaxWorkers;
}
