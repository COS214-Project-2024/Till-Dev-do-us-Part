// Concrete Creators - Facilities
#include "FacilitiesFactory.h"
#include "Railway.h"

class RailwayFactory : public FacilitiesFactory {
public:
    TransportFacilities* createFacilities();
};