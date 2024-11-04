#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <iostream>
using namespace std;

/**
 * @brief Abstract base class representing the operational state of a building.
 *
 * The BuildingState class provides an interface for various building states.
 * Each state determines the availability of utilities such as electricity and water,
 * as well as supports cloning for state management.
 */
class BuildingState
{
protected:
    string name; ///< The name representing the current state of the building.

public:
    /**
     * @brief Constructs a BuildingState with a specified name.
     *
     * @param name The name of the building state.
     */
    BuildingState(string name);

    /// @brief Virtual destructor to ensure proper cleanup of derived classes.
    virtual ~BuildingState();

    /**
     * @brief Checks if electricity can be utilized in the current state.
     *
     * @return true if electricity is available, false otherwise.
     */
    virtual bool canUseElectricity() = 0;

    /**
     * @brief Checks if water can be utilized in the current state.
     *
     * @return true if water is available, false otherwise.
     */
    virtual bool canUseWater() = 0;

    /**
     * @brief Creates a copy of the current BuildingState.
     *
     * @return BuildingState* A pointer to the cloned BuildingState object.
     */
    virtual BuildingState *clone() = 0;

    /**
     * @brief Retrieves the name of the current building state.
     *
     * @return string The name of the building state.
     */
    virtual string getName();
};

#endif
