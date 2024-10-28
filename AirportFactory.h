#include "FacilitiesFactory.h"
#include "Airport.h"
#include "TransportFacilities.h"

class AirportFactory : public FacilitiesFactory {
public:
    TransportFacilities* createFacilities();
};