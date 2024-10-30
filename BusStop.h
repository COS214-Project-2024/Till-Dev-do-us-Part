// BusStop.h
#pragma once
#include "TransportStation.h"
#include "TransportMode.h"
#include <list>

class BusStop : public TransportStation {
private:
    std::list<TransportMode*> buses;

public:
    void handlePassengers() override;
    void manageFreight() override;
    void maintain() override;
    //void addBus(TransportMode* bus);
};