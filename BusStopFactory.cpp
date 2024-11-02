// Concrete Creators - Stations
#include "BusStopFactory.h"
#pragma once
#include "BusStop.h"

TransportStation* BusStopFactory:: createStation() {
        // return new BusStop();
        auto station = new BusStop();
        // stations.push_back(station);
        return station;
    }
