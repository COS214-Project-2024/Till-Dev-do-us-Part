// Concrete Creators - Stations
#include "TaxiRankFactory.h"
#include "TaxiRank.h"

 TransportStation* TaxiRankFactory:: createStation() {
        auto station = new TaxiRank();
        return station;
    }

