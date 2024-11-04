// Concrete Creators - Facilities
#include "FacilitiesFactory.h"
#include "Road.h"

class RoadFactory : public FacilitiesFactory {
public:
    TransportFacilities* createFacilities();
};