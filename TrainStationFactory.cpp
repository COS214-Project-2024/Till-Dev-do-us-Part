// Concrete Creators - Stations
#include "TrainStationFactory.h"
#include "TrainStation.h"

TransportStation::~TransportStation(){
      
}

TransportStation* TrainStationFactory:: createStation() {
        auto station = new TrainStation();
        return station;
    }
    