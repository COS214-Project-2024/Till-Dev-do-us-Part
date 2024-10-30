// Road.h
#pragma once
#include "TransportFacilities.h"
#include "TransportMode.h"
#include <vector>

class Road : public TransportFacilities {
private:
    // int vehiclesCount;
    std::vector<TransportMode*> vehicles;

public:
    Road(TransState* state);
    Road();
    ~Road();
    void maintain() override;
    void useTransport() override;
    void addVehicle(TransportMode* vehicle);
    void removeVehicle(TransportMode* vehicle);
    void changeState();
    void setState(TransState* newState);
    int getVehicleCount();

};