// Concrete Creators - Facilities
#include "RailwayFactory.h"
#include "Railway.h"

TransportFacilities* RailwayFactory:: createFacilities() {
        auto facility = new Railway();
        return facility;
    }

