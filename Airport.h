// Airport.h
#pragma once
#include "TransportStation.h"
#include <vector>
#include "FacilitiesFactory.h"
#include "ConcreteTransportationMediator.h" 

class Airport : public TransportFacilities {
private:
    // int planesCount;
    std::vector<TransportMode*> planes;

public:
    // void handlePassengers() override;
    // void manageFreight() override;
    Airport();
    Airport(TransState* state);
    ~Airport();
    void maintain() override;
    void changeState();
    void setState(TransState* newState);
    void decreaseTraffic(Airport* airport2);
    
    
};