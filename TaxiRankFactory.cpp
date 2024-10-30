// Concrete Creators - Stations
#include "TaxiRankFactory.h"
#include "TaxiRank.h"

 TransportStation* TaxiRankFactory:: createStation() {
        // return new TaxiRank();
        auto station = new TaxiRank();
        // stations.push_back(station);
        return station;
    }

