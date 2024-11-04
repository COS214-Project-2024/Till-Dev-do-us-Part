#include "OperationalProductionState.h"
#include <iostream>

void OperationalProductionState::handleProduction(ProductionUtility *utility)
{
    // Calculate maximum possible production based on resources and workers
    float resourceFactor = utility->getResource()->getCurrentAmount() / utility->getResource()->getInitialAmount();
    float workerEfficiency = 100; // Assume 100% efficiency for simplification
    float workerFactor = static_cast<float>(utility->getActiveWorkers()) / utility->getMaxWorkers(); // Ratio of active workers to total
    float capacity = utility->getProductionCapacity();
    float yield = capacity * resourceFactor * workerFactor * (workerEfficiency / 100.0f); // Adjusted yield calculation

    // Cap yield to the maximum production capacity
    if (yield > capacity)
    {
        yield = capacity;
    }

    // Set the current production to the capped yield value
    utility->setCurrentProduction(yield);

    // Consume resources based on the yield
    float resourceConsumption = yield * 0.05; // Assume 5% of yield is the resource consumption rate
    if (utility->getResource()->consume(resourceConsumption))
    {
        std::cout << resourceConsumption << " units of resources consumed for production.\n";
    }

    // Check conditions for state transitions directly
    if (resourceFactor < 0.3 || workerFactor < 0.3)
    {
        std::cout << "Low resources or workers detected. Transitioning to Maintenance State.\n";
        utility->setProState(new MaintenanceProductionState());
        return;
    }

    // Simulate a random breakdown based on a 5% chance
    float breakdownProbability = 0.05; // 5% chance of breakdown
    if ((static_cast<float>(std::rand()) / RAND_MAX) < breakdownProbability)
    {
        std::cout << "Severe breakdown detected randomly! Transitioning to Outage State.\n";
        utility->setProState(new OutageProductionState());
        return;
    }
}
