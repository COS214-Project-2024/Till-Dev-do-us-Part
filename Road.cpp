#include "Road.h"
#include <string>
#include <iostream>
#include "TransState.h"
// TransportFacilities implementations
void Road::maintain() {
    std::cout << "Performing road maintenance" << std::endl;
    // Check road condition
    if (vehiclesCount > 100) {
        state = new CongestedState();
    } else if (vehiclesCount == 0) {
        state = new EmptyState();
    } else {
        state = new NormalState();
    }
    
    // Perform maintenance tasks
    std::cout << "Checking road surface" << std::endl;
    std::cout << "Repairing potholes" << std::endl;
    std::cout << "Maintaining road markings" << std::endl;
}
