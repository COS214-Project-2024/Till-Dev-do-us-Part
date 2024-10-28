#include "OutageState.h"
#include "Utility.h"

void startProduction(Utility* utility)  {
        std::cout << "Utility is in outage. No production." << std::endl;
        utility->setCurrentProduction(0); // No production during outage

        // Notify suburbs and update citizens' mood to "angry"
        // utility->notifySuburbs("The utility is in outage. Expect service disruption.");
        // utility->updateSuburbCitizensMood("angry");
    }

std::string OutageState::getStateName() {
    return "Outage";
}
