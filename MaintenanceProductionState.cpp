#include "MaintenanceProductionState.h"
#include <iostream>

void MaintenanceProductionState::handleProduction(ProductionUtility *utility)
{
    float resourceFactor = utility->getResource()->getCurrentAmount() / utility->getResource()->getInitialAmount();
    float workerEfficiency = utility->getWorkers() * 0.05; // Reduced efficiency
    float yield = utility->getProductionCapacity() * 0.5 * resourceFactor * workerEfficiency;

    utility->setCurrentProduction(yield);

    std::cout << utility->getName() << " in Maintenance State. Producing "
              << yield << " units at reduced capacity.\n";

    float resourceConsumption = yield * 0.03; // Reduced consumption rate
    if (utility->getResource()->consume(resourceConsumption))
    {
        std::cout << resourceConsumption << " units of " << utility->getResource()->getName() << " consumed during maintenance.\n";
    }
}
