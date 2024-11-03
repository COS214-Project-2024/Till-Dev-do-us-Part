#ifndef MAINTENANCEPRODUCTIONSTATE_H
#define MAINTENANCEPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

/**
 * @brief Class representing the maintenance state of a production utility.
 * 
 * Inherits from ProductionState and defines behavior specific to maintenance in production.
 */
class MaintenanceProductionState : public ProductionState {
public:
    /**
     * @brief Handles production operations while in maintenance state.
     * 
     * @param utility Pointer to the ProductionUtility that is in maintenance.
     */
    void handleProduction(ProductionUtility* utility) override;

    /**
     * @brief Gets the name of the state.
     * 
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Maintenance"; }
};

#endif // MAINTENANCEPRODUCTIONSTATE_H
