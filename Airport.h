// Airport.h
#pragma once
#include "TransportStation.h"
#include <vector>
#include "FacilitiesFactory.h"
#include "ConcreteTransportationMediator.h" 

class Airport : public TransportFacilities {
private:
    std::vector<TransportMode*> planes;

public:

    Airport();
    ~Airport();
    
    
};