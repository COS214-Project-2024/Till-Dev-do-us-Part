#pragma once
#include "TransportStation.h"
#include "StationFactory.h"

class TrainStationFactory : public StationFactory {
public:
    TransportStation* createStation();
};