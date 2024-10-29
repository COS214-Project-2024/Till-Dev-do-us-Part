#ifndef MAINTENANCEPRODUCTIONSTATE_H
#define MAINTENANCEPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

class MaintenanceProductionState : public ProductionState {
public:
    void startProduction(ProductionUtility* utility) override;
    std::string getStateName() const override { return "Maintenance"; }
};

#endif // MAINTENANCEPRODUCTIONSTATE_H
