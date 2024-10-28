#include "RoadFactory.h"
TransportFacilities* RoadFactory:: createFacilities() {
        return new Road();
    }