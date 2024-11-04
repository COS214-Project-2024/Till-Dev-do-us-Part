/**
 * @file WasteManagement.cpp
 * @brief Implements the WasteManagement class methods for managing waste services.
 */

#include "WasteManagement.h"
#include <iostream>

/**
 * @brief Constructs a WasteManagement utility with specified parameters.
 * @param name Name of the waste management utility
 * @param department Pointer to the Resource Department
 */
WasteManagement::WasteManagement(std::string name, ResourceDepartment *department)
    : ServiceUtility(name, department)
{
    setServState(new OperationalServiceState); // Set the initial service state to operational
}

/**
 * @brief Default destructor for WasteManagement.
 */
WasteManagement::~WasteManagement()
{
    delete servState; // Clean up the service state
}

/**
 * @brief Starts the waste management service.
 */
void WasteManagement::startService()
{
    std::cout << "\n--- Starting Service Cycle ---" << std::endl;

    if (servState)
    {
        servState->handleService(this); // Delegate service handling to the current state
    }
    else
    {
        std::cout << getName() << " has no service state set.\n"; // Handle case where service state is not set
    }

    std::cout << "--- End of Service ---\n" << std::endl;
    getStatus(); // Display current status
}

/**
 * @brief Creates a new Development Department (not implemented).
 * @return Pointer to the DevelopmentDept
 */
DevelopmentDept* WasteManagement::createDevelopmentDept() 
{
    // Implementation to be done in the future
    return nullptr; // Placeholder return
}

// Uncomment and implement in the future if building iteration is required
// void WasteManagement::iterateBuildings(bool limitedProcessing, int maxBuildings)
// {
//     std::cout << "Iterating Buildings" << std::endl;
//     iterator.reset();
//     int processedCount = 0;
//     while (iterator.hasNext() && (limitedProcessing ? processedCount < maxBuildings : true))
//     {
//         Building *building = iterator.next();
//         // Simulate partial waste collection or checks
//         processedCount++;
//     }
//     std::cout << "Completed waste collection on " << processedCount << " buildings." << std::endl;
// }
