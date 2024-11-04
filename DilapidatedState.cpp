#include "DilapidatedState.h"

/**
 * @brief Constructs a DilapidatedState object.
 *
 * Initializes the state to "Dilapidated," representing a building in a state of disrepair.
 */
DilapidatedState::DilapidatedState() : BuildingState("Dilapidated")
{
}

/**
 * @brief Checks if electricity can be used in the DilapidatedState.
 *
 * In this state, electricity access is restricted due to the building's condition.
 *
 * @return false Always returns false, indicating electricity is not accessible.
 */
bool DilapidatedState::canUseElectricity()
{
    return false;
}

/**
 * @brief Checks if water can be used in the DilapidatedState.
 *
 * Water access is also restricted in this state, reflecting limited functionality.
 *
 * @return false Always returns false, indicating water is not accessible.
 */
bool DilapidatedState::canUseWater()
{
    return false;
}

/**
 * @brief Creates a clone of the current DilapidatedState instance.
 *
 * This function returns a new DilapidatedState object, maintaining the "Dilapidated" state.
 *
 * @return BuildingState* A pointer to the newly created DilapidatedState instance.
 */
BuildingState *DilapidatedState::clone()
{
    return new DilapidatedState();
}
