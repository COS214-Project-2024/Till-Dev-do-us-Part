#include "OutageState.h"
#include "Utility.h"

void OutageState::startProduction(Utility* utility) {
    utility->setCurrentProduction(0);
    std::cout << "Utility is in an outage. No production." << std::endl;
}

std::string OutageState::getStateName() {
    return "Outage";
}
