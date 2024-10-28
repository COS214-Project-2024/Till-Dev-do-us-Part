// Concrete Creators - Stations
#include "BusStopFactory.h"
#pragma once
#include "BusStop.h"

TransportStation* BusStopFactory:: createStation(const std::string& type) {
        // return new BusStop();
        auto station = new BusStop();
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