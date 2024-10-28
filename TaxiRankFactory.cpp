// Concrete Creators - Stations
#include "TaxiRankFactory.h"
#include "TaxiRank.h"

 TransportStation* TaxiRankFactory:: createStation() {
        // return new TaxiRank();
        auto station = new TaxiRank();
        stations.push_back(station);
        return station;
    }

StationFactory::~StationFactory() {
    for (auto station : stations) {
        delete station;
    }
    stations.clear();
}

std::vector<TransportStation*>& StationFactory::getStations() {
    return stations;
}

void StationFactory::removeStation(TransportStation* station) {
    auto it = std::find(stations.begin(), stations.end(), station);
    if (it != stations.end()) {
        delete *it;
        stations.erase(it);
    }
}
