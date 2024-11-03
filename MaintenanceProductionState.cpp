#include "MaintenanceProductionState.h"
#include <iostream>

void MaintenanceProductionState::handleProduction(ProductionUtility *utility)
{
    // Calculate maximum possible production based on resources and workers
    float resourceFactor = utility->getResource()->getCurrentAmount() / utility->getResource()->getInitialAmount();
    float workerEfficiency = 50;                                                                    // Assume 50% efficiency for simplification, or set as needed
    float workerFactor = static_cast<float>(utility->getActiveWorkers()) / utility->getMaxWorkers(); // Ratio of active workers to total
    float capacity = utility->getProductionCapacity();
    float yield = capacity * resourceFactor * workerFactor * (workerEfficiency / 100.0f); // Adjusted yield calculation

    // Cap yield to the maximum production capacity
    if (yield > capacity)
    {
        yield = capacity;
    }


    // Set current production to the maintenance-level yield
    utility->setCurrentProduction(yield);

    std::cout << utility->getName() << " is in Maintenance State. Producing "
              << yield << " units at reduced capacity.\n";

    // Reduced resource consumption rate during maintenance
    float resourceConsumption = yield * 0.03; // 3% of yield is resource consumption rate during maintenance
    if (utility->getResource()->consume(resourceConsumption))
    {
        std::cout << resourceConsumption << " units of " << utility->getResource()->getName() 
                  << " consumed during maintenance.\n";
    }

    // Check conditions for transitions directly
    if (resourceFactor > 0.8 && workerFactor > 0.8) {
        std::cout << "Resources and workers restored. Transitioning to Operational State.\n";
        utility->setProState(new OperationalProductionState());
        return;
    }

    // Check for conditions that might lead to an outage
    if (resourceFactor < 0.2 || workerFactor < 0.2) {
        std::cout << "Further issues detected! Transitioning to Outage State.\n";
        utility->setProState(new OutageProductionState());
        return;
    }

    // Simulate a random breakdown during maintenance
    float breakdownProbability = 0.05; // 5% chance of breakdown
    if ((static_cast<float>(std::rand()) / RAND_MAX) < breakdownProbability) {
        std::cout << "Severe breakdown detected randomly during maintenance! Transitioning to Outage State.\n";
        utility->setProState(new OutageProductionState());
        return;
    }
}