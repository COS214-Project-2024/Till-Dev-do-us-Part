// Abstract Creators
#pragma once
#include "TransportStation.h"
#include <algorithm>
#include <vector>

class StationFactory {
public:
    virtual ~StationFactory();
    virtual TransportStation* createStation() = 0;  // Factory Method
    virtual void removeStation(TransportStation* station);
    virtual std::vector<TransportStation*>& getStations();
protected:
    StationFactory() = default;
    std::vector<TransportStation*> stations;
};