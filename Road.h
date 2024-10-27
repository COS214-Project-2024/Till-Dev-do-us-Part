// Road.h
#pragma once
#include "TransportFacilities.h"
#include <vector>

class Road : public TransportFacilities {
private:
    int vehiclesCount;
    std::vector<TransportMode*> vehicles;

public:
    void maintain() override;
    void useTransport() override;
    void addVehicle(TransportMode* vehicle);
    void removeVehicle(TransportMode* vehicle);
};