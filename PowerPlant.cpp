#include "PowerPlant.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @brief Constructs a PowerPlant object with specified parameters.
 * 
 * Initializes production capacity and sets the initial production state to operational.
 * 
 * @param name The name of the power plant.
 * @param department Pointer to the ResourceDepartment managing the plant.
 * @param resource Pointer to the Energy resource being produced.
 * @param numworkers The number of workers in the plant.
 */
PowerPlant::PowerPlant(std::string name, ResourceDepartment *department, Energy *resource, int numworkers)
    : ProductionUtility(name, department, resource, numworkers)
{
    std::cout << "Simulation " << std::endl;
    productionCapacity = 5000; ///< Maximum production capacity of the plant
    currentProduction = 0; ///< Current production amount
    setProState(new OperationalProductionState); ///< Set initial production state
}

/**
 * @brief Destroys the PowerPlant object.
 */
PowerPlant::~PowerPlant() {}

/**
 * @brief Starts the power production process.
 * 
 * This method manages the production cycle by checking for breakdowns and handling production
 * according to the current operational state of the plant.
 */
void PowerPlant::startProduction() {
    ActiveWorkers = UtilityBus->activelyWorking(); // Update the count of active workers
    std::cout << "\n--- Starting Production Cycle ---" << std::endl;

    // Step 1: Check for Breakdowns
    std::cout << "Checking for potential breakdowns..." << std::endl;
    checkForBreakdowns(); // Call method to check for any breakdowns
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate check time

    // Step 2: Handle Production based on current state
    if (proState) {
        if (proState->getStateName() == "Operational") {
            std::cout << "Production running normally." << std::endl;
            proState->handleProduction(this); // Call handleProduction for normal operation
        }
        else if (proState->getStateName() == "Maintenance") {
            std::cout << getName() << " is in Maintenance State. Production at reduced capacity.\n";
            proState->handleProduction(this); // Call handleProduction for maintenance
        }
        else if (proState->getStateName() == "Outage") {
            std::cout << getName() << " is in Outage State. Production halted. Checking if conditions allow restart...\n";
            
            // Attempt to restart production if conditions are met
            float resourceThreshold = 0.5; // 50% of initial resources required
            int minActiveWorkers = getMaxWorkers() * 0.5; // 50% of max workers required

            // Check if resources and workers are sufficient to resume production
            bool resourcesRestored = getResource()->getCurrentAmount() >= getResource()->getInitialAmount() * resourceThreshold;
            bool workersRestored = getActiveWorkers() >= minActiveWorkers;

            if (resourcesRestored && workersRestored) {
                std::cout << "Conditions met to resume production.\n";
                startProduction(); // Call startProduction to reinitiate production in an operational state
            }
        }
    }

    std::cout << "--- End of Production Cycle ---\n" << std::endl;
    getStatus(); // Output current status of the power plant
}
