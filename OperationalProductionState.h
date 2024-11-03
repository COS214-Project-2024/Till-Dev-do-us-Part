#ifndef OPERATIONALPRODUCTIONSTATE_H
#define OPERATIONALPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

/**
 * @brief Class representing the operational state of a production utility.
 * 
 * Inherits from ProductionState and defines behavior specific to operational production.
 */
class OperationalProductionState : public ProductionState {
public:
    /**
     * @brief Handles production operations while in the operational state.
     * 
     * @param utility Pointer to the ProductionUtility that is operational.
     */
    void handleProduction(ProductionUtility* utility) override;

    /**
     * @brief Gets the name of the state.
     * 
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Operational"; }
};

#endif // OPERATIONALPRODUCTIONSTATE_H
