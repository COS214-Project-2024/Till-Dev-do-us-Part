#include "OutageProductionState.h"
#include <iostream>

/**
 * @brief Handles production activities in the outage state.
 * 
 * This method sets the production to zero, checks for recovery conditions,
 * and potentially transitions to a maintenance or operational state based on resources and workers.
 * 
 * @param utility Pointer to the ProductionUtility managing the production.
 */
void OutageProductionState::handleProduction(ProductionUtility *utility)
{
    std::cout << utility->getName() << " is in Outage State. Production is halted.\n";
    utility->setCurrentProduction(0.0f); // Production set to zero, no resources consumed

    // Check for recovery conditions
    float resourceThreshold = 0.5f; // 50% of initial resources
    int minActiveWorkers = utility->getMaxWorkers() * 0.5; // Minimum 50% of workers

    bool hasSufficientResources = utility->getResource()->getCurrentAmount() >= utility->getResource()->getInitialAmount() * resourceThreshold;
    bool hasSufficientWorkers = utility->getActiveWorkers() >= minActiveWorkers;

    // Transition to Maintenance State if partial recovery detected
    if (hasSufficientResources && hasSufficientWorkers)
    {
        std::cout << "Partial recovery detected. Transitioning to Maintenance State.\n";
        utility->setProState(new MaintenanceProductionState());
        return;
    }

    // Transition to Operational State if full recovery detected
    if (utility->getResource()->getCurrentAmount() >= utility->getResource()->getInitialAmount() &&
        utility->getActiveWorkers() == utility->getMaxWorkers())
    {
        std::cout << "Full recovery detected. Transitioning to Operational State.\n";
        utility->setProState(new OperationalProductionState());
        return;
    }
}
