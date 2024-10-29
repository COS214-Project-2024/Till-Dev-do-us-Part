#ifndef CONCRETETRANSPORTATIONMEDIATOR_H
#define CONCRETETRANSPORTATIONMEDIATOR_H

// #pragma once
#include "TransportationMediator.h"
#include "TransportMode.h"
#include <vector>
#include <string>

class TransportMode;

class ConcreteTransportationMediator : public TransportationMediator {
private:
    std::vector<TransportMode*> roadModes;     // Colleagues using the road
    std::vector<TransportMode*> railwayModes;  // Colleagues using the railway
    std::vector<TransportMode*> airportModes;  // airport

public:
    ConcreteTransportationMediator();
    void notify(TransportMode* mode, const std::string& state) override;
    void registerMode(TransportMode* mode);
    void manageTraffic(TransportMode* originator, const std::string& state);
};

#endif // CONCRETE_TRANSPORTATION_MEDIATOR_H