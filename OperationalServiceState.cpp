
#include "OperationalState.h"

void startProduction(Utility* utility){
        std::cout << "Utility is operational. Production started." << std::endl;
        utility->setCurrentProduction(utility->getTotalProduction());

        // // Notify suburbs and update citizens' mood to "happy"
        // utility->notifySuburbs("The utility is operational. Enjoy uninterrupted services!");
        // utility->updateSuburbCitizensMood("happy");
    }

    std::string getStateName() {
        return "Operational";
    }