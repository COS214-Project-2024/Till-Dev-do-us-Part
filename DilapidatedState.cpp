#include "DilapidatedState.h"

DilapidatedState::DilapidatedState() : BuildingState("Dilapidated")
{
}

bool DilapidatedState::canUseElectricity()
{
    return false;
}

bool DilapidatedState::canUseWater()
{
    return false;
}