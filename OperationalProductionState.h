#ifndef OPERATIONALPRODUCTIONSTATE_H
#define OPERATIONALPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

class OperationalProductionState : public ProductionState {
public:
    void handleProduction(ProductionUtility* utility) override;

    std::string getStateName() const override { return "Operational"; }
};

#endif // OPERATIONALPRODUCTIONSTATE_H
