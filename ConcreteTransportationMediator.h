#ifndef CONCRETETRANSPORTATIONMEDIATOR_H
#define CONCRETETRANSPORTATIONMEDIATOR_H

#include "TransportationMediator.h"
#include <vector>
#include <string>

class TransportMode;

class ConcreteTransportationMediator : public TransportationMediator {
private:
    std::vector<TransportMode*> modes;
    int roadTraffic, airTraffic;
    bool accident;
    std::string roadState, airState;

public:
    ConcreteTransportationMediator();
    void notify(TransportMode* mode, const std::string& state) override;
    void registerMode(TransportMode* mode) override;
    void manageTraffic() override;
};

#endif // CONCRETE_TRANSPORTATION_MEDIATOR_H