#pragma once
// #include "TransportStation.h"
#include "StationFactory.h"

class TaxiRankFactory : public StationFactory {
public:
    TransportStation* createStation();

};
