#include "ConcreteTransportationMediator.h"
#include "TransportMode.h"
#include <iostream>



void ConcreteTransportationMediator::notify(TransportMode* mode) {
    std::cout << mode->getName() << " reported a "<<  mode->GetMessage()<< ". Notifying colleagues...\n";

    std::string message= mode->GetMessage();
 

         for (auto& colleague : mode->GetFacility()->GetModes()) {
            if (colleague != mode) {
                colleague->SendMessage(message); // Notify all colleagues
            }
        }
}


