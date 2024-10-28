#include "FacilitiesFactory.h"
#include "Airport.h"

class AirportFactory : public FacilitiesFactory {
public:
    TransportFacilities* createFacilities();
};