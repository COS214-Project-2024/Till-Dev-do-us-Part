#include "Railway.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include <iostream>
#include <string>
#include <algorithm>

Railway:: Railway(){
    std::cout << "Building Railway." << std::endl;
    currentState= new EmptyState(this);
    name= "Road";
}

Railway::~Railway() {
    delete currentState;
    moVec.clear();
}


