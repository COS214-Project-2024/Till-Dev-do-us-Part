// / Abstract Creators
#pragma once
#include "TransportFacilities.h"
#include <algorithm>
class FacilitiesFactory {
public:
    // virtual ~FacilitiesFactory();
    virtual TransportFacilities* createFacilities() = 0;  // Factory Method
    // virtual void removeFacility(TransportFacilities* facility);
    // virtual std::vector<TransportFacilities*>& getFacilities();
protected:
    FacilitiesFactory() = default;
    TransportFacilities* facilities;
    // std::vector<TransportFacilities*> facilities;
};