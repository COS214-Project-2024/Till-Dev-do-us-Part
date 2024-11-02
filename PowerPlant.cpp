#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(std::string name, ResourceDepartment *department, Energy *resource, int numworkers)
    : ProductionUtility(name, department, resource, numworkers)
{
    productionCapacity = 5000;
    currentProduction = 0;
    setProState(new OperationalProductionState);
}

PowerPlant::~PowerPlant() {}

void PowerPlant::startProduction() {
    ActiveWorkers = UtilityBus->activelyWorking();
    std::cout << "\n--- Starting Production Cycle ---" << std::endl;

    // Step 1: Check for Breakdowns
    std::cout << "Checking for potential breakdowns..." << std::endl;
    checkForBreakdowns();
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate check time

    // Step 2: Handle Production based on current state
    if (proState) {
        if (proState->getStateName() == "Operational") {
            std::cout << "Production running normally." << std::endl;
            proState->handleProduction(this);
        }
        else if (proState->getStateName() == "Maintenance") {
            std::cout << getName() << " is in Maintenance State. Production at reduced capacity.\n";
            proState->handleProduction(this);
        }
        else if (proState->getStateName() == "Outage") {
            std::cout << getName() << " is in Outage State. Production halted. Checking if conditions allow restart...\n";
            
            // Attempt to restart production if conditions are met
            float resourceThreshold = 0.5;
            int minActiveWorkers = getMaxWorkers() * 0.5;

            bool resourcesRestored = getResource()->getCurrentAmount() >= getResource()->getInitialAmount() * resourceThreshold;
            bool workersRestored = getActiveWorkers() >= minActiveWorkers;

            if (resourcesRestored && workersRestored) {
                std::cout << "Conditions met to resume production.\n";
                startProduction(); // Call startProduction to reinitiate production in an operational state
            }
        }
    }

    std::cout << "--- End of Production Cycle ---\n" << std::endl;
    getStatus();
}
