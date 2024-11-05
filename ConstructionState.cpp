#include "ConstructionState.h"

/**
 * @brief Constructs a ConstructionState object.
 *
 * Initializes the state to "Construction," indicating that the building
 * is still under development and utilities are limited.
 */
ConstructionState::ConstructionState() : BuildingState("Construction")
{
}

/**
 * @brief Checks if electricity can be used in the ConstructionState.
 *
 * In the ConstructionState, electricity is not accessible.
 *
 * @return false Always returns false as electricity cannot be used.
 */
bool ConstructionState::canUseElectricity()
{
    return false;
}

/**
 * @brief Checks if water can be used in the ConstructionState.
 *
 * In the ConstructionState, water access may be available for construction needs.
 *
 * @return true Returns true as water may be available in this state.
 */
bool ConstructionState::canUseWater()
{
    return true;
}

/**
 * @brief Creates a clone of the ConstructionState instance.
 *
 * This method creates a new instance of ConstructionState,
 * preserving the "Construction" state.
 *
 * @return BuildingState* A pointer to the newly created ConstructionState object.
 */
BuildingState *ConstructionState::clone()
{
    return new ConstructionState();
}
