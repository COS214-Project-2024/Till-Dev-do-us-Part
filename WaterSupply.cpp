#include "WaterSupply.h"
#include <iostream>
WaterSupply::WaterSupply(std::string name, ResourceDepartment *department, Water *resource, int numworkers)
    : ProductionUtility(name, department, resource, numworkers)
{
    productionCapacity = 5000;
    currentProduction = 0;
    setProState(new OperationalProductionState);
}

WaterSupply::~WaterSupply() {}

void WaterSupply::startProduction()
{
    std::cout << "\n--- Starting Production Cycle ---" << std::endl;

    std::cout << "Checking for potential breakdowns..." << std::endl;
    checkForBreakdowns();
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause to simulate checking time

    // Step 2: Handle Production based on state
    if (proState && proState->getStateName() == "Operational")
    {
        std::cout << "No breakdowns detected. Production running normally." << std::endl;
        proState->handleProduction(this); // Continue production if operational
    }
    else if (proState && proState->getStateName() == "Maintenance")
    {
        std::cout << "Breakdown detected! " << getName() << " is now in Maintenance State. Production halted.\n";
    }

    // End of single production cycle
    std::cout << "--- End of Production Cycle ---\n"
              << std::endl;
    getStatus();
}
