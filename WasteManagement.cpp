#include "WasteManagement.h"

#include <iostream>

WasteManagement::WasteManagement(std::string name, ResourceDepartment *department)
    : ServiceUtility(name, department)

{

    std::cout << "Constructor of WasteManagement called" << std::endl;
    setServState(new OperationalServiceState);
}

WasteManagement::~WasteManagement()
{
    delete servState;
}

void WasteManagement::startService()
{
    std::cout << "\n--- Starting Service Cycle ---" << std::endl;

    servState->handleService(this);

    // State-specific behavior
    std::cout << "--- End of Service ---\n"
              << std::endl;
    getStatus();
}

 DevelopmentDept* WasteManagement::createDevelopmentDept() 
 {
   // return new ;
 }

// void WasteManagement::iterateBuildings(bool limitedProcessing, int maxBuildings)
// {
//     std::cout << "Iterating Buildings" << std::endl;
//     iterator.reset();
//     int processedCount = 0;

//     iterator.hasNext();

//         Building *building = iterator.next();

//     // If in limited processing mode, only process up to maxBuildings
//     if (limitedProcessing && processedCount >= maxBuildings)
//     {
//         std::cout << "Reached limit of " << maxBuildings << " buildings during maintenance." << std::endl;
        
//     }

//     // Simulate partial waste collection or checks
//     if (limitedProcessing)
//     {
//         // Perform limited maintenance without printing for each iteration
//     }
//     else
//     {
//         // Collect waste without printing for each iteration
//         // Insert full waste collection logic here for Operational state
//     }

//     processedCount++;

//     // Output only after finishing the loop
//     if (limitedProcessing)
//     {
//         std::cout << "Completed limited maintenance on " << processedCount << " buildings." << std::endl;
//     }
//     else
//     {
//         std::cout << "Completed waste collection on " << processedCount << " buildings." << std::endl;
//     }
// }
