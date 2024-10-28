#include "Airport.h"
#include <string>
#include <iostream>


void Airport::maintain() {
    std::cout << "Performing airport maintenance" << std::endl;
    // Check airport condition
    if (planesCount > 50) {
        state = new CongestedState();
    } else if (planesCount == 0) {
        state = new EmptyState();
    } else {
        state = new NormalState();
    }
    
    // Perform maintenance tasks
    std::cout << "Inspecting runways" << std::endl;
    std::cout << "Checking navigation systems" << std::endl;
    std::cout << "Maintaining terminal facilities" << std::endl;
    std::cout << "Testing emergency systems" << std::endl;
}

