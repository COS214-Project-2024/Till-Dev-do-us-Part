/**
 * @file OperationalProductionState.h
 * @brief Defines the operational state for production utilities.
 */

#ifndef OPERATIONALPRODUCTIONSTATE_H
#define OPERATIONALPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

/**
 * @class OperationalProductionState
 * @brief Represents the operational state of a production utility.
 */
class OperationalProductionState : public ProductionState {
public:
    /**
     * @brief Handles production processes in the operational state.
     * 
     * Calculates the production yield based on available resources,
     * worker efficiency, and capacity. It also manages resource consumption
     * and checks for state transitions based on conditions.
     * 
     * @param utility Pointer to the ProductionUtility currently in this state.
     */
    void handleProduction(ProductionUtility* utility) override;

    /**
     * @brief Retrieves the name of this state.
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Operational"; }
};

#endif // OPERATIONALPRODUCTIONSTATE_H
