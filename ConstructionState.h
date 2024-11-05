#ifndef CONSTRUCTIONSTATE_H
#define CONSTRUCTIONSTATE_H
#include "BuildingState.h"
#include "CompleteState.h"

/**
 * @class ConstructionState
 * @brief Represents a building state where construction is ongoing.
 *
 * The ConstructionState class defines behavior for a building that is
 * still under construction, where utilities like electricity and water
 * are not yet available.
 */
class ConstructionState : public BuildingState
{
public:
    /**
     * @brief Constructs a ConstructionState object.
     *
     * Initializes the state to "Construction," indicating that the building
     * is still under development and utilities are unavailable.
     */
    ConstructionState();

    /**
     * @brief Checks if electricity can be used in the ConstructionState.
     *
     * In the ConstructionState, electricity is not accessible.
     *
     * @return false Always returns false as electricity cannot be used.
     */
    virtual bool canUseElectricity();

    /**
     * @brief Checks if water can be used in the ConstructionState.
     *
     * In the ConstructionState, water is not accessible.
     *
     * @return false Always returns false as water cannot be used.
     */
    virtual bool canUseWater();

    /**
     * @brief Creates a clone of the ConstructionState instance.
     *
     * This method creates a new instance of ConstructionState,
     * preserving the "Construction" state.
     *
     * @return BuildingState* A pointer to the newly created ConstructionState object.
     */
    virtual BuildingState *clone();
};

#endif
