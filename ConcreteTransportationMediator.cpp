#include "ConcreteTransportationMediator.h"
#include "TransportMode.h"
#include <iostream>



void ConcreteTransportationMediator::notify(TransportMode* mode) {
    // in transportmode return the trannsport facility example getRoad
    //then return the transport facilites vector of transport modes
    // ex. getRoad()->getVehicles
    std::cout << mode->getName() << " reported a "<<  mode->GetMessage()<< ". Notifying colleagues...\n";

    std::string message= mode->GetMessage();

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ode()) {
        //must look something like mode->getRoad()->getVehicles
         for (auto& colleague : mode->GetFacility()->GetModes()) {
            if (colleague != mode) {
                colleague->SendMessage(message); // Notify all colleagues
            }
        }

}
}


