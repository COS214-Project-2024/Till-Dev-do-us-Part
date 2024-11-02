#include "PowerPlant.h"
#include <iostream>
#include <thread>       // For sleep_for
#include <chrono>  

PowerPlant::PowerPlant(std::string name, ResourceDepartment *department, Resources *resource)
    : ProductionUtility(name, department, resource)
{
    productionCapacity = 5000;
    currentProduction = 0;
}

PowerPlant::~PowerPlant() {}


void PowerPlant::startProduction()
{
    std::cout << "\n--- Starting Production Cycle ---" << std::endl;

    // Step 1: Check for Breakdowns
    std::cout << "Checking for potential breakdowns..." << std::endl;
    checkForBreakdowns();
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause to simulate checking time

    // Step 2: Handle Production based on state
    if (proState && proState->getStateName() == "Operational") {
        std::cout << "No breakdowns detected. Production running normally." << std::endl;
        proState->handleProduction(this); // Continue production if operational
    }
    else if (proState && proState->getStateName() == "Maintenance") {
        std::cout << "Breakdown detected! " << getName() << " is now in Maintenance State. Production halted.\n";
    }

    // End of single production cycle
    std::cout << "--- End of Production Cycle ---\n" << std::endl;
}