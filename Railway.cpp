#include "Railway.h"
#include <iostream>
#include <string>


void Railway::maintain() {
    std::cout << "Performing railway maintenance" << std::endl;
    // Check railway condition
    if (trainsCount > 20) {
        state = new CongestedState();
    } else if (trainsCount == 0) {
        state = new EmptyState();
    } else {
        state = new NormalState();
    }
    
    // Perform maintenance tasks
    std::cout << "Checking rail tracks" << std::endl;
    std::cout << "Testing signals" << std::endl;
    std::cout << "Maintaining power lines" << std::endl;
}
