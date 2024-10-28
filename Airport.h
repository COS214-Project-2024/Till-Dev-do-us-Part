// Airport.h
#pragma once
#include "TransportStation.h"
#include <vector>
#include "FacilitiesFactory.h"

class Airport : public TransportFacilities {
private:
    int planesCount;
    std::vector<TransportMode*> planes;

public:
    // void handlePassengers() override;
    // void manageFreight() override;
    void maintain() override;
    void useTransport() override;
    void addPlane(TransportMode* plane);
    void removePlane(TransportMode* plane);
};