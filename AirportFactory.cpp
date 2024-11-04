// Concrete Creators - Facilities
#include "AirportFactory.h"
TransportFacilities* AirportFactory:: createFacilities() {
        return new Airport();
    }

