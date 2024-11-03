// Concrete Creators - Facilities
#ifndef RAILWAYFACTORY_H
#define TRAILWAYFACTORY_H
#include "FacilitiesFactory.h"
#include "Railway.h"

class RailwayFactory : public FacilitiesFactory {
public:
    TransportFacilities* createFacilities();
};
#endif