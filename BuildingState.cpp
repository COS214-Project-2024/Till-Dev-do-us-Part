#include "BuildingState.h"

/**
 * @brief Constructs a BuildingState object with a specified name.
 *
 * @param name The name of the building state.
 */
BuildingState::BuildingState(string name)
{
    this->name = name;
}

/**
 * @brief Retrieves the name of the building state.
 *
 * @return string The name of the building state.
 */
string BuildingState::getName()
{
    return this->name;
}

/**
 * @brief Virtual destructor for BuildingState, ensuring proper cleanup in derived classes.
 */
BuildingState::~BuildingState()
{
}
