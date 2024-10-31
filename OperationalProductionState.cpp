#include "OperationalProductionState.h"
#include <iostream>

void OperationalProductionState::handleProduction(ProductionUtility *utility)
{
    // Calculate maximum possible production based on resources and workers
    float resourceFactor = utility->getResource()->getCurrentAmount() / utility->getResource()->getInitialAmount();
    float workerEfficiency = utility->getWorkers() * 0.1; // Assume each worker contributes 10% to efficiency
    float capacity = utility->getProductionCapacity();
    float yield = capacity * resourceFactor * workerEfficiency; // Final yield based on resource and worker efficiency

    utility->setCurrentProduction(yield);

    std::cout << utility->getName() << " is in Operational State. "
              << "Producing at full capacity: " << yield << " units based on resources and worker efficiency.\n";

    // Consume resources based on the yield
    float resourceConsumption = yield * 0.05; // Assume 5% of yield is the resource consumption rate
    if (utility->getResource()->consume(resourceConsumption))
    {
        std::cout << resourceConsumption << " units of resources consumed for production.\n";
    }
}
