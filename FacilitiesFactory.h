// / Abstract Creators
#ifndef FACILITIESFACTORY_H
#define FACILITIESFACTORY_H
#pragma once
#include "TransportFacilities.h"
#include <algorithm>

class TransportFacilities;

class FacilitiesFactory {
public:
    ~FacilitiesFactory();
    virtual TransportFacilities* createFacilities() = 0;  // Factory Method

protected:
    // FacilitiesFactory();
    // TransportFacilities* facilities;
    
};
#endif