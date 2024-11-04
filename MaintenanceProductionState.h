/**
 * @file MaintenanceProductionState.h
 * @brief Defines the maintenance state for production utilities.
 */

#ifndef MAINTENANCEPRODUCTIONSTATE_H
#define MAINTENANCEPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

/**
 * @class MaintenanceProductionState
 * @brief Represents the maintenance state of a production utility.
 */
class MaintenanceProductionState : public ProductionState {
public:
    /**
     * @brief Handles production operations in the maintenance state.
     * 
     * In this state, the production utility is undergoing maintenance,
     * which may involve stopping production to perform necessary repairs
     * or checks on equipment and resources.
     * 
     * @param utility Pointer to the ProductionUtility currently in this state.
     */
    void handleProduction(ProductionUtility* utility) override;

    /**
     * @brief Retrieves the name of this state.
     * @return A string representing the state name.
     */
    std::string getStateName() const override { return "Maintenance"; }
};

#endif // MAINTENANCEPRODUCTIONSTATE_H
