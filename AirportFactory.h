#include "FacilitiesFactory.h"
#include "Airport.h"
#include "TransportFacilities.h"
#include <vector>

class AirportFactory : public FacilitiesFactory {
public:
    TransportFacilities* createFacilities();
};