#include "ConstructionState.h"

ConstructionState::ConstructionState():BuildingState("Construction"){
}

// BuildingState *ConstructionState::change()
// {
//     return new CompleteState();
// }

bool ConstructionState::canUseElectricity()
{
    return false;
}

bool ConstructionState::canUseWater()
{
    return true;
}