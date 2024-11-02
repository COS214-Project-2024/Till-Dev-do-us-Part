// Road.h
#pragma once
#include "TransportFacilities.h"
#include "TransportMode.h"
#include <vector>
class TransportMode;
class Road : public TransportFacilities {
private:
    // int vehiclesCount;
    std::vector<TransportMode*> vehicles;

public:
    Road(TransState* state);
    Road();
    ~Road();
    void maintain() override;
    void setState(TransState* newState);
 
};