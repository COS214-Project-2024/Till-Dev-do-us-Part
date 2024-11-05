#include "CompleteState.h"

/**
 * @brief Constructs a CompleteState object.
 *
 * Initializes the CompleteState, representing a state where all utilities
 * (electricity and water) are accessible.
 */
CompleteState::CompleteState() : BuildingState("Complete")
{
}

/**
 * @brief Determines if electricity can be used in this building state.
 *
 * Since this is the CompleteState, electricity is fully available.
 *
 * @return true Always returns true as electricity can be used in CompleteState.
 */
bool CompleteState::canUseElectricity()
{
    return true;
}

/**
 * @brief Determines if water can be used in this building state.
 *
 * In CompleteState, water usage is permitted.
 *
 * @return true Always returns true as water can be used in CompleteState.
 */
bool CompleteState::canUseWater()
{
    return true;
}

/**
 * @brief Creates a clone of this CompleteState instance.
 *
 * This method creates a new instance of CompleteState, preserving the "Complete" state.
 *
 * @return BuildingState* A pointer to the newly created CompleteState object.
 */
BuildingState *CompleteState::clone()
{
    return new CompleteState();
}
