#include "TransState.h"
#include <string>
#include <iostream>

// Additional TransportState implementations
void NormalState:: handleState() {
    std::cout << "Operating under normal conditions" << std::endl;
}

void CongestedState::handleState() {
    std::cout << "Operating under congested conditions" << std::endl;
    std::cout << "Implementing congestion management protocols" << std::endl;
}

void EmptyState::handleState() {
    std::cout << "No traffic - operating under empty conditions" << std::endl;
}