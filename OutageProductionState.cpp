#include "OutageProductionState.h"
#include <iostream>

void OutageProductionState::handleProduction(ProductionUtility *utility)
{
    std::cout << utility->getName() << " is in Outage State. Production is halted.\n";
    utility->setCurrentProduction(0.0); // Production set to zero, no resources consumed

    // Check for recovery conditions
    float resourceThreshold = 0.5;
    int minActiveWorkers = utility->getMaxWorkers() * 0.5;

    bool hasSufficientResources = utility->getResource()->getCurrentAmount() >= utility->getResource()->getInitialAmount() * resourceThreshold;
    bool hasSufficientWorkers = utility->getActiveWorkers() >= minActiveWorkers;

    if (hasSufficientResources && hasSufficientWorkers)
    {
        std::cout << "Partial recovery detected. Transitioning to Maintenance State.\n";
        utility->setProState(new MaintenanceProductionState());
        return;
    }

    if (utility->getResource()->getCurrentAmount() >= utility->getResource()->getInitialAmount() &&
        utility->getActiveWorkers() == utility->getMaxWorkers())
    {
        std::cout << "Full recovery detected. Transitioning to Operational State.\n";
        utility->setProState(new OperationalProductionState());
        return;
    }
}
