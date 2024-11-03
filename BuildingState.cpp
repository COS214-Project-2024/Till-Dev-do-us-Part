#include "BuildingState.h"

BuildingState::BuildingState(string name){
    this->name = name;
}

string BuildingState::getName(){
    return this->name;
}

BuildingState::~BuildingState(){
    
}