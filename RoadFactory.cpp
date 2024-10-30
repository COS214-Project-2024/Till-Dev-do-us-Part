#include "RoadFactory.h"
TransportFacilities* RoadFactory:: createFacilities() {
        // return new Road();
        auto facility = new Road();
        facilities.push_back(facility);
        return facility;
    }