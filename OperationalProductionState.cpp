#include "OperationalProductionState.h"
#include <iostream>

void OperationalProductionState::handleProduction(ProductionUtility *utility)
{
    // Calculate maximum possible production based on resources and workers
    float resourceFactor = utility->getResource()->getCurrentAmount() / utility->getResource()->getInitialAmount();
    float workerEfficiency = 100; // Assume 100% efficiency for simplification, or set as needed

    float capacity = utility->getProductionCapacity();
    float yield = capacity * resourceFactor * (workerEfficiency / 100.0f); // Adjusted yield calculation

    // Cap yield to the maximum production capacity
    if (yield > capacity) {
        yield = capacity;
    }

    // Set the current production to the capped yield value
    utility->setCurrentProduction(yield);
    

    std::cout << utility->getName() << " is in Operational State. "
              << "Producing at capacity: " << yield << " units based on resources and worker efficiency.\n";

    // Consume resources based on the yield
    float resourceConsumption = yield * 0.05; // Assume 5% of yield is the resource consumption rate
    if (utility->getResource()->consume(resourceConsumption))
    {
        std::cout << resourceConsumption << " units of resources consumed for production.\n";
    }
}
