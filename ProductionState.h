/**
 * @file ProductionState.h
 * @brief Defines the ProductionState interface for production utilities.
 */

#ifndef PRODUCTIONSTATE_H
#define PRODUCTIONSTATE_H

#include <string>

class ProductionUtility;

/**
 * @class ProductionState
 * @brief Abstract base class for defining different production states.
 */
class ProductionState  
{
public:
    virtual ~ProductionState() = default;

    /**
     * @brief Handles production behavior specific to this state.
     * @param utility Pointer to the ProductionUtility that is in this state.
     */
    virtual void handleProduction(ProductionUtility* utility) = 0;

    /**
     * @brief Retrieves the name of the state.
     * @return A string representing the state name.
     */
    virtual std::string getStateName() const = 0;
};

#endif // PRODUCTIONSTATE_H
