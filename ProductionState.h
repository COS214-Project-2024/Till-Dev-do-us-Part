#ifndef PRODUCTIONSTATE_H
#define PRODUCTIONSTATE_H

#include "UtilityState.h"

class ProductionUtility;

class ProductionState : public UtilityState {
public:
    virtual ~ProductionState() = default;

    // Production-specific behavior for this state
    virtual void startProduction(ProductionUtility* utility) = 0;
};

#endif // PRODUCTIONSTATE_H
