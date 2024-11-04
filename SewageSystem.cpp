/**
 * @file SewageSystem.cpp
 * @brief Implements the SewageSystem class methods for managing sewage services.
 */

#include "SewageSystem.h"
#include <iostream>

/**
 * @brief Constructs a SewageSystem with specified parameters.
 * @param name Name of the sewage system
 * @param department Pointer to the Resource Department
 */
SewageSystem::SewageSystem(std::string name, ResourceDepartment *department)
    : ServiceUtility(name, department)
{
    std::cout << "Constructor of SewageSystem called" << std::endl;
    setServState(new OperationalServiceState); // Set the initial service state to operational
}

/**
 * @brief Default destructor for SewageSystem.
 */
SewageSystem::~SewageSystem() {}

/**
 * @brief Starts the sewage management service.
 */
void SewageSystem::startService()
{
    if (servState)
    {
        servState->handleService(this); // Delegate service handling to the current state
    }
    else
    {
        std::cout << getName() << " has no service state set.\n"; // Handle case where service state is not set
    }
    getStatus(); // Display current status
}

/**
 * @brief Creates a new Development Department (not implemented).
 * @return Pointer to the DevelopmentDept
 */
DevelopmentDept* SewageSystem::createDevelopmentDept()
{
    // Implementation to be done in the future
    return nullptr; // Placeholder return
}
