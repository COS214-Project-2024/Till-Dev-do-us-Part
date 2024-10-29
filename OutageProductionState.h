#ifndef OUTAGEPRODUCTIONSTATE_H
#define OUTAGEPRODUCTIONSTATE_H

#include "ProductionState.h"
#include "ProductionUtility.h"

class OutageProductionState : public ProductionState {
public:
    void startProduction(ProductionUtility* utility) override;
    std::string getStateName() const override { return "Outage"; }
};

#endif // OUTAGEPRODUCTIONSTATE_H
