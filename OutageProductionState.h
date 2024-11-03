#ifndef OUTAGEPRODUCTIONSTATE_H
#define OUTAGEPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

/**
 * @brief Class representing the outage state of production.
 * 
 * Inherits from ProductionState and implements specific production handling when in outage.
 */
class OutageProductionState : public ProductionState {
public:
    /**
     * @brief Handles production activities in the outage state.
     * 
     * @param utility Pointer to the ProductionUtility managing the production.
     */
    void handleProduction(ProductionUtility* utility) override;

    /**
     * @brief Retrieves the name of this production state.
     * 
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Outage"; }
};

#endif // OUTAGEPRODUCTIONSTATE_H
