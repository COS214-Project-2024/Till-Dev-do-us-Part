/**
 * @file OutageProductionState.h
 * @brief Defines the outage state for production utilities.
 */

#ifndef OUTAGEPRODUCTIONSTATE_H
#define OUTAGEPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

/**
 * @class OutageProductionState
 * @brief Represents the outage state of a production utility.
 */
class OutageProductionState : public ProductionState {
public:
    /**
     * @brief Handles production processes in the outage state.
     * 
     * In this state, production is halted, and the utility may perform
     * necessary recovery steps or wait for repairs.
     * 
     * @param utility Pointer to the ProductionUtility currently in this state.
     */
    void handleProduction(ProductionUtility* utility) override;

    /**
     * @brief Retrieves the name of this state.
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Outage"; }
};

#endif // OUTAGEPRODUCTIONSTATE_H
