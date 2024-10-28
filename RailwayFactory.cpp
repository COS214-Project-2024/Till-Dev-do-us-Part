// Concrete Creators - Facilities
#include "RailwayFactory.h"
TransportFacilities* RailwayFactory:: createFacilities() {
        return new Railway();
    }