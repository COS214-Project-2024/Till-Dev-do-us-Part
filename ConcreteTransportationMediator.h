#ifndef CONCRETETRANSPORTATIONMEDIATOR_H
#define CONCRETETRANSPORTATIONMEDIATOR_H

// #pragma once
#include "TransportationMediator.h"
#include "TransportMode.h"
#include <vector>
#include <string>

class TransportMode;

class ConcreteTransportationMediator : public TransportationMediator {

public:
    ConcreteTransportationMediator();
    void notify(TransportMode* mode) override;
       
};

#endif // CONCRETE_TRANSPORTATION_MEDIATOR_H