// Concrete Creators - Stations

#include "TaxiRankFactory.h"

 TransportStation* TaxiRankFactory:: createStation() {
        return new TaxiRank();
    }