// Concrete Creators - Facilities
#include "RailwayFactory.h"
#include "Railway.h"

TransportFacilities* RailwayFactory:: createFacilities() {
        // return new Railway();
        auto facility = new Railway();
        facilities.push_back(facility);
        return facility;
    }

