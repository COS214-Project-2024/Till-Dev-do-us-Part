#include "OperationalServiceState.h"
#include <iostream>

void OperationalServiceState::handleService(ServiceUtility *utility)
{
    std::cout << "Waste Management is operational and processing buildings." << std::endl;

    // if (utility)
    // {
    //     utility->iterateBuildings(false, utility->getCapacity());
    // }
}

std::string OperationalServiceState::getStateName() const { return "Operational"; }
