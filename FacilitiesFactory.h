// / Abstract Creators
#pragma once
#include "TransportFacilities.h"
#include <algorithm>
class FacilitiesFactory {
public:
    ~FacilitiesFactory();
    virtual TransportFacilities* createFacilities() = 0;  // Factory Method

protected:
    FacilitiesFactory() = default;
    TransportFacilities* facilities;
    
};