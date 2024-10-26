#include "ConstructionState.h"

ConstructionState::ConstructionState(){

}

ConstructionState::~ConstructionState(){

}

BuildingState* ConstructionState::demolish(BuildingState *prevState){
    

}

BuildingState* ConstructionState::renovate(BuildingState *prevState){
    if (prevState != NULL)
    {
        if (prevState->getName() == "construction"){
            return prevState; // if we are in the construction state
        }
        
        if (prevState->getName() == "dilapidated"){
            return this;
        }
    }
}

BuildingState* ConstructionState::maintenance(BuildingState *prevState){

}

