#ifndef DILAPIDATEDSTATE_H
#define DILAPIDATEDSTATE_H
#include "BuildingState.h"

/**
 * @class DilapidatedState
 * @brief Represents the dilapidated state of a building where limited utilities are accessible.
 *
 * This state indicates that the building is in poor condition, potentially with restricted access
 * to utilities due to its degraded state.
 */
class DilapidatedState : public BuildingState
{
public:
    /**
     * @brief Constructs a DilapidatedState object.
     *
     * Initializes the state to "Dilapidated," representing a building in disrepair.
     */
    DilapidatedState();

    /**
     * @brief Checks if electricity can be used in the DilapidatedState.
     *
     * In the DilapidatedState, electricity access may be unavailable.
     *
     * @return false Always returns false, as electricity is not available in this state.
     */
    virtual bool canUseElectricity();

    /**
     * @brief Checks if water can be used in the DilapidatedState.
     *
     * In the DilapidatedState, water access may still be possible, though limited.
     *
     * @return true Returns true, as water may be accessible in this state.
     */
    virtual bool canUseWater();

    /**
     * @brief Creates a clone of the DilapidatedState instance.
     *
     * This method creates a new instance of DilapidatedState, preserving the "Dilapidated" state.
     *
     * @return BuildingState* A pointer to the newly created DilapidatedState object.
     */
    virtual BuildingState *clone();
};
#endif
