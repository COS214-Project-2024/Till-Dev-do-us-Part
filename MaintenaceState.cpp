#include "MaintenanceState.h"
#include "Utility.h"

void MaintenanceState::startProduction(Utility* utility) {
    std::cout << "Utility is under maintenance. Limited production." << std::endl;
        utility->setCurrentProduction(utility->getTotalProduction() * 0.5f); // Half production during maintenance

        // Notify suburbs and update citizens' mood to "neutral"
        // utility->notifySuburbs("The utility is under maintenance. Services may be disrupted.");
        // utility->updateSuburbCitizensMood("neutral");
}

std::string MaintenanceState::getStateName() {
    return "Maintenance";
}
