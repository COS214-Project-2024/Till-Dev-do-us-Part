#include "ConstructionState.h"

ConstructionState::ConstructionState():BuildingState("Construction"){
}

bool ConstructionState::canUseElectricity()
{
    return false;
}

bool ConstructionState::canUseWater()
{
    return true;
}