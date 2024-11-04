#include "RoadFactory.h"
TransportFacilities* RoadFactory:: createFacilities() {
        auto facility = new Road();
        return facility;
    }