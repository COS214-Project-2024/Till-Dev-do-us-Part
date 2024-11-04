#ifndef PRODUCTIONSTATE_H
#define PRODUCTIONSTATE_H

#include <string>


class ProductionUtility;

class ProductionState  {
public:
    virtual ~ProductionState() = default;

    // Production-specific behavior for this state
    virtual void handleProduction(ProductionUtility* utility) = 0;
    virtual std::string getStateName() const = 0;
};

#endif // PRODUCTIONSTATE_H
