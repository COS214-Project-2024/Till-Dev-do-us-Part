#ifndef COMPLETESTATE_H
#define COMPLETESTATE_H

#include "BuildingState.h"

/**
 * @brief Represents the "Complete" state of a building, where utilities are fully operational.
 *
 * The CompleteState class implements the BuildingState interface, allowing
 * buildings in this state to use electricity and water.
 */
class CompleteState : public BuildingState
{
public:
    /**
     * @brief Constructs a CompleteState object.
     *
     * Initializes the CompleteState, setting it up as the state where all utilities
     * (electricity and water) are accessible.
     */
    CompleteState();

    /**
     * @brief Checks if electricity can be used in the building.
     *
     * @return true if electricity can be used, otherwise false.
     */
    virtual bool canUseElectricity();

    /**
     * @brief Checks if water can be used in the building.
     *
     * @return true if water can be used, otherwise false.
     */
    virtual bool canUseWater();

    /**
     * @brief Creates a copy of this CompleteState object.
     *
     * @return BuildingState* A pointer to the newly cloned CompleteState object.
     */
    virtual BuildingState *clone();
};

#endif
