// Concrete Creators - Stations
#include "BusStopFactory.h"
#pragma once
#include "BusStop.h"

TransportStation* BusStopFactory:: createStation() {
        auto station = new BusStop();
        return station;
    }

