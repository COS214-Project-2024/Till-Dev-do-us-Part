#ifndef CRITICAL_STATE_H
#define CRITICAL_STATE_H

#include "ShortageState.h"
class Resources;
#include "ResourceState.h"

/**
 * @class CriticalState
 * @brief Represents the critical state of a resource, inheriting from ResourceState.
 * 
 * This class manages the state of resources that are in a critical condition,
 * evaluating the current amount of the resource and adjusting its state as necessary.
 * 
 * @author Thendo
 */
class CriticalState : public ResourceState {
public:
    /**
     * @brief Checks the availability of resources and updates the state accordingly.
     * 
     * This method evaluates the ratio of the current amount to the initial amount
     * and transitions to the appropriate state (Shortage, Balanced, or Surplus).
     * 
     * @param res Pointer to the Resources object being evaluated.
     */
    void checkAvailability(Resources* res) override;

    /**
     * @brief Retrieves the status of the critical state.
     * @return A string indicating the current state as "Critical State".
     */
    string getStatus() override;
};

#endif // CRITICAL_STATE_H
