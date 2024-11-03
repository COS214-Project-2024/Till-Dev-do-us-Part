#ifndef BALANCED_STATE_H
#define BALANCED_STATE_H

#include "ShortageState.h"
#include "ResourceState.h"

class Resources;

/**
 * @class BalancedState
 * @brief Represents the balanced state of a resource, inheriting from ResourceState.
 * 
 * This class manages the state of resources that are in balance, evaluating
 * the current amount of the resource and adjusting its state as necessary.
 */
class BalancedState : public ResourceState {
public:
    /**
     * @brief Checks the availability of resources and updates the state accordingly.
     * 
     * This method evaluates the ratio of the current amount to the initial amount
     * and transitions to the appropriate state (Surplus, Shortage, or Critical).
     * 
     * 
     * @author Thendo
     * @param res Pointer to the Resources object being evaluated.
     */
    void checkAvailability(Resources* res) override;

    /**
     * @brief Retrieves the status of the balanced state.
     * @return A string indicating the current state as "Balanced State".
     */
    string getStatus() override;
};

#endif // BALANCED_STATE_H
