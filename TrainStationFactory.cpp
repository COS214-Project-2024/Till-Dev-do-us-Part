// Concrete Creators - Stations
#include "TrainStationFactory.h"
#include "TrainStation.h"

TransportStation* TrainStationFactory:: createStation() {
        // return new TrainStation();
        auto station = new TrainStation();
        stations.push_back(station);
        return station;
    }
    