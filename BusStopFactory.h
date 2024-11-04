// Concrete Creators - Stations
#include "StationFactory.h"

class BusStopFactory : public StationFactory {
public:
    TransportStation* createStation();
};