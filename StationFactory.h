// Abstract Creators
#pragma once
#include "TransportStation.h"
#include <algorithm>
#include <vector>

class StationFactory {
public:
    virtual ~StationFactory();
    virtual TransportStation* createStation() = 0;  // Factory Method
    
    StationFactory() = default;
    TransportStation* stations;
};