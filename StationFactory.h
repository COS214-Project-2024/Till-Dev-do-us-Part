// Abstract Creators
#pragma once
#include "TransportStation.h"

class StationFactory {
public:
    virtual ~StationFactory() = default;
    virtual TransportStation* createStation() = 0;  // Factory Method
    virtual void removeStation(TransportStation* station);
    virtual std::vector<TransportStation*>& getStations();
protected:
    StationFactory() = default;
    std::vector<TransportStation*> stations;
};