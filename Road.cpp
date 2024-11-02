#include "Road.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include "TransState.h"
#include "TransportMode.h" 
#include <iostream>
#include <algorithm>
#include <string>

Road:: Road(){
    std::cout << "Building Road." << std::endl;
    currentState= new EmptyState;
    
}


Road::~Road() {
    delete currentState;
    moVec.clear();
}


