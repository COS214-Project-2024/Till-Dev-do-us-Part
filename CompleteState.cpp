#include "CompleteState.h"

CompleteState::CompleteState():BuildingState("Complete"){

}

bool CompleteState::canUseElectricity(){
    return true;
}

bool CompleteState::canUseWater()
{
    return true;
}
