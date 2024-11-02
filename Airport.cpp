#include "Airport.h"
#include "EmptyState.h"
#include "NormalState.h"
#include "CongestedState.h"
#include <string>
#include <iostream>
#include <algorithm>



Airport::Airport(){
    std::cout << "Building Airport." << std::endl;
    currentState= new EmptyState(this);
    name= "Road";
}

Airport::~Airport() {
    delete currentState;
    moVec.clear();
}



    
